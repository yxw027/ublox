//
// Copyright 2017 (C). Alex Robenko. All rights reserved.
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

#include "NavOdo.h"
#include "cc_plugin/field/nav.h"
#include "cc_plugin/field/common.h"

template class ublox::message::NavOdo<ublox::cc_plugin::Message>;
template class ublox::cc_plugin::ProtocolMessageBase<
    ublox::message::NavOdo<ublox::cc_plugin::Message>,
    ublox::cc_plugin::message::NavOdo>;


namespace cc = comms_champion;

namespace ublox
{

namespace cc_plugin
{

namespace message
{

namespace
{

using ublox::message::NavOdoFields;

QVariantList createFieldsProperties()
{
    QVariantList props;
    props.append(
        cc::property::field::ForField<NavOdoFields::version>().name("version").asMap());
    props.append(cc_plugin::field::common::props_reserved(1));
    props.append(cc_plugin::field::nav::props_iTOW());
    props.append(
        cc::property::field::ForField<NavOdoFields::distance>().name("distance").asMap());
    props.append(
        cc::property::field::ForField<NavOdoFields::totalDistance>().name("totalDistance").asMap());
    props.append(
        cc::property::field::ForField<NavOdoFields::distanceStd>().name("distanceStd").asMap());

    assert(props.size() == NavOdo::FieldIdx_numOfValues);
    return props;
}

}  // namespace

NavOdo::NavOdo() = default;
NavOdo::~NavOdo() = default;

NavOdo& NavOdo::operator=(const NavOdo&) = default;
NavOdo& NavOdo::operator=(NavOdo&&) = default;

const char* NavOdo::nameImpl() const
{
    static const char* Str = "NAV-ODO";
    return Str;
}

const QVariantList& NavOdo::fieldsPropertiesImpl() const
{
    static const auto Props = createFieldsProperties();
    return Props;
}

}  // namespace message

}  // namespace cc_plugin

}  // namespace ublox

