#include "SoldadoPatrulla.h"
#include "Config.h"

SoldadoPatrulla::SoldadoPatrulla(int x, int y, string rutaSprite, int velocidad, EjePatrulla eje)
	: Enemigo(x, y, rutaSprite, velocidad) {
	this->ejePatrulla = eje;
	this->sentido = 1;
	this->frameActual = 0;
	this->contadorAnim = 0;
	this->limMin = 0;
	this->limMax = 1366;

	Bitmap^ bmp = CacheImagenes::obtener(aStr(getRutaSprite()));
	this->frameAncho = bmp->Width / SOLDADO_COLS;
	this->frameAlto = bmp->Height / SOLDADO_FILAS;

	setAncho(SOLDADO_ANCHO);
	setAlto(SOLDADO_ALTO);
}

void SoldadoPatrulla::setLimites(int minimo, int maximo) {
	limMin = minimo;
	limMax = maximo;
}

void SoldadoPatrulla::mover() {
	int v = getVelocidad();
	if (ejePatrulla == EjePatrulla::Horizontal) {
		setX(getX() + v * sentido);
		if (getX() <= limMin) { setX(limMin); sentido = 1; }
		else if (getX() + getAncho() >= limMax) { setX(limMax - getAncho()); sentido = -1; }
	}
	else {
		setY(getY() + v * sentido);
		if (getY() <= limMin) { setY(limMin); sentido = 1; }
		else if (getY() + getAlto() >= limMax) { setY(limMax - getAlto()); sentido = -1; }
	}
	animar();
}

void SoldadoPatrulla::animar() {
	contadorAnim++;
	if (contadorAnim >= 6) {
		contadorAnim = 0;
		frameActual = (frameActual + 1) % SOLDADO_COLS;
	}
}

void SoldadoPatrulla::dibujar(Graphics^ g) {
	if (!getVisible())
		return;

	Bitmap^ bmp = CacheImagenes::obtener(aStr(getRutaSprite()));

	int ox = frameActual * frameAncho;
	int fila;

	if (ejePatrulla == EjePatrulla::Horizontal) {
		if (sentido == 1)
			fila = 1; // derecha
		else
			fila = 2; // izquierda
	}
	else {
		if (sentido == 1)
			fila = 3; // abajo
		else
			fila = 0; // arriba
	}

	int oy = fila * frameAlto;

	g->DrawImage(
		bmp,
		Rectangle(
			getX(),
			getY(),
			getAncho(),
			getAlto()),
		ox,
		oy,
		frameAncho,
		frameAlto,
		GraphicsUnit::Pixel);
}

EjePatrulla SoldadoPatrulla::getEjePatrulla() { return ejePatrulla; }
void SoldadoPatrulla::setEjePatrulla(EjePatrulla e) { this->ejePatrulla = e; }
int SoldadoPatrulla::getSentido() { return sentido; }
void SoldadoPatrulla::setSentido(int s) { this->sentido = s; }
