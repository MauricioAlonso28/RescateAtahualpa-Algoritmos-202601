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

	int frameActual;
	int contadorAnim;
	int frameAncho;
	int frameAlto;

	int limMin;
	int limMax;

public:
	SoldadoPatrulla(int x, int y, string rutaSprite, int velocidad, EjePatrulla eje);

	void mover();
	void animar();
	void dibujar(Graphics^ g);
	void setLimites(int minimo, int maximo);

	EjePatrulla getEjePatrulla();
	void setEjePatrulla(EjePatrulla e);
	int getSentido();
	void setSentido(int s);
};
