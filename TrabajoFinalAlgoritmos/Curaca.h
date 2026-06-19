#pragma once
#include "Aliado.h"
#include "Cusi.h"
#include <string>
using namespace System::Drawing;
using namespace std;

class Curaca : public Aliado {
public:
	Curaca(int x, int y, string rutaSprite, string frase);

	bool puedeActivarse(Cusi* c);
	void interactuar(Cusi* c);
};
