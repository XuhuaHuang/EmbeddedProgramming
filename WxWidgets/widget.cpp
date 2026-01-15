/**
 * @file widget.cpp
 * @author Xuhua Huang
 * @brief An example working with wxWidgets using modern C++ practices.
 * @version 0.1
 * @date 2026-01-13
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <wx/wx.h>

// Modern C++: keep logic in small classes, no globals needed.
class main_frame final : public wxFrame {
public:
  main_frame()
    : wxFrame(nullptr, wxID_ANY, "wxWidgets + Modern C++", wxDefaultPosition, wxSize(900, 600)) {
    // Simple UI: a panel + vertical sizer
    auto* panel = new wxPanel(this);
    auto* sizer = new wxBoxSizer(wxVERTICAL);

    auto* title = new wxStaticText(panel, wxID_ANY, "Hello wxWidgets");
    title->SetFont(title->GetFont().Scale(1.4));

    auto* button = new wxButton(panel, wxID_ANY, "Click me");
    auto* output = new wxStaticText(panel, wxID_ANY, "Status: idle");

    sizer->Add(title, 0, wxALL, 12);
    sizer->Add(button, 0, wxLEFT | wxRIGHT | wxBOTTOM, 12);
    sizer->Add(output, 0, wxLEFT | wxRIGHT | wxBOTTOM, 12);

    panel->SetSizer(sizer);

    // Modern C++ binding: lambda handler (lifetime is tied to `this`)
    button->Bind(wxEVT_BUTTON, [output](wxCommandEvent&) { output->SetLabel("Status: clicked"); });

    CreateStatusBar();
    SetStatusText("Ready");
  }
};

class app final : public wxApp {
public:
  bool OnInit() override {
    auto* frame = new main_frame();
    frame->Show(true);
    return true;
  }
};

wxIMPLEMENT_APP(app);
