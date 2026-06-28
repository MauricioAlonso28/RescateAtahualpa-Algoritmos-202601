#include "Nivel.h"
#include "SoldadoPatrulla.h"
#include "Curaca.h"
#include "Config.h"

Nivel::Nivel() {
	numero = 1;
	rutaFondo = IMG_FONDO_N1;
	tiempoLimite = 0;
	salidaActiva = false;
	xInicial = 0;
	yInicial = 0;
	rutaPuerta = IMG_PUERTA_N1;
	puertaX = 0;
	puertaY = 0;
	puertaAncho = 0;
	puertaAlto = 0;
}

Nivel::~Nivel() {
	for (size_t i = 0; i < enemigos.size(); i++) delete enemigos[i];
	for (size_t i = 0; i < aliados.size(); i++)  delete aliados[i];
	for (size_t i = 0; i < objetos.size(); i++)  delete objetos[i];
	enemigos.clear();
	aliados.clear();
	objetos.clear();
}

void Nivel::cargar() {
	rutaFondo = IMG_FONDO_N1;
	tiempoLimite = 0;
	salidaActiva = false;

	xInicial = 110;
	yInicial = 142;

	rutaPuerta = IMG_PUERTA_N1;
	puertaX = 1138;
	puertaY = 617;
	puertaAncho = 84;
	puertaAlto = 100;

	// Acceso manual al circulo central (cerrado por muro): permite que Cusi
	// entre desde el camino inferior hasta el centro a recoger la vasija.
	zonasLibres.push_back(ZonaLibre{ 695, 425, 115, 225 });

	ObjetoCultural* mascara = new ObjetoCultural(215, 577, IMG_MASCARA, "Mascara de oro", PTS_OBJETO);
	mascara->setAncho(50);
	mascara->setAlto(54);
	mascara->setDescripcionHistorica("Mascara funeraria de oro batido, simbolo del Sol y del linaje sagrado del Inca.");
	objetos.push_back(mascara);

	ObjetoCultural* vasija = new ObjetoCultural(703, 437, IMG_VASIJA, "Vasija ritual", PTS_OBJETO);
	vasija->setAncho(54);
	vasija->setAlto(66);
	vasija->setDescripcionHistorica("Quero ceremonial usado en ofrendas de chicha durante las festividades del Inti Raymi.");
	objetos.push_back(vasija);

	ObjetoCultural* textil = new ObjetoCultural(694, 86, IMG_TEXTIL, "Textil ceremonial", PTS_OBJETO);
	textil->setAncho(52);
	textil->setAlto(58);
	textil->setDescripcionHistorica("Tejido con tecnicas de tokapus que registran linajes y eventos del Imperio.");
	objetos.push_back(textil);

	Curaca* curaca = new Curaca(193, 150, IMG_CURACA,
		"Cusi, el camino esta vigilado. Evita a los soldados y recupera las ofrendas antes de que las fundan.");
	curaca->setAncho(40);
	curaca->setAlto(66);
	aliados.push_back(curaca);

	SoldadoPatrulla* s1 = new SoldadoPatrulla(400, 236, IMG_SOLDADO_N1, 2, EjePatrulla::Horizontal);
	s1->setLimites(280, 560);
	enemigos.push_back(s1);

	SoldadoPatrulla* s2 = new SoldadoPatrulla(760, 608, IMG_SOLDADO_N1, 3, EjePatrulla::Horizontal);
	s2->setLimites(640, 940);
	enemigos.push_back(s2);
}

bool Nivel::esTransitable(int px, int py) {
	for (size_t i = 0; i < zonasLibres.size(); i++) {
		ZonaLibre& z = zonasLibres[i];
		if (px >= z.x && px < z.x + z.w && py >= z.y && py < z.y + z.h)
			return true;
	}

	Bitmap^ bg = CacheImagenes::obtener(aStr(rutaFondo));
	int w = bg->Width;
	int h = bg->Height;
	int ok = 0;
	for (int dy = -6; dy <= 6; dy += 6) {
		for (int dx = -6; dx <= 6; dx += 6) {
			int x = px + dx;
			int y = py + dy;
			if (x < 0 || y < 0 || x >= w || y >= h)
				continue;
			Color c = bg->GetPixel(x, y);
			int r = c.R, g = c.G, b = c.B;
			if (r > g && g + 6 >= b && r >= 105 && (r - b) >= 25 && (r - b) <= 140)
				ok++;
		}
	}
	return ok >= 2;
}

void Nivel::actualizar() {
	for (size_t i = 0; i < enemigos.size(); i++)
		enemigos[i]->mover();
}

void Nivel::dibujarTodo(Graphics^ g) {
	for (size_t i = 0; i < objetos.size(); i++)
		if (!objetos[i]->getRecogido())
			objetos[i]->dibujar(g);

	for (size_t i = 0; i < aliados.size(); i++)
		if (aliados[i]->getVisible())
			aliados[i]->dibujar(g);

	for (size_t i = 0; i < enemigos.size(); i++)
		enemigos[i]->dibujar(g);
}

bool Nivel::verificarObjetosCompletos() {
	for (size_t i = 0; i < objetos.size(); i++)
		if (!objetos[i]->getRecogido())
			return false;
	return true;
}

void Nivel::activarSalida() {
	salidaActiva = true;
}

void Nivel::reiniciar() {
	// anadir logica
}

int Nivel::getNumero() { return numero; }
void Nivel::setNumero(int n) { this->numero = n; }
string Nivel::getRutaFondo() { return rutaFondo; }
void Nivel::setRutaFondo(string f) { this->rutaFondo = f; }
vector<Enemigo*> Nivel::getEnemigos() { return enemigos; }
vector<Aliado*> Nivel::getAliados() { return aliados; }
vector<ObjetoCultural*> Nivel::getObjetos() { return objetos; }
int Nivel::getTiempoLimite() { return tiempoLimite; }
void Nivel::setTiempoLimite(int t) { this->tiempoLimite = t; }
bool Nivel::getSalidaActiva() { return salidaActiva; }
void Nivel::setSalidaActiva(bool s) { this->salidaActiva = s; }
int Nivel::getXInicial() { return xInicial; }
void Nivel::setXInicial(int x) { this->xInicial = x; }
int Nivel::getYInicial() { return yInicial; }
void Nivel::setYInicial(int y) { this->yInicial = y; }

string Nivel::getRutaPuerta() { return rutaPuerta; }
int Nivel::getPuertaX() { return puertaX; }
int Nivel::getPuertaY() { return puertaY; }
int Nivel::getPuertaAncho() { return puertaAncho; }
int Nivel::getPuertaAlto() { return puertaAlto; }
