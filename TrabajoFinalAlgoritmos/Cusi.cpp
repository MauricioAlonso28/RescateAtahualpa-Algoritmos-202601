#include "Cusi.h"
#include "Config.h"

Cusi::Cusi(int x, int y, vector<string> sprites)
	: Personaje(x, y, sprites.empty() ? string(IMG_CUSI) : sprites[0], VEL_CUSI) {
	this->vidas = VIDAS_INICIALES;
	this->puntaje = 0;
	this->direccion = Direccion::Sur;
	this->spritesDireccion = sprites;
	this->enMovimiento = false;
	this->frameActual = 0;
	this->contadorAnim = 0;

	Bitmap^ bmp = CacheImagenes::obtener(aStr(getRutaSprite()));
	this->frameAncho = bmp->Width / CUSI_COLS;
	this->frameAlto = bmp->Height / CUSI_FILAS;

	setAncho(CUSI_ANCHO);
	setAlto(CUSI_ALTO);
}

void Cusi::mover() {
	if (!enMovimiento)
		return;
	int v = getVelocidad();
	switch (direccion) {
	case Direccion::Norte: setY(getY() - v); break;
	case Direccion::Sur:   setY(getY() + v); break;
	case Direccion::Este:  setX(getX() + v); break;
	case Direccion::Oeste: setX(getX() - v); break;
	}
}

void Cusi::animar() {
	if (!enMovimiento) {
		frameActual = 0;
		contadorAnim = 0;
		return;
	}
	contadorAnim++;
	if (contadorAnim >= 5) {
		contadorAnim = 0;
		frameActual = (frameActual + 1) % CUSI_COLS;
	}
}

void Cusi::caminar(Direccion d) {
	direccion = d;
	enMovimiento = true;
}

void Cusi::detener() {
	enMovimiento = false;
}

void Cusi::dibujar(Graphics^ g) {
	Bitmap^ bmp = CacheImagenes::obtener(aStr(getRutaSprite()));

	int fila;
	switch (direccion) {
	case Direccion::Norte: fila = CUSI_FILA_NORTE; break;
	case Direccion::Este:  fila = CUSI_FILA_ESTE;  break;
	case Direccion::Oeste: fila = CUSI_FILA_OESTE; break;
	default:               fila = CUSI_FILA_SUR;   break;
	}

	int ox = frameActual * frameAncho;
	int oy = fila * frameAlto;

	g->DrawImage(bmp, System::Drawing::Rectangle(getX(), getY(), getAncho(), getAlto()),
		ox, oy, frameAncho, frameAlto, GraphicsUnit::Pixel);
}

void Cusi::recogerObjeto(ObjetoCultural* obj) {
	int p = obj->recoger();
	puntaje += p;
	inventario.push_back(obj);
}

void Cusi::interactuarCon(Aliado* a) {
	a->interactuar(this);
}

void Cusi::perderVida() {
	vidas--;
	if (vidas < 0)
		vidas = 0;
}

void Cusi::recuperarVida() {
	vidas++;
}

void Cusi::reaparecer(int x, int y) {
	setX(x);
	setY(y);
	enMovimiento = false;
	direccion = Direccion::Sur;
	frameActual = 0;
}

int Cusi::cantidadFragmentosQuipu() {

	int cantidad = 0;

	for (size_t i = 0; i < inventario.size(); i++) {

		string nombre = inventario[i]->getNombre();

		if (nombre == "Parte del Quipu 1" ||
			nombre == "Parte del Quipu 2" ||
			nombre == "Parte del Quipu 3")
			cantidad++;
	}

	return cantidad;
}

void Cusi::sumarPuntos(int p) {
	puntaje += p;
	if (puntaje < 0)
		puntaje = 0;
}

int Cusi::getVidas() { return vidas; }
void Cusi::setVidas(int v) { this->vidas = v; }
int Cusi::getPuntaje() { return puntaje; }
void Cusi::setPuntaje(int p) { this->puntaje = p; }
Direccion Cusi::getDireccion() { return direccion; }
void Cusi::setDireccion(Direccion d) { this->direccion = d; }
vector<ObjetoCultural*> Cusi::getInventario() { return inventario; }
