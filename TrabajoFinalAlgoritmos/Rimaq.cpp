#include "Rimaq.h"

namespace TrabajoFinalAlgoritmos {

	Rimaq::Rimaq(int x, int y, Bitmap^ sprite, String^ frase)
		: Aliado(x, y, sprite, frase)
	{
		// anadir logica
	}

	bool Rimaq::puedeActivarse(Cusi^ c)
	{
		// anadir logica
		return false;
	}

	void Rimaq::interactuar(Cusi^ c)
	{
		// anadir logica
	}

	void Rimaq::abrirPaso()
	{
		// anadir logica
	}

	Entidad^ Rimaq::getPuerta() { return puerta; }
	void Rimaq::setPuerta(Entidad^ p) { this->puerta = p; }
}
