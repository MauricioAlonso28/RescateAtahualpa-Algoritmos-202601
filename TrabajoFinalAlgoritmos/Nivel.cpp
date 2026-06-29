#include "Nivel.h"
#include "SoldadoPatrulla.h"
#include "Curaca.h"
#include "Rimaq.h"
#include "Wayra.h"
#include "Config.h"

Nivel::Nivel() {
	numero = 1;
	rutaFondo = IMG_FONDO_N1;
	tiempoLimite = 0;
	salidaActiva = false;
	xInicial = 0;
	yInicial = 0;
	rutaPuerta = IMG_PUERTA_N1;
	puertaX = 0;
	puertaY = 0;
	puertaAncho = 0;
	puertaAlto = 0;
	puertaRimaqAbierta = false;
	puertaWayraAbierta = false;

	puertaRimaqX = 0;
	puertaRimaqY = 0;

	puertaWayraX = 0;
	puertaWayraY = 0;
}

Nivel::~Nivel() {
	for (size_t i = 0; i < enemigos.size(); i++) delete enemigos[i];
	for (size_t i = 0; i < aliados.size(); i++)  delete aliados[i];
	for (size_t i = 0; i < objetos.size(); i++)  delete objetos[i];
	enemigos.clear();
	aliados.clear();
	objetos.clear();
}


void Nivel::cargar() {

	corredores.clear();

	for (size_t i = 0; i < enemigos.size(); i++)
		delete enemigos[i];
	enemigos.clear();

	for (size_t i = 0; i < aliados.size(); i++)
		delete aliados[i];
	aliados.clear();

	for (size_t i = 0; i < objetos.size(); i++)
		delete objetos[i];
	objetos.clear();

	switch (numero)
	{
	case 1:
		cargarNivel1();
		break;

	case 2:
		cargarNivel2();
		break;

	case 3:
		cargarNivel3();
		break;

	default:
		cargarNivel1();
		break;
	}
}

void Nivel::cargarNivel1() 
{
	rutaFondo = IMG_FONDO_N1;
	tiempoLimite = 0;
	salidaActiva = false;

	xInicial = 110;
	yInicial = 142;

	rutaPuerta = IMG_PUERTA_N1;
	puertaX = 1143;
	puertaY = 600;
	puertaAncho = 100;
	puertaAlto = 100;

	// Acceso manual al circulo central (cerrado por muro): permite que Cusi
	// entre desde el camino inferior hasta el centro a recoger la vasija.
	zonasLibres.push_back(ZonaLibre{ 695, 425, 115, 225 });

	ObjetoCultural* mascara = new ObjetoCultural(215, 577, IMG_MASCARA, "Mascara de oro", PTS_OBJETO);
	mascara->setAncho(50);
	mascara->setAlto(54);
	mascara->setDescripcionHistorica("Mascara funeraria de oro batido, simbolo del Sol y del linaje sagrado del Inca.");
	objetos.push_back(mascara);

	ObjetoCultural* vasija = new ObjetoCultural(703, 437, IMG_VASIJA, "Vasija ritual", PTS_OBJETO);
	vasija->setAncho(54);
	vasija->setAlto(66);
	vasija->setDescripcionHistorica("Quero ceremonial usado en ofrendas de chicha durante las festividades del Inti Raymi.");
	objetos.push_back(vasija);

	ObjetoCultural* textil = new ObjetoCultural(694, 86, IMG_TEXTIL, "Textil ceremonial", PTS_OBJETO);
	textil->setAncho(52);
	textil->setAlto(58);
	textil->setDescripcionHistorica("Tejido con tecnicas de tokapus que registran linajes y eventos del Imperio.");
	objetos.push_back(textil);

	Curaca* curaca = new Curaca(193, 150, IMG_CURACA,
		"Cusi, el camino esta vigilado. Evita a los soldados y recupera las ofrendas antes de que las fundan.");
	curaca->setAncho(40);
	curaca->setAlto(66);
	aliados.push_back(curaca);

	SoldadoPatrulla* s1 = new SoldadoPatrulla(400, 236, IMG_SOLDADO_N1, 2, EjePatrulla::Horizontal);
	s1->setLimites(280, 560);
	enemigos.push_back(s1);

	SoldadoPatrulla* s2 = new SoldadoPatrulla(760, 608, IMG_SOLDADO_N1, 3, EjePatrulla::Horizontal);
	s2->setLimites(640, 940);
	enemigos.push_back(s2);
}

