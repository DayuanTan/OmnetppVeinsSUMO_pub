//
// Copyright (C) 2013 Christoph Sommer <sommer@ccs-labs.org>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "veins/veins_testsims/utils/asserts.h"

bool haltOnFails = false;
bool displayPassed = true;

void fail(std::string msg)
{
    EV_STATICCONTEXT;
    EV_ERROR_C("asserts") << "FAILED: " << msg << std::endl;
    if (haltOnFails) exit(1);
}

void pass(std::string msg, bool hidePassed)
{
    EV_STATICCONTEXT;
    if (!hidePassed && displayPassed) EV_INFO_C("asserts") << "Passed: " << msg << std::endl;
}

void skip(std::string msg)
{
    EV_STATICCONTEXT;
    EV_INFO_C("asserts") << "Skipped: " << msg << std::endl;
}

void assertTrue(std::string msg, bool value, bool hidePassed)
{
    if (!value) {
        fail(msg);
    }
    else {
        pass(msg, hidePassed);
    }
}

void assertFalse(std::string msg, bool value)
{
    assertTrue(msg, !value);
}
