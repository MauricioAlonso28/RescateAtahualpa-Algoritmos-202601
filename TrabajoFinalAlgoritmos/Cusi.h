#pragma once
#include "Personaje.h"
#include "Enums.h"
#include "ObjetoCultural.h"
#include "Aliado.h"
#include <string>
#include <vector>
using namespace System::Drawing;
using namespace std;

class Cusi : public Personaje {
private:
	int vidas;
	int puntaje;
	Direccion direccion;
	vector<string> spritesDireccion;
	vector<ObjetoCultural*> inventario;

public:
	Cusi(int x, int y, vector<string> sprites);

	void mover();
	void dibujar(Graphics^ g);
	void recogerObjeto(ObjetoCultural* obj);
	void interactuarCon(Aliado* a);
	void perderVida();
	void recuperarVida();
	void reaparecer(int x, int y);
	int cantidadFragmentosQuipu();
	void sumarPuntos(int p);

	int getVidas();
	void setVidas(int v);
	int getPuntaje();
	void setPuntaje(int p);
	Direccion getDireccion();
	void setDireccion(Direccion d);
	vector<ObjetoCultural*> getInventario();
};
