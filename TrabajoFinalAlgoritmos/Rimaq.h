#pragma once
#include "Aliado.h"
#include "Cusi.h"
#include "Config.h"
class Rimaq : public Aliado {

private:
	bool puertaAbierta;

public:

	Rimaq(int x, int y, string rutaSprite, string frase);

	bool puedeActivarse(Cusi* c);
	void interactuar(Cusi* c);

	bool getPuertaAbierta();
	void dibujar(Graphics^ g);
};