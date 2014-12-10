//
//  TestApp.h
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 09/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__TestApp__
#define __Network_Dynamics__TestApp__

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};


class Simple : public wxFrame
{
public:
    Simple(const wxString& title);
    
};

#endif /* defined(__Network_Dynamics__TestApp__) */
