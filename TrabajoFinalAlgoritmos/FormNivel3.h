#pragma once
#include "FormControlJuego.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class FormNivel3 : public FormControlJuego
	{
	private:
		Bitmap^ fondoSelva;
		ProgressBar^ barraTiempo;
		int tiempoRestante;

	public:
		FormNivel3(Juego* j) : FormControlJuego(j)
		{
			// anadir logica
		}

		virtual void cargarNivel() override;
		virtual void mostrarPreguntaReflexiva() override;
		void decrementarTiempo();
		int getTiempoRestante();
		void setTiempoRestante(int t);
	};
}
