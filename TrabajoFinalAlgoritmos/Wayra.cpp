#include "Wayra.h"

Wayra::Wayra(int x, int y, string rutaSprite, string frase)
	: Aliado(x, y, rutaSprite, frase) {
	// anadir logica
}

void Wayra::recibirSenal() {
	// anadir logica
}

bool Wayra::puedeActivarse(Cusi* c) {
	// anadir logica
	return false;
}

void Wayra::interactuar(Cusi* c) {
	// anadir logica
}

bool Wayra::getSenalDeRimaq() { return senalDeRimaq; }
void Wayra::setSenalDeRimaq(bool s) { this->senalDeRimaq = s; }
