//
//  NDMainFrame.cpp
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 13/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "NDMainFrame.h"

NDMainFrame::NDMainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 800)) {
    
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
    initStatsPanel();
    initCommandPanel();
    Layout();
    Centre();
}

BEGIN_EVENT_TABLE(NDMainFrame, wxFrame)
    EVT_MENU(wxID_AUTHORS, NDMainFrame::OnAbout)
    EVT_MENU(wxID_QUIT,  NDMainFrame::OnQuit)
    EVT_BUTTON(wxID_RUN_BUTTON,  NDMainFrame::onRun)
END_EVENT_TABLE()

void NDMainFrame::initOutterPanels() {
    wxBoxSizer* verticalSizer = new wxBoxSizer(wxVERTICAL);
    
    this->histogramPanel = new SimpleHistogram(this, wxID_HISTOGRAM_PANEL);
    this->statsPanel = new wxPanel(this, wxID_GRAPH_PANEL);
    this->commandPanel = new wxPanel(this, wxID_COMMAND_PANEL);


    this->histogramPanel->SetBackgroundColour(wxColour(222, 222, 222));
    this->statsPanel->SetBackgroundColour(wxColour(222, 222, 222));
    this->commandPanel->SetBackgroundColour(wxColour(222, 222, 222));
    
    verticalSizer->Add(histogramPanel, 4, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 10);
    verticalSizer->Add(statsPanel, 1, wxEXPAND | wxLEFT | wxRIGHT, 10);
    verticalSizer->Add(commandPanel, 1, wxEXPAND | wxBOTTOM | wxLEFT | wxRIGHT, 10);
    
    this->SetSizer(verticalSizer);
}

void NDMainFrame::initStatsPanel() {
    wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);
    
    // Graph Statistics Static Box Setup
    wxGridSizer* innerSizerLeft = new wxGridSizer(3, 2, 10, 0);
    wxStaticBox* boxLeft = new wxStaticBox(this->statsPanel, -1, "Graph statistics: ");
    wxStaticBoxSizer* boxSizerLeft = new wxStaticBoxSizer(boxLeft, wxVERTICAL);
    
    // Average Degree Label Setup
    wxStaticText* degreeLabel = new wxStaticText(boxLeft, -1, "Average node degree: ");
    this->avgDegreeLabel = new wxStaticText(boxLeft, -1, "Set me");
    innerSizerLeft->Add(degreeLabel, 0, wxALIGN_RIGHT);
    innerSizerLeft->Add(this->avgDegreeLabel, 0);

    // Clustering Coefficient Label Setup
    wxStaticText* clusterLabel = new wxStaticText(boxLeft, -1, "Clustering coefficient: ");
    this->clusteringCoefLabel = new wxStaticText(boxLeft, -1, "Set me");
    innerSizerLeft->Add(clusterLabel, 0, wxALIGN_RIGHT);
    innerSizerLeft->Add(this->clusteringCoefLabel, 0);
    
    // Small World Distance Label Setup
    wxStaticText* smallworldLabel = new wxStaticText(boxLeft, -1, "Small world distance: ");
    this->swDistanceLabel = new wxStaticText(boxLeft, -1, "Set me");
    innerSizerLeft->Add(smallworldLabel, 0, wxALIGN_RIGHT);
    innerSizerLeft->Add(this->swDistanceLabel, 0);
    
    // Left Box Sizer Setup
    boxSizerLeft->Add(innerSizerLeft);
    horizontalSizer->Add(boxSizerLeft, wxEXPAND);
    
    // Graph Statistics Static Box Setup
    wxGridSizer* innerSizerRight = new wxGridSizer(3, 2, 10, 0);
    wxStaticBox* boxRight = new wxStaticBox(this->statsPanel, -1, "Simulation statistics: ");
    wxStaticBoxSizer* boxSizerRight = new wxStaticBoxSizer(boxRight, wxVERTICAL);
    
    // Algorithm Iteration Counter Setup
    wxStaticText* iterLabel = new wxStaticText(boxRight, -1, "Iteration: ");
    this->algIterationLabel = new wxStaticText(boxRight, -1, "Set me");
    innerSizerRight->Add(iterLabel, 0, wxALIGN_RIGHT);
    innerSizerRight->Add(this->algIterationLabel, 0);
    
    // Algorithm Progress Gauge Setup
    wxStaticText* gaugeLabel = new wxStaticText(boxRight, -1, "Progress: ");
    this->algProgressGauge =  new wxGauge(boxRight, wxID_PROGRESS_GAUGE, 1000);
    innerSizerRight->Add(gaugeLabel, 0, wxALIGN_RIGHT);
    innerSizerRight->Add(this->algProgressGauge, 0);
    
    boxSizerRight->Add(innerSizerRight);
    horizontalSizer->Add(boxSizerRight, wxEXPAND);
    
    this->statsPanel->SetSizer(horizontalSizer);
    
}

