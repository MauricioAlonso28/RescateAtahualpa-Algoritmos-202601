#pragma once
#include "Enemigo.h"
#include "Aliado.h"
#include "ObjetoCultural.h"
#include <string>
#include <vector>
using namespace System::Drawing;
using namespace std;

class Nivel {
private:
	int numero;
	string rutaFondo;
	vector<Enemigo*> enemigos;
	vector<Aliado*> aliados;
	vector<ObjetoCultural*> objetos;
	int tiempoLimite;
	bool salidaActiva;
	int xInicial;
	int yInicial;

public:
	void cargar();
	void actualizar();
	void dibujarTodo(Graphics^ g);
	bool verificarObjetosCompletos();
	void activarSalida();
	void reiniciar();

	int getNumero();
	void setNumero(int n);
	string getRutaFondo();
	void setRutaFondo(string f);
	vector<Enemigo*> getEnemigos();
	vector<Aliado*> getAliados();
	vector<ObjetoCultural*> getObjetos();
	int getTiempoLimite();
	void setTiempoLimite(int t);
	bool getSalidaActiva();
	void setSalidaActiva(bool s);
	int getXInicial();
	void setXInicial(int x);
	int getYInicial();
	void setYInicial(int y);
};
