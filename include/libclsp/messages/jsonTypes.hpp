// A C++17 library for language servers.
// Copyright © 2019-2020 otreblan
//
// libclsp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libclsp is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libclsp.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <string>
#include <variant>
#include <vector>
#include <memory>

#include <libclsp/messages/objectT.hpp>

namespace libclsp
{

using namespace std;

/// Primitive json-rpc types
using String  = string;
using Number  = variant<int, double>;
using Boolean = bool;
using Null    = monostate;

/// Structured json-rpc types
using Object = shared_ptr<ObjectT>; // Types in variant have to be CopyConstructible
using Array = vector<variant<String, Number, Boolean, Null, Object>>;

/// A collection of all json-rpc types
using Any = variant<String, Number, Boolean, Null, Object, Array>;

/// Protocol types
using DocumentUri = String;

}
