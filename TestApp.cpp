//
//  TestApp.cpp
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 09/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "TestApp.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    Simple *simple = new Simple(wxT("Simple"));
    simple->Show(true);
    
    return true;
}

Simple::Simple(const wxString& title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150))
{
    Centre();
}