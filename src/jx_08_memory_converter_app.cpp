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
 * jx_08_memory_converter_app.cpp
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
#include "wx/fs_zip.h"
////@end includes

#include "jx_08_memory_converter_app.h"

////@begin XPM images
////@end XPM images

/**
 * Initialize the C++-encoded XML resources.
 *
 * This function is generated from resources.xrc, which is generated via DialogBlocks.
 */
extern void InitXmlResource();

/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( Jx08MemoryConverterApp )
////@end implement app


/*
 * Jx08MemoryConverterApp type definition
 */

IMPLEMENT_CLASS( Jx08MemoryConverterApp, wxApp )


/*
 * Jx08MemoryConverterApp event table definition
 */

BEGIN_EVENT_TABLE( Jx08MemoryConverterApp, wxApp )

////@begin Jx08MemoryConverterApp event table entries
////@end Jx08MemoryConverterApp event table entries

END_EVENT_TABLE()


/*
 * Constructor for Jx08MemoryConverterApp
 */

Jx08MemoryConverterApp::Jx08MemoryConverterApp()
{
    Init();
}


/*
 * Member initialisation
 */

void Jx08MemoryConverterApp::Init()
{
////@begin Jx08MemoryConverterApp member initialisation
////@end Jx08MemoryConverterApp member initialisation
}

/*
 * Initialisation for Jx08MemoryConverterApp
 */

bool Jx08MemoryConverterApp::OnInit()
{    
////@begin Jx08MemoryConverterApp initialisation
	// Remove the comment markers above and below this block
	// to make permanent changes to the code.

	wxXmlResource::Get()->InitAllHandlers();
    InitXmlResource();

#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	dlgJX08MemoryConverter* mainWindow = new dlgJX08MemoryConverter(NULL);
	/* int returnValue = */ mainWindow->ShowModal();

	mainWindow->Destroy();
	// A modal dialog application should return false to terminate the app.
	return false;
////@end Jx08MemoryConverterApp initialisation

    return true;
}


/*
 * Cleanup for Jx08MemoryConverterApp
 */

int Jx08MemoryConverterApp::OnExit()
{    
////@begin Jx08MemoryConverterApp cleanup
	return wxApp::OnExit();
////@end Jx08MemoryConverterApp cleanup
}

