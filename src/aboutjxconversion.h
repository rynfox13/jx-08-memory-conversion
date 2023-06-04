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
 * aboutjxconversion.h
 *
 * \copyright Copyright (C) 2022 by Angel Fox Designs LLC.
 */

#ifndef _ABOUTJXCONVERSION_H_
#define _ABOUTJXCONVERSION_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/xrc/xmlres.h"
#include "wx/html/htmlwin.h"
#include "wx/hyperlink.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_ABOUTJXCONVERSION 10000
#define SYMBOL_ABOUTJXCONVERSION_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_ABOUTJXCONVERSION_TITLE _("AboutJxConversion")
#define SYMBOL_ABOUTJXCONVERSION_IDNAME ID_ABOUTJXCONVERSION
#define SYMBOL_ABOUTJXCONVERSION_SIZE wxSize(400, 300)
#define SYMBOL_ABOUTJXCONVERSION_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * AboutJxConversion class declaration
 */

class AboutJxConversion: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( AboutJxConversion )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    AboutJxConversion();
    AboutJxConversion( wxWindow* parent, wxWindowID id = SYMBOL_ABOUTJXCONVERSION_IDNAME, const wxString& caption = SYMBOL_ABOUTJXCONVERSION_TITLE, const wxPoint& pos = SYMBOL_ABOUTJXCONVERSION_POSITION, const wxSize& size = SYMBOL_ABOUTJXCONVERSION_SIZE, long style = SYMBOL_ABOUTJXCONVERSION_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_ABOUTJXCONVERSION_IDNAME, const wxString& caption = SYMBOL_ABOUTJXCONVERSION_TITLE, const wxPoint& pos = SYMBOL_ABOUTJXCONVERSION_POSITION, const wxSize& size = SYMBOL_ABOUTJXCONVERSION_SIZE, long style = SYMBOL_ABOUTJXCONVERSION_STYLE );

    /// Destructor
    ~AboutJxConversion();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin AboutJxConversion event handler declarations

////@end AboutJxConversion event handler declarations

////@begin AboutJxConversion member function declarations

    wxString GetVersionString() const { return m_version_string ; }
    void SetVersionString(wxString value) { m_version_string = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end AboutJxConversion member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin AboutJxConversion member variables
    wxStaticText* m_version_text;
protected:
    wxString m_version_string;
////@end AboutJxConversion member variables
};

#endif
    // _ABOUTJXCONVERSION_H_
