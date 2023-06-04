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
#include "aboutjxconversion.h"

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
    EVT_CHOICE( XRCID("ID_JX_GROUP"), dlgJX08MemoryConverter::OnJxGroupSelected )
    EVT_CHOICE( XRCID("ID_JX_BANK"), dlgJX08MemoryConverter::OnJxBankSelected )
    EVT_CHOICE( XRCID("ID_JX_NUMBER"), dlgJX08MemoryConverter::OnJxNumberSelected )
    EVT_SPINCTRL( XRCID("ID_LSB"), dlgJX08MemoryConverter::OnLsbUpdated )
    EVT_SPINCTRL( XRCID("ID_MSB"), dlgJX08MemoryConverter::OnMsbUpdated )
    EVT_SPINCTRL( XRCID("ID_PC"), dlgJX08MemoryConverter::OnPcUpdated )
    EVT_CHECKBOX( XRCID("ID_DAW_START_ONE"), dlgJX08MemoryConverter::OnDawStartOneClick )
    EVT_BUTTON( XRCID("ID_ABOUT_JX_CONV"), dlgJX08MemoryConverter::OnAboutJxConvClick )
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
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
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
    m_daw_start_one = false;
    m_jx_bank = wxT("1");
    m_jx_group = wxT("A");
    m_jx_number = wxT("1");
    m_midi_lsb = 0;
    m_midi_msb = 0;
    m_midi_pc = 0;
    m_midi_pc_ctl = NULL;
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
    m_midi_pc_ctl = XRCCTRL(*this, "ID_PC", wxSpinCtrl);
    // Set validators
    if (FindWindow(XRCID("ID_JX_GROUP")))
        FindWindow(XRCID("ID_JX_GROUP"))->SetValidator( wxGenericValidator(& m_jx_group) );
    if (FindWindow(XRCID("ID_JX_BANK")))
        FindWindow(XRCID("ID_JX_BANK"))->SetValidator( wxGenericValidator(& m_jx_bank) );
    if (FindWindow(XRCID("ID_JX_NUMBER")))
        FindWindow(XRCID("ID_JX_NUMBER"))->SetValidator( wxGenericValidator(& m_jx_number) );
    if (FindWindow(XRCID("ID_LSB")))
        FindWindow(XRCID("ID_LSB"))->SetValidator( wxGenericValidator(& m_midi_lsb) );
    if (FindWindow(XRCID("ID_MSB")))
        FindWindow(XRCID("ID_MSB"))->SetValidator( wxGenericValidator(& m_midi_msb) );
    if (FindWindow(XRCID("ID_PC")))
        FindWindow(XRCID("ID_PC"))->SetValidator( wxGenericValidator(& m_midi_pc) );
    if (FindWindow(XRCID("ID_DAW_START_ONE")))
        FindWindow(XRCID("ID_DAW_START_ONE"))->SetValidator( wxGenericValidator(& m_daw_start_one) );
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


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_JX_TO_MIDI
 */

void dlgJX08MemoryConverter::OnAboutJxConvClick( wxCommandEvent& event )
{
    AboutJxConversion *dlg = new AboutJxConversion(this);
    dlg->ShowModal();
    dlg->Destroy();
}


void dlgJX08MemoryConverter::UpdateMidi()
{
    if (Validate() && TransferDataFromWindow()) {
        int pc = 0;

        m_midi_pc = (wxAtoi(m_jx_bank) - 1) * 8 + (wxAtoi(m_jx_number) - 1);
        if(m_jx_group == wxT("B") || m_jx_group == wxT("D"))
            m_midi_pc += 64;

        if(m_daw_start_one) {
            m_midi_pc += 1;
        }

        if(m_jx_group == wxT("C") || m_jx_group == wxT("D"))
            m_midi_msb = 1;
        else
            m_midi_msb = 0;

        TransferDataToWindow();
    }
}

void dlgJX08MemoryConverter::UpdateJx08()
{
    if (Validate() && TransferDataFromWindow()) {
        int pc = m_midi_pc;

        if(m_daw_start_one) {
            pc -= 1;
        }

        if(m_midi_msb > 1 || m_midi_lsb > 0) {
            wxMessageBox(wxT("The JX-08 and JD-08 do not support more than 256 memories.\nPlease set LSB to 0 and MSB to 0 or 1."),
                         wxT("Conversion Error"),
                         wxOK | wxICON_ERROR,
                         this);
            return;
        }

        if(pc >= 64 && m_midi_msb == 0) {
            m_jx_group = wxT("B");
            pc -= 64;
        } else if(pc >= 64 && m_midi_msb == 1) {
            m_jx_group = wxT("D");
            pc -= 64;
        } else if(pc < 64 && m_midi_msb == 0) {
            m_jx_group = wxT("A");
        } else if(pc < 64 && m_midi_msb == 1) {
            m_jx_group = wxT("C");
        }

        wxString out = wxString::Format(wxT("%02o"), pc);
        int bank = wxAtoi(out.Left(1)) + 1;
        int number = wxAtoi(out.Right(1)) + 1;
        m_jx_bank = wxString::Format(wxT("%d"), bank);
        m_jx_number = wxString::Format(wxT("%d"), number);
        TransferDataToWindow();
    }
}

/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_DAW_START_ZERO
 */

void dlgJX08MemoryConverter::OnDawStartOneClick( wxCommandEvent& event )
{
    if (Validate() && TransferDataFromWindow()) {
        if(m_daw_start_one) {
            m_midi_pc_ctl->SetRange(1, 128);
            m_midi_pc += 1;
        } else {
            m_midi_pc_ctl->SetRange(0, 127);
            m_midi_pc -= 1;
        }
        TransferDataToWindow();
    }
}


/*
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_JX_GROUP
 */

void dlgJX08MemoryConverter::OnJxGroupSelected( wxCommandEvent& event )
{
    UpdateMidi();
}


/*
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_JX_BANK
 */

void dlgJX08MemoryConverter::OnJxBankSelected( wxCommandEvent& event )
{
    UpdateMidi();
}


/*
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_JX_NUMBER
 */

void dlgJX08MemoryConverter::OnJxNumberSelected( wxCommandEvent& event )
{
    UpdateMidi();
}


/*
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_LSB
 */

void dlgJX08MemoryConverter::OnLsbUpdated( wxSpinEvent& event )
{
    UpdateJx08();
}


/*
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_MSB
 */

void dlgJX08MemoryConverter::OnMsbUpdated( wxSpinEvent& event )
{
    UpdateJx08();
}


/*
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_PC
 */

void dlgJX08MemoryConverter::OnPcUpdated( wxSpinEvent& event )
{
    UpdateJx08();
}

