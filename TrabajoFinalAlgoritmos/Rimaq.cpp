#include "Rimaq.h"

Rimaq::Rimaq(int x, int y,
	string rutaSprite,
	string frase)
	: Aliado(x, y, rutaSprite, frase)
{
	puertaAbierta = false;
}

bool Rimaq::puedeActivarse(Cusi* c) {
	return true;
}

void Rimaq::interactuar(Cusi* c) {

	if (!puertaAbierta &&
		c->cantidadFragmentosQuipu() >= 1) {

		puertaAbierta = true;
	}
}

bool Rimaq::getPuertaAbierta() {
	return puertaAbierta;
}

void Rimaq::dibujar(Graphics^ g) {

	if (!getVisible())
		return;

	Bitmap^ bmp = CacheImagenes::obtener(aStr(getRutaSprite()));

	int columnas = 3; // Rimaq tiene 3 sprites
	int fw = bmp->Width / columnas;
	int fh = bmp->Height;

	g->DrawImage(
		bmp,
		Rectangle(getX(), getY(), getAncho(), getAlto()),
		0,
		0,
		fw,
		fh,
		GraphicsUnit::Pixel);
}