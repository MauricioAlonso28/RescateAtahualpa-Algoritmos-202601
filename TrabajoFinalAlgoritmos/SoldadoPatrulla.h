#pragma once
#include "Enemigo.h"
#include "Enums.h"
#include <string>
using namespace System::Drawing;
using namespace std;

class SoldadoPatrulla : public Enemigo {
private:
	EjePatrulla ejePatrulla;
	int sentido;

public:
	SoldadoPatrulla(int x, int y, string rutaSprite, int velocidad, EjePatrulla eje);

	void mover();

	EjePatrulla getEjePatrulla();
	void setEjePatrulla(EjePatrulla e);
	int getSentido();
	void setSentido(int s);
};
