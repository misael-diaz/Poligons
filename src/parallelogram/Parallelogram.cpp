#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

struct Polygon {
	std::string _name_;
	Polygon(std::string name);
	virtual double area() const = 0;
	std::string name() const;
};

struct Parallelogram : Polygon {
	double _base_ = 0;
	double _height_ = 0;
	Parallelogram(double const b, double const h);
	double base() const;
	double height() const;
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
	printf("PROGRAM THAT COMPUTES THE AREA OF A PARALLELOGRAM\n");
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

static double base (void)
{
	double b = 0;
	std::cout << "input the base of the parallelogram:";
	std::cin >> b;
	return b;
}

static double height (void)
{
	double h = 0;
	std::cout << "input the height of the parallelogram:";
	std::cin >> h;
	return h;
}

Polygon::Polygon(std::string name) : _name_(name)
{
	return;
}

std::string Polygon::name () const
{
	return this->_name_;
}

Parallelogram::Parallelogram (double const b, double const h):
	Polygon("parallelogram"),
	_base_(b),
	_height_(h)
{
	return;
}

double Parallelogram::base () const
{
	return this->_base_;
}

double Parallelogram::height () const
{
	return this->_height_;
}

double Parallelogram::area () const
{
	double const b = this->base();
	double const h = this->height();
	return (b * h);
}

void prompt (void)
{
	double const b = base();
	double const h = height();
	Parallelogram p(b, h);
	double const a = p.area();
	clear();
	auto const default_precision = std::cout.precision();
	std::cout << std::scientific << std::setprecision(15);
	std::cout << "polygon: " << p.name() << std::endl;
	std::cout << "area: " << a << std::endl;
	std::cout.precision(default_precision);
}

/*

Polygons				February 19, 2024

source: Parallelogram.cpp
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
