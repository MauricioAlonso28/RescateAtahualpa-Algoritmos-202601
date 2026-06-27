#pragma once

enum class Direccion {
	Norte,
	Sur,
	Este,
	Oeste
};

enum class EjePatrulla {
	Horizontal,
	Vertical
};

enum class EstadoJuego {
	EnMenu,
	Jugando,
	Victoria,
	Derrota
};