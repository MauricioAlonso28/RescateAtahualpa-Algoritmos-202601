#pragma once
#include "FormControlJuego.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class FormNivel2 : public FormControlJuego
	{
	private:
		Bitmap^ fondoAltiplano;
		List<Rectangle>^ zonasNieve;

	public:
		FormNivel2(Juego* j) : FormControlJuego(j)
		{
			// anadir logica
		}

		virtual void cargarNivel() override;
		virtual void mostrarPreguntaReflexiva() override;
		void aplicarLentitudNieve();
	};
}
