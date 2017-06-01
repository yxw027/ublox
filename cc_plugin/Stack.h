//
// Copyright 2015 - 2016 (C). Alex Robenko. All rights reserved.
//

// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#pragma once

#include "ublox/Stack.h"
#include "Message.h"

#ifdef UBLOX8_ONLY
#include "Ublox8Messages.h"

namespace ublox
{

namespace cc_plugin
{

using Stack = ublox::Stack<
    cc_plugin::Message,
    cc_plugin::Ublox8Messages
>;


}  // namespace cc_plugin

}  // namespace ublox

#else
#include "AllMessages.h"

namespace ublox
{

namespace cc_plugin
{

using Stack = ublox::Stack<
    cc_plugin::Message,
    cc_plugin::AllMessages
>;


}  // namespace cc_plugin

}  // namespace ublox

#endif

