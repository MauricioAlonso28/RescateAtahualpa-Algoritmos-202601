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

	xInicial = 45;
	yInicial = 188;

	rutaPuerta = IMG_PUERTA_N1;
	puertaX = 612;
	puertaY = 120;
	puertaAncho = 60;
	puertaAlto = 60;

	corredores.push_back(Corredor{ 20, 180, 140, 60 });
	corredores.push_back(Corredor{ 130, 188, 150, 58 });
	corredores.push_back(Corredor{ 245, 182, 140, 73 });
	corredores.push_back(Corredor{ 350, 200, 130, 60 });
	corredores.push_back(Corredor{ 445, 150, 95, 115 });
	corredores.push_back(Corredor{ 520, 110, 150, 100 });
	corredores.push_back(Corredor{ 410, 250, 120, 100 });
	corredores.push_back(Corredor{ 248, 235, 84, 165 });
	corredores.push_back(Corredor{ 262, 378, 110, 95 });

	ObjetoCultural* mascara = new ObjetoCultural(285, 147, IMG_MASCARA, "Mascara de oro", PTS_OBJETO);
	mascara->setAncho(52);
	mascara->setAlto(56);
	mascara->setDescripcionHistorica("Mascara funeraria de oro batido, simbolo del Sol y del linaje sagrado del Inca.");
	objetos.push_back(mascara);

	ObjetoCultural* vasija = new ObjetoCultural(466, 265, IMG_VASIJA, "Vasija ritual", PTS_OBJETO);
	vasija->setAncho(62);
	vasija->setAlto(76);
	vasija->setDescripcionHistorica("Quero ceremonial usado en ofrendas de chicha durante las festividades del Inti Raymi.");
	objetos.push_back(vasija);

	ObjetoCultural* textil = new ObjetoCultural(300, 405, IMG_TEXTIL, "Textil ceremonial", PTS_OBJETO);
	textil->setAncho(62);
	textil->setAlto(68);
	textil->setDescripcionHistorica("Tejido con tecnicas de tokapus que registran linajes y eventos del Imperio.");
	objetos.push_back(textil);

	Curaca* curaca = new Curaca(118, 122, IMG_CURACA,
		"Cusi, el camino esta vigilado. Evita a los soldados y recupera las ofrendas antes de que las fundan.");
	curaca->setAncho(40);
	curaca->setAlto(66);
	aliados.push_back(curaca);

	SoldadoPatrulla* s1 = new SoldadoPatrulla(250, 188, IMG_SOLDADO_N1, 2, EjePatrulla::Horizontal);
	s1->setLimites(235, 400);
	enemigos.push_back(s1);

	SoldadoPatrulla* s2 = new SoldadoPatrulla(430, 196, IMG_SOLDADO_N1, 3, EjePatrulla::Horizontal);
	s2->setLimites(405, 560);
	enemigos.push_back(s2);
}

bool Nivel::esTransitable(int px, int py) {
	for (size_t i = 0; i < corredores.size(); i++) {
		Corredor& c = corredores[i];
		if (px >= c.x && px < c.x + c.w && py >= c.y && py < c.y + c.h)
			return true;
	}
	return false;
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
