#pragma once
#include "Aliado.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	ref class Cusi;

	// Curaca: aliado que orienta y da puntos a Cusi.
	public ref class Curaca : public Aliado
	{
	public:
		Curaca(int x, int y, Bitmap^ sprite, String^ frase);

		virtual bool puedeActivarse(Cusi^ c) override;
		virtual void interactuar(Cusi^ c) override;
	};
}
