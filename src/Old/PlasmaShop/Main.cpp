/* This file is part of PlasmaShop.
 *
 * PlasmaShop is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PlasmaShop is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PlasmaShop.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <wx/wx.h>
#include <wx/config.h>
#include <Debug/plDebug.h>
#include "wxPlasmaShopFrame.h"

class wxPlasmaShopApp : public wxApp {
public:
    virtual bool OnInit()
    {
        // Initialize application globals
        plDebug::InitFile(plDebug::kDLAll);
        wxConfigBase::Set(new wxConfig(wxT("PlasmaShop")));

        // Create and show the main frame
        wxPlasmaShopFrame* frame = new wxPlasmaShopFrame(this);
        frame->Show(true);
        SetTopWindow(frame);

        // Command-line loading
        for (int i=1; i<argc; i++)
            frame->LoadFile(argv[i]);

        return true;
    }

    /*
    virtual int OnExit()
    {
        return wxApp::OnExit();
    }*/
};

IMPLEMENT_APP(wxPlasmaShopApp)
