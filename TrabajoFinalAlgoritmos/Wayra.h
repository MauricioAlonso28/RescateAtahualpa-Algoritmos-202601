#pragma once
#include "Aliado.h"
#include "Cusi.h"
#include "Config.h"

class Wayra : public Aliado {

private:
	bool puertaAbierta;

public:

	Wayra(int x, int y, string rutaSprite, string frase);

	bool puedeActivarse(Cusi* c);
	void interactuar(Cusi* c);

	bool getPuertaAbierta();

	virtual void dibujar(Graphics^ g);
};