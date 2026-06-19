#pragma once
#include "Enemigo.h"
#include "Enums.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	// Enemigo que patrulla en linea recta sobre un eje.
	public ref class SoldadoPatrulla : public Enemigo
	{
	private:
		EjePatrulla ejePatrulla;
		int sentido;

	public:
		SoldadoPatrulla(int x, int y, Bitmap^ sprite, int velocidad, EjePatrulla eje);

		virtual void mover() override;

		EjePatrulla getEjePatrulla();
		void setEjePatrulla(EjePatrulla e);
		int getSentido();
		void setSentido(int s);
	};
}
