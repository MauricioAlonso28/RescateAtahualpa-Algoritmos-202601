#include "SoldadoPatrulla.h"

SoldadoPatrulla::SoldadoPatrulla(int x, int y, string rutaSprite, int velocidad, EjePatrulla eje)
	: Enemigo(x, y, rutaSprite, velocidad) {
	// anadir logica
}

void SoldadoPatrulla::mover() {
	// anadir logica
}

EjePatrulla SoldadoPatrulla::getEjePatrulla() { return ejePatrulla; }
void SoldadoPatrulla::setEjePatrulla(EjePatrulla e) { this->ejePatrulla = e; }
int SoldadoPatrulla::getSentido() { return sentido; }
void SoldadoPatrulla::setSentido(int s) { this->sentido = s; }
