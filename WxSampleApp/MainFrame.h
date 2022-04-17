#pragma once

#include <windows.h>
#include "Base.h"

class MainFrame : public MainFrameBase
{
public:
	MainFrame();
	virtual ~MainFrame();

private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnButton7Clicked(wxCommandEvent& event);
	void OnButton5Clicked(wxCommandEvent& event);
};

enum
{
	ID_Hello = 1
};

class NotifyFrame : public NotifyFrameBase
{
public:
	NotifyFrame(wxWindow* parent, const wxString& title, const wxString& message, LPCWSTR iconStyle);
	virtual ~NotifyFrame();

private:
	void OnButtonClicked(wxCommandEvent& event);
};