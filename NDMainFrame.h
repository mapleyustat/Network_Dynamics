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
        wxID_RANDPROB_CTRL = wxID_HIGHEST + 44
    };
    
private:
    wxMenuBar* menuBar;
    wxMenu* fileMenu;
    wxPanel* statsPanel;
    SimpleHistogram* histogramPanel;
    wxPanel* commandPanel;
    wxButton* runButton;
    wxSpinCtrl* agentCountCtrl;
    wxSpinCtrl* connectionCountCtrl;
    wxSpinCtrl* maxRandomCtrl;
    wxSpinCtrl* randomProbCtrl;
    wxCheckBox* printGraphChBox;
    
    void initOutterPanels();
    void initButtons();
    void OnAbout(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void onRun(wxCommandEvent& event);
    
protected:
    DECLARE_EVENT_TABLE();
    
public:
    NDMainFrame(const wxString& title);
};


#endif /* defined(__Network_Dynamics__NDMainFrame__) */
