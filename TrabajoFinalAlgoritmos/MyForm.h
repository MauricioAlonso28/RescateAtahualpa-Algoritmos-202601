#pragma once
#include "FormInstrucciones.h"
#include "FormRanking.h"
#include "FormCreditos.h"
#include "FormSalir.h"

namespace TodoDelMenu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
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
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
		/// Variable del diseñador necesaria.
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
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();

			// Escalado
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;

			// Mejora visual
			this->DoubleBuffered = true;

			// Tamaño del formulario
			this->ClientSize = System::Drawing::Size(1366, 768);

			// No redimensionar
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;

			// Centrado
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;

			// Nombre y título
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

		// Fondo del menú
		this->BackgroundImage = Image::FromFile("img/pantallaMenuPrincipal.jpeg");
		this->BackgroundImageLayout = ImageLayout::Stretch; //Estira la imagen para el formulario

		// TÍTULO DEL JUEGO
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
		btnCreditos->Text = L"CRÉDITOS";
		btnSalir->Text = L"SALIR";

		// Tamaño
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
