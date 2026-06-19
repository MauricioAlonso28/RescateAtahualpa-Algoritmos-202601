#pragma once
#include "Personaje.h"
#include "Enums.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	ref class ObjetoCultural;
	ref class Aliado;

	// Cusi: el personaje que controla el jugador.
	public ref class Cusi : public Personaje
	{
	private:
		int vidas;
		int puntaje;
		Direccion direccion;
		List<Bitmap^>^ spritesDireccion;
		List<ObjetoCultural^>^ inventario;

	public:
		Cusi(int x, int y, List<Bitmap^>^ sprites);

		virtual void mover() override;
		virtual void dibujar(Graphics^ g) override;
		void recogerObjeto(ObjetoCultural^ obj);
		void interactuarCon(Aliado^ a);
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
		List<ObjetoCultural^>^ getInventario();
	};
}
