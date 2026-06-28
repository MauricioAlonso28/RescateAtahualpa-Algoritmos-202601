#pragma once
#include "FormControlJuego.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class FormNivel1 : public FormControlJuego
	{
	private:
		Bitmap^ fondoCostero;

	public:
		FormNivel1(Juego* j) : FormControlJuego(j)
		{
			// anadir logica
		}

		virtual void cargarNivel() override;
		virtual void mostrarPreguntaReflexiva() override;
	};
}