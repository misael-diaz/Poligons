#!/usr/bin/make
#
# Polygons					February 11, 2024
#
# source: src/trapezoid/Makefile
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

all: $(TRAPEZOID_BIN)

$(TRAPEZOID_BIN): $(TRAPEZOID_OBJ)
	$(CXX) $(CXXOPT) $(TRAPEZOID_OBJ) -o $(TRAPEZOID_BIN)

$(TRAPEZOID_OBJ): $(HEADERS) $(TRAPEZOID_CXX)
	$(CXX) $(INC) $(CXXOPT) -c $(TRAPEZOID_CXX) -o $(TRAPEZOID_OBJ)

clean:
	/bin/rm -f *.obj *.bin
