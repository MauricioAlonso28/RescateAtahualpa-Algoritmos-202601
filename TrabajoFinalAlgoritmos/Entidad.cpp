#include "Entidad.h"
#include "Config.h"

Entidad::Entidad(int x, int y, string rutaSprite) {
	this->x = x;
	this->y = y;
	this->ancho = 0;
	this->alto = 0;
	this->rutaSprite = rutaSprite;
	this->visible = true;
}

Entidad::~Entidad() {}

void Entidad::dibujar(Graphics^ g) {
	if (!visible || rutaSprite.empty())
		return;
	Bitmap^ bmp = CacheImagenes::obtener(aStr(rutaSprite));
	g->DrawImage(bmp, System::Drawing::Rectangle(x, y, ancho, alto));
}

bool Entidad::colisionaCon(Entidad* otra) {
	if (!visible || !otra->getVisible())
		return false;
	return getRectangulo().IntersectsWith(otra->getRectangulo());
}

Rectangle Entidad::getRectangulo() {
	return Rectangle(x, y, ancho, alto);
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
