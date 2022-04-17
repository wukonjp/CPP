///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.0-4761b0c)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
private:

protected:
	wxScrolledWindow* m_scrolledWindow1;
	wxButton* m_button7;
	wxPanel* m_panel1;
	wxButton* m_button5;

public:

	MainFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(320, 344), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MainFrameBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class NotifyFrameBase
///////////////////////////////////////////////////////////////////////////////
class NotifyFrameBase : public wxFrame
{
private:

protected:
	wxPanel* m_panel2;
	wxStaticBitmap* m_bitmap1;
	wxStaticText* m_staticText4;
	wxPanel* m_panel3;
	wxButton* m_button28;

public:

	NotifyFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("title"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(238, 133), long style = wxCAPTION | wxCLOSE_BOX | wxFRAME_FLOAT_ON_PARENT | wxSTAY_ON_TOP | wxTAB_TRAVERSAL);

	~NotifyFrameBase();

};

