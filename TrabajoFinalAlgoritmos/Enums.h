#pragma once

namespace TrabajoFinalAlgoritmos {

	// Direccion de movimiento de Cusi (para elegir el sprite y desplazarse).
	public enum class Direccion {
		Norte,
		Sur,
		Este,
		Oeste
	};

	// Eje sobre el que patrulla un SoldadoPatrulla.
	public enum class EjePatrulla {
		Horizontal,
		Vertical
	};

	// Estados generales del juego.
	public enum class EstadoJuego {
		EnMenu,
		Jugando,
		Victoria,
		Derrota
	};
}
