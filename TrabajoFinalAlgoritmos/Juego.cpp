#include "Juego.h"

void Juego::iniciar() {
	// anadir logica
}

void Juego::detectarColisiones() {
	// anadir logica
}

void Juego::avanzarNivel() {
	// anadir logica
}

bool Juego::verificarVictoria() {
	// anadir logica
	return false;
}

bool Juego::verificarDerrota() {
	// anadir logica
	return false;
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
