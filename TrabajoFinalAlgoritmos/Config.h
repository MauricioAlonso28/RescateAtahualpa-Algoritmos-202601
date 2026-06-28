#pragma once
#include <string>

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

// Nivel 1
#define IMG_CUSI        "img/personajePrincipal.png"
#define IMG_SOLDADO_N1  "img/enemigo_nivel1.png"
#define IMG_CURACA      "img/curaca_aliado.png"
#define IMG_MASCARA     "img/mascara_objeto.png"
#define IMG_TEXTIL      "img/textil_objeto.png"
#define IMG_VASIJA      "img/vasija_objeto.png"
#define IMG_PUERTA_N1   "img/puerta_final_nivel1.png"
#define IMG_FONDO_N1    "img/background_nivel_1.png"

// Nivel 2
#define IMG_N2_HISTORIA1 "img/nivel2/n2_historia1.png"
#define IMG_N2_HISTORIA2 "img/nivel2/n2_historia2.png"
#define IMG_N2_HISTORIA3 "img/nivel2/n2_historia3.png"
#define IMG_N2_HISTORIA4 "img/nivel2/n2_historia4.png"
#define IMG_N2_HISTORIA5 "img/nivel2/ndd2_historia5.png"
#define IMG_FONDO_N2     "img/nivel2/fondoNivel2.png"


#define IMG_PUERTA_N2    "img/nivel2/puerta_final_nivel2.png"

#define IMG_ENEMIGO_N2   "img/nivel2/Enemigo.png"

#define IMG_RIMAQ        "img/nivel2/Rimaq.png"
#define IMG_WAYRA        "img/nivel2/Wayra.png"

#define IMG_PARTE_QUIPU1 "img/nivel2/parteQuipu1.png"
#define IMG_PARTE_QUIPU2 "img/nivel2/parteQuipu2.png"
#define IMG_PARTE_QUIPU3 "img/nivel2/parteQuipu3.png"

#define IMG_OBJETO_VIDA  "img/nivel2/objetoVida.png"

const int NIVEL_ANCHO = 677;
const int NIVEL_ALTO  = 642;

const int CUSI_COLS  = 4;
const int CUSI_FILAS = 4;
const int CUSI_FILA_NORTE = 0;
const int CUSI_FILA_ESTE  = 1;
const int CUSI_FILA_OESTE = 2;
const int CUSI_FILA_SUR   = 3;

const int SOLDADO_COLS  = 5;
const int SOLDADO_FILAS = 5;
const int SOLDADO_FILA_CAMINAR = 2;

const int CURACA_COLS = 4;

const int PUERTA_ESTADOS = 2;

const int VEL_CUSI = 6;

const int CUSI_ANCHO = 40;
const int CUSI_ALTO  = 46;
const int SOLDADO_ANCHO = 38;
const int SOLDADO_ALTO  = 44;

const int PTS_OBJETO         = 100;
const int PTS_ALIADO         = 50;
const int PTS_BONUS_SIN_DANO = 200;
const int PTS_CASTIGO_ENEMIGO = -50;

const int VIDAS_INICIALES = 3;

const int RADIO_INTERACCION = 35;

const int RADIO_OBJETO = 30;

const bool MOSTRAR_CORREDORES = false; // por el momento activado para ver los caminos, luego le damos false

ref class CacheImagenes {
private:
	static Dictionary<String^, Bitmap^>^ cache;
public:
	static Bitmap^ obtener(String^ ruta) {
		if (cache == nullptr)
			cache = gcnew Dictionary<String^, Bitmap^>();
		Bitmap^ bmp;
		if (cache->TryGetValue(ruta, bmp))
			return bmp;
		bmp = gcnew Bitmap(ruta);
		cache->Add(ruta, bmp);
		return bmp;
	}
};

inline System::String^ aStr(const std::string& s) {
	return gcnew System::String(s.c_str());
}
