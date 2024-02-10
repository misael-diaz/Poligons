#!/usr/bin/make
#
# Polygons					February 10, 2024
#
# source: src/rectangle/Makefile
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

all: $(RECTANGLE_BIN)

$(RECTANGLE_BIN): $(RECTANGLE_OBJ)
	$(CXX) $(CXXOPT) $(RECTANGLE_OBJ) -o $(RECTANGLE_BIN)

$(RECTANGLE_OBJ): $(HEADERS) $(RECTANGLE_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(RECTANGLE_CXX) -o $(RECTANGLE_OBJ)

clean:
	/bin/rm -f *.obj *.bin
