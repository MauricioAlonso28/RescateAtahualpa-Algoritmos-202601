#include "GuardianEspecial.h"

namespace TrabajoFinalAlgoritmos {

	GuardianEspecial::GuardianEspecial(int x, int y, Bitmap^ sprite, int velocidad, EjePatrulla eje)
		: SoldadoPatrulla(x, y, sprite, velocidad, eje)
	{
		// anadir logica
	}

	void GuardianEspecial::mover()
	{
		// anadir logica
	}

	bool GuardianEspecial::detecta(Cusi^ c)
	{
		// anadir logica
		return false;
	}

	int GuardianEspecial::getRadioVigilancia() { return radioVigilancia; }
	void GuardianEspecial::setRadioVigilancia(int r) { this->radioVigilancia = r; }
	int GuardianEspecial::getVelocidadPersecucion() { return velocidadPersecucion; }
	void GuardianEspecial::setVelocidadPersecucion(int v) { this->velocidadPersecucion = v; }
}
