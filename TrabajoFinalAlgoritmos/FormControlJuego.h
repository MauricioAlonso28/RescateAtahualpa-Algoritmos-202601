#pragma once
#include "Juego.h"

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormControlJuego : public System::Windows::Forms::Form
	{
	private:
		Juego* juego;
		System::Windows::Forms::Timer^ timerJuego;
		Label^ lblVidas;
		Label^ lblPuntaje;
		Label^ lblObjetos;
		System::ComponentModel::Container^ components;

	public:
		FormControlJuego(Juego* j)
		{
			this->juego = j;
			InitializeComponent();
		}

		virtual void cargarNivel();
		virtual void mostrarPreguntaReflexiva();
		void actualizarHUD();
		Juego* getJuego();

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
			this->timerJuego = gcnew System::Windows::Forms::Timer(this->components);
			this->SuspendLayout();

			this->timerJuego->Interval = 30;
			this->timerJuego->Tick += gcnew System::EventHandler(this, &FormControlJuego::timerJuego_Tick);

			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 600);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Name = L"FormControlJuego";
			this->Text = L"Cusi";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormControlJuego::form_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormControlJuego::form_KeyDown);
			this->ResumeLayout(false);
		}
#pragma endregion
	};
}
