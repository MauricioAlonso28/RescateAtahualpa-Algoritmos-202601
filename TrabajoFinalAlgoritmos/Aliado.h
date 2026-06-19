#pragma once
#include "Entidad.h"
#include <string>
using namespace System::Drawing;
using namespace std;

class Cusi;

class Aliado : public Entidad {
private:
	string fraseClave;
	int puntosInteraccion;
	bool activado;

public:
	Aliado(int x, int y, string rutaSprite, string frase);

	virtual bool puedeActivarse(Cusi* c);
	virtual void interactuar(Cusi* c);

	string getFraseClave();
	void setFraseClave(string f);
	int getPuntosInteraccion();
	void setPuntosInteraccion(int p);
	bool getActivado();
	void setActivado(bool a);
};
