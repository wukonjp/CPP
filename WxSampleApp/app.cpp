#include <wx/msw/msvcrt.h> 
#include "MainFrame.h"
#include "app.h"


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	auto frame = new MainFrame();
	frame->Show(true);
	return true;
}
