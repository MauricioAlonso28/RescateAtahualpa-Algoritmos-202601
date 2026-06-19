#pragma once

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::Collections::Generic;

	// Tabla de puntajes (nombres y puntajes en paralelo).
	public ref class Ranking
	{
	private:
		List<String^>^ nombres;
		List<int>^ puntajes;

	public:
		void agregar(String^ nombre, int puntos);
		void mostrarTop();

		List<String^>^ getNombres();
		List<int>^ getPuntajes();
	};
}
