#pragma once
#include "Aliado.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	ref class Cusi;

	// Wayra: aliado que se activa al recibir la senial de Rimaq.
	public ref class Wayra : public Aliado
	{
	private:
		bool senalDeRimaq;

	public:
		Wayra(int x, int y, Bitmap^ sprite, String^ frase);

		void recibirSenal();
		virtual bool puedeActivarse(Cusi^ c) override;
		virtual void interactuar(Cusi^ c) override;

		bool getSenalDeRimaq();
		void setSenalDeRimaq(bool s);
	};
}
