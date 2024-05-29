#!/usr/bin/make
#
# Polygons					May 20, 2024
#
# source: src/polygon/Makefile
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

all: $(POLYGON_BIN)

$(POLYGON_BIN): $(POLYGON_OBJ)
	$(CXX) $(CXXOPT) $(POLYGON_OBJ) -o $(POLYGON_BIN)

$(POLYGON_OBJ): $(HEADERS) $(POLYGON_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(POLYGON_CXX) -o $(POLYGON_OBJ)

clean:
	/bin/rm -f *.obj *.bin
