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

#include <libclsp/server/jsonHandler.hpp>
#include <libclsp/types/objectT.hpp>

namespace libclsp
{

using namespace std;

bool JsonHandler::Null()
{

	function<void()> setNull;


	auto topObject = objectStack.top();

	auto& setterMap = topObject.setterMap;

	auto jsonPair = setterMap.find(lastKey);


	if(jsonPair != setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setNull.has_value())
		{
			setNull = jsonPair->second.setNull.value();
		}
		else
		{
			// This Key is not a Null
			return false;
		}
	}
	else // Key not found
	{
		auto& extraSetter = topObject.extraSetter;

		if(extraSetter.has_value())
		{
			setNull = extraSetter->setNull.value();
		}
		else
		{
			// Key not found and no extra members on the object
			return false;
		}
	}

	//TODO add exceptions

	setNull();

	return true;
}

bool JsonHandler::Bool(bool b)
{
	auto jsonPair = objectStack.top().setterMap.find(lastKey);

	if(jsonPair != objectStack.top().setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setBoolean.has_value())
		{
			auto& setBoolean = jsonPair->second.setBoolean.value();

			setBoolean(b);
		}
		else
		{
			// This Key is not a Boolean
			return false;
		}
	}
	else
	{
		// TODO
		// Add something to build objects with index signatures

		// Key not found
		return false;
	}

	return true;
}

bool JsonHandler::Number(libclsp::Number n)
{
	auto jsonPair = objectStack.top().setterMap.find(lastKey);

	if(jsonPair != objectStack.top().setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setNumber.has_value())
		{
			auto& setNumber = jsonPair->second.setNumber.value();

			setNumber(n);
		}
		else
		{
			// This Key is not a Number
			return false;
		}
	}
	else
	{
		// TODO
		// Add something to build objects with index signatures

		// Key not found
		return false;
	}

	return true;
}

bool JsonHandler::Int(int i)
{
	return Number(i);
}

bool JsonHandler::Uint(unsigned u)
{
	return Number((int)u);
}

bool JsonHandler::Int64(int64_t i)
{
	return Number((int)i);
}

bool JsonHandler::Uint64(uint64_t u)
{
	return Number((int)u);
}

bool JsonHandler::Double(double d)
{
	return Number(d);
}

bool JsonHandler::String(const char* str, SizeType, bool)
{
	auto jsonPair = objectStack.top().setterMap.find(lastKey);

	if(jsonPair != objectStack.top().setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setString.has_value())
		{
			auto& setString = jsonPair->second.setString.value();

			setString(str);
		}
		else
		{
			// This Key is not a String
			return false;
		}
	}
	else
	{
		// TODO
		// Add something to build objects with index signatures

		// Key not found
		return false;
	}

	return true;
}

bool JsonHandler::StartObject()
{

	auto jsonPair = objectStack.top().setterMap.find(lastKey);

	if(jsonPair != objectStack.top().setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setObject.has_value())
		{
			auto& setObject = jsonPair->second.setObject.value();

			setObject();
		}
		else
		{
			// This Key is not an Object
			return false;
		}
	}
	else
	{
		// TODO
		// Add something to build objects with index signatures

		// Key not found
		return false;
	}

	return true;
}

bool JsonHandler::Key(const char* str, SizeType, bool)
{
	lastKey = str;

	return true;
}

bool JsonHandler::EndObject(SizeType)
{
	if(objectStack.top().object->isValid())
	{
		objectStack.pop();

		// The key returns to the last Object/Array
		lastKey = objectStack.top().key;

		return true;
	}
	else
	{
		return false;
	}
}

bool JsonHandler::StartArray()
{
	auto jsonPair = objectStack.top().setterMap.find(lastKey);

	if(jsonPair != objectStack.top().setterMap.end()) // Key found in map
	{
		if(jsonPair->second.setArray.has_value())
		{
			auto& setArray = jsonPair->second.setArray.value();

			setArray();
		}
		else
		{
			// This Key is not an Array
			return false;
		}
	}
	else
	{
		// TODO
		// Add something to build objects with index signatures

		// Key not found
		return false;
	}

	return true;
}
bool JsonHandler::EndArray(SizeType elementCount)
{
	// ObjectT is also used by array makers
	return EndObject(elementCount);
}

}
