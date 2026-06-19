#include "MyForm.h"
#include "PantallaCargaInicial.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TodoDelMenu::PantallaCargaInicial form;
	Application::Run(% form);

	return 0;
}
