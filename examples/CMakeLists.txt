# Targets:
#  - examples:  Make all examples
#  - For each example file:
#    - <name>:  Make only example <name>
#
# None of these targets is in the default target. 
#
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

# The example files (expand as needed)
set(EXAMPLES
    basics
    own_types
)


# Add separate target for each example 
foreach(EXAMPLE ${EXAMPLES})
    add_executable(${EXAMPLE} EXCLUDE_FROM_ALL ${EXAMPLE}.cpp ${TMP})
endforeach()

# Add target to build all examples
add_custom_target(examples DEPENDS ${EXAMPLES})

unset(EXAMPLES)
