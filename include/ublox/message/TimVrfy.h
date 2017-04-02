//
// Copyright 2015 - 2017 (C). Alex Robenko. All rights reserved.
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

/// @file
/// @brief Contains definition of TIM-VRFY message and its fields.

#pragma once

#include <algorithm>

#include "ublox/Message.h"
#include "ublox/field/common.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the TIM-VRFY message fields.
/// @see TimVrfy
struct TimVrfyFields
{
    /// @brief Value enumeration for @ref src field.
    enum class Src : std::uint8_t
    {
        None, ///< no time aiding
        Rtc = 2, ///< source was RTC
        AidIni = 3 ///< source was AID-INI
    };

    /// @brief Custom validator for @ref src field
    struct SrcValidator
    {
        template <typename TField>
        bool operator()(const TField& field) const
        {
            auto value = field.value();
            static const Src Values[] = {
                Src::None,
                Src::Rtc,
                Src::AidIni
            };

            auto iter = std::lower_bound(std::begin(Values), std::end(Values), value);
            return (iter != std::end(Values)) && (*iter == value);
        }
    };

    /// @brief Definition of "itow" field.
    using itow = field::common::I4T<field::common::Scaling_ms2s>;

    /// @brief Definition of "frac" field.
    using frac = field::common::I4T<field::common::Scaling_ns2s>;

    /// @brief Definition of "deltaMS" field.
    using deltaMS = field::common::I4T<field::common::Scaling_ms2s>;

    /// @brief Definition of "deltaNS" field.
    using deltaNS = field::common::I4T<field::common::Scaling_ns2s>;

    /// @brief Definition of "wno" field.
    using wno = field::common::U2;

    /// @brief Definition of "src" member field of @ref flags field.
    using src =
        field::common::EnumT<
            Src,
            comms::option::ContentsValidator<SrcValidator>
        >;

    /// @brief Definition of "flags" field as equivalent to @ref src to save
    ///     extra work on reserved bits.
    using flags = src;

    /// @brief Definition of "reserved1" field.
    using reserved1 = field::common::res1;

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        itow,
        frac,
        deltaMS,
        deltaNS,
        wno,
        flags,
        reserved1
    >;

};

/// @brief Definition of TIM-VRFY message
/// @details Inherits from @b comms::MessageBase
///     while providing @b TMsgBase as common interface class as well as
///     various implementation options. @n
///     See @ref TimVrfyFields and for definition of the fields this message contains
///         and COMMS_MSG_FIELDS_ACCESS() for fields access details.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class TimVrfy : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_TIM_VRFY>,
        comms::option::FieldsImpl<TimVrfyFields::All>,
        comms::option::MsgType<TimVrfy<TMsgBase> >
    >
{
    typedef comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_TIM_VRFY>,
        comms::option::FieldsImpl<TimVrfyFields::All>,
        comms::option::MsgType<TimVrfy<TMsgBase> >
    > Base;
public:

    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The field names are:
    ///     @li @b itow for @ref TimVrfyFields::itow field
    ///     @li @b frac for @ref TimVrfyFields::frac field
    ///     @li @b deltaMS for @ref TimVrfyFields::deltaMS field
    ///     @li @b deltaNS for @ref TimVrfyFields::deltaNS field
    ///     @li @b wno for @ref TimVrfyFields::wno field
    ///     @li @b flags for @ref TimVrfyFields::flags field
    ///     @li @b reserved1 for @ref TimVrfyFields::reserved1 field
    COMMS_MSG_FIELDS_ACCESS(itow, frac, deltaMS, deltaNS, wno, flags, reserved1);

    /// @brief Default constructor
    TimVrfy() = default;

    /// @brief Copy constructor
    TimVrfy(const TimVrfy&) = default;

    /// @brief Move constructor
    TimVrfy(TimVrfy&& other) = default;

    /// @brief Destructor
    ~TimVrfy() = default;

    /// @brief Copy assignment
    TimVrfy& operator=(const TimVrfy&) = default;

    /// @brief Move assignment
    TimVrfy& operator=(TimVrfy&&) = default;
};


}  // namespace message

}  // namespace ublox

