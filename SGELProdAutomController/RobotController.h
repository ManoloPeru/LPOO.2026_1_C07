#pragma once

namespace SGELProdAutomController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGELProdAutomModel;

    public ref class RobotController {
    private:
        // Ruta del archivo para almacenar los tipos de robots, esto se puede modificar según sea necesario
        String^ pathArchivo;
        // Repositorio en memoria para almacenar las unidades roboticas
        List<UnidadRobotica^>^ repositorio;

    public:
        RobotController(String^ pathArchivo);

        // CRUD Operations:
		// RegistrarUnidad devuelve true si el registro fue exitoso, false si hubo un error (e.g., robot nulo o Serial ID duplicado)
        String^ RegistrarUnidad(UnidadRobotica^ robot);
		// ConsultarUnidad devuelve la unidad encontrada o nullptr si no se encuentra
        UnidadRobotica^ ConsultarUnidad(String^ serialId);
		// ListarUnidades devuelve la lista completa de unidades registradas
        List<UnidadRobotica^>^ ListarUnidades();
		// ModificarUnidad devuelve true si la modificación fue exitosa, false si no se encuentra la unidad
        String^ ModificarUnidad(String^ serialId, String^ nuevoAlias, String^ nuevoTipo, EstadoOperativo nuevoEstado, String^ nuevaUbicacion);
		// EliminarUnidad devuelve true si la eliminación fue exitosa, false si no se encuentra la unidad
        String^ EliminarUnidad(String^ serialId);
        List<UnidadRobotica^>^ ConsultarIdTipo(String^ serialId, String^ tipoRobot);

        // Métodos auxiliares:
		// ContarUnidades devuelve el número total de unidades registradas
        int ContarUnidades();
		// ExisteUnidad devuelve true si existe una unidad con el Serial ID dado, false en caso contrario
        bool ExisteUnidad(String^ serialId);

		// Método para escribir el repositorio en el archivo, se puede llamar después de cada operación que modifique el repositorio
        void escribirArchivo();
        // Ultima acción para liberar memoria, conexiones
        void LibreraMemoria();
    };
}