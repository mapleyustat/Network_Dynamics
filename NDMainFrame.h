//
//  NDMainFrame.h
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 13/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__NDMainFrame__
#define __Network_Dynamics__NDMainFrame__

#include <iostream>
#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include "SimpleHistogram.h"
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include "SocialNetworkGraph.h"
#include "SocialNetworkAlgorithm.h"

class NDMainFrame : public wxFrame {
    enum {
        wxID_AUTHORS = wxID_HIGHEST + 10,
        wxID_QUIT = wxID_HIGHEST + 11,
        wxID_GRAPH_PANEL = wxID_HIGHEST + 20,
        wxID_HISTOGRAM_PANEL = wxID_HIGHEST + 21,
        wxID_COMMAND_PANEL = wxID_HIGHEST+ 22,
        wxID_RUN_BUTTON = wxID_HIGHEST + 31,
        wxID_AGCOUNT_CTRL = wxID_HIGHEST + 41,
        wxID_CONCOUNT_CTRL = wxID_HIGHEST + 42,
        wxID_MAXRAND_CTRL = wxID_HIGHEST + 43,
        wxID_RANDPROB_CTRL = wxID_HIGHEST + 44,
        wxID_PRINTGRAPH_CTRL = wxID_HIGHEST + 45,
        wxID_DLSDEPTH_CTRL = wxID_HIGHEST + 46,
        wxID_DLSPARAM_CTRL = wxID_HIGHEST + 47,
        wxID_SIMLENGTH_CTRL = wxID_HIGHEST + 48,
        wxID_PROGRESS_GAUGE = wxID_HIGHEST + 49
    };
    
private:
    friend class SocialNetworkAlgorithm;
    wxMenuBar* menuBar;
    wxMenu* fileMenu;
    wxPanel* statsPanel;
    SimpleHistogram* histogramPanel;
    wxPanel* commandPanel;
    wxButton* runButton;
    wxSpinCtrl* simulationLengthCtrl;
    wxSpinCtrl* agentCountCtrl;
    wxSpinCtrl* connectionCountCtrl;
    wxSpinCtrl* maxRandomCtrl;
    wxSpinCtrl* randomProbCtrl;
    wxSpinCtrl* dlsDepthCtrl;
    wxSpinCtrl* dlsParamCtrl;
    wxCheckBox* printGraphChBox;
    wxStaticText* avgDegreeLabel;
    wxStaticText* clusteringCoefLabel;
    wxStaticText* swDistanceLabel;
    wxStaticText* algIterationLabel;
    wxGauge* algProgressGauge;
    
    void initOutterPanels();
    void initStatsPanel();
    void initCommandPanel();
    void OnAbout(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void onRun(wxCommandEvent& event);
    
protected:
    DECLARE_EVENT_TABLE();
    
public:
    NDMainFrame(const wxString& title);
};


#endif /* defined(__Network_Dynamics__NDMainFrame__) */
