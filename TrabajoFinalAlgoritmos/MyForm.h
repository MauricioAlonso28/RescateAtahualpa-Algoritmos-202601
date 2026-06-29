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
		/// Método necesario para admitir el Dise�ador. No se puede modificar
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
		btnCreditos->Text = L"CR\u00c9DITOS";
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
			// Historia del Nivel 1

			List<String^>^ historia1 = gcnew List<String^>();
			historia1->Add(nullptr);
			//historia1->Add("img/n1_historia1");
			historia1->Add(nullptr);
			//historia1->Add("img/n1_historia2");
			historia1->Add(nullptr);
			//historia1->Add("img/n1_historia3");
			historia1->Add("img/n1_historia3_op2");
			//historia1->Add("img/n1_historia4");
			historia1->Add("img/n1_historia4_op2");
			historia1->Add("img/n1_historia5");

			// cinemática nivel 1
			List<String^>^ textos1 = gcnew List<String^>();
			textos1->Add(
				"Cajamarca, noviembre de 1532. El Sapa Inca Atahualpa ha sido capturado. "
				"Los espa\u00f1oles exigen un rescate inmenso: llenar un cuarto entero de oro y plata. "
				"El Imperio tiembla. Los chasquis, mensajeros del viento, son los \u00fanicos que pueden "
				"llegar a los cuatro suyos a tiempo. T\u00fa eres Cusi. Y el Imperio te necesita.");
			textos1->Add("NIVEL 1: El Camino del Chinchaysuyo");
			textos1->Add(
				"\u00bfPuede un mensaje cambiar el destino de un pueblo?");
			textos1->Add(
				"Tras la captura de Atahualpa, el Tahuantinsuyo atraviesa momentos de incertidumbre. "
				"Cusi, un joven chasqui, recibe una misi\u00f3n crucial: recorrer el Qhapaq \u00d1an hacia el norte, "
				"llevar el mensaje a los curacas aliados y recuperar los objetos ceremoniales que representan "
				"la memoria y el legado de su pueblo antes de que desaparezcan para siempre.");
			textos1->Add(
				"Cusi ha llegado al Chinchaysuyo. El curaca local le indica la ubicaci\u00f3n de tres objetos "
				"ceremoniales en peligro. Recupera la m\u00e1scara de oro, el textil ceremonial y la vasija ritual "
				"mientras evitas a los soldados espa\u00f1oles que patrullan la regi\u00f3n.");

			List<TodoDelMenu::PosTexto>^ posiciones1 = gcnew List<TodoDelMenu::PosTexto>();
			posiciones1->Add(TodoDelMenu::PosTexto::SoloTexto);
			posiciones1->Add(TodoDelMenu::PosTexto::Titulo);
			posiciones1->Add(TodoDelMenu::PosTexto::SoloTextoCursiva);
			posiciones1->Add(TodoDelMenu::PosTexto::Inferior);
			posiciones1->Add(TodoDelMenu::PosTexto::Superior);

			this->Hide();

			TodoDelMenu::FormHistoria^ intro1 =
				gcnew TodoDelMenu::FormHistoria(historia1, textos1, posiciones1);
			intro1->ShowDialog();

			// Escenario jugable
			Juego* juego = new Juego();
			TrabajoFinalAlgoritmos::FormNivel1^ nivel1 =
				gcnew TrabajoFinalAlgoritmos::FormNivel1(juego);
			nivel1->ShowDialog();
			delete nivel1;

			// post nivel 1
			if (juego->getEstado() == EstadoJuego::Derrota) {
				List<String^>^ imgs_lost1 = gcnew List<String^>();
				imgs_lost1->Add("img/escenario_lost");

				// escenario YOU LOST *************************
				List<String^>^ txts_lost1 = gcnew List<String^>();
				txts_lost1->Add(
					"Cusi no logr\u00f3 recuperar los objetos ceremoniales a tiempo. "
					"Los soldados espa\u00f1oles tomaron las ofrendas sagradas del Chinchaysuyo "
					"y muchas fueron fundidas para convertirse en oro sin historia ni memoria.\n"
					"El mensaje no lleg\u00f3 completo a los curacas aliados, y parte del conocimiento "
					"del Tahuantinsuyo comenz\u00f3 a desaparecer en los caminos del norte.");

				List<TodoDelMenu::PosTexto>^ pos_lost1 = gcnew List<TodoDelMenu::PosTexto>();
				pos_lost1->Add(TodoDelMenu::PosTexto::Inferior);

				TodoDelMenu::FormHistoria^ lost1 =
					gcnew TodoDelMenu::FormHistoria(imgs_lost1, txts_lost1, pos_lost1);
				lost1->ShowDialog();

				delete juego;
				this->Show();
				return;
			}

			// escenario YOU WIN 
			List<String^>^ imgs_win1 = gcnew List<String^>();
			imgs_win1->Add("img/escenario_win");

			List<String^>^ txts_win1 = gcnew List<String^>();
			txts_win1->Add(
				"Los objetos ceremoniales han sido recuperados. La m\u00e1scara de oro, el textil sagrado "
				"y la vasija ritual vuelven a estar bajo resguardo antes de caer en manos de los invasores. "
				"El curaca del Chinchaysuyo reconoce el valor de Cusi y confirma que el mensaje podr\u00e1 "
				"continuar su recorrido hacia el Collasuyo.\n"
				"Pero los soldados espa\u00f1oles contin\u00faan patrullando los caminos del Qhapaq \u00d1an. "
				"Cada objeto salvado preserva una parte de la memoria del Tahuantinsuyo, "
				"y las alturas del sur esconden desaf\u00edos a\u00fan m\u00e1s peligrosos.");

			List<TodoDelMenu::PosTexto>^ pos_win1 = gcnew List<TodoDelMenu::PosTexto>();
			pos_win1->Add(TodoDelMenu::PosTexto::Inferior);

			TodoDelMenu::FormHistoria^ win1 =
				gcnew TodoDelMenu::FormHistoria(imgs_win1, txts_win1, pos_win1);
			win1->ShowDialog();

			// Historia del Nivel 2 (storyboard)
			List<String^>^ historia2 = gcnew List<String^>();
			historia2->Add(nullptr);
			historia2->Add(nullptr);
			historia2->Add("img/nivel2/n2_historia1");
			historia2->Add("img/nivel2/n2_historia2");

			List<String^>^ textos2 = gcnew List<String^>();
			textos2->Add("NIVEL 2: Los Pasos del Collasuyo");
			textos2->Add(
				"\u00bfQu\u00e9 se pierde cuando desaparece un objeto que nadie sabe que exist\u00eda?");
			textos2->Add(
				"Con el Chinchaysuyo informado, Cusi contin\u00faa su viaje hacia el Collasuyo. "
				"En las alturas del sur, el fr\u00edo endurece los caminos y la desconfianza divide a los pueblos. "
				"Los fragmentos del quipu sagrado fueron ocultados para proteger el conocimiento del Imperio, "
				"pero separados pierden su significado.\n"
				"Ahora Cusi deber\u00e1 reunir los fragmentos dispersos, ganarse la confianza de los chasquis "
				"aliados y atravesar las puertas de piedra antes de que los invasores encuentren "
				"el conocimiento oculto del Tahuantinsuyo.");
			textos2->Add(
				"Cusi ha llegado al Collasuyo. "
				"Rimaq y Wayra, dos chasquis aliados, desconf\u00edan de cualquier "
				"mensajero desconocido y solo ayudar\u00e1n a quien demuestre ser digno de su confianza. "
				"Recupera los tres fragmentos del quipu, consigue la ayuda de ambos para abrir las puertas "
				"de piedra y evita a los soldados espa\u00f1oles que patrullan los caminos del altiplano."
			);
			textos2->Add("");   // n2_historia4 se usa al TERMINAR el nivel, no al inicio

			List<TodoDelMenu::PosTexto>^ posiciones2 = gcnew List<TodoDelMenu::PosTexto>();
			posiciones2->Add(TodoDelMenu::PosTexto::Titulo);
			posiciones2->Add(TodoDelMenu::PosTexto::SoloTextoCursiva);
			posiciones2->Add(TodoDelMenu::PosTexto::Inferior);
			posiciones2->Add(TodoDelMenu::PosTexto::Inferior);

			//introduccion nivel 2
			TodoDelMenu::FormHistoria^ intro2 =
				gcnew TodoDelMenu::FormHistoria(historia2, textos2, posiciones2);
			intro2->ShowDialog();
			delete intro2;

			// Nivel 2 jugable
			Juego* juego2 = new Juego();
			juego2->getJugador()->setVidas(juego->getJugador()->getVidas());   // conserva vidas
			juego2->getJugador()->setPuntaje(juego->getJugador()->getPuntaje()); // conserva puntaje
			TrabajoFinalAlgoritmos::FormNivel2^ nivel2 =
				gcnew TrabajoFinalAlgoritmos::FormNivel2(juego2);
			nivel2->ShowDialog();
			delete nivel2;

			// post nivel 2
			if (juego2->getEstado() == EstadoJuego::Derrota)
			{

				// escenario YOU LOST
				List<String^>^ imgs_lost2 = gcnew List<String^>();
				//imgs_cierre->Add("img/n2_historia4_op2");
				imgs_lost2->Add("img/escenario_lost");
			
				List<String^>^ txts_lost2 = gcnew List<String^>();
				txts_lost2->Add(
					"Los fragmentos del quipu han sido reunidos. Lo que antes era solo un conjunto "
					"de hilos dispersos vuelve a contener la memoria del Imperio. Rimaq y Wayra reconocen "
					"a Cusi como un verdadero mensajero del Tahuantinsuyo y le abren el paso hacia el "
					"siguiente territorio.\n"
					"Pero mientras el conocimiento recupera su forma, las patrullas espa\u00f1olas avanzan "
					"cada vez m\u00e1s cerca. El tiempo se agota, y el camino hacia el Antisuyo "
					"ser\u00e1 a\u00fan m\u00e1s peligroso.");

				List<TodoDelMenu::PosTexto>^ pos_lost2 = gcnew List<TodoDelMenu::PosTexto>();
				pos_lost2->Add(TodoDelMenu::PosTexto::Inferior);

				TodoDelMenu::FormHistoria^ lost2 =
					gcnew TodoDelMenu::FormHistoria(imgs_lost2, txts_lost2, pos_lost2);
				lost2->ShowDialog();

				delete juego;
				delete juego2;
				this->Show();
				return;
			}

			// escenario YOU WIN
			List<String^>^ imgs_win2 = gcnew List<String^>();
			imgs_win2->Add("img/escenario_win");

			List<String^>^ txts_win2 = gcnew List<String^>();
			txts_win2->Add(
				"Los fragmentos del quipu han sido reunidos. Lo que antes era solo un conjunto "
				"de hilos dispersos vuelve a contener la memoria del Imperio. Rimaq y Wayra reconocen "
				"a Cusi como un verdadero mensajero del Tahuantinsuyo y le abren el paso "
				"hacia el siguiente territorio.\n"
				"Pero mientras el conocimiento recupera su forma, las patrullas espa\u00f1olas avanzan "
				"cada vez m\u00e1s cerca. El tiempo se agota, y el camino hacia el Antisuyo "
				"ser\u00e1 a\u00fan m\u00e1s peligroso.");

			List<TodoDelMenu::PosTexto>^ pos_win2 = gcnew List<TodoDelMenu::PosTexto>();
			pos_win2->Add(TodoDelMenu::PosTexto::Inferior);

			TodoDelMenu::FormHistoria^ win2 =
				gcnew TodoDelMenu::FormHistoria(imgs_win2, txts_win2, pos_win2);
			win2->ShowDialog();

			delete juego;
			delete juego2;
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
