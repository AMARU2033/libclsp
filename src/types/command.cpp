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

#include <libclsp/types/command.hpp>

namespace libclsp
{

using namespace std;

const String Command::titleKey     = "title";
const String Command::commandKey   = "command";
const String Command::argumentsKey = "arguments";

Command::Command(String title, String command, optional<vector<Any>> arguments):
	title(title),
	command(command),
	arguments(arguments)
{};

Command::Command():
	title(),
	command(),
	arguments()
{};

Command::~Command(){};

}
