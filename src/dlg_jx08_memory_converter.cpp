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
 * dlg_jx08_memory_converter.cpp
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

#include "dlg_jx08_memory_converter.h"

////@begin XPM images

////@end XPM images


/*
 * dlgJX08MemoryConverter type definition
 */

IMPLEMENT_DYNAMIC_CLASS( dlgJX08MemoryConverter, wxDialog )


/*
 * dlgJX08MemoryConverter event table definition
 */

BEGIN_EVENT_TABLE( dlgJX08MemoryConverter, wxDialog )

////@begin dlgJX08MemoryConverter event table entries
////@end dlgJX08MemoryConverter event table entries

END_EVENT_TABLE()


/*
 * dlgJX08MemoryConverter constructors
 */

dlgJX08MemoryConverter::dlgJX08MemoryConverter()
{
    Init();
}

dlgJX08MemoryConverter::dlgJX08MemoryConverter( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * dlgJX08MemoryConverter creator
 */

bool dlgJX08MemoryConverter::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin dlgJX08MemoryConverter creation
    SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY|wxWS_EX_BLOCK_EVENTS);
    SetParent(parent);
    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end dlgJX08MemoryConverter creation
    return true;
}


/*
 * dlgJX08MemoryConverter destructor
 */

dlgJX08MemoryConverter::~dlgJX08MemoryConverter()
{
////@begin dlgJX08MemoryConverter destruction
////@end dlgJX08MemoryConverter destruction
}


/*
 * Member initialisation
 */

void dlgJX08MemoryConverter::Init()
{
////@begin dlgJX08MemoryConverter member initialisation
////@end dlgJX08MemoryConverter member initialisation
}


/*
 * Control creation for dlgJX08MemoryConverter
 */

void dlgJX08MemoryConverter::CreateControls()
{    
////@begin dlgJX08MemoryConverter content construction
    if (!wxXmlResource::Get()->LoadDialog(this, GetParent(), wxT("ID_DLGJX08MEMORYCONVERTER")))
        wxLogError(wxT("Missing wxXmlResource::Get()->Load() in OnInit()?"));
////@end dlgJX08MemoryConverter content construction

    // Create custom windows not generated automatically here.
////@begin dlgJX08MemoryConverter content initialisation
////@end dlgJX08MemoryConverter content initialisation
}


/*
 * Should we show tooltips?
 */

bool dlgJX08MemoryConverter::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap dlgJX08MemoryConverter::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin dlgJX08MemoryConverter bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end dlgJX08MemoryConverter bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon dlgJX08MemoryConverter::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin dlgJX08MemoryConverter icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end dlgJX08MemoryConverter icon retrieval
}
