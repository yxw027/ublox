//
// Copyright 2015 - 2017 (C). Alex Robenko. All rights reserved.
//

// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRSMGRY; without even the implied warranty of
// MERCHSMGRABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/// @file
/// @brief Contains definition of CFG-SMGR (@b poll) message and its fields.

#pragma once

#include "ublox/Message.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the CFG-SMGR (@b poll) message fields.
/// @see CfgSmgrPoll
struct CfgSmgrPollFields
{
    using All = std::tuple<>;
};

/// @brief Definition of CFG-SMGR (@b poll) message
/// @details Inherits from @b comms::MessageBase
///     while providing @b TMsgBase as common interface class as well as
///     various implementation options. @n
///     See @ref CfgSmgrPollFields and for definition of the fields this message contains.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class CfgSmgrPoll : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_SMGR>,
        comms::option::FieldsImpl<CfgSmgrPollFields::All>,
        comms::option::MsgType<CfgSmgrPoll<TMsgBase> >
    >
{
public:

    /// @brief Default constructor
    CfgSmgrPoll() = default;

    /// @brief Copy constructor
    CfgSmgrPoll(const CfgSmgrPoll&) = default;

    /// @brief Move constructor
    CfgSmgrPoll(CfgSmgrPoll&& other) = default;

    /// @brief Destructor
    ~CfgSmgrPoll() = default;

    /// @brief Copy assignment
    CfgSmgrPoll& operator=(const CfgSmgrPoll&) = default;

    /// @brief Move assignment
    CfgSmgrPoll& operator=(CfgSmgrPoll&&) = default;
};


}  // namespace message

}  // namespace ublox

