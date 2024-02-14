#include <cstdio>
#include <cstdlib>

static double _width_ = 0;
static double _length_ = 0;
static double _area_ = 0;

void info();
void clear();
void prompt();
void area();
void pause();

int main ()
{
	info();
	prompt();
	clear();
	area();
	pause();
	return EXIT_SUCCESS;
}

void info ()
{
	printf("PROGRAM THAT COMPUTES THE AREA OF A RECTANGLE\n");
}

#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
void clear ()
{
        system("clear");
}
#elif defined(_WIN32) || defined(_WIN64)
void clear ()
{
        system("cls");
}
#else
void clear ()
{
	return;
}
#endif

#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
void pause ()
{
        return;
}
#elif defined(_WIN32) || defined(_WIN64)
void pause ()
{
        system("pause");
}
#else
void pause ()
{
	return;
}
#endif

static void length ()
{
	double length = 0;
	printf("input the length of the rectangle:");
	fscanf(stdin, "%lf", &length);
	printf("\n");
	_length_ = length;
}

static void width ()
{
	double width = 0;
	printf("input the width of the rectangle:");
	fscanf(stdin, "%lf", &width);
	printf("\n");
	_width_ = width;
}

void area ()
{
	_area_ = _width_ * _length_ ;
	printf("polygon: rectangle\n");
	printf("area: %f\n", _area_);
}

void prompt ()
{
	length();
	width();
}

/*

Polygons				February 10, 2024

source: Rectangle.cpp
author: @misael-diaz

Copyright (C) 2024 Misael Díaz-Maldonado

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

References:

[0] https://en.cppreference.com/w/cpp
[1] https://www.man7.org/linux/man-pages/man3/system.3.html

*/