void Nivel::cargarNivel2()
{
	rutaFondo = IMG_FONDO_N2;
	tiempoLimite = 0;
	salidaActiva = false;

	xInicial = 10;
	yInicial = 130;

	rutaPuerta = IMG_PUERTA_N2;

	puertaX = 1230;
	puertaY = 220;

	puertaAncho = 150;
	puertaAlto = 150;

	//Enemmigo 1 horizontal

	SoldadoPatrulla* s1 = new SoldadoPatrulla(
		200,
		630,
		IMG_ENEMIGO_N2,
		2,
		EjePatrulla::Horizontal);

	s1->setLimites(200, 550);

	enemigos.push_back(s1);

	//Enemigo 2 horizontal

	SoldadoPatrulla* s2 = new SoldadoPatrulla(
		625,
		230,
		IMG_ENEMIGO_N2,
		3,
		EjePatrulla::Horizontal);

	s2->setLimites(625, 970);

	enemigos.push_back(s2);


	//Enemigo 3 vertical

	SoldadoPatrulla* s3 = new SoldadoPatrulla(
		540,
		420,
		IMG_ENEMIGO_N2,
		5,
		EjePatrulla::Vertical);

	s3->setLimites(340, 610);

	enemigos.push_back(s3);

	//Enemigo 4 vertical

	SoldadoPatrulla* s4 = new SoldadoPatrulla(
		675,
		400,
		IMG_ENEMIGO_N2,
		3,
		EjePatrulla::Vertical);

	s4->setLimites(370, 720);

	enemigos.push_back(s4);

	//Primera parte del quipu
	ObjetoCultural* quipu1 = new ObjetoCultural(
		300,
		500,
		IMG_PARTE_QUIPU1,
		"Parte del Quipu 1",
		PTS_OBJETO);

	quipu1->setAncho(45);
	quipu1->setAlto(45);

	quipu1->setDescripcionHistorica(
		"Fragmento de un quipu utilizado para registrar informacion en el Imperio Inca.");

	objetos.push_back(quipu1);

	//Segunda parte del quipu

	ObjetoCultural* quipu2 = new ObjetoCultural(
		1040,
		230,
		IMG_PARTE_QUIPU2,
		"Parte del Quipu 2",
		PTS_OBJETO);

	quipu2->setAncho(45);
	quipu2->setAlto(45);

	quipu2->setDescripcionHistorica(
		"Fragmento de quipu empleado por los quipucamayoc para conservar registros.");

	objetos.push_back(quipu2);

	//tercera parte del quipu

	ObjetoCultural* quipu3 = new ObjetoCultural(
		670,
		720,
		IMG_PARTE_QUIPU3,
		"Parte del Quipu 3",
		PTS_OBJETO);

	quipu3->setAncho(45);
	quipu3->setAlto(45);

	quipu3->setDescripcionHistorica(
		"Ultimo fragmento necesario para reconstruir el antiguo quipu.");

	objetos.push_back(quipu3);

	//Objeto aumentar vida
	// Bonus de vida

	ObjetoCultural* vidaExtra = new ObjetoCultural(
		760,
		420,
		IMG_OBJETO_VIDA,
		"Objeto Sagrado",
		50);

	vidaExtra->setAncho(60);
	vidaExtra->setAlto(60);

	vidaExtra->setDescripcionHistorica(
		"Vida aumentada.");

	objetos.push_back(vidaExtra);

	// NPC Rimaq

	Rimaq* rimaq = new Rimaq(
		280,
		60,
		IMG_RIMAQ,
		"Encuentra el primer fragmento del quipu y vuelve conmigo.");

	rimaq->setAncho(50);
	rimaq->setAlto(70);

	aliados.push_back(rimaq);


	// NPC Wayra


	Wayra* wayra = new Wayra(
		750,
		60,
		IMG_WAYRA,
		"Ahora encuentra el segundo fragmento del quipu.");

	wayra->setAncho(50);
	wayra->setAlto(70);

	aliados.push_back(wayra);


	setPuertaRimaq(510, 280);
	setPuertaWayra(890, 440);

	corredores.push_back(Corredor{ 0, 130, 350, 60 }); //Camino de donde empieza
	corredores.push_back(Corredor{ 340, 250, 70, 150 }); //Camino que para abajo de la casa cerca del puente
	corredores.push_back(Corredor{ 170, 100, 200, 40 }); //Camino que es la parte de la casa
	corredores.push_back(Corredor{ 240, 190, 90, 50 }); //camino de que va de forma diagonal
	corredores.push_back(Corredor{ 270, 230, 90, 50 }); //camino de que va de forma diagonal 2
	corredores.push_back(Corredor{ 270, 360, 90, 50 }); //camino que rodea al circulo en la parte izquierda, parte izquierda
	corredores.push_back(Corredor{ 220, 370, 90, 50 }); //camino que rodea al circulo en la parte izquierda, parte izquierda 2
	corredores.push_back(Corredor{ 170, 380, 90, 50 }); //camino que rodea al circulo en la parte izquierda, parte izquierda 2
	corredores.push_back(Corredor{ 120, 390, 90, 50 }); //camino que rodea al circulo en la parte izquierda, parte izquierda 3
	corredores.push_back(Corredor{ 110, 400, 50, 190 }); //camino que rodea al circulo en la parte izquierda, parte izquierda vertical 
	corredores.push_back(Corredor{ 120, 570, 50, 40 }); //camino que rodea al circulo en la parte izquierda, parte derecha inferior 1
	corredores.push_back(Corredor{ 140, 580, 50, 40 }); //camino que rodea al circulo en la parte izquierda, parte derecha inferior 2
	corredores.push_back(Corredor{ 160, 590, 70, 40 }); //camino que rodea al circulo en la parte izquierda, parte derecha inferior 3	
	corredores.push_back(Corredor{ 110, 620, 130, 90 }); //circulo ue hay en la parte inferior y cerca del ciruclo grande de la parte izquierda 

	corredores.push_back(Corredor{ 210, 630, 250, 60 }); //Camino que parte de la izquierda del circulo hacia la derecha para que podamos subir al circulo grande que hay 1 


	corredores.push_back(Corredor{ 310, 590, 40, 60 }); //Camino vertical que va hacia el circulo donde se encuentra el primer objetoa recoger
	corredores.push_back(Corredor{ 235, 470, 180, 120 }); //parte central del circulo en donde se va recoger el primer objeto


	corredores.push_back(Corredor{ 430, 610, 100, 80 }); //Camino que parte de la izquierda del circulo hacia la derecha y sube de forma diagonal por el camino 
	corredores.push_back(Corredor{ 460, 570, 100, 80 }); //Camino que parte de la izquierda del circulo hacia la derecha y sube de forma diagonal por el camino 2 


	corredores.push_back(Corredor{ 525, 250, 85, 370 }); //Camino que parte de la izquierda del circulo hacia la derecha y sube  recta por el camino 3


	corredores.push_back(Corredor{ 475, 390, 50, 50 }); //Camino que va a la izquierda para volver a la casa del NPC 1
	corredores.push_back(Corredor{ 400, 370, 100, 60 }); //Camino que va a la izquierda para volver a la casa del NPC 2


	corredores.push_back(Corredor{ 525, 250, 130, 50 }); //Camino que parte de la izquierda del circulo hacia la derecha y sube  recta por el camino 3

	corredores.push_back(Corredor{ 600, 200, 50, 50 }); //Parte central y que va a la izquierda camino arriba
	corredores.push_back(Corredor{ 570, 70, 50, 150 }); //Parte central y que va a la izquierda camino arriba y de forma vertical




	corredores.push_back(Corredor{ 625, 225, 230, 50 }); //Parte central y que va a la derecha






	corredores.push_back(Corredor{ 750, 135, 60, 90 }); //Parte central que conecta al segunda npc y que va de forma vertical
	corredores.push_back(Corredor{ 670, 70, 180, 90 }); //Parte central en donde va el segundo npc 

	corredores.push_back(Corredor{ 820, 250, 90, 90 }); //Parte que conecta la parte vertical y el camino que va para el segundo objeto

	corredores.push_back(Corredor{ 900, 220, 50, 135 }); //Parte central y que va para abajo que conecta el camino al segundo objeto

	corredores.push_back(Corredor{ 920, 70, 60, 150 }); //Parte central que viene despues del centro que aparece el segundo npc y que va a la derecha vertical

	corredores.push_back(Corredor{ 910, 340, 200, 50 }); //Parte debajo de donde es el camino para recoger el segundo objeto

	corredores.push_back(Corredor{ 1035, 270, 40, 70 }); //Parte central que conecta el camino hacia el segundo objeto, forma vertical

	corredores.push_back(Corredor{ 1015, 230, 100, 40 }); //Parte donde se enccuentra el objeto en un cuadrado del circulo de la derecha 


	corredores.push_back(Corredor{ 960, 390, 50, 50 }); //Parte del camino que va hacia la direccion del tercer objeto por el puente que hay en la parte derecha del medio 1
	corredores.push_back(Corredor{ 950, 410, 50, 50 }); //Parte del camino que va hacia la direccion del tercer objeto por el puente que hay en la parte derecha del medio 2
	corredores.push_back(Corredor{ 940, 430, 50, 50 }); //Parte del camino que va hacia la direccion del tercer objeto por el puente que hay en la parte derecha del medio 3
	corredores.push_back(Corredor{ 930, 450, 50, 50 }); //Parte del camino que va hacia la direccion del tercer objeto por el puente que hay en la parte derecha del medio 4
	corredores.push_back(Corredor{ 920, 450, 50, 50 }); //Parte del camino que va hacia la direccion del tercer objeto por el puente que hay en la parte derecha del medio 5
	corredores.push_back(Corredor{ 910, 470, 50, 50 }); //Parte del camino que va hacia la direccion del tercer objeto por el puente que hay en la parte derecha del medio 6
	corredores.push_back(Corredor{ 900, 490, 50, 50 }); //Parte del camino que va hacia la direccion del tercer objeto por el puente que hay en la parte derecha del medio 7
	corredores.push_back(Corredor{ 890, 510, 50, 50 }); //Parte del camino que va hacia la direccion del tercer objeto por el puente que hay en la parte derecha del medio 8
	corredores.push_back(Corredor{ 850, 530, 80, 100 }); //Parte del camino que va hacia la direccion del tercer objeto por el puente que hay en la parte derecha del medio 8


	corredores.push_back(Corredor{ 630, 560, 220, 50 }); //Parte del camino que va hacia el tercer objeto por la izquierda


	corredores.push_back(Corredor{ 725, 430, 110, 50 }); //Lugar donde se va agarrar la vida


	corredores.push_back(Corredor{ 670, 400, 55, 360 }); //Parte central de doonde se encuentra el objeto de forma vertical






	corredores.push_back(Corredor{ 630, 710, 130, 57 }); //Lugar donde se encuentra el tercer objeto en un cuadrado


	corredores.push_back(Corredor{ 890, 600, 60, 60 }); //Camino que va a la puerta del final parte derecha por el puente 1
	corredores.push_back(Corredor{ 920, 620, 90, 60 }); //Camino que va a la puerta del final parte derecha por el puente 2
	corredores.push_back(Corredor{ 960, 630, 120, 60 }); //Camino que va a la puerta del final parte derecha por el puente 3
	corredores.push_back(Corredor{ 1040, 660, 60, 60 }); //Camino que va a la puerta del final parte derecha por el puente 4
	corredores.push_back(Corredor{ 1060, 680, 60, 50 }); //Camino que va a la puerta del final parte derecha por el puente 5
	corredores.push_back(Corredor{ 1090, 700, 200, 60 }); //Camino que va a la puerta del final parte derecha por el puente 6
	corredores.push_back(Corredor{ 1270, 270, 70, 150 }); //Camino vertical que va hacia la puerta final 1
	corredores.push_back(Corredor{ 1250, 370, 30, 60 }); //Camino vertical que va hacia la puerta final 2
	corredores.push_back(Corredor{ 1220, 400, 50, 50 }); //Camino vertical que va hacia la puerta final 3
	corredores.push_back(Corredor{ 1190, 430, 60, 80 }); //Camino vertical que va hacia la puerta final 4
	corredores.push_back(Corredor{ 1220, 490, 60, 80 }); //Camino vertical que va hacia la puerta final 5
	corredores.push_back(Corredor{ 1260, 540, 50, 220 }); //Camino vertical que va hacia la puerta final 6












}

