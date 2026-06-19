#include "SoldadoPatrulla.h"

namespace TrabajoFinalAlgoritmos {

	SoldadoPatrulla::SoldadoPatrulla(int x, int y, Bitmap^ sprite, int velocidad, EjePatrulla eje)
		: Enemigo(x, y, sprite, velocidad)
	{
		// anadir logica
	}

	void SoldadoPatrulla::mover()
	{
		// anadir logica
	}

	EjePatrulla SoldadoPatrulla::getEjePatrulla() { return ejePatrulla; }
	void SoldadoPatrulla::setEjePatrulla(EjePatrulla e) { this->ejePatrulla = e; }
	int SoldadoPatrulla::getSentido() { return sentido; }
	void SoldadoPatrulla::setSentido(int s) { this->sentido = s; }
}
