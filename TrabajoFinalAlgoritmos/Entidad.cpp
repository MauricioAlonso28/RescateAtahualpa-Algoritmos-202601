#include "Entidad.h"

namespace TrabajoFinalAlgoritmos {

	Entidad::Entidad(int x, int y, Bitmap^ sprite)
	{
		// anadir logica
	}

	void Entidad::dibujar(Graphics^ g)
	{
		// anadir logica
	}

	bool Entidad::colisionaCon(Entidad^ otra)
	{
		// anadir logica
		return false;
	}

	Rectangle Entidad::getRectangulo()
	{
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
	Bitmap^ Entidad::getSprite() { return sprite; }
	void Entidad::setSprite(Bitmap^ s) { this->sprite = s; }
	bool Entidad::getVisible() { return visible; }
	void Entidad::setVisible(bool v) { this->visible = v; }
}