void NDMainFrame::initCommandPanel() {
    wxGridSizer* innerSizer = new wxGridSizer(4, 4, 10, 0);
    wxStaticBox* box = new wxStaticBox(this->commandPanel, -1, "Initial settings: ");
    wxStaticBoxSizer* boxSizer = new wxStaticBoxSizer(box, wxVERTICAL);
    
    // Agent Count Control Setup
    wxStaticText* nodesLabel = new wxStaticText(box, -1, "Nodes: ");
    this->agentCountCtrl = new wxSpinCtrl(box, wxID_AGCOUNT_CTRL, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 150, 10000, 300);
    innerSizer->Add(nodesLabel, 0, wxALIGN_RIGHT);
    innerSizer->Add(this->agentCountCtrl, 0);
    
    // Connection Count Control Setup
    wxStaticText* connectionsLabel = new wxStaticText(box, -1, "Connections: ");
    this->connectionCountCtrl = new wxSpinCtrl(box, wxID_CONCOUNT_CTRL, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 150, 4);
    innerSizer->Add(connectionsLabel, 0, wxALIGN_RIGHT);
    innerSizer->Add(this->connectionCountCtrl);
    
    // Random Connection Count Control Setup
    wxStaticText* randConnectionsLabel = new wxStaticText(box, -1, "Random connections: ");
    this->maxRandomCtrl = new wxSpinCtrl(box, wxID_MAXRAND_CTRL, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 50, 1);
    innerSizer->Add(randConnectionsLabel, 0, wxALIGN_RIGHT);
    innerSizer->Add(this->maxRandomCtrl, 0);
    
    // Random Probability Control Setup
    wxStaticText* randomProbLabel = new wxStaticText(box, -1, "Random probability: ");
    this->randomProbCtrl = new wxSpinCtrl(box, wxID_RANDPROB_CTRL, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 10);
    innerSizer->Add(randomProbLabel, 0, wxALIGN_RIGHT);
    innerSizer->Add(this->randomProbCtrl);
    
    // DLS Depth Limit Probability Control Setup
    wxStaticText* depthLabel = new wxStaticText(box, -1, "DLS Depth Limit: ");
    this->dlsDepthCtrl  = new wxSpinCtrl(box, wxID_DLSDEPTH_CTRL, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 2, 7, 3);
    innerSizer->Add(depthLabel, 0, wxALIGN_RIGHT);
    innerSizer->Add(this->dlsDepthCtrl );
    
    // DLS Param Control Setup
    wxStaticText* paramLabel = new wxStaticText(box, -1, "DLS Probability: ");
    this->dlsParamCtrl = new wxSpinCtrl(box, wxID_DLSPARAM_CTRL, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 5);
    innerSizer->Add(paramLabel, 0, wxALIGN_RIGHT);
    innerSizer->Add(this->dlsParamCtrl);
    
    // DLS Param Control Setup
    wxStaticText* maxDlsLabel = new wxStaticText(box, -1, "DLS Max Connections: ");
    this->maxDlsParamCtrl = new wxSpinCtrl(box, wxID_DLSPARAM_CTRL, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 1);
    innerSizer->Add(maxDlsLabel, 0, wxALIGN_RIGHT);
    innerSizer->Add(this->maxDlsParamCtrl);
    
    // Simulation Length Control Setup
    wxStaticText* simulationLabel = new wxStaticText(box, -1, "Simulation length: ");
    this->simulationLengthCtrl = new wxSpinCtrl(box, wxID_SIMLENGTH_CTRL, "Set field", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 100);
    innerSizer->Add(simulationLabel, 0, wxALIGN_RIGHT);
    innerSizer->Add(this->simulationLengthCtrl);
    innerSizer->Add(new wxStaticText(this, -1, wxT("")), 0);
    
    // Graph Plot Checkbox Setup
    this->printGraphChBox = new wxCheckBox(box, wxID_PRINTGRAPH_CTRL, "Save Graph To File");
    innerSizer->Add(this->printGraphChBox, wxALIGN_LEFT);
    innerSizer->Add(new wxStaticText(this, -1, wxT("")), 0);

    // Run Button Setup
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);
    this->runButton = new wxButton(box, wxID_RUN_BUTTON, wxT("Run"));
    buttonSizer->Add(runButton, 0);
    innerSizer->Add(buttonSizer, 0, wxALIGN_LEFT);
    
    boxSizer->Add(innerSizer, 0, wxALL | wxCENTER, 0);
    this->commandPanel->SetSizer(boxSizer);
}

void NDMainFrame::onRun(wxCommandEvent& event){
    SocialNetworkGraph* mGraph=new SocialNetworkGraph();
    SocialNetworkAlgorithm* mAlgorithm=new SocialNetworkAlgorithm(*mGraph);
    
    std::cout<<connectionCountCtrl->GetValue();
    //do podpiecia zaraz
    mAlgorithm->run(this,agentCountCtrl->GetValue(),
                    connectionCountCtrl->GetValue(),
                    maxRandomCtrl->GetValue(),
                    randomProbCtrl->GetValue(),
                    simulationLengthCtrl->GetValue(),
                    dlsParamCtrl->GetValue()/100,
                    dlsDepthCtrl->GetValue(),
                    maxDlsParamCtrl->GetValue(),
                    printGraphChBox->GetValue());
    delete mAlgorithm;
    delete mGraph;
}

void NDMainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Aleksander Wójcik\nFilip Pasternak\nWojciech Kryściński", "Twórcy aplikacji", wxOK | wxICON_INFORMATION);
}

void NDMainFrame::OnQuit(wxCommandEvent& event) {
    Close(true);
}