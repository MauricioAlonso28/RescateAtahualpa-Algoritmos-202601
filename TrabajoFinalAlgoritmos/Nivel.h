#pragma once
#include "Enemigo.h"
#include "Aliado.h"
#include "ObjetoCultural.h"
#include <string>
#include <vector>
using namespace System::Drawing;
using namespace std;

struct ZonaLibre {
	int x, y, w, h;
};

class Nivel {
private:
	int numero;
	string rutaFondo;
	vector<Enemigo*> enemigos;
	vector<Aliado*> aliados;
	vector<ObjetoCultural*> objetos;
	vector<ZonaLibre> zonasLibres;
	int tiempoLimite;
	bool salidaActiva;
	int xInicial;
	int yInicial;

	string rutaPuerta;
	int puertaX;
	int puertaY;
	int puertaAncho;
	int puertaAlto;

	bool puertaRimaqAbierta;
	bool puertaWayraAbierta;

	int puertaRimaqX;
	int puertaRimaqY;

	int puertaWayraX;
	int puertaWayraY;

public:
	Nivel();
	~Nivel();

	void cargar();
	void cargarNivel1();
	void cargarNivel2();
	void cargarNivel3();
	void actualizar();
	void dibujarTodo(Graphics^ g);
	bool verificarObjetosCompletos();
	void activarSalida();
	void reiniciar();
	bool esTransitable(int px, int py);

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

	string getRutaPuerta();
	int getPuertaX();
	int getPuertaY();
	int getPuertaAncho();
	int getPuertaAlto();

	bool getPuertaRimaqAbierta();
	bool getPuertaWayraAbierta();

	void abrirPuertaRimaq();
	void abrirPuertaWayra();

	int getPuertaRimaqX();
	int getPuertaRimaqY();

	int getPuertaWayraX();
	int getPuertaWayraY();

	void setPuertaRimaq(int x, int y);
	void setPuertaWayra(int x, int y);
};
