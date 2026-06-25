#include "Aliado.h"
#include "Cusi.h"
#include "Config.h"

Aliado::Aliado(int x, int y, string rutaSprite, string frase)
	: Entidad(x, y, rutaSprite) {
	this->fraseClave = frase;
	this->puntosInteraccion = PTS_ALIADO;
	this->activado = false;
}

bool Aliado::puedeActivarse(Cusi* c) {
	return !activado;
}

void Aliado::interactuar(Cusi* c) {
	if (activado)
		return;
	activado = true;
	c->sumarPuntos(puntosInteraccion);
	setVisible(false);
}

string Aliado::getFraseClave() { return fraseClave; }
void Aliado::setFraseClave(string f) { this->fraseClave = f; }
int Aliado::getPuntosInteraccion() { return puntosInteraccion; }
void Aliado::setPuntosInteraccion(int p) { this->puntosInteraccion = p; }
bool Aliado::getActivado() { return activado; }
void Aliado::setActivado(bool a) { this->activado = a; }
