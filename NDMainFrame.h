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

class NDMainFrame : public wxFrame {
    enum {
        wxID_AUTHORS = 10,
        wxID_QUIT = 11,
        wxID_GRAPH_PANEL = 20,
        wxID_HISTOGRAM_PANEL = 21,
        wxID_BOTTOM_PANEL = 22,
        wxID_RUN_BUTTON = 31
    };
    
private:
    wxMenuBar* menuBar;
    wxMenu* fileMenu;
    wxPanel* graphPanel;
    wxPanel* histogramPanel;
    wxPanel* bottomPanel;
    wxButton* runButton;
    
    void initOutterPanels();
    void initButtons();
    void OnAbout(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    
protected:
    DECLARE_EVENT_TABLE();
    
public:
    NDMainFrame(const wxString& title);
};


#endif /* defined(__Network_Dynamics__NDMainFrame__) */
