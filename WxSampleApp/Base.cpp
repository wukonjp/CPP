///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.0-4761b0c)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Base.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	m_scrolledWindow1 = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	m_scrolledWindow1->SetScrollRate(5, 5);
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxVERTICAL);

	m_button7 = new wxButton(m_scrolledWindow1, wxID_ANY, wxT("ボタン1"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer6->Add(m_button7, 0, wxALL, 5);


	m_scrolledWindow1->SetSizer(bSizer6);
	m_scrolledWindow1->Layout();
	bSizer6->Fit(m_scrolledWindow1);
	bSizer1->Add(m_scrolledWindow1, 1, wxEXPAND | wxALL, 5);

	m_panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxVERTICAL);

	m_button5 = new wxButton(m_panel1, wxID_ANY, wxT("ボタン2"), wxDefaultPosition, wxDefaultSize, 0);
	m_button5->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial")));

	bSizer5->Add(m_button5, 0, wxALL, 5);


	m_panel1->SetSizer(bSizer5);
	m_panel1->Layout();
	bSizer5->Fit(m_panel1);
	bSizer1->Add(m_panel1, 1, wxEXPAND | wxALL, 5);

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("label")), wxVERTICAL);


	bSizer1->Add(sbSizer1, 1, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);
}

MainFrameBase::~MainFrameBase()
{
}

NotifyFrameBase::NotifyFrameBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(200, 100), wxDefaultSize);

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer(wxVERTICAL);

	bSizer21->SetMinSize(wxSize(200, 100));
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer(0, 0, 0, 0);

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer(wxHORIZONTAL);

	m_bitmap1 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
	bSizer22->Add(m_bitmap1, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("message"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText4->Wrap(-1);
	m_staticText4->SetMinSize(wxSize(200, -1));

	bSizer22->Add(m_staticText4, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);


	gSizer4->Add(bSizer22, 1, wxEXPAND, 5);


	bSizer21->Add(gSizer4, 1, wxEXPAND, 5);

	wxGridSizer* gSizer5;
	gSizer5 = new wxGridSizer(0, 0, 0, 0);

	m_button28 = new wxButton(this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0);
	gSizer5->Add(m_button28, 0, wxALIGN_CENTER | wxALL, 5);


	bSizer21->Add(gSizer5, 1, wxEXPAND, 5);


	this->SetSizer(bSizer21);
	this->Layout();

	this->Centre(wxBOTH);
}

NotifyFrameBase::~NotifyFrameBase()
{
}
