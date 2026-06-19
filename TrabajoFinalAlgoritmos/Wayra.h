#pragma once
#include "Aliado.h"
#include "Cusi.h"
#include <string>
using namespace System::Drawing;
using namespace std;

class Wayra : public Aliado {
private:
	bool senalDeRimaq;

public:
	Wayra(int x, int y, string rutaSprite, string frase);

	void recibirSenal();
	bool puedeActivarse(Cusi* c);
	void interactuar(Cusi* c);

	bool getSenalDeRimaq();
	void setSenalDeRimaq(bool s);
};
