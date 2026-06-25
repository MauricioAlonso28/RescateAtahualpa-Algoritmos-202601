#pragma once
#include "Enums.h"
#include "Cusi.h"
#include "Nivel.h"
#include "Ranking.h"
#include <string>
#include <vector>
using namespace std;

class Juego {
private:
	Cusi* jugador;
	vector<Nivel*> niveles;
	int nivelActual;
	EstadoJuego estado;
	Ranking* ranking;
	string nombreJugador;

public:
	Juego();
	~Juego();

	void iniciar();
	void detectarColisiones();
	void avanzarNivel();
	bool verificarVictoria();
	bool verificarDerrota();
	void calcularBonificaciones();

	Cusi* getJugador();
	vector<Nivel*> getNiveles();
	int getNivelActual();
	void setNivelActual(int n);
	EstadoJuego getEstado();
	void setEstado(EstadoJuego e);
	Ranking* getRanking();
	string getNombreJugador();
	void setNombreJugador(string n);
};
