#include "Cusi.h"

Cusi::Cusi(int x, int y, vector<string> sprites)
	: Personaje(x, y, "", 0) {
	// anadir logica
}

void Cusi::mover() {
	// anadir logica
}

void Cusi::dibujar(Graphics^ g) {
	// anadir logica
}

void Cusi::recogerObjeto(ObjetoCultural* obj) {
	// anadir logica
}

void Cusi::interactuarCon(Aliado* a) {
	// anadir logica
}

void Cusi::perderVida() {
	// anadir logica
}

void Cusi::recuperarVida() {
	// anadir logica
}

void Cusi::reaparecer(int x, int y) {
	// anadir logica
}

int Cusi::cantidadFragmentosQuipu() {
	// anadir logica
	return 0;
}

void Cusi::sumarPuntos(int p) {
	// anadir logica
}

int Cusi::getVidas() { return vidas; }
void Cusi::setVidas(int v) { this->vidas = v; }
int Cusi::getPuntaje() { return puntaje; }
void Cusi::setPuntaje(int p) { this->puntaje = p; }
Direccion Cusi::getDireccion() { return direccion; }
void Cusi::setDireccion(Direccion d) { this->direccion = d; }
vector<ObjetoCultural*> Cusi::getInventario() { return inventario; }
