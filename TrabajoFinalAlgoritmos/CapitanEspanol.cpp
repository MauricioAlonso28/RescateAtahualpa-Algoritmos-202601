#include "CapitanEspanol.h"

namespace TrabajoFinalAlgoritmos {

	CapitanEspanol::CapitanEspanol(int x, int y, Bitmap^ sprite, int velocidad)
		: Enemigo(x, y, sprite, velocidad)
	{
		// anadir logica
	}

	void CapitanEspanol::mover()
	{
		// anadir logica
	}

	double CapitanEspanol::calcularDistancia(Cusi^ c)
	{
		// anadir logica
		return 0.0;
	}

	void CapitanEspanol::quedarBloqueado()
	{
		// anadir logica
	}

	int CapitanEspanol::getRadioDeteccion() { return radioDeteccion; }
	void CapitanEspanol::setRadioDeteccion(int r) { this->radioDeteccion = r; }
	Cusi^ CapitanEspanol::getObjetivo() { return objetivo; }
	void CapitanEspanol::setObjetivo(Cusi^ c) { this->objetivo = c; }
	bool CapitanEspanol::getBloqueado() { return bloqueado; }
}
