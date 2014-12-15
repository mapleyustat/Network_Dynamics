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

    initOutterPanels();
    initButtons();
    Layout();
    Centre();
}

BEGIN_EVENT_TABLE(NDMainFrame, wxFrame)
    EVT_MENU(wxID_AUTHORS, NDMainFrame::OnAbout)
    EVT_MENU(wxID_QUIT,  NDMainFrame::OnQuit)
END_EVENT_TABLE()

void NDMainFrame::initOutterPanels() {
    wxBoxSizer* verticalSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);
    
    // Left Panel Setup
    this->graphPanel = new wxPanel(this, wxID_GRAPH_PANEL);
    this->graphPanel->SetBackgroundColour(wxColour(120, 120, 120));
    
    // Right Panel Setup
    this->histogramPanel = new wxPanel(this, wxID_HISTOGRAM_PANEL);
    this->commandPanel = new wxPanel(this, wxID_COMMAND_PANEL);
    this->histogramPanel->SetBackgroundColour(wxColour(166, 166, 166));
    this->commandPanel->SetBackgroundColour(wxColour(166, 166, 166));
    
    verticalSizer->Add(histogramPanel, true, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 5);
    verticalSizer->Add(commandPanel, true, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 5);
    
    // Sizer Setup
    horizontalSizer->Add(graphPanel, 3, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 5);
    horizontalSizer->Add(verticalSizer, 1, wxEXPAND | wxTOP | wxBOTTOM | wxLEFT, 0);
    
    this->SetSizer(horizontalSizer);
}

void NDMainFrame::initButtons() {
    wxGridSizer* verticalSizer = new wxGridSizer(6, 2, 3, 3);
    
    // Section Header Setup
    verticalSizer->Add(new wxStaticText(this->commandPanel, -1, "Initial settings: "), 0, wxTOP | wxLEFT, 20);
    verticalSizer->Add(new wxStaticText(this, -1, wxT("")), 0);
    
    // Agent Count Control Setup
    wxStaticText* nodesCount = new wxStaticText(this->commandPanel, -1, "Nodes: ");
    this->agentCountCtrl = new wxSpinCtrl(this->commandPanel, -1, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 150, 10000, 2500);
    verticalSizer->Add(nodesCount, 0, wxLEFT, 25);
    verticalSizer->Add(this->agentCountCtrl, 0, wxRIGHT, 25);
    
    // Connection Count Control Setup
    wxStaticText* connectionsCount = new wxStaticText(this->commandPanel, -1, "Connections: ");
    this->connectionCountCtrl = new wxSpinCtrl(this->commandPanel, -1, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 150, 50);
    verticalSizer->Add(connectionsCount, 0, wxLEFT, 25);
    verticalSizer->Add(this->connectionCountCtrl, 0, wxRIGHT, 25);
    
    // Random Connection Count Control Setup
    wxStaticText* randConnectionsCount = new wxStaticText(this->commandPanel, -1, "Random connections: ");
    this->maxRandomCtrl = new wxSpinCtrl(this->commandPanel, -1, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 50, 25);
    verticalSizer->Add(randConnectionsCount, 0, wxLEFT, 25);
    verticalSizer->Add(this->maxRandomCtrl, 0, wxRIGHT, 25);
    
    // Random Probability Control Setup
    wxStaticText* randomProbCount = new wxStaticText(this->commandPanel, -1, "Random probability: ");
    this->randomProbCtrl = new wxSpinCtrl(this->commandPanel, -1, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 10);
    verticalSizer->Add(randomProbCount, 0, wxLEFT, 25);
    verticalSizer->Add(this->randomProbCtrl, 0, wxRIGHT, 25);
    
    // Run Button Setup
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);
    this->runButton = new wxButton(this->commandPanel, wxID_RUN_BUTTON, wxT("Run"));
    buttonSizer->Add(runButton, 0);
    verticalSizer->Add(buttonSizer, 0, wxLEFT, 25);
    verticalSizer->Add(new wxStaticText(this, -1, wxT("")), 0);
    
    this->commandPanel->SetSizer(verticalSizer);
    Centre();
}

void NDMainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Aleksander Wójcik\nFilip Pasternak\nWojciech Kryściński", "Twórcy aplikacji", wxOK | wxICON_INFORMATION);
}

void NDMainFrame::OnQuit(wxCommandEvent& event) {
    Close(true);
}