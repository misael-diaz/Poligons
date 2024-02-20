#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

struct Circle {
	double _radius_ = 0;
	Circle(double const radius);
	double radius() const;
	double area() const;
};

void info(void);
void prompt(void);
void pause(void);

int main ()
{
	info();
	prompt();
	pause();
	return 0;
}

void info (void)
{
	printf("PROGRAM THAT COMPUTES THE AREA OF A CIRCLE\n");
}

#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
void clear (void)
{
        system("clear");
}
#elif defined(_WIN32) || defined(_WIN64)
void clear (void)
{
        system("cls");
}
#else
void clear (void)
{
	return;
}
#endif

#if defined(_WIN32) || defined(_WIN64)
void pause (void)
{
	system("pause");
}
#else
void pause (void)
{
	return;
}
#endif

static double radius (void)
{
	double r = 0;
	std::cout << "input the radius:";
	std::cin >> r;
	return r;
}

Circle::Circle (double const radius) : _radius_(radius)
{
	return;
}

double Circle::radius () const
{
	return this->_radius_;
}

double Circle::area () const
{
	constexpr double pi = M_PI;
	double const r = this->radius();
	return (pi * r * r);
}

void prompt (void)
{
	double const r = radius();
	Circle circle(r);
	double const a = circle.area();
	clear();
	auto const default_precision = std::cout.precision();
	std::cout << std::scientific << std::setprecision(15);
	std::cout << "polygon: circle" << std::endl;
	std::cout << "area: " << a << std::endl;
	std::cout.precision(default_precision);
}

/*

Polygons				February 19, 2024

source: Circle.cpp
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
