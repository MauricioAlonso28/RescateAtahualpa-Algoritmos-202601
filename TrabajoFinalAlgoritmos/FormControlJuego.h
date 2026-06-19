#pragma once

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Juego;

	// Form base de la pantalla de juego: HUD, bucle (timer) y entrada por teclado.
	// cargarNivel() y mostrarPreguntaReflexiva() son virtuales (polimorfismo).
	public ref class FormControlJuego : public System::Windows::Forms::Form
	{
	private:
		Juego^ juego;
		System::Windows::Forms::Timer^ timerJuego;
		Label^ lblVidas;
		Label^ lblPuntaje;
		Label^ lblObjetos;
		System::ComponentModel::Container^ components;

	public:
		FormControlJuego(Juego^ j)
		{
			this->juego = j;
			InitializeComponent();
		}

		virtual void cargarNivel();
		virtual void mostrarPreguntaReflexiva();
		void actualizarHUD();
		Juego^ getJuego();

	protected:
		~FormControlJuego()
		{
			if (components)
			{
				delete components;
			}
		}

		void timerJuego_Tick(Object^ sender, EventArgs^ e);
		void form_KeyDown(Object^ sender, KeyEventArgs^ e);
		void form_Paint(Object^ sender, PaintEventArgs^ e);

	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->lblVidas = gcnew Label();
			this->lblPuntaje = gcnew Label();
			this->lblObjetos = gcnew Label();
			this->timerJuego = gcnew System::Windows::Forms::Timer(this->components);
			this->SuspendLayout();
			//
			// lblVidas
			//
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(12, 9);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Text = L"Vidas: 3";
			//
			// lblPuntaje
			//
			this->lblPuntaje->AutoSize = true;
			this->lblPuntaje->Location = System::Drawing::Point(12, 30);
			this->lblPuntaje->Name = L"lblPuntaje";
			this->lblPuntaje->Text = L"Puntaje: 0";
			//
			// lblObjetos
			//
			this->lblObjetos->AutoSize = true;
			this->lblObjetos->Location = System::Drawing::Point(12, 51);
			this->lblObjetos->Name = L"lblObjetos";
			this->lblObjetos->Text = L"Objetos: 0";
			//
			// timerJuego
			//
			this->timerJuego->Interval = 30;
			this->timerJuego->Tick += gcnew System::EventHandler(this, &FormControlJuego::timerJuego_Tick);
			//
			// FormControlJuego
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 600);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->lblPuntaje);
			this->Controls->Add(this->lblObjetos);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Name = L"FormControlJuego";
			this->Text = L"Cusi";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormControlJuego::form_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormControlJuego::form_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	};
}