void Nivel::cargarNivel3()
{

}

bool Nivel::esTransitable(int px, int py) {

	// Bloquear puerta de Rimaq
	if (!puertaRimaqAbierta) {

		Rectangle puertaR(
			puertaRimaqX,
			puertaRimaqY,
			120,
			120);

		if (puertaR.Contains(px, py))
			return false;
	}

	// Bloquear puerta de Wayra
	if (!puertaWayraAbierta) {

		Rectangle puertaW(
			puertaWayraX,
			puertaWayraY,
			60,
			90);

		if (puertaW.Contains(px, py))
			return false;
	}

	// Bloquear solamente la entrada de la puerta final
	if (!salidaActiva) {

		Rectangle puertaFinal(
			puertaX + puertaAncho / 4,
			puertaY + puertaAlto / 3,
			puertaAncho / 2,
			puertaAlto / 2);

		if (puertaFinal.Contains(px, py))
			return false;
	}


	// Zonas libres
	for (size_t i = 0; i < zonasLibres.size(); i++) {

		ZonaLibre& z = zonasLibres[i];

		if (px >= z.x && px < z.x + z.w &&
			py >= z.y && py < z.y + z.h)
			return true;
	}

	// Corredores generados
	for (size_t i = 0; i < corredores.size(); i++) {

		Corredor& c = corredores[i];

		if (px >= c.x && px < c.x + c.w &&
			py >= c.y && py < c.y + c.h)
			return true;
	}

	if (numero == 2)
		return false;

	// Verificación por color del fondo
	Bitmap^ bg = CacheImagenes::obtener(aStr(rutaFondo));

	int w = bg->Width;
	int h = bg->Height;

	int ok = 0;

	for (int dy = -6; dy <= 6; dy += 6) {

		for (int dx = -6; dx <= 6; dx += 6) {

			int x = px + dx;
			int y = py + dy;

			if (x < 0 || y < 0 || x >= w || y >= h)
				continue;

			Color c = bg->GetPixel(x, y);

			int r = c.R;
			int g = c.G;
			int b = c.B;

			if (r > g &&
				g + 6 >= b &&
				r >= 105 &&
				(r - b) >= 25 &&
				(r - b) <= 140)
				ok++;
		}
	}

	return ok >= 2;
}

