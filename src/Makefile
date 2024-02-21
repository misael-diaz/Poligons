#!/usr/bin/make
#
# Polygons				February 10, 2024
#
# source: src/Makefile
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

all: rectangles triangles circles parallelograms trapezoids rhombuses

rectangles:
	@$(MAKE) -C rectangle
triangles:
	@$(MAKE) -C triangle
circles:
	@$(MAKE) -C circle
parallelograms:
	@$(MAKE) -C parallelogram
trapezoids:
	@$(MAKE) -C trapezoid
rhombuses:
	@$(MAKE) -C rhombus
clean:
	@$(MAKE) -C rectangle clean
	@$(MAKE) -C triangle clean
	@$(MAKE) -C circle clean
	@$(MAKE) -C parallelogram clean
	@$(MAKE) -C trapezoid clean
	@$(MAKE) -C rhombus clean
