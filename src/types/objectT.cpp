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

#include <libclsp/types/objectT.hpp>

namespace libclsp
{

using namespace std;
using namespace rapidjson;


void ObjectT::fillInitializer(ObjectInitializer&){};
void ObjectT::partialWrite(JsonWriter&){};
void ObjectT::write(JsonWriter&){};

bool ObjectT::isValid(JsonHandler& handler)
{
	auto& neededMap = handler.objectStack.top().neededMap;

	for(auto initializedPair: neededMap)
	{
		// If a needed value is left uninitialized
		if(!initializedPair.second)
		{
			return false;
		}
	}

	return true;
}

ObjectT::ObjectT(){};
ObjectT::~ObjectT(){};

}
