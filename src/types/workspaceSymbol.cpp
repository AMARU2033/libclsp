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

#include <libclsp/types/workspaceSymbol.hpp>

namespace libclsp
{

using namespace std;

const String WorkspaceSymbolClientCapabilities::
	dynamicRegistrationKey = "dynamicRegistration";

const String WorkspaceSymbolClientCapabilities::
	symbolKindKey          = "symbolKind";

WorkspaceSymbolClientCapabilities::
	WorkspaceSymbolClientCapabilities(optional<Boolean> dynamicRegistration,
		optional<SymbolKind> symbolKind):
			dynamicRegistration(dynamicRegistration),
			symbolKind(symbolKind)
{};

WorkspaceSymbolClientCapabilities::WorkspaceSymbolClientCapabilities():
	dynamicRegistration(),
	symbolKind()
{};

WorkspaceSymbolClientCapabilities::~WorkspaceSymbolClientCapabilities(){};


const String WorkspaceSymbolClientCapabilities::SymbolKind::
	valueSetKey = "valueSet";

WorkspaceSymbolClientCapabilities::SymbolKind::
	SymbolKind(optional<vector<libclsp::SymbolKind>> valueSet):
		valueSet(valueSet)
{};

WorkspaceSymbolClientCapabilities::SymbolKind::SymbolKind():
	valueSet()
{};

WorkspaceSymbolClientCapabilities::SymbolKind::~SymbolKind(){};


const String WorkspaceSymbolParams::queryKey = "query";

WorkspaceSymbolParams::WorkspaceSymbolParams(
	optional<ProgressToken> workDoneToken,
	optional<ProgressToken> partialResultToken,
	String query):
		WorkDoneProgressParams(workDoneToken),
		PartialResultParams(partialResultToken),
		query(query)
{};

WorkspaceSymbolParams::WorkspaceSymbolParams():
	WorkDoneProgressParams(),
	PartialResultParams(),
	query()
{};

WorkspaceSymbolParams::~WorkspaceSymbolParams(){};

}
