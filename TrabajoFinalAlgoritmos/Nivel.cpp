#include "Nivel.h"

namespace TrabajoFinalAlgoritmos {

	void Nivel::cargar()
	{
		// anadir logica
	}

	void Nivel::actualizar()
	{
		// anadir logica
	}

	void Nivel::dibujarTodo(Graphics^ g)
	{
		// anadir logica
	}

	bool Nivel::verificarObjetosCompletos()
	{
		// anadir logica
		return false;
	}

	void Nivel::activarSalida()
	{
		// anadir logica
	}

	void Nivel::reiniciar()
	{
		// anadir logica
	}

	int Nivel::getNumero() { return numero; }
	void Nivel::setNumero(int n) { this->numero = n; }
	Bitmap^ Nivel::getFondo() { return fondo; }
	void Nivel::setFondo(Bitmap^ f) { this->fondo = f; }
	List<Enemigo^>^ Nivel::getEnemigos() { return enemigos; }
	List<Aliado^>^ Nivel::getAliados() { return aliados; }
	List<ObjetoCultural^>^ Nivel::getObjetos() { return objetos; }
	int Nivel::getTiempoLimite() { return tiempoLimite; }
	void Nivel::setTiempoLimite(int t) { this->tiempoLimite = t; }
	bool Nivel::getSalidaActiva() { return salidaActiva; }
	void Nivel::setSalidaActiva(bool s) { this->salidaActiva = s; }
	int Nivel::getXInicial() { return xInicial; }
	void Nivel::setXInicial(int x) { this->xInicial = x; }
	int Nivel::getYInicial() { return yInicial; }
	void Nivel::setYInicial(int y) { this->yInicial = y; }
}
