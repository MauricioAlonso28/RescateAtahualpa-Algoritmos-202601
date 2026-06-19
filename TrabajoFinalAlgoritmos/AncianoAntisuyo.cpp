#include "AncianoAntisuyo.h"

namespace TrabajoFinalAlgoritmos {

	AncianoAntisuyo::AncianoAntisuyo(int x, int y, Bitmap^ sprite, String^ frase)
		: Aliado(x, y, sprite, frase)
	{
		// anadir logica
	}

	void AncianoAntisuyo::revelarse()
	{
		// anadir logica
	}

	bool AncianoAntisuyo::puedeActivarse(Cusi^ c)
	{
		// anadir logica
		return false;
	}

	void AncianoAntisuyo::interactuar(Cusi^ c)
	{
		// anadir logica
	}

	bool AncianoAntisuyo::getNivelesPreviosCompletos() { return nivelesPreviosCompletos; }
	void AncianoAntisuyo::setNivelesPreviosCompletos(bool n) { this->nivelesPreviosCompletos = n; }
}
