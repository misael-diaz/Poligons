#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <cctype>
#include <string>

struct Polygon {
	std::string _name_;
	Polygon(std::string name);
	virtual ~Polygon();
	virtual double area() const = 0;
	std::string name() const;
};

struct Rhombus : Polygon {
	double _diag_minor_ = 0;
	double _diag_major_ = 0;
	Rhombus(double const minor, double const major);
	~Rhombus();
	double minor() const;
	double major() const;
	double area() const;
};

static size_t _sz_ = 0;
static char *_line_[] = {NULL};

void info(void);
void prompt(void);
void pause(void);
void cleanup(void);

int main ()
{
	info();
	prompt();
	cleanup();
	pause();
	return 0;
}

void info (void)
{
	printf("PROGRAM THAT COMPUTES THE AREA OF A RHOMBUS\n");
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

void cleanup (void)
{
	if (*_line_) {
		free(*_line_);
		*_line_ = NULL;
	}
}

static bool isValidSymbol (char const c)
{
	if (c == '+' || c == '-' || c == ',' || c == '.' || c == 'e' || c == 'E') {
		return true;
	} else {
		return false;
	}
}

static bool isNumber (char const c)
{
	if (c >= '0' && c <= '9') {
		return true;
	} else {
		return false;
	}
}

static void skipWhiteSpace (char **txt)
{
	while (**txt && **txt <= ' ') {
		++*txt;
	}
}

static bool is_numeric (char **text)
{
	char *start = *text;
	if (!**text || **text == '\n') {
		return false;
	}

	skipWhiteSpace(text);
	char *iter = *text;
	bool space = false;
	while (*iter && *iter != '\n') {

		if (*iter <= ' ' && !space) {
			space = true;
			++iter;
			continue;
		}

		// ignores trailing whitespace
		if (*iter <= ' ' && space) {
			++iter;
			continue;
		}

		if (*iter > ' ' && space) {
			*text = start;
			return false;
		}

		if (!isValidSymbol(*iter) && !isNumber(*iter)) {
			*text = start;
			return false;
		}

		++iter;
	}

	*text = start;
	return true;
}

static bool toNumber (char **text, double *number)
{
	bool invalid = true;
	errno = 0;
	char *endptr[] = {NULL};
	*number = strtod(*text, endptr);
	if (errno == ERANGE) {
		invalid = true;
	} else if (!isspace(**endptr)) {
		invalid = true;
	} else {
		invalid = false;
	}

	return invalid;
}

static void validData (const char *fname, const char *prompt, double *number)
{
	*number = 0;
	printf("%s", prompt);
	ssize_t chars = 0;
	bool invalid = true;
	do {
		errno = 0;
		chars = getline(_line_, &_sz_, stdin);
		if (chars == -1) {

			if (errno) {
				fprintf(stderr, "%s: %s\n", fname, strerror(errno));
				exit(EXIT_FAILURE);
			}

			clearerr(stdin);
			printf("\nplease input valid data\n");
			printf("%s", prompt);

		} else {

			if (!is_numeric(_line_)) {
				invalid = true;
			} else {
				invalid = toNumber(_line_, number);
			}

			if (*number < 0) {
				invalid = true;
			}

			if (invalid) {
				printf("please input valid data\n");
				printf("%s", prompt);
			}
		}

	} while (chars == -1 || invalid);
}

static double minor (void)
{
	double minor = 0;
	char prompt[] = "input the minor diagonal of the rhombus:";
	validData("minor", prompt, &minor);
	return minor;
}

static double major (void)
{
	double major = 0;
	char prompt[] = "input the major diagonal of the rhombus:";
	validData("major", prompt, &major);
	return major;
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

Rhombus::Rhombus (double const minor, double const major):
	Polygon("rhombus"),
	_diag_minor_(minor),
	_diag_major_(major)
{
	return;
}

Rhombus::~Rhombus ()
{
	return;
}

double Rhombus::minor () const
{
	return this->_diag_minor_;
}

double Rhombus::major () const
{
	return this->_diag_major_;
}

double Rhombus::area () const
{
	double const minor = this->minor();
	double const major = this->major();
	return (0.5 * minor * major);
}

void prompt (void)
{
	double const a = minor();
	double const b = major();
	Rhombus *p = new Rhombus(a, b);
	if (!p) {
		fprintf(stderr, "prompt: malloc error\n");
		exit(EXIT_FAILURE);
	}

	clear();
	fprintf(stdout, "polygon: %s\n", p->name().c_str());
	fprintf(stdout, "area: %lf\n", p->area());
	delete(p);
	p = NULL;
}

/*

Polygons				February 19, 2024

source: Rhombus.cpp
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
