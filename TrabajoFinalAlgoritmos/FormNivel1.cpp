#include "FormNivel1.h"

namespace TrabajoFinalAlgoritmos {

	void FormNivel1::cargarNivel() {
		nivel = new Nivel();
		nivel->setNumero(1);
		nivel->cargar();

		this->Text = L"El Rescate de Atahualpa - Nivel 1: El Camino del Chinchaysuyo";
	}

	void FormNivel1::mostrarPreguntaReflexiva() {
		System::Windows::Forms::MessageBox::Show(
			"Pregunta reflexiva:\n\"Puede un mensaje cambiar el destino de un pueblo?\"\n\n"
			"La transmision del conocimiento requiere accion. "
			"Un mensaje que no llega es un mensaje perdido.",
			"Nivel 1 - Reflexion",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Information);
	}
}
