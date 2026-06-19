#pragma once
#include "SoldadoPatrulla.h"
#include "Cusi.h"
#include <string>
using namespace System::Drawing;
using namespace std;

class GuardianEspecial : public SoldadoPatrulla {
private:
	int radioVigilancia;
	int velocidadPersecucion;

public:
	GuardianEspecial(int x, int y, string rutaSprite, int velocidad, EjePatrulla eje);

	void mover();
	bool detecta(Cusi* c);

	int getRadioVigilancia();
	void setRadioVigilancia(int r);
	int getVelocidadPersecucion();
	void setVelocidadPersecucion(int v);
};
