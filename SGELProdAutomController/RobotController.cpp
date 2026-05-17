#include "RobotController.h"
using namespace System::IO; // Agregar esta línea para usar System::IO para manejo de archivos

namespace SGELProdAutomController {
    RobotController::RobotController(String^ pathArchivo) {
		//Paso 1: Inicializar el repositorio en memoria
        this->repositorio = gcnew List<UnidadRobotica^>();
        
        //Paso 2: Construye la ruta completa del archivo de unidadRobotica
        this->pathArchivo = Path::Combine(pathArchivo, "unidadRobotica.txt");
        
        //Paso 3: Asegura que el directorio exista y carga los unidadRoboticas desde el archivo
        String^ dir = Path::GetDirectoryName(this->pathArchivo);
        
        //Paso4: Si el directorio no existe, lo crea (no falla si ya existe)
        Directory::CreateDirectory(dir);
        
        //Paso 5: Si el archivo no existe, lo crea vacío. 
        if (!File::Exists(this->pathArchivo)) {
            // Si el archivo no existe, lo crea vacío
            File::WriteAllText(this->pathArchivo, "");
        }
        
		//Paso6: Lee las líneas del archivo y carga las unidades roboticas en la lista
        array<String^>^ lineas = File::ReadAllLines(this->pathArchivo);
        
        //Paso7: Define el separador para dividir los campos en cada línea
        String^ separadores = ";";

		//Paso8: Recorre cada línea del archivo, divide los campos por el separador y crea objetos UnidadRobotica para agregarlos al repositorio en memoria
        for each (String ^ linea in lineas) {
            array<String^>^ campos = linea->Split(separadores->ToCharArray());
            String^ SerialId = campos[0];
            String^ alias = campos[1];
			String^ tipo = campos[2];
			EstadoOperativo estado = UnidadRobotica::ConvertirEstadoOperativo(campos[3]);
			String^ ubicacion = campos[4];

			//Paso9: Crea un nuevo objeto UnidadRobotica con los datos leídos del archivo y lo agrega al repositorio en memoria
            UnidadRobotica^ robot = gcnew UnidadRobotica(SerialId, alias, tipo, estado, ubicacion);
            this->repositorio->Add(robot);
        }
    }

	// Implementación de los métodos CRUD y auxiliares:
	// ----------------------------------------------------------
	// RegistrarUnidad valida que el robot no sea nulo y que el Serial ID no esté duplicado antes de agregarlo al repositorio
    String^ RobotController::RegistrarUnidad(UnidadRobotica^ robot) {
		// Validar que el robot no sea nulo
        if (robot == nullptr) {
            return "Robot nulo.";
        }
		// Validar que el Serial ID no esté vacío
        else if (ExisteUnidad(robot->getSerialId())) {
            return "Ya existe un robot con el Serial ID: " + robot->getSerialId();
        }
        else
        {   // Agregar el robot al repositorio
            this->repositorio->Add(robot);
            escribirArchivo();
            return "";
        }
    }

	// ConsultarUnidad recorre el repositorio para encontrar un robot con el Serial ID dado, ignorando mayúsculas/minúsculas
    UnidadRobotica^ RobotController::ConsultarUnidad(String^ serialId) {
		// Validar que el Serial ID no esté vacío
        if (String::IsNullOrEmpty(serialId)) {
            Console::WriteLine("Error: Serial ID no puede ser vacío.");
            return nullptr;
        }
		// Buscar el robot en el repositorio
        for each (UnidadRobotica ^ robot in this->repositorio) {
			// Comparar Serial ID ignorando mayúsculas/minúsculas
            if (robot->getSerialId()->Equals(serialId, StringComparison::OrdinalIgnoreCase)) {
				// Robot encontrado
                return robot;
            }
        }
		
        Console::WriteLine("Robot no encontrado con Serial ID: {0}", serialId);
		// Robot no encontrado
        return nullptr;
    }

	// ListarUnidades devuelve la lista completa de robots registrados en el repositorio
    List<UnidadRobotica^>^ RobotController::ListarUnidades() {
		return this->repositorio; // Devuelve la referencia a la lista completa de robots
    }

