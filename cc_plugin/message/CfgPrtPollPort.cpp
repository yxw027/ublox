//
// Copyright 2015 (C). Alex Robenko. All rights reserved.
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


#include "CfgPrtPollPort.h"

#include "cc_plugin/field/cfg.h"

template class ublox::message::CfgPrtPollPort<ublox::cc_plugin::Message>;
template class ublox::cc_plugin::ProtocolMessageBase<
    ublox::message::CfgPrtPollPort<ublox::cc_plugin::Message>,
    ublox::cc_plugin::message::CfgPrtPollPort>;

namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

QVariantList createFieldsProperties()
{

    QVariantList props;
    props.append(cc_plugin::field::cfg::props_portID());

    assert(props.size() == CfgPrtPollPort::FieldIdx_numOfValues);
    return props;
}

}  // namespace

CfgPrtPollPort::CfgPrtPollPort() = default;
CfgPrtPollPort::~CfgPrtPollPort() = default;

CfgPrtPollPort& CfgPrtPollPort::operator=(const CfgPrtPollPort&) = default;
CfgPrtPollPort& CfgPrtPollPort::operator=(CfgPrtPollPort&&) = default;


const char* CfgPrtPollPort::nameImpl() const
{
    static const char* Str = "CFG-PRT (Poll Port)";
    return Str;
}

const QVariantList& CfgPrtPollPort::fieldsPropertiesImpl() const
{
    static const auto Props = createFieldsProperties();
    return Props;
}

}  // namespace message

}  // namespace cc_plugin

}  // namespace ublox

