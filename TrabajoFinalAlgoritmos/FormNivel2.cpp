#include "FormNivel2.h"

namespace TrabajoFinalAlgoritmos {

	void FormNivel2::cargarNivel()
	{
		nivel = new Nivel();
		nivel->setNumero(2);
		nivel->cargar();
		
		this->Text = L"Nivel 2";

		// Tamaño temporal del formulario para el Nivel 2
		this->ClientSize = System::Drawing::Size(1366, 768);
		this->CenterToScreen();

		zonasNieve = gcnew List<Rectangle>();

		// Las zonas de nieve se agregarán cuando diseñemos el mapa.
	}

	void FormNivel2::mostrarPreguntaReflexiva()
	{
		// La reflexión del Nivel 2 se muestra mediante una imagen,
		// por lo que aquí no es necesario poner logica :V xD
	}

	void FormNivel2::aplicarLentitudNieve()
	{
		// anadir logica
	}

}