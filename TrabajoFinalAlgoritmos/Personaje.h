#pragma once
#include "Entidad.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	// Entidad que ademas tiene nombre y velocidad y se puede mover.
	public ref class Personaje : public Entidad
	{
	private:
		String^ nombre;
		int velocidad;

	public:
		Personaje(int x, int y, Bitmap^ sprite, int velocidad);

		virtual void mover();

		String^ getNombre();
		void setNombre(String^ n);
		int getVelocidad();
		void setVelocidad(int v);
	};
}
