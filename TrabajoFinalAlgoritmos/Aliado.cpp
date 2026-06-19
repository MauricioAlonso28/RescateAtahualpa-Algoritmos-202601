#include "Aliado.h"

Aliado::Aliado(int x, int y, string rutaSprite, string frase)
	: Entidad(x, y, rutaSprite) {
	// anadir logica
}

bool Aliado::puedeActivarse(Cusi* c) {
	// anadir logica
	return false;
}

void Aliado::interactuar(Cusi* c) {
	// anadir logica
}

string Aliado::getFraseClave() { return fraseClave; }
void Aliado::setFraseClave(string f) { this->fraseClave = f; }
int Aliado::getPuntosInteraccion() { return puntosInteraccion; }
void Aliado::setPuntosInteraccion(int p) { this->puntosInteraccion = p; }
bool Aliado::getActivado() { return activado; }
void Aliado::setActivado(bool a) { this->activado = a; }
