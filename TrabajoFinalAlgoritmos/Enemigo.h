#pragma once
#include "Personaje.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	ref class Cusi;

	// Base de todos los enemigos. Castiga a Cusi al colisionar.
	public ref class Enemigo : public Personaje
	{
	private:
		int puntosCastigo;

	public:
		Enemigo(int x, int y, Bitmap^ sprite, int velocidad);

		virtual void alColisionar(Cusi^ c);

		int getPuntosCastigo();
		void setPuntosCastigo(int p);
	};
}
