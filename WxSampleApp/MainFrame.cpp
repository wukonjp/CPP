#include <wx/wx.h>
#include <wx/msw/msvcrt.h>
#include "MainFrame.h"

MainFrame::MainFrame()
	: MainFrameBase(NULL, wxID_ANY, "Hello World")
{
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");

	SetMenuBar(menuBar);

	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");

	Bind(wxEVT_MENU, &MainFrame::OnHello, this, ID_Hello);
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);

	// Connect Events
	m_button7->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnButton7Clicked), NULL, this);
	m_button5->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnButton5Clicked), NULL, this);
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_button7->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnButton7Clicked), NULL, this);
	m_button5->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnButton5Clicked), NULL, this);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets Hello World example",
		"About Hello World", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}

void MainFrame::OnButton7Clicked(wxCommandEvent& event)
{
	auto frame = new NotifyFrame(this, L"OnButton7Clicked", L"message is here.\nsecond line.\nthird line.", IDI_ERROR);
	frame->Show();
}

void MainFrame::OnButton5Clicked(wxCommandEvent& event)
{
	wxMessageDialog dialog(this, L"message is here.", L"OnButton5Clicked", wxOK | wxICON_ERROR | wxSTAY_ON_TOP);
	dialog.ShowModal();
}

NotifyFrame::NotifyFrame(wxWindow* parent, const wxString& title, const wxString& message, LPCWSTR iconStyle)
	: NotifyFrameBase(
		parent, 
		wxID_ANY,
		title,
		wxDefaultPosition,
		wxSize(238, 133),
		wxCAPTION | wxCLOSE_BOX | wxFRAME_FLOAT_ON_PARENT | wxSTAY_ON_TOP | wxTAB_TRAVERSAL
	)
{
	auto hIcon = LoadIconW(NULL, iconStyle);
	wxIcon icon;
	icon.CreateFromHICON(hIcon);
	m_bitmap1->SetBitmap(wxBitmap(icon));
	m_staticText4->SetLabelText(message);

	// Connect Events
	m_button28->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(NotifyFrame::OnButtonClicked), NULL, this);
}

NotifyFrame::~NotifyFrame()
{
	// Disconnect Events
	m_button28->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(NotifyFrame::OnButtonClicked), NULL, this);
}

void NotifyFrame::OnButtonClicked(wxCommandEvent& event)
{
	this->Destroy();
}
