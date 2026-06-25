#include "Enemigo.h"
#include "Config.h"

Enemigo::Enemigo(int x, int y, string rutaSprite, int velocidad)
	: Personaje(x, y, rutaSprite, velocidad) {
	this->puntosCastigo = PTS_CASTIGO_ENEMIGO;
}

void Enemigo::alColisionar(Cusi* c) {
	c->perderVida();
	c->sumarPuntos(puntosCastigo);
}

int Enemigo::getPuntosCastigo() { return puntosCastigo; }
void Enemigo::setPuntosCastigo(int p) { this->puntosCastigo = p; }
