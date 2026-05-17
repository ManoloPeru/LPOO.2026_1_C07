#pragma once

namespace SGELProdAutomModel {
    using namespace System;
	
	// Empleamos Enumeración para listar Estados, Tipos, etc. 
    // Cualquier lista de opciones fijas es ideal para esto.
    public enum class EstadoOperativo {
		// Definir los estados operativos típicos
        Operativo,
        EnMantenimiento,
        Falla
    };

    public ref class UnidadRobotica {
    private:
        String^ serialId;           // Identificador único
        String^ alias;              // Nombre descriptivo
        String^ tipo;               // "Paralelo", "Redundante"
        EstadoOperativo estado;     // Estado operativo
        String^ ubicacion;          // Ubicación en la planta

    public:
        UnidadRobotica();
        UnidadRobotica(String^ serialId, String^ alias, String^ tipo,
            EstadoOperativo estado, String^ ubicacion);

        String^ getSerialId();
        void setSerialId(String^ value);

        String^ getAlias();
        void setAlias(String^ value);

        String^ getTipo();
        void setTipo(String^ value);

        EstadoOperativo getEstado();
        void setEstado(EstadoOperativo value);

        String^ getUbicacion();
        void setUbicacion(String^ value);

        // Métodos
        // Para representar la unidad robótica como una cadena legible
		virtual String^ ToString() override;    
        // Para convertir el estado operativo a una cadena legible
		String^ ObtenerEstadoString();  
		// Para convertir una cadena a un valor del enum EstadoOperativo, útil para convertir datos ingresados por el usuario o leídos de una fuente externa
        static EstadoOperativo ConvertirEstadoOperativo(System::String^ estado); 
    };
}