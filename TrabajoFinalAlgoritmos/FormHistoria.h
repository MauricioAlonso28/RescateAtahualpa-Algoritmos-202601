#pragma once

namespace TodoDelMenu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	// Muestra una secuencia de imagenes (storyboard) y se cierra al terminar.
	// Avanza con cualquier tecla o con click.
	public ref class FormHistoria : public System::Windows::Forms::Form
	{
	private:
		System::ComponentModel::Container^ components;
		List<String^>^ imagenes;
		int indice;

	public:
		FormHistoria(List<String^>^ imgs)
		{
			imagenes = imgs;
			indice = 0;
			InitializeComponent();
		}

	protected:
		~FormHistoria()
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
			this->SuspendLayout();
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->DoubleBuffered = true;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->KeyPreview = true;
			this->Name = L"FormHistoria";
			this->Text = L"El Rescate de Atahualpa";
			this->Load += gcnew System::EventHandler(this, &FormHistoria::FormHistoria_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormHistoria::FormHistoria_KeyDown);
			this->Click += gcnew System::EventHandler(this, &FormHistoria::FormHistoria_Click);
			this->ResumeLayout(false);
		}
#pragma endregion

		// Dado un nombre base sin extension, busca el archivo probando extensiones comunes.
		String^ resolverRuta(String^ base)
		{
			List<String^>^ exts = gcnew List<String^>();
			exts->Add(".jpg");
			exts->Add(".jpeg");
			exts->Add(".png");
			exts->Add(".bmp");
			for each (String ^ ext in exts)
			{
				if (System::IO::File::Exists(base + ext))
					return base + ext;
			}
			return nullptr;
		}

		void mostrarImagen()
		{
			if (indice >= 0 && indice < imagenes->Count)
			{
				String^ ruta = resolverRuta(imagenes[indice]);
				if (ruta != nullptr)
				{
					this->BackgroundImage = Image::FromFile(ruta);
					this->BackgroundImageLayout = ImageLayout::Stretch;
				}
				else
				{
					this->BackgroundImage = nullptr;
				}
			}
		}

		void avanzar()
		{
			indice++;
			if (indice >= imagenes->Count)
			{
				this->Close();
			}
			else
			{
				mostrarImagen();
			}
		}

		System::Void FormHistoria_Load(System::Object^ sender, System::EventArgs^ e)
		{
			mostrarImagen();
		}

		System::Void FormHistoria_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			avanzar();
		}

		System::Void FormHistoria_Click(System::Object^ sender, System::EventArgs^ e)
		{
			avanzar();
		}
	};
}
