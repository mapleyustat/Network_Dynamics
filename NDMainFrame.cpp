//
//  NDMainFrame.cpp
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 13/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "NDMainFrame.h"

NDMainFrame::NDMainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)) {
    
    CreateStatusBar(3);
    SetStatusText(wxT("Ready"), 0);
    
    this->menuBar = new wxMenuBar();
    
    // File Menu
    this->fileMenu = new wxMenu();
    this->fileMenu->Append(wxID_AUTHORS, wxT("Autorzy"), wxT("Pokaż informacje o autorach"));
    this->fileMenu->AppendSeparator();
    this->fileMenu->Append(wxID_QUIT, wxT("Zakończ"), wxT("Zakończ działanie programu"));
    
    menuBar->Append(this->fileMenu, wxT("Menu"));
    SetMenuBar(menuBar);
    
    //initButtons();
    initOutterPanels();
    Layout();
    Centre();
}

BEGIN_EVENT_TABLE(NDMainFrame, wxFrame)
    EVT_MENU(wxID_AUTHORS, NDMainFrame::OnAbout)
    EVT_MENU(wxID_QUIT,  NDMainFrame::OnQuit)
END_EVENT_TABLE()

void NDMainFrame::initOutterPanels() {
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    this->graphPanel = new wxPanel(this, wxID_GRAPH_PANEL);
    this->histogramPanel = new wxPanel(this, wxID_HISTOGRAM_PANEL);
    this->bottomPanel = new wxPanel(this, wxID_BOTTOM_PANEL);
    
    this->graphPanel->SetBackgroundColour(wxColour(255, 255, 0));
    this->histogramPanel->SetBackgroundColour(wxColour(255, 0, 255));
    this->bottomPanel->SetBackgroundColour(wxColour(0, 255, 255));
    
//    this->graphPanel->SetMinSize(wxSize(180, 120));
//    this->histogramPanel->SetMinSize(wxSize(180, 120));
    
    sizer->SetSizeHints(this);
    
    sizer->Add(graphPanel, true, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 20);
    sizer->AddSpacer(20);
    sizer->Add(histogramPanel, true, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 20);
    sizer->Add(graphPanel, true, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 20);
    sizer->AddSpacer(20);
    sizer->Add(bottomPanel, true, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 20);
    this->SetSizer(sizer);
    //Layout();
}

void NDMainFrame::initButtons() {
    this->runButton = new wxButton(this->bottomPanel, wxID_RUN_BUTTON, wxT("Run"));
    
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);
    runButton->SetMinSize(wxSize(130,30));
    buttonSizer->AddStretchSpacer();
    buttonSizer->Add(runButton, false, wxEXPAND | wxALL, 20);
    buttonSizer->AddStretchSpacer();
    buttonSizer->SetSizeHints(this->bottomPanel);
}

void NDMainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Aleksander Wójcik\nFilip Pasternak\nWojciech Kryściński", "Twórcy aplikacji", wxOK | wxICON_INFORMATION);
}

void NDMainFrame::OnQuit(wxCommandEvent& event) {
    Close(true);
}