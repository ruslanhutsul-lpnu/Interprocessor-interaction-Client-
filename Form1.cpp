#include "Form1.h"
using namespace System;
using namespace System::Windows::Forms;

[System::STAThread]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	WFtry2::MyForm form;
	Application::Run(% form);
}