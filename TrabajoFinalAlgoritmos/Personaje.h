#pragma once
#include "Entidad.h"
#include <string>
using namespace System::Drawing;
using namespace std;

class Personaje : public Entidad {
private:
	string nombre;
	int velocidad;

public:
	Personaje(int x, int y, string rutaSprite, int velocidad);

	virtual void mover();

	string getNombre();
	void setNombre(string n);
	int getVelocidad();
	void setVelocidad(int v);
};
