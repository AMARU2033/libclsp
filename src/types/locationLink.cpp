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

#include <libclsp/types/locationLink.hpp>

namespace libclsp
{

const String LocationLink::originSelectionRangeKey = "originSelectionRange";
const String LocationLink::targetUriKey            = "targetUri";
const String LocationLink::targetRangeKey          = "targetRange";
const String LocationLink::targetSelectionRangeKey = "targetSelectionRange";

LocationLink::LocationLink(optional<Range> originSelectionRange,
	DocumentUri targetUri,
	Range targetRange,
	Range targetSelectionRange):
		originSelectionRange(originSelectionRange),
		targetUri(targetUri),
		targetRange(targetRange),
		targetSelectionRange(targetSelectionRange)
{};

LocationLink::LocationLink(){};
LocationLink::~LocationLink(){};


void LocationLink::fillInitializer(ObjectInitializer& initializer)
{
	auto* handler = initializer.handler;

	auto& setterMap = initializer.setterMap;
	auto& neededMap = initializer.neededMap;

	// Value setters

	// originSelectionRange?:
	setterMap.emplace(
		originSelectionRangeKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler]()
			{
				handler->preFillInitializer();

				originSelectionRange.emplace();
				originSelectionRange.value().
					fillInitializer(handler->objectStack.top());
			}
		}
	);

	// targetUri:
	setterMap.emplace(
		targetUriKey,
		ValueSetter{
			// String
			[this, &neededMap](String str)
			{
				targetUri = str;

				neededMap[targetUriKey] = true;
			},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			{}
		}
	);

	// targetRange:
	setterMap.emplace(
		targetRangeKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler, &neededMap]()
			{
				handler->preFillInitializer();

				targetRange.fillInitializer(handler->objectStack.top());

				neededMap[targetRangeKey] = true;
			}
		}
	);

	// targetSelectionRange:
	setterMap.emplace(
		targetSelectionRangeKey,
		ValueSetter{
			// String
			{},

			// Number
			{},

			// Boolean
			{},

			// Null
			{},

			// Array
			{},

			// Object
			[this, handler, &neededMap]()
			{
				handler->preFillInitializer();

				targetSelectionRange.
					fillInitializer(handler->objectStack.top());

				neededMap[targetSelectionRangeKey] = true;
			}
		}
	);

	// Needed members
	neededMap.emplace(targetUriKey, 0);
	neededMap.emplace(targetRangeKey, 0);
	neededMap.emplace(targetSelectionRangeKey, 0);

	// This
	initializer.object = this;
}

}
