#include "Juego.h"
#include "Config.h"

Juego::Juego() {
	vector<string> sprites;
	sprites.push_back(IMG_CUSI);
	jugador = new Cusi(0, 0, sprites);

	nivelActual = 1;
	estado = EstadoJuego::Jugando;
	ranking = new Ranking();
	nombreJugador = "";
}

Juego::~Juego() {
	if (jugador != nullptr) { delete jugador; jugador = nullptr; }
	if (ranking != nullptr) { delete ranking; ranking = nullptr; }
	for (size_t i = 0; i < niveles.size(); i++)
		delete niveles[i];
	niveles.clear();
}

void Juego::iniciar() {
	estado = EstadoJuego::Jugando;
	nivelActual = 1;
}

void Juego::detectarColisiones() {
	// anadir logica
}

void Juego::avanzarNivel() {
	nivelActual++;
}

bool Juego::verificarVictoria() {
	return estado == EstadoJuego::Victoria;
}

bool Juego::verificarDerrota() {
	return jugador != nullptr && jugador->getVidas() <= 0;
}

void Juego::calcularBonificaciones() {
	// anadir logica
}

Cusi* Juego::getJugador() { return jugador; }
vector<Nivel*> Juego::getNiveles() { return niveles; }
int Juego::getNivelActual() { return nivelActual; }
void Juego::setNivelActual(int n) { this->nivelActual = n; }
EstadoJuego Juego::getEstado() { return estado; }
void Juego::setEstado(EstadoJuego e) { this->estado = e; }
Ranking* Juego::getRanking() { return ranking; }
string Juego::getNombreJugador() { return nombreJugador; }
void Juego::setNombreJugador(string n) { this->nombreJugador = n; }
