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
 * jx_08_memory_converter_app.h
 *
 * \copyright Copyright (C) 2022 by Angel Fox Designs LLC.
 */

#ifndef _JX_08_MEMORY_CONVERTER_APP_H_
#define _JX_08_MEMORY_CONVERTER_APP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/xrc/xmlres.h"
#include "wx/image.h"
#include "dlg_jx08_memory_converter.h"
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
////@end control identifiers

/*!
 * Jx08MemoryConverterApp class declaration
 */

class Jx08MemoryConverterApp: public wxApp
{    
    DECLARE_CLASS( Jx08MemoryConverterApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    Jx08MemoryConverterApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin Jx08MemoryConverterApp event handler declarations

////@end Jx08MemoryConverterApp event handler declarations

////@begin Jx08MemoryConverterApp member function declarations

////@end Jx08MemoryConverterApp member function declarations

////@begin Jx08MemoryConverterApp member variables
////@end Jx08MemoryConverterApp member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(Jx08MemoryConverterApp)
////@end declare app

#endif
    // _JX_08_MEMORY_CONVERTER_APP_H_
