#pragma once
#include "Aliado.h"
#include "Cusi.h"
#include "Config.h"
#include "Wayra.h"
#include <string>

using namespace System::Drawing;
using namespace std;

class Rimaq : public Aliado {
private:
	Entidad* puerta;
	Wayra* wayra;
	bool puertaAbierta;

public:
	Rimaq(int x, int y, string rutaSprite, string frase);

	bool puedeActivarse(Cusi* c);
	void interactuar(Cusi* c);
	void abrirPaso();

	bool getPuertaAbierta();
	void dibujar(Graphics^ g);
	Entidad* getPuerta();
	void setPuerta(Entidad* p);
};
