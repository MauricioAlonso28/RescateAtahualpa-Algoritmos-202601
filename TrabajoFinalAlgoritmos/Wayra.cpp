#include "Wayra.h"

namespace TrabajoFinalAlgoritmos {

	Wayra::Wayra(int x, int y, Bitmap^ sprite, String^ frase)
		: Aliado(x, y, sprite, frase)
	{
		// anadir logica
	}

	void Wayra::recibirSenal()
	{
		// anadir logica
	}

	bool Wayra::puedeActivarse(Cusi^ c)
	{
		// anadir logica
		return false;
	}

	void Wayra::interactuar(Cusi^ c)
	{
		// anadir logica
	}

	bool Wayra::getSenalDeRimaq() { return senalDeRimaq; }
	void Wayra::setSenalDeRimaq(bool s) { this->senalDeRimaq = s; }
}
