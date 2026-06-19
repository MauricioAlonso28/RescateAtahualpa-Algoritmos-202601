#include "Personaje.h"

namespace TrabajoFinalAlgoritmos {

	Personaje::Personaje(int x, int y, Bitmap^ sprite, int velocidad)
		: Entidad(x, y, sprite)
	{
		// anadir logica
	}

	void Personaje::mover()
	{
		// anadir logica
	}

	String^ Personaje::getNombre() { return nombre; }
	void Personaje::setNombre(String^ n) { this->nombre = n; }
	int Personaje::getVelocidad() { return velocidad; }
	void Personaje::setVelocidad(int v) { this->velocidad = v; }
}
