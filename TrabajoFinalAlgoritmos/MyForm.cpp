#include "MyForm.h"
#include "PantallaCargaInicial.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TodoDelMenu::MyForm form;    //reempazamos despues con PantallaCargaInicial
	Application::Run(% form);

	return 0;
}
