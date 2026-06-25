#include "ObjetoCultural.h"

ObjetoCultural::ObjetoCultural(int x, int y, string rutaSprite, string nombre, int puntos)
	: Entidad(x, y, rutaSprite) {
	this->nombre = nombre;
	this->descripcionHistorica = "";
	this->puntos = puntos;
	this->recogido = false;
	this->esBonus = false;
}

int ObjetoCultural::recoger() {
	recogido = true;
	setVisible(false);
	return puntos;
}

string ObjetoCultural::getNombre() { return nombre; }
void ObjetoCultural::setNombre(string n) { this->nombre = n; }
string ObjetoCultural::getDescripcionHistorica() { return descripcionHistorica; }
void ObjetoCultural::setDescripcionHistorica(string d) { this->descripcionHistorica = d; }
int ObjetoCultural::getPuntos() { return puntos; }
void ObjetoCultural::setPuntos(int p) { this->puntos = p; }
bool ObjetoCultural::getRecogido() { return recogido; }
void ObjetoCultural::setRecogido(bool r) { this->recogido = r; }
bool ObjetoCultural::getEsBonus() { return esBonus; }
void ObjetoCultural::setEsBonus(bool b) { this->esBonus = b; }
