#pragma once
#include "MyForm.h"
namespace TodoDelMenu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PantallaCargaInicial
	/// </summary>
	public ref class PantallaCargaInicial : public System::Windows::Forms::Form
	{
	public:
		PantallaCargaInicial(void)
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
		~PantallaCargaInicial()
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
		Panel^ fondoBarra;
		Panel^ progresoBarra;
		Label^ lblCarga;
		Timer^ timerCarga;
		int progresoActual;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			{
				this->SuspendLayout();

				// Escalado
				this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;

				// Reduce parpadeos
				this->DoubleBuffered = true;

				// Tamaño del formulario
				this->ClientSize = System::Drawing::Size(1366, 768);

				// Evita que el usuario cambie el tamaño
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false;

				// Centrar el formulario
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;

				// Nombre interno
				this->Name = L"PantallaCargaInicial";

				// Texto que aparece en la barra superior
				this->Text = L"Pantalla de Carga";
				this->Load += gcnew System::EventHandler(this, &PantallaCargaInicial::PantallaCargaInicial_Load);
				this->ResumeLayout(false);
			}
		}
#pragma endregion

	private: System::Void PantallaCargaInicial_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->SuspendLayout();

		// Fondo de pantalla
		this->BackgroundImage = Image::FromFile("img/pantallaDeCarga.jpeg");

		// Ocupamos todo el espacio del formulario
		this->BackgroundImageLayout = ImageLayout::Stretch;

		// Texto de carga
		lblCarga = gcnew Label();
		lblCarga->Text = L"Cargando...";
		lblCarga->Font = gcnew Drawing::Font("Bahnschrift", 16, FontStyle::Bold);
		lblCarga->ForeColor = Color::Gold;
		lblCarga->BackColor = Color::Transparent;
		lblCarga->AutoSize = true;
		lblCarga->Location = Point(610, 620);

		// Fondo de la barra 
		fondoBarra = gcnew Panel();
		fondoBarra->Location = Point(383, 660);
		fondoBarra->Size = Drawing::Size(600, 30);
		fondoBarra->BackColor = Color::FromArgb(70, 50, 30);

		// Progreso 
		progresoBarra = gcnew Panel();
		progresoBarra->Location = Point(0, 0);
		progresoBarra->Size = Drawing::Size(0, 30);
		progresoBarra->BackColor = Color::FromArgb(212, 175, 55);

		fondoBarra->Controls->Add(progresoBarra);

		progresoActual = 0;

		// los controladores del formulario
		this->Controls->Add(lblCarga);
		this->Controls->Add(fondoBarra);

		// Timer de carga
		timerCarga = gcnew Timer();
		timerCarga->Interval = 50; // 5 segundos    porque es 100 x 50 ms, para ver si despues cambiamos
		timerCarga->Tick += gcnew EventHandler(this, &PantallaCargaInicial::timerCarga_Tick);
		timerCarga->Start();


		this->ResumeLayout(false);
	}
	private: System::Void timerCarga_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		if (progresoActual < 600)
		{
			progresoActual += 12;

			if (progresoActual > 600)
				progresoActual = 600;

			progresoBarra->Width = progresoActual;
		}
		else
		{
			timerCarga->Stop();

			this->Hide();

			MyForm^ menuPrincipal = gcnew MyForm();

			menuPrincipal->ShowDialog();

			this->Close();
		}
	}

	};


}
