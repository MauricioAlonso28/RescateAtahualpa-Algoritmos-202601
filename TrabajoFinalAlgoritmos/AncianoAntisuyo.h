#pragma once
#include "Aliado.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	ref class Cusi;

	// Anciano del Antisuyo: solo se revela si los niveles previos estan completos.
	public ref class AncianoAntisuyo : public Aliado
	{
	private:
		bool nivelesPreviosCompletos;

	public:
		AncianoAntisuyo(int x, int y, Bitmap^ sprite, String^ frase);

		void revelarse();
		virtual bool puedeActivarse(Cusi^ c) override;
		virtual void interactuar(Cusi^ c) override;

		bool getNivelesPreviosCompletos();
		void setNivelesPreviosCompletos(bool n);
	};
}
