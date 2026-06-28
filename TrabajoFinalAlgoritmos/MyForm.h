#pragma once
#include "FormInstrucciones.h"
#include "FormRanking.h"
#include "FormCreditos.h"
#include "FormSalir.h"
#include "FormNivel1.h"
#include "FormNivel2.h"
#include "FormHistoria.h"

namespace TodoDelMenu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
		Label^ lblTitulo;
		Button^ btnJugar;
		Button^ btnInstrucciones;
		Button^ btnRanking;
		Button^ btnCreditos;
		Button^ btnSalir;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();

			// Escalado
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;

			// Mejora visual
			this->DoubleBuffered = true;

			// Tama�o del formulario
			this->ClientSize = System::Drawing::Size(1366, 768);

			// No redimensionar
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;

			// Centrado
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;

			// Nombre y t�tulo
			this->Name = L"MyForm";
			this->Text = L"El Rescate de Atahualpa";

			// Fondo 
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);


			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->SuspendLayout();

		// Fondo del men�
		this->BackgroundImage = Image::FromFile("img/pantallaMenuPrincipal.jpeg");
		this->BackgroundImageLayout = ImageLayout::Stretch; //Estira la imagen para el formulario

		// T�TULO DEL JUEGO
		lblTitulo = gcnew Label();
		lblTitulo->Text = L"EL RESCATE DE ATAHUALPA";
		lblTitulo->Font = gcnew Drawing::Font("Bahnschrift", 42, FontStyle::Bold);

		// Color
		lblTitulo->ForeColor = Color::FromArgb(150, 75, 0);
		lblTitulo->BackColor = Color::Transparent;
		lblTitulo->AutoSize = true;
		lblTitulo->Location = Point(350, 80);

		// BOTONES

		btnJugar = gcnew Button();
		btnInstrucciones = gcnew Button();
		btnRanking = gcnew Button();
		btnCreditos = gcnew Button();
		btnSalir = gcnew Button();

		// Textos
		btnJugar->Text = L"JUGAR";
		btnInstrucciones->Text = L"INSTRUCCIONES";
		btnRanking->Text = L"RANKING";
		btnCreditos->Text = L"CREDITOS";
		btnSalir->Text = L"SALIR";

		// Tama�o
		btnJugar->Size = Drawing::Size(300, 50);
		btnInstrucciones->Size = Drawing::Size(300, 50);
		btnRanking->Size = Drawing::Size(300, 50);
		btnCreditos->Size = Drawing::Size(300, 50);
		btnSalir->Size = Drawing::Size(300, 50);

		// Posiciones
		btnJugar->Location = Point(530, 200);
		btnInstrucciones->Location = Point(530, 270);
		btnRanking->Location = Point(530, 340);
		btnCreditos->Location = Point(530, 410);
		btnSalir->Location = Point(530, 480);

		// Cambiamos el cursor al pasar por los botones
		btnJugar->Cursor = Cursors::Hand;
		btnInstrucciones->Cursor = Cursors::Hand;
		btnRanking->Cursor = Cursors::Hand;
		btnCreditos->Cursor = Cursors::Hand;
		btnSalir->Cursor = Cursors::Hand;

		//Interaccion con los otros formularios

		btnJugar->Click += gcnew EventHandler(this, &MyForm::btnJugar_Click);
		btnSalir->Click += gcnew EventHandler(this, &MyForm::btnSalir_Click);
		btnInstrucciones->Click += gcnew EventHandler(this, &MyForm::btnInstrucciones_Click);
		btnRanking->Click += gcnew EventHandler(this, &MyForm::btnRanking_Click);
		btnCreditos->Click += gcnew EventHandler(this, &MyForm::btnCreditos_Click);


		// Agregamos al formulario
		this->Controls->Add(lblTitulo);
		this->Controls->Add(btnJugar);
		this->Controls->Add(btnInstrucciones);
		this->Controls->Add(btnRanking);
		this->Controls->Add(btnCreditos);
		this->Controls->Add(btnSalir);
		this->ResumeLayout(false);
	}

	private:
		

		//Jugar

		System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e)
		{

			// Historia nivel 1

			List<String^>^ historia1 = gcnew List<String^>();

			historia1->Add("img/n1_historia1");
			historia1->Add("img/n1_historia2");
			historia1->Add("img/n1_historia3");
			historia1->Add("img/n1_historia4");
			historia1->Add("img/n1_historia5");

			this->Hide();

			Juego* juego = new Juego();
			/*
			
			
			
			
			FormHistoria^ intro1 = gcnew FormHistoria(historia1);
			intro1->ShowDialog();

			delete intro1;

			// Nivel 1

			TrabajoFinalAlgoritmos::FormNivel1^ nivel1 =
				gcnew TrabajoFinalAlgoritmos::FormNivel1(juego);

			nivel1->ShowDialog();

			delete nivel1;

			if (juego->getEstado() != EstadoJuego::Victoria)
			{
				delete juego;
				this->Show();
				return;
			}

			// Historia nivel 2

			List<String^>^ historia2 = gcnew List<String^>();

			historia2->Add("img/nivel2/n2_historia1");
			historia2->Add("img/nivel2/n2_historia2");
			historia2->Add("img/nivel2/n2_historia3");
			historia2->Add("img/nivel2/n2_historia4");
			historia2->Add("img/nivel2/n2_historia5");

			FormHistoria^ intro2 = gcnew FormHistoria(historia2);

			intro2->ShowDialog();

			delete intro2;

			*/
			// Nivel 2

			TrabajoFinalAlgoritmos::FormNivel2^ nivel2 =
				gcnew TrabajoFinalAlgoritmos::FormNivel2(juego);

			nivel2->ShowDialog();

			delete nivel2;

			if (juego->getEstado() != EstadoJuego::Victoria)
			{
				delete juego;
				this->Show();
				return;
			}

			// Historia nivel 3

			// Nivel 3

			delete juego;

			this->Show();
		}

		//Instrucciones

		System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e)
		{
			FormInstrucciones^ ventanaInstrucciones = gcnew FormInstrucciones(this);
			this->Hide();
			ventanaInstrucciones->ShowDialog();
			this->Show();
		}

		//Ranking

		System::Void btnRanking_Click(System::Object^ sender, System::EventArgs^ e)
		{
			FormRanking^ ventanaRanking = gcnew FormRanking(this);
			this->Hide();
			ventanaRanking->ShowDialog();
			this->Show();
		}

		//Creditos

		System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e)
		{
			FormCreditos^ ventanaCreditos = gcnew FormCreditos(this);
			this->Hide();
			ventanaCreditos->ShowDialog();
			this->Show();
		}

		//Salir


		System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e)
		{
			FormSalir^ ventanaSalir = gcnew FormSalir();

			this->Hide();

			ventanaSalir->ShowDialog();
		}



	};
}
