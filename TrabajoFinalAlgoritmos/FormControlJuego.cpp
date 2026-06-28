#include "FormControlJuego.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System::Drawing;

	static bool overlapEstricto(Entidad* a, Entidad* b) {
		int max = a->getAncho() / 5;
		int may = a->getAlto() / 5;
		Rectangle ra(a->getX() + max, a->getY() + may,
			a->getAncho() - 2 * max, a->getAlto() - 2 * may);

		int mbx = b->getAncho() / 4;
		int mby = b->getAlto() / 4;
		Rectangle rb(b->getX() + mbx, b->getY() + mby,
			b->getAncho() - 2 * mbx, b->getAlto() - 2 * mby);

		return ra.IntersectsWith(rb);
	}

	void FormControlJuego::cargarNivel() {
		// anadir logica
	}

	void FormControlJuego::mostrarPreguntaReflexiva() {
		// anadir logica
	}

	void FormControlJuego::actualizarHUD() {
		this->Invalidate();
	}

	void FormControlJuego::mostrarMensaje(String^ texto, int ticks) {
		mensaje = texto;
		mensajeTicks = ticks;
	}

	Juego* FormControlJuego::getJuego() { return juego; }

	void FormControlJuego::form_Load(Object^ sender, EventArgs^ e) {
		cargarNivel();

		if (nivel != nullptr) {
			Cusi* c = juego->getJugador();
			c->reaparecer(nivel->getXInicial(), nivel->getYInicial());
			c->setDireccion(Direccion::Este);
			mostrarMensaje("Recoge los 3 objetos sagrados y llega al tambo iluminado. Usa W A S D.", 130);
		}
		timerJuego->Start();
	}

	void FormControlJuego::timerJuego_Tick(Object^ sender, EventArgs^ e) {
		if (nivelTerminado || nivel == nullptr)
			return;

		Cusi* c = juego->getJugador();

		int ox = c->getX();
		int oy = c->getY();
		c->mover();
		int pieX = c->getX() + c->getAncho() / 2;
		int pieY = c->getY() + (int)(c->getAlto() * 0.82);
		if (!nivel->esTransitable(pieX, pieY)) {
			c->setX(ox);
			c->setY(oy);
		}
		c->animar();

		nivel->actualizar();

		vector<ObjetoCultural*> objs = nivel->getObjetos();

		for (size_t i = 0; i < objs.size(); i++) {

			int dx = (c->getX() + c->getAncho() / 2) -
				(objs[i]->getX() + objs[i]->getAncho() / 2);

			int dy = (c->getY() + c->getAlto() / 2) -
				(objs[i]->getY() + objs[i]->getAlto() / 2);

			const int RADIO_OBJETO = 30;

			if (!objs[i]->getRecogido() &&
				dx * dx + dy * dy <= RADIO_OBJETO * RADIO_OBJETO) {

				bool esBonusVida =
					objs[i]->getNombre() == "Objeto Sagrado";

				c->recogerObjeto(objs[i]);

				if (esBonusVida)
					c->recuperarVida();

				String^ msg = String::Format("{0}: {1}",
					aStr(objs[i]->getNombre()),
					aStr(objs[i]->getDescripcionHistorica()));

				mostrarMensaje(msg, 110);
			}
		}

		vector<Aliado*> alis = nivel->getAliados();

		for (size_t i = 0; i < alis.size(); i++) {

			Aliado* a = alis[i];

			if (a->getVisible()) {

				int dx = (c->getX() + c->getAncho() / 2)
					- (a->getX() + a->getAncho() / 2);

				int dy = (c->getY() + c->getAlto() / 2)
					- (a->getY() + a->getAlto() / 2);

				if (dx * dx + dy * dy <=
					RADIO_INTERACCION * RADIO_INTERACCION) {

					a->interactuar(c);

					// RIMAQ
					Rimaq* r = dynamic_cast<Rimaq*>(a);

					if (r != nullptr) {

						if (r->getPuertaAbierta()) {

							nivel->abrirPuertaRimaq();

							mostrarMensaje(
								"Rimaq: Excelente. El camino esta abierto.",
								150);
						}
						else {

							mostrarMensaje(
								"Rimaq: Encuentra el primer fragmento del quipu.",
								150);
						}
					}

					// WAYRA
					Wayra* w = dynamic_cast<Wayra*>(a);

					if (w != nullptr) {

						if (w->getPuertaAbierta()) {

							nivel->abrirPuertaWayra();

							mostrarMensaje(
								"Wayra: Muy bien. El segundo camino esta abierto.",
								150);
						}
						else {

							mostrarMensaje(
								"Wayra: Recupera el segundo fragmento del quipu.",
								150);
						}
					}
				}
			}
		}

		vector<Enemigo*> ens = nivel->getEnemigos();
		for (size_t i = 0; i < ens.size(); i++) {
			if (overlapEstricto(c, ens[i])) {
				ens[i]->alColisionar(c);
				perdioVida = true;

				if (c->getVidas() <= 0) {
					finalizarNivel(false);
					return;
				}
				else {
					c->reaparecer(nivel->getXInicial(), nivel->getYInicial());
					mostrarMensaje(String::Format(
						"Te atrapo un soldado. Vidas restantes: {0}", c->getVidas()), 90);
				}
				break;
			}
		}

		if (nivel->verificarObjetosCompletos()) {
			if (!nivel->getSalidaActiva()) {
				nivel->activarSalida();
				mostrarMensaje("La puerta del tambo se ha iluminado. Llega a ella!", 110);
			}

			int dxPuerta = (c->getX() + c->getAncho() / 2) - (nivel->getPuertaX() + nivel->getPuertaAncho() / 2);

			int dyPuerta = (c->getY() + c->getAlto() / 2) - (nivel->getPuertaY() + nivel->getPuertaAlto() / 2);

			const int RADIO_PUERTA = 30;

			if (dxPuerta * dxPuerta + dyPuerta * dyPuerta
				<= RADIO_PUERTA * RADIO_PUERTA) {

				finalizarNivel(true);
				return;
			}
		}

		if (mensajeTicks > 0)
			mensajeTicks--;

		this->Invalidate();
	}

	void FormControlJuego::form_KeyDown(Object^ sender, KeyEventArgs^ e) {
		if (nivelTerminado)
			return;
		Cusi* c = juego->getJugador();
		switch (e->KeyCode) {
		case Keys::W: c->caminar(Direccion::Norte); break;
		case Keys::S: c->caminar(Direccion::Sur);   break;
		case Keys::A: c->caminar(Direccion::Oeste); break;
		case Keys::D: c->caminar(Direccion::Este);  break;
		case Keys::Escape:
			nivelTerminado = true;
			timerJuego->Stop();
			this->Close();
			break;
		}
	}

	void FormControlJuego::form_KeyUp(Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W || e->KeyCode == Keys::S ||
			e->KeyCode == Keys::A || e->KeyCode == Keys::D) {
			juego->getJugador()->detener();
		}
	}

	void FormControlJuego::form_Paint(Object^ sender, PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		if (nivel == nullptr)
			return;

		Bitmap^ fondo = CacheImagenes::obtener(aStr(nivel->getRutaFondo()));
		g->DrawImage(fondo, 0, 0, this->ClientSize.Width, this->ClientSize.Height);

		nivel->dibujarTodo(g);

		dibujarPuertasIntermedias(g); 

		dibujarPuerta(g);

		juego->getJugador()->dibujar(g);

		dibujarHUD(g);
		dibujarMensaje(g);
	}

	void FormControlJuego::dibujarPuerta(Graphics^ g) {

		Bitmap^ bmp = CacheImagenes::obtener(
			aStr(nivel->getRutaPuerta()));

		int columnas = 1;
		int filas = 2;

		int frameAncho = bmp->Width / columnas;
		int frameAlto = bmp->Height / filas;

		int fila = 0; // puerta cerrada

		if (nivel->getSalidaActiva())
			fila = 1; // puerta abierta

		g->DrawImage(
			bmp,
			Rectangle(
				nivel->getPuertaX(),
				nivel->getPuertaY(),
				nivel->getPuertaAncho(),
				nivel->getPuertaAlto()),
			0,
			fila * frameAlto,
			frameAncho,
			frameAlto,
			GraphicsUnit::Pixel);
	}

	void FormControlJuego::dibujarHUD(Graphics^ g) {
		Cusi* c = juego->getJugador();

		vector<ObjetoCultural*> objs = nivel->getObjetos();

		int total = 0;
		int rec = 0;

		for (size_t i = 0; i < objs.size(); i++) {

			if (objs[i]->getNombre() != "Objeto Sagrado") {

				total++;

				if (objs[i]->getRecogido())
					rec++;
			}
		}

		System::Drawing::Font^ f = gcnew System::Drawing::Font("Bahnschrift", 11, FontStyle::Bold);
		SolidBrush^ panel = gcnew SolidBrush(Color::FromArgb(150, 0, 0, 0));
		SolidBrush^ oro = gcnew SolidBrush(Color::Gold);

		g->FillRectangle(panel, 0, 0, this->ClientSize.Width, 30);
		g->DrawString(String::Format("Vidas: {0}", c->getVidas()), f, oro, 12, 5);
		g->DrawString(String::Format("Puntaje: {0}", c->getPuntaje()), f, oro, 150, 5);
		g->DrawString(String::Format("Objetos: {0}/{1}", rec, total), f, oro, 330, 5);

		String^ objetivo = nivel->getSalidaActiva() ? "A la SALIDA!" : "Recupera 3 objetos";
		g->DrawString(objetivo, f, oro, 500, 5);

		delete oro;
		delete panel;
		delete f;
	}

	void FormControlJuego::dibujarMensaje(Graphics^ g) {
		if (mensajeTicks <= 0 || mensaje == nullptr)
			return;

		System::Drawing::Font^ f = gcnew System::Drawing::Font("Bahnschrift", 11, FontStyle::Bold);
		SizeF sz = g->MeasureString(mensaje, f, this->ClientSize.Width - 80);
		int bw = (int)sz.Width + 30;
		int bh = (int)sz.Height + 18;
		int bx = (this->ClientSize.Width - bw) / 2;
		int by = this->ClientSize.Height - bh - 24;

		SolidBrush^ fondo = gcnew SolidBrush(Color::FromArgb(200, 35, 22, 10));
		Pen^ borde = gcnew Pen(Color::Gold, 2);
		SolidBrush^ texto = gcnew SolidBrush(Color::White);

		g->FillRectangle(fondo, bx, by, bw, bh);
		g->DrawRectangle(borde, bx, by, bw, bh);
		RectangleF area((float)(bx + 15), (float)(by + 9), (float)(bw - 30), (float)(bh - 18));
		g->DrawString(mensaje, f, texto, area);

		delete texto;
		delete borde;
		delete fondo;
		delete f;
	}

	void FormControlJuego::finalizarNivel(bool gano) {
		if (nivelTerminado)
			return;
		nivelTerminado = true;
		timerJuego->Stop();

		Cusi* c = juego->getJugador();
		if (gano) {
			if (!perdioVida)
				c->sumarPuntos(PTS_BONUS_SIN_DANO);
			juego->setEstado(EstadoJuego::Victoria);
		}
		else {
			juego->setEstado(EstadoJuego::Derrota);
		}

		this->Close();
	}

	void FormControlJuego::dibujarPuertasIntermedias(Graphics^ g) {

		Bitmap^ bmp = CacheImagenes::obtener(aStr(IMG_PUERTA_N2));

		int frameAncho = bmp->Width;
		int frameAlto = bmp->Height / 2;

		// Puerta de Rimaq
		if (!nivel->getPuertaRimaqAbierta()) {

			g->DrawImage(
				bmp,
				Rectangle(
					nivel->getPuertaRimaqX(),
					nivel->getPuertaRimaqY(),
					120,
					120),
				0,
				0,
				frameAncho,
				frameAlto,
				GraphicsUnit::Pixel);
		}

		// Puerta de Wayra
		if (!nivel->getPuertaWayraAbierta()) {

			g->DrawImage(
				bmp,
				Rectangle(
					nivel->getPuertaWayraX(),
					nivel->getPuertaWayraY(),
					100,
					100),
				0,
				0,
				frameAncho,
				frameAlto,
				GraphicsUnit::Pixel);
		}
	}

}
