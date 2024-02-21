#!/usr/bin/make
#
# Polygons					February 11, 2024
#
# source: src/rhombus/Makefile
# author: @misael-diaz
#
# Synopsis:
# Defines the Makefile for building the program with GNU make.
#
# Copyright (c) 2024 Misael Díaz-Maldonado
# This file is released under the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#

include make-inc

all: $(RHOMBUS_BIN)

$(RHOMBUS_BIN): $(RHOMBUS_OBJ)
	$(CXX) $(CXXOPT) $(RHOMBUS_OBJ) -o $(RHOMBUS_BIN)

$(RHOMBUS_OBJ): $(HEADERS) $(RHOMBUS_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(RHOMBUS_CXX) -o $(RHOMBUS_OBJ)

clean:
	/bin/rm -f *.obj *.bin
