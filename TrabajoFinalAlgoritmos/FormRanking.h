#pragma once

namespace TodoDelMenu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormRanking
	/// </summary>
	public ref class FormRanking : public System::Windows::Forms::Form
	{
	public:
		FormRanking(Form^ menu)
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
		~FormRanking()
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
			this->Name = L"Pantalla Ranking";
			this->Text = L"Ranking";

			// Fondo 
			this->Load += gcnew System::EventHandler(this, &FormRanking::FormRanking_Load);


			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormRanking_Load(System::Object^ sender, System::EventArgs^ e) {
		// Fondo de pantalla
		this->BackgroundImage = Image::FromFile("img/pantallaRanking.png");

		// Ocupamos todo el espacio del formulario
		this->BackgroundImageLayout = ImageLayout::Stretch;

		//Creamos los botones
		btnVolver = gcnew Button();

		//Texto de los botones
		btnVolver->Text = L"VOLVER";
		//btnVolver->BackColor = Color::Red;

		//Posiciones
		btnVolver->Location = Point(1050, 695);

		//Tamanos
		btnVolver->Size = Drawing::Size(300, 60);

		//Cambiar Cursor al pasar por los botones y interracion con el menu
		btnVolver->Cursor = Cursors::Hand;
		btnVolver->Click += gcnew EventHandler(this, &FormRanking::btnVolver_Click);

		//Aparicion de los botones y textos
		this->Controls->Add(btnVolver);



	}

	private:
		System::Void btnVolver_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			menuPrincipal->Show();

			this->Close();
		}

	};
}
