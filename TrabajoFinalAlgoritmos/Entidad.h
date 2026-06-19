#pragma once

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	// Clase base de todo lo que aparece en pantalla (posicion, tamanio y sprite).
	public ref class Entidad
	{
	private:
		int x;
		int y;
		int ancho;
		int alto;
		Bitmap^ sprite;
		bool visible;

	public:
		Entidad(int x, int y, Bitmap^ sprite);

		virtual void dibujar(Graphics^ g);
		bool colisionaCon(Entidad^ otra);
		Rectangle getRectangulo();

		int getX();
		void setX(int x);
		int getY();
		void setY(int y);
		int getAncho();
		void setAncho(int a);
		int getAlto();
		void setAlto(int a);
		Bitmap^ getSprite();
		void setSprite(Bitmap^ s);
		bool getVisible();
		void setVisible(bool v);
	};
}
