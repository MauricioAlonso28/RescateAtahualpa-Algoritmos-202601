#pragma once
#include "Enemigo.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	ref class Cusi;

	// Capitan espaniol: persigue a Cusi dentro de su radio de deteccion.
	public ref class CapitanEspanol : public Enemigo
	{
	private:
		int radioDeteccion;
		Cusi^ objetivo;
		bool bloqueado;

	public:
		CapitanEspanol(int x, int y, Bitmap^ sprite, int velocidad);

		virtual void mover() override;
		double calcularDistancia(Cusi^ c);
		void quedarBloqueado();

		int getRadioDeteccion();
		void setRadioDeteccion(int r);
		Cusi^ getObjetivo();
		void setObjetivo(Cusi^ c);
		bool getBloqueado();
	};
}
