#pragma once
#include "SoldadoPatrulla.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	ref class Cusi;

	// Soldado especial: si detecta a Cusi lo persigue.
	public ref class GuardianEspecial : public SoldadoPatrulla
	{
	private:
		int radioVigilancia;
		int velocidadPersecucion;

	public:
		GuardianEspecial(int x, int y, Bitmap^ sprite, int velocidad, EjePatrulla eje);

		virtual void mover() override;
		bool detecta(Cusi^ c);

		int getRadioVigilancia();
		void setRadioVigilancia(int r);
		int getVelocidadPersecucion();
		void setVelocidadPersecucion(int v);
	};
}
