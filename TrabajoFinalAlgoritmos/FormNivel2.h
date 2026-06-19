#pragma once
#include "FormControlJuego.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	// Nivel 2: altiplano. Las zonas de nieve frenan a Cusi.
	public ref class FormNivel2 : public FormControlJuego
	{
	private:
		Bitmap^ fondoAltiplano;
		List<Rectangle>^ zonasNieve;

	public:
		FormNivel2(Juego^ j) : FormControlJuego(j)
		{
			// anadir logica
		}

		virtual void cargarNivel() override;
		virtual void mostrarPreguntaReflexiva() override;
		void aplicarLentitudNieve();
	};
}
