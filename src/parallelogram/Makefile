#!/usr/bin/make
#
# Polygons					February 11, 2024
#
# source: src/parallelogram/Makefile
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

all: $(PARALLELOGRAM_BIN)

$(PARALLELOGRAM_BIN): $(PARALLELOGRAM_OBJ)
	$(CXX) $(CXXOPT) $(PARALLELOGRAM_OBJ) -o $(PARALLELOGRAM_BIN)

$(PARALLELOGRAM_OBJ): $(HEADERS) $(PARALLELOGRAM_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(PARALLELOGRAM_CXX) -o $(PARALLELOGRAM_OBJ)

clean:
	/bin/rm -f *.obj *.bin
