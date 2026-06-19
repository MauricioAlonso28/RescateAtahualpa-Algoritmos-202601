#pragma once

namespace TodoDelMenu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormInstrucciones
	/// </summary>
	public ref class FormInstrucciones : public System::Windows::Forms::Form
	{
	public:
		FormInstrucciones(Form^ menu)
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
		~FormInstrucciones()
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
			this->Name = L"Pantalla Instrucciones";
			this->Text = L"Instrucciones";

			// Fondo 
			this->Load += gcnew System::EventHandler(this, &FormInstrucciones::FormInstrucciones_Load);


			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormInstrucciones_Load(System::Object^ sender, System::EventArgs^ e) {

		// Fondo de pantalla
		this->BackgroundImage = Image::FromFile("img/pantallaInstrucciones.png");

		// Ocupamos todo el espacio del formulario
		this->BackgroundImageLayout = ImageLayout::Stretch;

		//Creamos boton de volver al menu
		btnVolver = gcnew Button();

		//Texto al boton
		btnVolver->Text = L"VOLVER";

		//Posicion del boton 
		btnVolver->Location = Point(1050, 695);

		//Tamano
		btnVolver->Size = Drawing::Size(300, 60);

		//Cambiar el cursor al pasar por encima e interracion con el menu
		btnVolver->Cursor = Cursors::Hand;
		btnVolver->Click += gcnew EventHandler(this, &FormInstrucciones::btnVolver_Click);

		//Aparicion de los botones y textos
		this->Controls->Add(btnVolver);

	}
	private: 
		System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e)
		{
			menuPrincipal->Show();
			this->Close();
		}

	};
}
