#include "Rimaq.h"

Rimaq::Rimaq(int x, int y, string rutaSprite, string frase)
	: Aliado(x, y, rutaSprite, frase) {
	// anadir logica
}

bool Rimaq::puedeActivarse(Cusi* c) {
	// anadir logica
	return false;
}

void Rimaq::interactuar(Cusi* c) {
	// anadir logica
}

void Rimaq::abrirPaso() {
	// anadir logica
}

Entidad* Rimaq::getPuerta() { return puerta; }
void Rimaq::setPuerta(Entidad* p) { this->puerta = p; }
