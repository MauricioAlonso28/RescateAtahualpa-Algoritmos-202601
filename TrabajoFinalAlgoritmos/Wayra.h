#pragma once
#include "Aliado.h"
#include "Cusi.h"
#include <string>
#include "Config.h"

using namespace System::Drawing;
using namespace std;

class Wayra : public Aliado {
private:
	bool puertaAbierta;
	bool senalDeRimaq;

public:
	Wayra(int x, int y, string rutaSprite, string frase);

	bool puedeActivarse(Cusi* c);
	void recibirSenal();
	void interactuar(Cusi* c);
	bool getPuertaAbierta();

	virtual void dibujar(Graphics^ g);
	bool getSenalDeRimaq();
	void setSenalDeRimaq(bool s);
};
