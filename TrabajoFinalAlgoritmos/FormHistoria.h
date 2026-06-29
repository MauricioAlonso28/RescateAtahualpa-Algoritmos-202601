#pragma once

namespace TodoDelMenu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

    public enum class PosTexto { Inferior, Superior, SoloTexto, SoloTextoCursiva, Titulo};

	// Muestra una secuencia de imagenes (storyboard) y se cierra al terminar.
	// Avanza con cualquier tecla o con click.
	public ref class FormHistoria : public System::Windows::Forms::Form
	{
	private:
		System::ComponentModel::Container^ components;
		List<String^>^ imagenes;
		List<String^>^ textos;
        List<PosTexto>^ posiciones;
		int indice;

		// Typewriter
		String^ textoCompleto;
		String^ textoVisible;
		int charActual;
		Timer^ timerTyping;
		Label^ lblContinuar;

        Image^ imagenActual;

	public:
		FormHistoria(List<String^>^ imgs, List<String^>^ txts, List<PosTexto>^ pos)
		{
			imagenes = imgs;
			textos = txts;
			posiciones = pos;
			indice = 0;
			textoCompleto = "";
			textoVisible = "";
			charActual = 0;
			imagenActual = nullptr;
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
            this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormHistoria::FormHistoria_Paint);
            this->ResumeLayout(false);
        }
