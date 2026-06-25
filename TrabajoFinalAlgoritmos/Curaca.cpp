#include "Curaca.h"
#include "Config.h"

Curaca::Curaca(int x, int y, string rutaSprite, string frase)
	: Aliado(x, y, rutaSprite, frase) {
	// anadir logica
}

bool Curaca::puedeActivarse(Cusi* c) {
	return !getActivado();
}

void Curaca::interactuar(Cusi* c) {
	Aliado::interactuar(c);
}

void Curaca::dibujar(Graphics^ g) {
	if (!getVisible())
		return;
	Bitmap^ bmp = CacheImagenes::obtener(aStr(getRutaSprite()));
	int fw = bmp->Width / CURACA_COLS;
	int fh = bmp->Height;
	g->DrawImage(bmp, System::Drawing::Rectangle(getX(), getY(), getAncho(), getAlto()),
		0, 0, fw, fh, GraphicsUnit::Pixel);
}
