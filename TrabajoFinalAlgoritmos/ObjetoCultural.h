#pragma once
#include "Entidad.h"
#include <string>
using namespace System::Drawing;
using namespace std;

class ObjetoCultural : public Entidad {
private:
	string nombre;
	string descripcionHistorica;
	int puntos;
	bool recogido;
	bool esBonus;

public:
	ObjetoCultural(int x, int y, string rutaSprite, string nombre, int puntos);

	int recoger();

	string getNombre();
	void setNombre(string n);
	string getDescripcionHistorica();
	void setDescripcionHistorica(string d);
	int getPuntos();
	void setPuntos(int p);
	bool getRecogido();
	void setRecogido(bool r);
	bool getEsBonus();
	void setEsBonus(bool b);
};