void Nivel::actualizar() {
	for (size_t i = 0; i < enemigos.size(); i++)
		enemigos[i]->mover();
}

void Nivel::dibujarTodo(Graphics^ g) {

	// Solo para depuración: muestra los corredores del mapa
	if (MOSTRAR_CORREDORES)
	{
		Pen^ lapiz = gcnew Pen(Color::Red, 2);

		for (size_t i = 0; i < corredores.size(); i++)
		{
			Corredor c = corredores[i];

			g->DrawRectangle(
				lapiz,
				c.x,
				c.y,
				c.w,
				c.h);
		}

		delete lapiz;
	}

	for (size_t i = 0; i < objetos.size(); i++)
		if (!objetos[i]->getRecogido())
			objetos[i]->dibujar(g);

	for (size_t i = 0; i < aliados.size(); i++)
		if (aliados[i]->getVisible())
			aliados[i]->dibujar(g);

	for (size_t i = 0; i < enemigos.size(); i++)
		enemigos[i]->dibujar(g);
}

bool Nivel::verificarObjetosCompletos() {

	for (size_t i = 0; i < objetos.size(); i++) {

		// El Objeto Sagrado no cuenta para completar el nivel
		if (objetos[i]->getNombre() == "Objeto Sagrado")
			continue;

		if (!objetos[i]->getRecogido())
			return false;
	}

	return true;
}

