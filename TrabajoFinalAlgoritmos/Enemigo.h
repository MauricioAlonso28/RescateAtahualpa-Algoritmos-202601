#pragma once
#include "Personaje.h"
#include "Cusi.h"
#include <string>
using namespace System::Drawing;
using namespace std;

class Enemigo : public Personaje {
private:
	int puntosCastigo;

public:
	Enemigo(int x, int y, string rutaSprite, int velocidad);

	virtual void alColisionar(Cusi* c);

	int getPuntosCastigo();
	void setPuntosCastigo(int p);
};
