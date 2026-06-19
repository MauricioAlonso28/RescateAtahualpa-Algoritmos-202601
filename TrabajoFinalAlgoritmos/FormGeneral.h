#pragma once

namespace TrabajoFinalAlgoritmos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Juego;
	ref class FormNivel1;
	ref class FormNivel2;
	ref class FormNivel3;

	// Menu principal del juego (jugar, instrucciones, creditos, ranking, salir).
	public ref class FormGeneral : public System::Windows::Forms::Form
	{
	private:
		Juego^ juego;
		Button^ btnJugar;
		Button^ btnInstrucciones;
		Button^ btnCreditos;
		Button^ btnRanking;
		Button^ btnSalir;
		TextBox^ txtNombreJugador;
		Bitmap^ fondoMenu;
		System::ComponentModel::Container^ components;

	public:
		FormGeneral(void)
		{
			InitializeComponent();
		}

		void iniciarPartida();
		void mostrarCinematicaIntro();
		void mostrarInstrucciones();
		void mostrarCreditos();
		void mostrarRanking();
		void mostrarPantallaFinal(bool gano);
		Juego^ getJuego();

	protected:
		~FormGeneral()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->txtNombreJugador = gcnew TextBox();
			this->btnJugar = gcnew Button();
			this->btnInstrucciones = gcnew Button();
			this->btnCreditos = gcnew Button();
			this->btnRanking = gcnew Button();
			this->btnSalir = gcnew Button();
			this->SuspendLayout();
			//
			// txtNombreJugador
			//
			this->txtNombreJugador->Location = System::Drawing::Point(300, 110);
			this->txtNombreJugador->Name = L"txtNombreJugador";
			this->txtNombreJugador->Size = System::Drawing::Size(200, 23);
			//
			// btnJugar
			//
			this->btnJugar->Location = System::Drawing::Point(300, 150);
			this->btnJugar->Size = System::Drawing::Size(200, 35);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Text = L"Jugar";
			//
			// btnInstrucciones
			//
			this->btnInstrucciones->Location = System::Drawing::Point(300, 195);
			this->btnInstrucciones->Size = System::Drawing::Size(200, 35);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Text = L"Instrucciones";
			//
			// btnCreditos
			//
			this->btnCreditos->Location = System::Drawing::Point(300, 240);
			this->btnCreditos->Size = System::Drawing::Size(200, 35);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Text = L"Creditos";
			//
			// btnRanking
			//
			this->btnRanking->Location = System::Drawing::Point(300, 285);
			this->btnRanking->Size = System::Drawing::Size(200, 35);
			this->btnRanking->Name = L"btnRanking";
			this->btnRanking->Text = L"Ranking";
			//
			// btnSalir
			//
			this->btnSalir->Location = System::Drawing::Point(300, 330);
			this->btnSalir->Size = System::Drawing::Size(200, 35);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Text = L"Salir";
			//
			// FormGeneral
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 600);
			this->Controls->Add(this->txtNombreJugador);
			this->Controls->Add(this->btnJugar);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnRanking);
			this->Controls->Add(this->btnSalir);
			this->Name = L"FormGeneral";
			this->Text = L"Cusi - Menu principal";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	};
}
