#pragma once
#include <string>
using namespace System::Drawing;
using namespace std;

class Entidad {
private:
	int x;
	int y;
	int ancho;
	int alto;
	string rutaSprite;
	bool visible;

public:
	Entidad(int x, int y, string rutaSprite);
	virtual ~Entidad();

	virtual void dibujar(Graphics^ g);
	bool colisionaCon(Entidad* otra);
	Rectangle getRectangulo();

	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getAncho();
	void setAncho(int a);
	int getAlto();
	void setAlto(int a);
	string getRutaSprite();
	void setRutaSprite(string s);
	bool getVisible();
	void setVisible(bool v);
};
