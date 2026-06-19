#include "Entidad.h"

Entidad::Entidad(int x, int y, string rutaSprite) {
	// anadir logica
}

Entidad::~Entidad() {}

void Entidad::dibujar(Graphics^ g) {
	// anadir logica
}

bool Entidad::colisionaCon(Entidad* otra) {
	// anadir logica
	return false;
}

Rectangle Entidad::getRectangulo() {
	// anadir logica
	return Rectangle();
}

int Entidad::getX() { return x; }
void Entidad::setX(int x) { this->x = x; }
int Entidad::getY() { return y; }
void Entidad::setY(int y) { this->y = y; }
int Entidad::getAncho() { return ancho; }
void Entidad::setAncho(int a) { this->ancho = a; }
int Entidad::getAlto() { return alto; }
void Entidad::setAlto(int a) { this->alto = a; }
string Entidad::getRutaSprite() { return rutaSprite; }
void Entidad::setRutaSprite(string s) { this->rutaSprite = s; }
bool Entidad::getVisible() { return visible; }
void Entidad::setVisible(bool v) { this->visible = v; }
