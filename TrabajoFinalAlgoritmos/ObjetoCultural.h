#pragma once
#include "Entidad.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;

	// Objeto cultural recolectable (fragmentos del quipu, etc.).
	public ref class ObjetoCultural : public Entidad
	{
	private:
		String^ nombre;
		String^ descripcionHistorica;
		int puntos;
		bool recogido;
		bool esBonus;

	public:
		ObjetoCultural(int x, int y, Bitmap^ sprite, String^ nombre, int puntos);

		int recoger();

		String^ getNombre();
		void setNombre(String^ n);
		String^ getDescripcionHistorica();
		void setDescripcionHistorica(String^ d);
		int getPuntos();
		void setPuntos(int p);
		bool getRecogido();
		void setRecogido(bool r);
		bool getEsBonus();
		void setEsBonus(bool b);
	};
}
