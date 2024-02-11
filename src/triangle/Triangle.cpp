#include <cstdlib>
#include <iostream>

void info();
void prompt();

int main ()
{
	info();
	prompt();
	return 0;
}

void info ()
{
	printf("PROGRAM THAT COMPUTES THE AREA OF A TRIANGLE\n");
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

static double height ()
{
	double height = 0;
	std::cout << "input the height of the triangle:";
	std::cin >> height;
	return height;
}

static double width ()
{
	double width = 0;
	std::cout << "input the width of the triangle:";
	std::cin >> width;
	return width;
}

static double area (double const w, double const h)
{
	return (0.5 * w * h);
}

void prompt ()
{
	double const w = width();
	double const h = height();
	double const a = area(w, h);
	clear();
	std::cout << "polygon: triangle" << std::endl;
	std::cout << "area: " << a << std::endl;
}

/*

Polygons				February 11, 2024

source: Triangle.cpp
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
