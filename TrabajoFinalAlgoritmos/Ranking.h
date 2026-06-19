#pragma once
#include <string>
#include <vector>
using namespace std;

class Ranking {
private:
	vector<string> nombres;
	vector<int> puntajes;

public:
	void agregar(string nombre, int puntos);
	void mostrarTop();

	vector<string> getNombres();
	vector<int> getPuntajes();
};
