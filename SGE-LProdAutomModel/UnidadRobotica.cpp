#include "UnidadRobotica.h"

namespace SGELProdAutomModel {
    UnidadRobotica::UnidadRobotica() {
        this->serialId = "DESCONOCIDO";
        this->alias = "SIN_NOMBRE";
        this->tipo = "DESCONOCIDO";
		this->estado = EstadoOperativo::Falla; // Asumimos que el estado por defecto es "Falla" para indicar que no está operativo
        this->ubicacion = "SIN_UBICACION";
    }

    UnidadRobotica::UnidadRobotica(String^ serialId, String^ alias, String^ tipo,
        EstadoOperativo estado, String^ ubicacion) {
        this->serialId = serialId;
        this->alias = alias;
        this->tipo = tipo;
        this->estado = estado;
        this->ubicacion = ubicacion;
    }

    String^ UnidadRobotica::getSerialId() {
        return this->serialId;
	}

    void UnidadRobotica::setSerialId(String^ value) {
        this->serialId = value;
	}

    String^ UnidadRobotica::getAlias() {
		return this->alias;
	}

    void UnidadRobotica::setAlias(String^ value) {
		this->alias = value;
	}

	String^ UnidadRobotica::getTipo() {
		return this->tipo;
	}

	void UnidadRobotica::setTipo(String^ value) {
		this->tipo = value;
	}

    EstadoOperativo UnidadRobotica::getEstado() {
		return this->estado;
	}

	void UnidadRobotica::setEstado(EstadoOperativo value) {
		this->estado = value;
	}

	String^ UnidadRobotica::getUbicacion() {
		return this->ubicacion;
	}

	void UnidadRobotica::setUbicacion(String^ value) {
		this->ubicacion = value;
	}

	// Método para convertir el estado operativo a una cadena legible
    String^ UnidadRobotica::ObtenerEstadoString() {
        switch (this->estado) {
        case EstadoOperativo::Operativo:
            return "Operativo";
        case EstadoOperativo::EnMantenimiento:
            return "En Mantenimiento";
        case EstadoOperativo::Falla:
            return "Falla";
        default:
            return "Desconocido";
        }
    }

	// Método para convertir una cadena a un valor del enum EstadoOperativo, útil para convertir datos ingresados por el usuario o leídos de una fuente externa
    EstadoOperativo UnidadRobotica::ConvertirEstadoOperativo(String^ estadoStr) {
        if (estadoStr == "Operativo") return EstadoOperativo::Operativo;
        if (estadoStr == "En Mantenimiento") return EstadoOperativo::EnMantenimiento;
        return EstadoOperativo::Falla;
    }

	// Método ToString para representar la unidad robótica como una cadena legible, útil para depuración y visualización
    String^ UnidadRobotica::ToString() {
        return String::Format(
            "Serial ID: {0},  Alias: {1},  Tipo: {2},  Estado: {3},  Ubicacion: {4}",
            this->serialId, this->alias, this->tipo, ObtenerEstadoString(), this->ubicacion);
    }
}