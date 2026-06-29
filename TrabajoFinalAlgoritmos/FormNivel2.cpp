#include "FormNivel2.h"

namespace TrabajoFinalAlgoritmos {

	void FormNivel2::cargarNivel() 
	{
		nivel = new Nivel();
		nivel->setNumero(2);
		nivel->cargar();

		this->Text = L"Nivel 2";

		zonasNieve = gcnew List<Rectangle>();

		// Las zonas de nieve se agregarán cuando diseñemos el mapa.
	}

	void FormNivel2::mostrarPreguntaReflexiva() {
		// anadir logica
	}

	void FormNivel2::aplicarLentitudNieve() {
		// anadir logica
	}
}