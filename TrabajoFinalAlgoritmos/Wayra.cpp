#include "Wayra.h"

Wayra::Wayra(int x, int y,
	string rutaSprite,
	string frase)
	: Aliado(x, y, rutaSprite, frase)
{
	puertaAbierta = false;
}

bool Wayra::puedeActivarse(Cusi* c) {
	return true;
}

void Wayra::interactuar(Cusi* c) {

	if (!puertaAbierta &&
		c->cantidadFragmentosQuipu() >= 2) {

		puertaAbierta = true;
	}
}

bool Wayra::getPuertaAbierta() {
	return puertaAbierta;
}  

void Wayra::dibujar(Graphics^ g) {

	if (!getVisible())
		return;

	Bitmap^ bmp = CacheImagenes::obtener(aStr(getRutaSprite()));

	int columnas = 3; // Wayra tiene 3 sprites
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