#include "AncianoAntisuyo.h"

AncianoAntisuyo::AncianoAntisuyo(int x, int y, string rutaSprite, string frase)
	: Aliado(x, y, rutaSprite, frase) {
	// anadir logica
}

void AncianoAntisuyo::revelarse() {
	// anadir logica
}

bool AncianoAntisuyo::puedeActivarse(Cusi* c) {
	// anadir logica
	return false;
}

void AncianoAntisuyo::interactuar(Cusi* c) {
	// anadir logica
}

bool AncianoAntisuyo::getNivelesPreviosCompletos() { return nivelesPreviosCompletos; }
void AncianoAntisuyo::setNivelesPreviosCompletos(bool n) { this->nivelesPreviosCompletos = n; }