#pragma endregion

		// Dado un nombre base sin extension, busca el archivo probando extensiones comunes.
        String^ resolverRuta(String^ base)
        {
            if (base == nullptr) return nullptr;
            List<String^>^ exts = gcnew List<String^>();
            exts->Add(".jpg");
            exts->Add(".jpeg");
            exts->Add(".png");
            exts->Add(".bmp");
            for each (String ^ ext in exts)
                if (System::IO::File::Exists(base + ext))
                    return base + ext;
            return nullptr;
        }

		void iniciarDiapositiva()
		{
			// Imagen (nullptr = pantalla negra)
			imagenActual = nullptr;
			this->BackgroundImage = nullptr;
			if (indice < imagenes->Count && imagenes[indice] != nullptr)
			{
				String^ ruta = resolverRuta(imagenes[indice]);
				if (ruta != nullptr)
					imagenActual = Image::FromFile(ruta);
			}

			// Texto
			textoCompleto = (textos != nullptr && indice < textos->Count)
				? textos[indice] : "";
			textoVisible = "";
			charActual = 0;

			lblContinuar->Visible = false;

			if (textoCompleto->Length > 0)
				timerTyping->Start();
			else
				lblContinuar->Visible = true;

			this->Invalidate();
		}

		void accionAvanzar()
		{
			if (charActual < textoCompleto->Length)
			{
				timerTyping->Stop();
				textoVisible = textoCompleto;
				charActual = textoCompleto->Length;
				lblContinuar->Visible = true;
				this->Invalidate();
			}
			else
			{
				indice++;
				if (indice >= posiciones->Count)
					this->Close();
				else
					iniciarDiapositiva();
			}
		}

		System::Void FormHistoria_Load(System::Object^ sender, System::EventArgs^ e)
		{
			lblContinuar = gcnew Label();
			lblContinuar->Text = L"[ Presiona ESPACIO ]";
			lblContinuar->Font = gcnew Drawing::Font("Bahnschrift", 11, FontStyle::Italic);
			lblContinuar->ForeColor = Color::FromArgb(200, 212, 175, 55);
			lblContinuar->BackColor = Color::Transparent;
			lblContinuar->AutoSize = true;
			lblContinuar->Location = Point(950, 724);
			lblContinuar->Visible = false;
			this->Controls->Add(lblContinuar);

			timerTyping = gcnew Timer();
			timerTyping->Interval = 35;
			timerTyping->Tick += gcnew EventHandler(this, &FormHistoria::timerTyping_Tick);

			iniciarDiapositiva();
		}

		System::Void timerTyping_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			if (charActual < textoCompleto->Length)
			{
				charActual++;
				textoVisible = textoCompleto->Substring(0, charActual);
				this->Invalidate();
			}
			else
			{
				timerTyping->Stop();
				lblContinuar->Visible = true;
				this->Invalidate();
			}
		}

		System::Void FormHistoria_Paint(System::Object^ sender,
			System::Windows::Forms::PaintEventArgs^ e)
		{
			Graphics^ g = e->Graphics;
			int W = this->ClientSize.Width;
			int H = this->ClientSize.Height;

			// Dibujar imagen si hay una
			if (imagenActual != nullptr)
				g->DrawImage(imagenActual, 0, 0, W, H);

			if (textoVisible == nullptr || textoVisible->Length == 0)
				return;

			PosTexto pos = posiciones[indice];

			// Caso 0: título grande rojo centrado
			if (pos == PosTexto::Titulo)
			{
				System::Drawing::Font^ fuente = gcnew System::Drawing::Font(
					"Bahnschrift", 48.0f, FontStyle::Bold);
				SolidBrush^ pincel = gcnew SolidBrush(Color::FromArgb(220, 60, 0));

				SizeF sz = g->MeasureString(textoVisible, fuente,
					System::Drawing::Size(W - 160, H - 80));
				RectangleF area(
					(float)80,
					(float)((H - sz.Height) / 2.0f),
					(float)(W - 160),
					(float)(H - 80));
				g->DrawString(textoVisible, fuente, pincel, area);

				delete pincel; delete fuente;
				return;
			}

			// Caso 1: solo texto centrado en negro
			if (pos == PosTexto::SoloTexto || pos == PosTexto::SoloTextoCursiva)
			{
				bool cursiva = (pos == PosTexto::SoloTextoCursiva);
				System::Drawing::Font^ fuente = gcnew System::Drawing::Font(
					"Bahnschrift",
					cursiva ? 30.0f : 16.0f,
					cursiva ? FontStyle::Italic : FontStyle::Regular);
				SolidBrush^ pincel = gcnew SolidBrush(Color::White);

				// Centrar verticalmente
				SizeF sz = g->MeasureString(textoVisible, fuente,
					System::Drawing::Size(W - 160, H - 80));
				RectangleF area(
					(float)80,
					(float)((H - sz.Height) / 2.0f),
					(float)(W - 160),
					(float)(H - 80));
				g->DrawString(textoVisible, fuente, pincel, area);

				delete pincel; delete fuente;
				return;
			}

			// Caso 2: caja sobre imagen (Inferior o Superior)
			bool esInferior = (pos == PosTexto::Inferior);
			int boxH = 130;
			int boxY = esInferior ? (H - boxH - 10) : 10;

			SolidBrush^ fondoCaja = gcnew SolidBrush(Color::FromArgb(200, 20, 12, 5));
			Pen^ borde = gcnew Pen(Color::FromArgb(220, 212, 175, 55), 2);
			g->FillRectangle(fondoCaja, 40, boxY, W - 80, boxH);
			g->DrawRectangle(borde, 40, boxY, W - 80, boxH);
			delete fondoCaja; delete borde;

			System::Drawing::Font^ fuente = gcnew System::Drawing::Font(
				"Bahnschrift", 13, FontStyle::Regular);
			SolidBrush^ pincel = gcnew SolidBrush(Color::White);
			RectangleF area(
				(float)(40 + 18),
				(float)(boxY + 14),
				(float)(W - 80 - 36),
				(float)(boxH - 28));
			g->DrawString(textoVisible, fuente, pincel, area);
			delete pincel; delete fuente;
		}

		System::Void FormHistoria_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode == Keys::Space)
				accionAvanzar();
		}

		System::Void FormHistoria_Click(System::Object^ sender, System::EventArgs^ e)
		{
			accionAvanzar();
		}
	};
}