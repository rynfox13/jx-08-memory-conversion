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
 * dlg_jx08_memory_converter.h
 *
 * \copyright Copyright (C) 2022 by Angel Fox Designs LLC.
 */

#ifndef _DLG_JX08_MEMORY_CONVERTER_H_
#define _DLG_JX08_MEMORY_CONVERTER_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/xrc/xmlres.h"
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
#define ID_DLGJX08MEMORYCONVERTER 10000
#define SYMBOL_DLGJX08MEMORYCONVERTER_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_DLGJX08MEMORYCONVERTER_TITLE _("JX-08 Memory Converter")
#define SYMBOL_DLGJX08MEMORYCONVERTER_IDNAME ID_DLGJX08MEMORYCONVERTER
#define SYMBOL_DLGJX08MEMORYCONVERTER_SIZE wxSize(400, 300)
#define SYMBOL_DLGJX08MEMORYCONVERTER_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * dlgJX08MemoryConverter class declaration
 */

class dlgJX08MemoryConverter: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( dlgJX08MemoryConverter )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    dlgJX08MemoryConverter();
    dlgJX08MemoryConverter( wxWindow* parent, wxWindowID id = SYMBOL_DLGJX08MEMORYCONVERTER_IDNAME, const wxString& caption = SYMBOL_DLGJX08MEMORYCONVERTER_TITLE, const wxPoint& pos = SYMBOL_DLGJX08MEMORYCONVERTER_POSITION, const wxSize& size = SYMBOL_DLGJX08MEMORYCONVERTER_SIZE, long style = SYMBOL_DLGJX08MEMORYCONVERTER_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DLGJX08MEMORYCONVERTER_IDNAME, const wxString& caption = SYMBOL_DLGJX08MEMORYCONVERTER_TITLE, const wxPoint& pos = SYMBOL_DLGJX08MEMORYCONVERTER_POSITION, const wxSize& size = SYMBOL_DLGJX08MEMORYCONVERTER_SIZE, long style = SYMBOL_DLGJX08MEMORYCONVERTER_STYLE );

    /// Destructor
    ~dlgJX08MemoryConverter();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin dlgJX08MemoryConverter event handler declarations
////@end dlgJX08MemoryConverter event handler declarations

////@begin dlgJX08MemoryConverter member function declarations
    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end dlgJX08MemoryConverter member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin dlgJX08MemoryConverter member variables
////@end dlgJX08MemoryConverter member variables
};

#endif
    // _DLG_JX08_MEMORY_CONVERTER_H_
