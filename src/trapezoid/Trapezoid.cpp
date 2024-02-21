#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

struct Polygon {
	std::string _name_;
	Polygon(std::string name);
	virtual ~Polygon();
	virtual double area() const = 0;
	std::string name() const;
};

struct Trapezoid : Polygon {
	double _base_minor_ = 0;
	double _base_major_ = 0;
	double _height_ = 0;
	Trapezoid(double const minor, double const major, double const height);
	~Trapezoid();
	double minor() const;
	double major() const;
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
	printf("PROGRAM THAT COMPUTES THE AREA OF A TRAPEZOID\n");
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

static double minor (void)
{
	double minor = 0;
	std::cout << "input the minor base of the trapezoid:";
	std::cin >> minor;
	return minor;
}

static double major (void)
{
	double major = 0;
	std::cout << "input the major base of the trapezoid:";
	std::cin >> major;
	return major;
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

Polygon::~Polygon ()
{
	return;
}

std::string Polygon::name () const
{
	return this->_name_;
}

Trapezoid::Trapezoid (double const minor, double const major, double const height):
	Polygon("trapezoid"),
	_base_minor_(minor),
	_base_major_(major),
	_height_(height)
{
	return;
}

Trapezoid::~Trapezoid ()
{
	return;
}

double Trapezoid::minor () const
{
	return this->_base_minor_;
}

double Trapezoid::major () const
{
	return this->_base_major_;
}

double Trapezoid::height () const
{
	return this->_height_;
}

double Trapezoid::area () const
{
	double const minor = this->minor();
	double const major = this->major();
	double const height = this->height();
	return (0.5 * (minor + major) * height);
}

void prompt (void)
{
	double const a = minor();
	double const b = major();
	double const h = height();
	Trapezoid *p = new Trapezoid(a, b, h);
	if (!p) {
		fprintf(stderr, "prompt: malloc error\n");
		exit(EXIT_FAILURE);
	}

	clear();
	auto const default_precision = std::cout.precision();
	std::cout << std::scientific << std::setprecision(15);
	std::cout << "polygon: " << p->name() << std::endl;
	std::cout << "area: " << p->area() << std::endl;
	std::cout.precision(default_precision);
	delete(p);
}

/*

Polygons				February 19, 2024

source: Trapezoid.cpp
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
