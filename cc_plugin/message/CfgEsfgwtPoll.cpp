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

#include <cassert>

#include "CfgEsfgwtPoll.h"

template class ublox::message::CfgEsfgwtPoll<ublox::cc_plugin::Message>;
template class ublox::cc_plugin::ProtocolMessageBase<
    ublox::message::CfgEsfgwtPoll<ublox::cc_plugin::Message>,
    ublox::cc_plugin::message::CfgEsfgwtPoll>;

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

CfgEsfgwtPoll::CfgEsfgwtPoll() = default;
CfgEsfgwtPoll::~CfgEsfgwtPoll() = default;

CfgEsfgwtPoll& CfgEsfgwtPoll::operator=(const CfgEsfgwtPoll&) = default;
CfgEsfgwtPoll& CfgEsfgwtPoll::operator=(CfgEsfgwtPoll&&) = default;


const char* CfgEsfgwtPoll::nameImpl() const
{
    static const char* Str = "CFG-ESFGWT (Poll)";
    return Str;
}


}  // namespace message

}  // namespace cc_plugin

}  // namespace ublox

