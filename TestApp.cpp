//
//  TestApp.cpp
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 09/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "TestApp.h"
#include "NDMainFrame.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    NDMainFrame* menu = new NDMainFrame(wxT("Network Dynamics Menu"));
    menu->Show();
    //menu->Maximize(true);
    
    return true;
}

Simple::Simple(const wxString& title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150))
{
    Centre();
}