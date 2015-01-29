# Copyright (C) 2015 Robert Gantner. All rights reserved.
#
# This project is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This project is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this project.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 2.8)
project(direct_product)

# Version number
set(direct_product_VERSION_MAJOR 0)
set(direct_product_VERSION_MINOR 1)

# Global options
add_definitions(-std=c++11)
add_definitions(-g)
#add_definitions(-Xclang -fdump-record-layouts) # Xclang: prefix for plugin options
include_directories(${direct_product_SOURCE_DIR}/include/)

####################################################################################################
#### targets
####################################################################################################
#add_subdirectory(test)
add_subdirectory(examples)

####################################################################################################
#### installation
####################################################################################################
# set library name
SET(LIBNAME direct_product)
# set header files to install
SET(header_files
    include/direct_product.hpp
    )
# set source files to install
SET(src_files # don't confuse with source_files command
    )

# install to path
ADD_LIBRARY(${LIBNAME} EXCLUDE_FROM_ALL ${header_files} ${src_files})
# hack b/c without source files CMake can't detect the language
SET_TARGET_PROPERTIES (${LIBNAME} PROPERTIES LINKER_LANGUAGE CXX)
INSTALL(FILES ${header_files}	  DESTINATION "include/${LIBNAME}")
#INSTALL (TARGETS ${LIBNAME} ARCHIVE DESTINATION "${INSTTARGET}/${LIBPOSIX}")
