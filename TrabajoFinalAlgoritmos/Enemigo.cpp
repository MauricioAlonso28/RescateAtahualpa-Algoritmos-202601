#include "Enemigo.h"

Enemigo::Enemigo(int x, int y, string rutaSprite, int velocidad)
	: Personaje(x, y, rutaSprite, velocidad) {
	// anadir logica
}

void Enemigo::alColisionar(Cusi* c) {
	// anadir logica
}

int Enemigo::getPuntosCastigo() { return puntosCastigo; }
void Enemigo::setPuntosCastigo(int p) { this->puntosCastigo = p; }
