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
			if (!objs[i]->getRecogido() && c->colisionaCon(objs[i])) {
				c->recogerObjeto(objs[i]);
				String^ msg = String::Format("{0}: {1}",
					aStr(objs[i]->getNombre()), aStr(objs[i]->getDescripcionHistorica()));
				mostrarMensaje(msg, 110);
			}
		}

		vector<Aliado*> alis = nivel->getAliados();
		for (size_t i = 0; i < alis.size(); i++) {
			Aliado* a = alis[i];
			if (a->getVisible() && a->puedeActivarse(c)) {
				int dx = (c->getX() + c->getAncho() / 2) - (a->getX() + a->getAncho() / 2);
				int dy = (c->getY() + c->getAlto() / 2) - (a->getY() + a->getAlto() / 2);
				if (dx * dx + dy * dy <= RADIO_INTERACCION * RADIO_INTERACCION) {
					String^ frase = aStr(a->getFraseClave());
					a->interactuar(c);
					mostrarMensaje(frase, 150);
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

			Rectangle puerta(nivel->getPuertaX(), nivel->getPuertaY(),
				nivel->getPuertaAncho(), nivel->getPuertaAlto());
			if (puerta.IntersectsWith(c->getRectangulo())) {
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

		dibujarPuerta(g);

		juego->getJugador()->dibujar(g);

		dibujarHUD(g);
		dibujarMensaje(g);
	}

	void FormControlJuego::dibujarPuerta(Graphics^ g) {
		Bitmap^ bmp = CacheImagenes::obtener(aStr(nivel->getRutaPuerta()));
		int fh = bmp->Height / PUERTA_ESTADOS;
		int estado = nivel->getSalidaActiva() ? 1 : 0; // 0 cerrada, 1 abierta
		g->DrawImage(bmp,
			System::Drawing::Rectangle(nivel->getPuertaX(), nivel->getPuertaY(),
				nivel->getPuertaAncho(), nivel->getPuertaAlto()),
			0, estado * fh, bmp->Width, fh, GraphicsUnit::Pixel);

		if (nivel->getSalidaActiva()) {
			System::Drawing::Font^ ff = gcnew System::Drawing::Font("Bahnschrift", 11, FontStyle::Bold);
			SolidBrush^ b = gcnew SolidBrush(Color::Gold);
			g->DrawString("SALIDA", ff, b, (float)(nivel->getPuertaX()), (float)(nivel->getPuertaY() - 18));
			delete b; delete ff;
		}
	}

	/*void FormControlJuego::dibujarHUD(Graphics^ g) {
		Cusi* c = juego->getJugador();

		vector<ObjetoCultural*> objs = nivel->getObjetos();
		int total = (int)objs.size();
		int rec = 0;
		for (size_t i = 0; i < objs.size(); i++)
			if (objs[i]->getRecogido()) rec++;

		System::Drawing::Font^ f = gcnew System::Drawing::Font("Bahnschrift", 14, FontStyle::Bold);
		SolidBrush^ panel = gcnew SolidBrush(Color::FromArgb(150, 0, 0, 0));
		SolidBrush^ oro = gcnew SolidBrush(Color::Gold);

		g->FillRectangle(panel, 0, 0, this->ClientSize.Width, 36);
		g->DrawString(String::Format("Vidas: {0}", c->getVidas()), f, oro, 20, 6);
		g->DrawString(String::Format("Puntaje: {0}", c->getPuntaje()), f, oro, 230, 6);
		g->DrawString(String::Format("Objetos: {0}/{1}", rec, total), f, oro, 470, 6);

		String^ objetivo = nivel->getSalidaActiva() ? "A la SALIDA!" : "Recupera 3 objetos";
		g->DrawString(objetivo, f, oro, 720, 6);

		delete oro;
		delete panel;
		delete f;
	}*/

	void FormControlJuego::dibujarHUD(Graphics^ g) {
		Cusi* c = juego->getJugador();

		vector<ObjetoCultural*> objs = nivel->getObjetos();
		int total = (int)objs.size();
		int rec = 0;
		for (size_t i = 0; i < objs.size(); i++)
			if (objs[i]->getRecogido()) rec++;

		// Panel de fondo
		SolidBrush^ panel = gcnew SolidBrush(Color::FromArgb(170, 0, 0, 0));
		g->FillRectangle(panel, 0, 0, this->ClientSize.Width, 34);
		delete panel;

		System::Drawing::Font^ fNormal = gcnew System::Drawing::Font("Bahnschrift", 11, FontStyle::Bold);
		System::Drawing::Font^ fCorazon = gcnew System::Drawing::Font("Segoe UI Symbol", 14, FontStyle::Bold);
		SolidBrush^ oro = gcnew SolidBrush(Color::Gold);
		SolidBrush^ rojo = gcnew SolidBrush(Color::FromArgb(220, 80, 0));
		SolidBrush^ gris = gcnew SolidBrush(Color::FromArgb(80, 80, 80));

		// Corazones (m�x 3)
		int vidaMax = 3;
		int vidas = c->getVidas();
		float cx = 12;
		for (int i = 0; i < vidaMax; i++) {
			SolidBrush^ color = (i < vidas) ? rojo : gris;
			g->DrawString(L"\u2665", fCorazon, color, cx, 7);
			cx += 24;
		}

		// Puntaje
		g->DrawString(String::Format("Pts: {0}", c->getPuntaje()), fNormal, oro, 90, 7);

		// Objetos recogidos
		g->DrawString(String::Format("Objetos: {0}/{1}", rec, total), fNormal, oro, 240, 7);

		// Objetivo
		String^ objetivo = nivel->getSalidaActiva()
			? L"\u2192 Llega a la SALIDA!"
			: String::Format(L"\u2192 Recupera {0} objeto(s) mas", total - rec);
		g->DrawString(objetivo, fNormal, oro, 420, 7);

		delete oro; delete rojo; delete gris;
		delete fNormal; delete fCorazon;
	}

	void FormControlJuego::dibujarMensaje(Graphics^ g) {
		if (mensajeTicks <= 0 || mensaje == nullptr)
			return;

		System::Drawing::Font^ f = gcnew System::Drawing::Font("Bahnschrift", 14, FontStyle::Bold);
		SizeF sz = g->MeasureString(mensaje, f, this->ClientSize.Width - 120);
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
}