	// ModificarUnidad busca el robot por Serial ID y actualiza sus propiedades si se encuentra, permitiendo mantener valores actuales si no se proporcionan nuevos
    String^ RobotController::ModificarUnidad(String^ serialId, String^ nuevoAlias, String^ nuevoTipo, EstadoOperativo nuevoEstado, String^ nuevaUbicacion) {
		// Buscar el robot por Serial ID
        UnidadRobotica^ robot = ConsultarUnidad(serialId);
		// Validar que el robot exista
        if (robot == nullptr) {
            return "Robot no encontrado.";
        }
        else
        {
            // Actualizar las propiedades del robot solo si se proporcionan nuevos valores, de lo contrario mantener los actuales
            if (!String::IsNullOrEmpty(nuevoAlias)) {
                robot->setAlias(nuevoAlias);
            }
            if (!String::IsNullOrEmpty(nuevoTipo)) {
                robot->setTipo(nuevoTipo);
            }
            // El estado operativo se actualiza siempre, ya que es un valor enum y no puede ser nulo
            robot->setEstado(nuevoEstado);
            // La ubicación se actualiza solo si se proporciona un nuevo valor, de lo contrario se mantiene la ubicación actual
            if (!String::IsNullOrEmpty(nuevaUbicacion)) {
                robot->setUbicacion(nuevaUbicacion);
            }
            escribirArchivo();
            return "";    // Modificación exitosa
        }
    }

	// EliminarUnidad busca el robot por Serial ID y lo elimina del repositorio si se encuentra, devolviendo true si la eliminación fue exitosa o false si no se encuentra el robot
    String^ RobotController::EliminarUnidad(String^ serialId) {
		// Buscar el robot por Serial ID
        for (int i = 0; i < this->repositorio->Count; i++) {
			// Comparar Serial ID ignorando mayúsculas/minúsculas
            if (this->repositorio[i]->getSerialId()->Equals(serialId, StringComparison::OrdinalIgnoreCase)) {
				// Robot encontrado, eliminarlo del repositorio
                this->repositorio->RemoveAt(i);
				// Escribir los cambios en el archivo
                escribirArchivo();
				// Devolvemos vacio para indicar que la eliminación fue exitosa
                return "";    // Eliminación exitosa
            }
        }
		// Robot no encontrado, devolvemos mensaje de error
        return "Robot no encontrado para eliminar: {0}", serialId;
    }

	// ContarUnidades devuelve el número total de robots registrados en el repositorio
    int RobotController::ContarUnidades() {
		// El número total de robots registrados es igual a la cantidad de elementos en el repositorio
        return this->repositorio->Count;
    }

	// ExisteUnidad utiliza el método ConsultarUnidad para verificar si un robot con el Serial ID dado existe en el repositorio, devolviendo true si se encuentra o false si no se encuentra
    bool RobotController::ExisteUnidad(String^ serialId) {
		// Utilizar el método ConsultarUnidad para verificar si el robot existe
        return ConsultarUnidad(serialId) != nullptr;
    }

	// ConsultarIdTipo busca robots que coincidan con el Serial ID o el Tipo de robot proporcionados, devolviendo una lista filtrada de robots que cumplen con alguno de los criterios, ignorando mayúsculas/minúsculas
    List<UnidadRobotica^>^ RobotController::ConsultarIdTipo(String^ serialId, String^ tipoRobot) {
        List<UnidadRobotica^>^ listaFiltrada = gcnew List<UnidadRobotica^>();
        // Validar que el Serial ID no esté vacío
        if (String::IsNullOrEmpty(serialId) && String::IsNullOrEmpty(tipoRobot)) {
            Console::WriteLine("Error: Serial ID o Tipo rabot no pueden ser vacíos.");
            return listaFiltrada;
        }
        // Buscar el robot en el repositorio
        for each (UnidadRobotica ^ robot in this->repositorio) {
            // Comparar Serial ID ignorando mayúsculas/minúsculas
            if (robot->getSerialId()->Equals(serialId, StringComparison::OrdinalIgnoreCase)) {
                // Robot encontrado
                listaFiltrada->Add(robot);
            }
            else if (robot->getTipo()->Equals(tipoRobot, StringComparison::OrdinalIgnoreCase)) {
                // Robot encontrado
                listaFiltrada->Add(robot);
            }
        }
		// retorna la lista filtrada de robots que coinciden con el Serial ID o el Tipo de robot, si no se encuentra ningún robot coincidente, la lista estará vacía
        return listaFiltrada;
    }

    void RobotController::escribirArchivo() {
        array<String^>^ lineasArchivo = gcnew array<String^>(this->repositorio->Count);
        for (int i = 0; i < this->repositorio->Count; i++) {
            UnidadRobotica^ unidadRobotica = this->repositorio[i];
            lineasArchivo[i] = unidadRobotica->getSerialId() + ";" +
                unidadRobotica->getAlias() + ";" +
                unidadRobotica->getTipo() + ";" +
                unidadRobotica->ObtenerEstadoString() + ";" +
                unidadRobotica->getUbicacion();
        }
        // Escribe todas las líneas al archivo, sobrescribiendo el contenido anterior
        File::WriteAllLines(this->pathArchivo, lineasArchivo);
    }

    void RobotController::LibreraMemoria() {
        this->repositorio = nullptr;
    }
}