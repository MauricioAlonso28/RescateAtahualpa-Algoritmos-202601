#include "Personaje.h"

Personaje::Personaje(int x, int y, string rutaSprite, int velocidad)
	: Entidad(x, y, rutaSprite) {
	// anadir logica
}

void Personaje::mover() {
	// anadir logica
}

string Personaje::getNombre() { return nombre; }
void Personaje::setNombre(string n) { this->nombre = n; }
int Personaje::getVelocidad() { return velocidad; }
void Personaje::setVelocidad(int v) { this->velocidad = v; }
