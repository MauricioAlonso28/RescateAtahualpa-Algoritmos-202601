#pragma once
#include "Aliado.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	ref class Cusi;
	ref class Wayra;

	// Rimaq: aliado que abre un paso (puerta) y avisa a Wayra.
	public ref class Rimaq : public Aliado
	{
	private:
		Entidad^ puerta;
		Wayra^ wayra;

	public:
		Rimaq(int x, int y, Bitmap^ sprite, String^ frase);

		virtual bool puedeActivarse(Cusi^ c) override;
		virtual void interactuar(Cusi^ c) override;
		void abrirPaso();

		Entidad^ getPuerta();
		void setPuerta(Entidad^ p);
	};
}
