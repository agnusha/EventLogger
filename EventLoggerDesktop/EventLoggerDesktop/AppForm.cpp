#include "AppForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(cli::array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    //EventLoggerDesktop is project name
    EventLoggerDesktop::AppForm form;
    Application::Run(% form);
}