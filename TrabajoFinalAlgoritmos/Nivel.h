#pragma once

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	ref class Enemigo;
	ref class Aliado;
	ref class ObjetoCultural;

	// Un nivel del juego: fondo, enemigos, aliados, objetos y la salida.
	public ref class Nivel
	{
	private:
		int numero;
		Bitmap^ fondo;
		List<Enemigo^>^ enemigos;
		List<Aliado^>^ aliados;
		List<ObjetoCultural^>^ objetos;
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
		Bitmap^ getFondo();
		void setFondo(Bitmap^ f);
		List<Enemigo^>^ getEnemigos();
		List<Aliado^>^ getAliados();
		List<ObjetoCultural^>^ getObjetos();
		int getTiempoLimite();
		void setTiempoLimite(int t);
		bool getSalidaActiva();
		void setSalidaActiva(bool s);
		int getXInicial();
		void setXInicial(int x);
		int getYInicial();
		void setYInicial(int y);
	};
}
