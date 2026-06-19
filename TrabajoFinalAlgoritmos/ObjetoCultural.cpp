#include "ObjetoCultural.h"

namespace TrabajoFinalAlgoritmos {

	ObjetoCultural::ObjetoCultural(int x, int y, Bitmap^ sprite, String^ nombre, int puntos)
		: Entidad(x, y, sprite)
	{
		// anadir logica
	}

	int ObjetoCultural::recoger()
	{
		// anadir logica
		return 0;
	}

	String^ ObjetoCultural::getNombre() { return nombre; }
	void ObjetoCultural::setNombre(String^ n) { this->nombre = n; }
	String^ ObjetoCultural::getDescripcionHistorica() { return descripcionHistorica; }
	void ObjetoCultural::setDescripcionHistorica(String^ d) { this->descripcionHistorica = d; }
	int ObjetoCultural::getPuntos() { return puntos; }
	void ObjetoCultural::setPuntos(int p) { this->puntos = p; }
	bool ObjetoCultural::getRecogido() { return recogido; }
	void ObjetoCultural::setRecogido(bool r) { this->recogido = r; }
	bool ObjetoCultural::getEsBonus() { return esBonus; }
	void ObjetoCultural::setEsBonus(bool b) { this->esBonus = b; }
}
