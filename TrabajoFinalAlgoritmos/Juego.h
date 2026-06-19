#pragma once
#include "Enums.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Collections::Generic;

	ref class Cusi;
	ref class Nivel;
	ref class Ranking;

	// Coordinador general de la partida: jugador, niveles, estado y ranking.
	public ref class Juego
	{
	private:
		Cusi^ jugador;
		List<Nivel^>^ niveles;
		int nivelActual;
		EstadoJuego estado;
		Ranking^ ranking;
		String^ nombreJugador;

	public:
		void iniciar();
		void detectarColisiones();
		void avanzarNivel();
		bool verificarVictoria();
		bool verificarDerrota();
		void calcularBonificaciones();

		Cusi^ getJugador();
		List<Nivel^>^ getNiveles();
		int getNivelActual();
		void setNivelActual(int n);
		EstadoJuego getEstado();
		void setEstado(EstadoJuego e);
		Ranking^ getRanking();
		String^ getNombreJugador();
		void setNombreJugador(String^ n);
	};
}
