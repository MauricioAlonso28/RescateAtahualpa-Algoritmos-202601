#pragma once
#include "Enemigo.h"
#include "Cusi.h"
#include <string>
using namespace System::Drawing;
using namespace std;

class CapitanEspanol : public Enemigo {
private:
	int radioDeteccion;
	Cusi* objetivo;
	bool bloqueado;

public:
	CapitanEspanol(int x, int y, string rutaSprite, int velocidad);

	void mover();
	double calcularDistancia(Cusi* c);
	void quedarBloqueado();

	int getRadioDeteccion();
	void setRadioDeteccion(int r);
	Cusi* getObjetivo();
	void setObjetivo(Cusi* c);
	bool getBloqueado();
};
