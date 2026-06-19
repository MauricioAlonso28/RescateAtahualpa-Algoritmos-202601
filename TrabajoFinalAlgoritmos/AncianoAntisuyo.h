#pragma once
#include "Aliado.h"
#include "Cusi.h"
#include <string>
using namespace System::Drawing;
using namespace std;

class AncianoAntisuyo : public Aliado {
private:
	bool nivelesPreviosCompletos;

public:
	AncianoAntisuyo(int x, int y, string rutaSprite, string frase);

	void revelarse();
	bool puedeActivarse(Cusi* c);
	void interactuar(Cusi* c);

	bool getNivelesPreviosCompletos();
	void setNivelesPreviosCompletos(bool n);
};
