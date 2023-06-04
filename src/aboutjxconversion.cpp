/*
BSD 3-Clause License

Copyright (C) 2022 by Angel Fox Designs LLC.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * aboutjxconversion.cpp
 *
 * \copyright Copyright (C) 2022 by Angel Fox Designs LLC.
 */

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "aboutjxconversion.h"

////@begin XPM images
////@end XPM images


/*
 * AboutJxConversion type definition
 */

IMPLEMENT_DYNAMIC_CLASS( AboutJxConversion, wxDialog )


/*
 * AboutJxConversion event table definition
 */

BEGIN_EVENT_TABLE( AboutJxConversion, wxDialog )

////@begin AboutJxConversion event table entries
////@end AboutJxConversion event table entries

END_EVENT_TABLE()


/*
 * AboutJxConversion constructors
 */

AboutJxConversion::AboutJxConversion()
{
    Init();
}

AboutJxConversion::AboutJxConversion( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * AboutJxConversion creator
 */

bool AboutJxConversion::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin AboutJxConversion creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    SetParent(parent);
    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end AboutJxConversion creation
    return true;
}


/*
 * AboutJxConversion destructor
 */

AboutJxConversion::~AboutJxConversion()
{
////@begin AboutJxConversion destruction
////@end AboutJxConversion destruction
}


/*
 * Member initialisation
 */

void AboutJxConversion::Init()
{
////@begin AboutJxConversion member initialisation
    m_version_string = wxString::Format(wxT("JX-08 Conversion Tool version %s"), JX_CONV_VERSION);
    m_version_text = NULL;
////@end AboutJxConversion member initialisation
}


/*
 * Control creation for AboutJxConversion
 */

void AboutJxConversion::CreateControls()
{    
////@begin AboutJxConversion content construction
    if (!wxXmlResource::Get()->LoadDialog(this, GetParent(), wxT("ID_ABOUTJXCONVERSION")))
        wxLogError(wxT("Missing wxXmlResource::Get()->Load() in OnInit()?"));
    m_version_text = XRCCTRL(*this, "ID_VERSION_DISPLAY", wxStaticText);
////@end AboutJxConversion content construction

    // Create custom windows not generated automatically here.
////@begin AboutJxConversion content initialisation
////@end AboutJxConversion content initialisation

    // Set our text right.
    m_version_text->SetLabel(m_version_string);
}


/*
 * Should we show tooltips?
 */

bool AboutJxConversion::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap AboutJxConversion::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin AboutJxConversion bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end AboutJxConversion bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon AboutJxConversion::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin AboutJxConversion icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end AboutJxConversion icon retrieval
}