void Nivel::activarSalida() {
	salidaActiva = true;
}

void Nivel::reiniciar() {
	// anadir logica
}

int Nivel::getNumero() { return numero; }
void Nivel::setNumero(int n) { this->numero = n; }
string Nivel::getRutaFondo() { return rutaFondo; }
void Nivel::setRutaFondo(string f) { this->rutaFondo = f; }
vector<Enemigo*> Nivel::getEnemigos() { return enemigos; }
vector<Aliado*> Nivel::getAliados() { return aliados; }
vector<ObjetoCultural*> Nivel::getObjetos() { return objetos; }
int Nivel::getTiempoLimite() { return tiempoLimite; }
void Nivel::setTiempoLimite(int t) { this->tiempoLimite = t; }
bool Nivel::getSalidaActiva() { return salidaActiva; }
void Nivel::setSalidaActiva(bool s) { this->salidaActiva = s; }
int Nivel::getXInicial() { return xInicial; }
void Nivel::setXInicial(int x) { this->xInicial = x; }
int Nivel::getYInicial() { return yInicial; }
void Nivel::setYInicial(int y) { this->yInicial = y; }

string Nivel::getRutaPuerta() { return rutaPuerta; }
int Nivel::getPuertaX() { return puertaX; }
int Nivel::getPuertaY() { return puertaY; }
int Nivel::getPuertaAncho() { return puertaAncho; }
int Nivel::getPuertaAlto() { return puertaAlto; }

bool Nivel::getPuertaRimaqAbierta() {
	return puertaRimaqAbierta;
}

bool Nivel::getPuertaWayraAbierta() {
	return puertaWayraAbierta;
}

void Nivel::abrirPuertaRimaq() {
	puertaRimaqAbierta = true;
}

void Nivel::abrirPuertaWayra() {
	puertaWayraAbierta = true;
}

int Nivel::getPuertaRimaqX() {
	return puertaRimaqX;
}

int Nivel::getPuertaRimaqY() {
	return puertaRimaqY;
}

int Nivel::getPuertaWayraX() {
	return puertaWayraX;
}

int Nivel::getPuertaWayraY() {
	return puertaWayraY;
}

void Nivel::setPuertaRimaq(int x, int y) {
	puertaRimaqX = x;
	puertaRimaqY = y;
}

void Nivel::setPuertaWayra(int x, int y) {
	puertaWayraX = x;
	puertaWayraY = y;
}
