#pragma once

namespace TodoDelMenu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormSalir
	/// </summary>
	public ref class FormSalir : public System::Windows::Forms::Form
	{
	public:
		FormSalir(void)
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
		~FormSalir()
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
		Timer^ timerSalida;

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
			this->Name = L"Pantalla Salir";
			this->Text = L"Salir";

			// Fondo 
			this->Load += gcnew System::EventHandler(this, &FormSalir::FormSalir_Load);
			this->FormClosing += gcnew FormClosingEventHandler(this, &FormSalir::FormSalir_FormClosing);

			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormSalir_Load(System::Object^ sender, System::EventArgs^ e) {

		// Fondo de pantalla
		this->BackgroundImage = Image::FromFile("img/pantallaSalir.jpeg");

		// Ocupamos todo el espacio del formulario
		this->BackgroundImageLayout = ImageLayout::Stretch;

		timerSalida = gcnew Timer();
		timerSalida->Interval = 3000; // 3 segundos
		timerSalida->Tick += gcnew EventHandler(this, &FormSalir::timerSalida_Tick);
		timerSalida->Start();

	}

	private: System::Void timerSalida_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		timerSalida->Stop();

		Application::Exit();
	}
	private: System::Void FormSalir_FormClosing(System::Object^ sender, FormClosingEventArgs^ e)
	{
		Application::Exit();
	}

	};
}
