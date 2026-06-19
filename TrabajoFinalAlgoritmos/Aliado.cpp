#include "Aliado.h"

namespace TrabajoFinalAlgoritmos {

	Aliado::Aliado(int x, int y, Bitmap^ sprite, String^ frase)
		: Entidad(x, y, sprite)
	{
		// anadir logica
	}

	bool Aliado::puedeActivarse(Cusi^ c)
	{
		// anadir logica
		return false;
	}

	void Aliado::interactuar(Cusi^ c)
	{
		// anadir logica
	}

	String^ Aliado::getFraseClave() { return fraseClave; }
	void Aliado::setFraseClave(String^ f) { this->fraseClave = f; }
	int Aliado::getPuntosInteraccion() { return puntosInteraccion; }
	void Aliado::setPuntosInteraccion(int p) { this->puntosInteraccion = p; }
	bool Aliado::getActivado() { return activado; }
	void Aliado::setActivado(bool a) { this->activado = a; }
}
