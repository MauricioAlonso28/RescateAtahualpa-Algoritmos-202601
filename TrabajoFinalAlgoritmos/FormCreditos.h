#pragma once

namespace TodoDelMenu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormCreditos
	/// </summary>
	public ref class FormCreditos : public System::Windows::Forms::Form
	{
	public:
		FormCreditos(Form^ menu)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			menuPrincipal = menu;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormCreditos()
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
		Form^ menuPrincipal;
		Button^ btnVolver;

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
			this->Name = L"Pantalla Creditos";
			this->Text = L"Creditos";

			// Fondo 
			this->Load += gcnew System::EventHandler(this, &FormCreditos::FormCreditos_Load);


			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormCreditos_Load(System::Object^ sender, System::EventArgs^ e) {

		// Fondo de pantalla
		this->BackgroundImage = Image::FromFile("img/pantallaCreditos.jpeg");

		// Ocupamos todo el espacio del formulario
		this->BackgroundImageLayout = ImageLayout::Stretch;

		// Crear botón
		btnVolver = gcnew Button();

		// Texto
		btnVolver->Text = L"VOLVER";

		// Tamaño
		btnVolver->Size = Drawing::Size(300, 60);

		// Posición
		btnVolver->Location = Point(550, 690);

		// Cursor
		btnVolver->Cursor = Cursors::Hand;
		btnVolver->Click += gcnew EventHandler(this, &FormCreditos::btnVolver_Click);

		// Mostrar botón
		this->Controls->Add(btnVolver);
	}

	private:
		System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Hide();
			menuPrincipal->Show();
			this->Close();
		}

	};
}
