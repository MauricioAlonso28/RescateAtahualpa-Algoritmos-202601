#pragma once
#include "Entidad.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	ref class Cusi;

	// Base de los personajes aliados con los que Cusi puede interactuar.
	public ref class Aliado : public Entidad
	{
	private:
		String^ fraseClave;
		int puntosInteraccion;
		bool activado;

	public:
		Aliado(int x, int y, Bitmap^ sprite, String^ frase);

		virtual bool puedeActivarse(Cusi^ c);
		virtual void interactuar(Cusi^ c);

		String^ getFraseClave();
		void setFraseClave(String^ f);
		int getPuntosInteraccion();
		void setPuntosInteraccion(int p);
		bool getActivado();
		void setActivado(bool a);
	};
}
