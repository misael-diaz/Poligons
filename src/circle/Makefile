#!/usr/bin/make
#
# Polygons					February 11, 2024
#
# source: src/circle/Makefile
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

all: $(CIRCLE_BIN)

$(CIRCLE_BIN): $(CIRCLE_OBJ)
	$(CXX) $(CXXOPT) $(CIRCLE_OBJ) -o $(CIRCLE_BIN)

$(CIRCLE_OBJ): $(HEADERS) $(CIRCLE_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(CIRCLE_CXX) -o $(CIRCLE_OBJ)

clean:
	/bin/rm -f *.obj *.bin
