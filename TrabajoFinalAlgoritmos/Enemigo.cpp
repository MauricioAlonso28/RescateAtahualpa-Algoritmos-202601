#include "Enemigo.h"

namespace TrabajoFinalAlgoritmos {

	Enemigo::Enemigo(int x, int y, Bitmap^ sprite, int velocidad)
		: Personaje(x, y, sprite, velocidad)
	{
		// anadir logica
	}

	void Enemigo::alColisionar(Cusi^ c)
	{
		// anadir logica
	}

	int Enemigo::getPuntosCastigo() { return puntosCastigo; }
	void Enemigo::setPuntosCastigo(int p) { this->puntosCastigo = p; }
}
