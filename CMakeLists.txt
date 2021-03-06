# A C++17 library for language servers.
# Copyright © 2019-2020 otreblan
#
# libclsp is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# libclsp is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with libclsp.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.13.0)

project(libclsp
	VERSION 0.1.3
	DESCRIPTION "A language server protocol C++ library"
	HOMEPAGE_URL "https://github.com/otreblan/libclsp"
	LANGUAGES "CXX"
)

# Without this, paths are not relative in the sources list
cmake_policy(SET CMP0076 NEW)

include(GNUInstallDirs)
include(FindPkgConfig)

# The library itself
add_library(${PROJECT_NAME} SHARED)

# Version for the library symlinks
set_target_properties(${PROJECT_NAME}
	PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION ${PROJECT_VERSION_MAJOR}
		PREFIX ""
		CXX_STANDARD 17
)

# Headers
target_include_directories(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# Sources list
add_subdirectory(src)

# Header installation
add_subdirectory(include)

# pkg-config file
configure_file(libclsp.pc.in
	${CMAKE_BINARY_DIR}/libclsp.pc
	@ONLY
)
install(FILES
	${CMAKE_BINARY_DIR}/libclsp.pc
	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)

# Libraries
pkg_check_modules(RAPIDJSON REQUIRED RapidJSON)
include(FindBoost)

# Header path
target_include_directories(${PROJECT_NAME}
	PUBLIC
		${RAPIDJSON_INCLUDE_DIRS}
		${Boost_INCLUDE_DIRS}
)

# Linking
target_link_libraries(${PROJECT_NAME}
	PUBLIC
		${RAPIDJSON_LIBRARIES}
		${Boost_LIBRARIES}
)

# Other flags
target_compile_definitions(${PROJECT_NAME}
	PUBLIC
		${RAPIDJSON_CFLAGS_OTHER}
		RAPIDJSON_HAS_STDSTRING=1
)

# Default flags
if(NOT DEFINED ENV{CXXFLAGS})
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")
endif()


install(TARGETS ${PROJECT_NAME}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
