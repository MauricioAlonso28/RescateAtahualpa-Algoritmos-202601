#pragma once
#include "Juego.h"
#include "Config.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormControlJuego : public System::Windows::Forms::Form
	{
	protected:
		Juego* juego;
		Nivel* nivel;
		String^ mensaje;
		int mensajeTicks;
		bool perdioVida;
		bool nivelTerminado;

	private:
		System::Windows::Forms::Timer^ timerJuego;
		System::ComponentModel::Container^ components;

	public:
		FormControlJuego(Juego* j)
		{
			this->juego = j;
			this->nivel = nullptr;
			this->mensaje = nullptr;
			this->mensajeTicks = 0;
			this->perdioVida = false;
			this->nivelTerminado = false;
			InitializeComponent();
		}

		virtual void cargarNivel();
		virtual void mostrarPreguntaReflexiva();
		void actualizarHUD();
		void mostrarMensaje(String^ texto, int ticks);
		Juego* getJuego();

	protected:
		~FormControlJuego()
		{
			if (nivel != nullptr) { delete nivel; nivel = nullptr; }
			if (components)
			{
				delete components;
			}
		}

		void timerJuego_Tick(Object^ sender, EventArgs^ e);
		void form_KeyDown(Object^ sender, KeyEventArgs^ e);
		void form_KeyUp(Object^ sender, KeyEventArgs^ e);
		void form_Paint(Object^ sender, PaintEventArgs^ e);
		void form_Load(Object^ sender, EventArgs^ e);
		void dibujarHUD(Graphics^ g);
		void dibujarPuerta(Graphics^ g);
		void dibujarMensaje(Graphics^ g);
		void finalizarNivel(bool gano);

	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->timerJuego = gcnew System::Windows::Forms::Timer(this->components);
			this->SuspendLayout();

			this->timerJuego->Interval = 30;
			this->timerJuego->Tick += gcnew System::EventHandler(this, &FormControlJuego::timerJuego_Tick);

			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(NIVEL_ANCHO, NIVEL_ALTO);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->KeyPreview = true;
			this->Name = L"FormControlJuego";
			this->Text = L"El Rescate de Atahualpa";
			this->Load += gcnew System::EventHandler(this, &FormControlJuego::form_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormControlJuego::form_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormControlJuego::form_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormControlJuego::form_KeyUp);
			this->ResumeLayout(false);
		}
#pragma endregion
	};
}
