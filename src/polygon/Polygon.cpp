// DEVNOTE:
// the MACRO DEBUG is defined via command-line (see make-inc at the top level of
// the repository) it's not defined explicitly in the source code
#include <cmath>
#if defined(DEBUG) && DEBUG
#include <cstdlib>
#endif
#include <cstdio>

#define NUM_POLYGONS 4
#define TOL 2.3283064365386963e-10
#define ABS(X) (((X) < 0)? -(X) : (X))

enum polygon {
	TRIANGLE,
	RECTANGLE,
	TRAPEZOID,
	PARALLELOGRAM
};

static double _triangle_right_base_ = 0;
static double _triangle_right_height_ = 0;
static double _triangle_right_hypotenuse_ = 0;
static double _triangle_right_perimeter_ = 0;
static double _triangle_right_area_ = 0;

#if defined(DEBUG) && DEBUG
static bool   _triangle_right_base_defined_ = false;
static bool   _triangle_right_height_defined_ = false;
static bool   _triangle_right_hypotenuse_defined_ = false;
static bool   _triangle_right_perimeter_defined_= false;
static bool   _triangle_right_area_defined_= false;
#endif

static double _rectangle_width_ = 0;
static double _rectangle_length_ = 0;
static double _rectangle_perimeter_ = 0;
static double _rectangle_area_ = 0;

#if defined(DEBUG) && DEBUG
static bool   _rectangle_width_defined_ = false;
static bool   _rectangle_length_defined_ = false;
static bool   _rectangle_perimeter_defined_ = false;
static bool   _rectangle_area_defined_ = false;
#endif

static double _trapezoid_base_minor_ = 0;
static double _trapezoid_base_major_ = 0;
static double _trapezoid_height_ = 0;
static double _trapezoid_lateral_side_ = 0;
static double _trapezoid_perimeter_ = 0;
static double _trapezoid_area_ = 0;

#if defined(DEBUG) && DEBUG
static bool   _trapezoid_base_minor_defined_= false;
static bool   _trapezoid_base_major_defined_= false;
static bool   _trapezoid_height_defined_= false;
static bool   _trapezoid_lateral_side_defined_ = false;
static bool   _trapezoid_perimeter_defined_ = false;
static bool   _trapezoid_area_defined_ = false;
#endif

static double _parallelogram_base_ = 0;
static double _parallelogram_lateral_side_ = 0;
static double _parallelogram_height_ = 0;
static double _parallelogram_perimeter_ = 0;
static double _parallelogram_area_ = 0;

#if defined(DEBUG) && DEBUG
static bool   _parallelogram_base_defined_= false;
static bool   _parallelogram_lateral_side_defined_ = false;
static bool   _parallelogram_height_defined_= false;
static bool   _parallelogram_perimeter_defined_ = false;
static bool   _parallelogram_area_defined_ = false;
#endif

void polygon(enum polygon);

int main ()
{
	for (int i = 0; i != NUM_POLYGONS; ++i) {
		enum polygon const kind = ((enum polygon) i);
		polygon(kind);
	}
}

static void setTriangleBase (void)
{
	double base = 0;
	printf("input the base of the triangle:");
	scanf("%lf", &base);
	_triangle_right_base_ = base;
	_triangle_right_base_defined_ = true;
}

static void setTriangleHeight (void)
{
	double height = 0;
	printf("input the height of the triangle:");
	scanf("%lf", &height);
	_triangle_right_height_ = height;
	_triangle_right_height_defined_ = true;
}

static void setTriangleDims (void)
{
	setTriangleBase();
	setTriangleHeight();
}

static void calcTriangleHypotenuse (void)
{
	// DEVNOTE: this is just a GUARD to catch implementation errors in development
	if (!_triangle_right_base_defined_ || !_triangle_right_height_defined_) {
		char errmsg[] = "calcTriangleHypotenuse: "
				"TriangleUndefinedDimensionsError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	double const base = _triangle_right_base_;
	double const height = _triangle_right_height_;
	double const hypotenuse = sqrt((base * base) + (height * height));
	_triangle_right_hypotenuse_ = hypotenuse;
	_triangle_right_hypotenuse_defined_ = true;
}

static void calcTrianglePerimeter (void)
{
	bool const tr_base = _triangle_right_base_defined_;
	bool const tr_height = _triangle_right_height_defined_;
	bool const tr_hypotenuse = _triangle_right_hypotenuse_defined_;
	if (!tr_base || !tr_height || !tr_hypotenuse) {
		char errmsg[] = "calcTrianglePerimeter: "
				"TriangleUndefinedDimensionsError\n";
		fprintf(stderr, "%s", errmsg);
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	double const base = _triangle_right_base_;
	double const height = _triangle_right_height_;
	double const hypotenuse = _triangle_right_hypotenuse_;
	_triangle_right_perimeter_ = (base + height + hypotenuse);
	_triangle_right_perimeter_defined_ = true;
}

static void calcTriangleArea (void)
{
	if (!_triangle_right_base_defined_ || !_triangle_right_height_defined_) {
		char errmsg[] = "calcTriangleArea: "
				"TriangleUndefinedDimensionsError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	_triangle_right_area_ = 0.5 * (_triangle_right_base_ * _triangle_right_height_);
	_triangle_right_area_defined_ = true;
}

static void calcTriangleProps (void)
{
	calcTriangleHypotenuse();
	calcTrianglePerimeter();
	calcTriangleArea();
}

static void promptTriangleDims (void)
{
	setTriangleDims();
}

static void logTriangleInfo (void)
{
	if (!_triangle_right_perimeter_defined_ || !_triangle_right_area_defined_) {
		char errmsg[] = "logTriangleInfo: "
				"TriangleUndefinedPropertiesError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	printf("polygon: triangle\n");
	printf("perimeter: %.15e\n", _triangle_right_perimeter_);
	printf("area: %.15e\n", _triangle_right_area_);
	printf("\n");
}

static void setRectangleLength (void)
{
	double length = 0;
	printf("input the length of the rectangle:");
	scanf("%lf", &length);
	_rectangle_length_ = length;
	_rectangle_length_defined_ = true;
}

static void setRectangleWidth (void)
{
	double width = 0;
	printf("input the width of the rectangle:");
	scanf("%lf", &width);
	_rectangle_width_ = width;
	_rectangle_width_defined_ = true;
}

static void setRectangleDims (void)
{
	setRectangleLength();
	setRectangleWidth();
}

static void calcRectanglePerimeter (void)
{
	if (!_rectangle_width_defined_ || !_rectangle_length_defined_) {
		char errmsg[] = "calcRectanglePerimeter: "
				"RectangleUndefinedDimensionsError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	_rectangle_perimeter_ = 2.0 * (_rectangle_width_ + _rectangle_length_);
	_rectangle_perimeter_defined_ = true;
}

static void calcRectangleArea (void)
{
	if (!_rectangle_width_defined_ || !_rectangle_length_defined_) {
		char errmsg[] = "calcRectangleArea: "
				"RectangleUndefinedDimensionsError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	_rectangle_area_ = (_rectangle_width_ * _rectangle_length_);
	_rectangle_area_defined_ = true;
}

static void calcRectangleProps (void)
{
	calcRectangleArea();
	calcRectanglePerimeter();
}

static void promptRectangleDims (void)
{
	setRectangleDims();
}

static void logRectangleInfo (void)
{
	if (!_rectangle_perimeter_defined_ || !_rectangle_area_defined_) {
		char errmsg[] = "logRectangleInfo: "
				"RectangleUndefinedPropertiesError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	printf("polygon: rectangle\n");
	printf("perimeter: %.15e\n", _rectangle_perimeter_);
	printf("area: %.15e\n", _rectangle_area_);
	printf("\n");
}

static void setTrapezoidMinorBase (void)
{
	double base_minor = 0;
	printf("input the minor base of the trapezoid:");
	scanf("%lf", &base_minor);
	_trapezoid_base_minor_ = base_minor;
	_trapezoid_base_minor_defined_ = true;
}

static void setTrapezoidMajorBase (void)
{
	double base_major = 0;
	printf("input the major base of the trapezoid:");
	scanf("%lf", &base_major);
	_trapezoid_base_major_ = base_major;
	_trapezoid_base_major_defined_ = true;
}

static void setTrapezoidHeight (void)
{
	double height = 0;
	printf("input the height of the trapezoid:");
	scanf("%lf", &height);
	_trapezoid_height_ = height;
	_trapezoid_height_defined_ = true;
}

static void setTrapezoidDims (void)
{
	setTrapezoidMinorBase();
	setTrapezoidMajorBase();
	setTrapezoidHeight();
}

static void calcTrapezoidArea (void)
{
	bool const t_base_minor_defined = _trapezoid_base_minor_defined_;
	bool const t_base_major_defined = _trapezoid_base_major_defined_;
	bool const t_height_defined = _trapezoid_height_defined_;
	if (!t_base_minor_defined || !t_base_major_defined || !t_height_defined) {
		char errmsg[] = "calcTrapezoidArea: "
				"TrapezoidUndefinedDimensionsError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	double const base_minor = _trapezoid_base_minor_;
	double const base_major = _trapezoid_base_major_;
	double const height = _trapezoid_height_;
	_trapezoid_area_ = (0.5 * (base_minor + base_major) * height);
	_trapezoid_area_defined_ = true;
}

static void calcTrapezoidLateralSide (void)
{
	if (!_trapezoid_area_defined_) {
		char errmsg[] = "calcTrapezoidLateralSide: "
				"TrapezoidUndefinedAreaError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	// DEVNOTE:
	// These formulas were obtained from my own geometric analysis by noting that
	// the trapezoid can be broken down into a rectangle (whose dimensions are
	// base_minor and height) and two right-triangles (of dimensions base and height).
	double const area = _trapezoid_area_;
	double const height = _trapezoid_height_;
	double const base_minor = _trapezoid_base_minor_;
	double const base_major = _trapezoid_base_major_;
	double const triangle_base = ((area / height) - base_minor);
	double const base = triangle_base;
	double const lateral_side = sqrt((base * base) + (height * height));

	if (ABS(triangle_base - 0.5 * (base_major - base_minor)) > TOL) {
		char errmsg[] = "calcTrapezoidLateralSide: ImplementationError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}

	_trapezoid_lateral_side_ = lateral_side;
	_trapezoid_lateral_side_defined_ = true;
}

static void calcTrapezoidPerimeter (void)
{
	if (!_trapezoid_lateral_side_defined_) {
		char errmsg[] = "calcTrapezoidLateralSide: "
				"TrapezoidUndefinedLateralSideError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	double const base_minor = _trapezoid_base_minor_;
	double const base_major = _trapezoid_base_major_;
	double const lateral_side = _trapezoid_lateral_side_;
	_trapezoid_perimeter_ = (base_minor + base_major + 2.0 * lateral_side);
	_trapezoid_perimeter_defined_ = true;
}

static void calcTrapezoidProps (void)
{
	calcTrapezoidArea();
	calcTrapezoidLateralSide();
	calcTrapezoidPerimeter();
}

static void promptTrapezoidDims (void)
{
	setTrapezoidDims();
}

static void logTrapezoidInfo (void)
{
	if (!_trapezoid_perimeter_defined_ || !_trapezoid_area_defined_) {
		char errmsg[] = "logTrapezoidInfo: "
				"TrapezoidUndefinedPropertiesError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	printf("polygon: trapezoid\n");
	printf("perimeter: %.15e\n", _trapezoid_perimeter_);
	printf("area: %.15e\n", _trapezoid_area_);
	printf("\n");
}

static void setParallelogramBase (void)
{
	double base = 0;
	printf("input the base of the parallelogram:");
	scanf("%lf", &base);
	_parallelogram_base_ = base;
	_parallelogram_base_defined_ = true;
}

static void setParallelogramLateralSide (void)
{
	double lateral_side = 0;
	printf("input the lateral side of the parallelogram:");
	scanf("%lf", &lateral_side);
	_parallelogram_lateral_side_ = lateral_side;
	_parallelogram_lateral_side_defined_ = true;
}

static void setParallelogramHeight (void)
{
	double height = 0;
	printf("input the height of the parallelogram:");
	scanf("%lf", &height);
	_parallelogram_height_ = height;
	_parallelogram_height_defined_ = true;
}

static void setParallelogramDims (void)
{
	setParallelogramBase();
	setParallelogramHeight();
	setParallelogramLateralSide();
}

static void calcParallelogramPerimeter (void)
{
	if (!_parallelogram_base_defined_ || !_parallelogram_height_defined_) {
		char errmsg[] = "calcParallelogramPerimeter: "
				"ParallelogramUndefinedDimensionsError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	double const base = _parallelogram_base_;
	double const lateral_side = _parallelogram_lateral_side_;
	_parallelogram_perimeter_ = 2.0 * (base + lateral_side);
	_parallelogram_perimeter_defined_ = true;
}

static void calcParallelogramArea (void)
{
	if (!_parallelogram_base_defined_ || !_parallelogram_height_defined_) {
		char errmsg[] = "calcParallelogramArea: "
				"ParallelogramUndefinedDimensionsError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	_parallelogram_area_ = (_parallelogram_base_ * _parallelogram_height_);
	_parallelogram_area_defined_ = true;
}

static void calcParallelogramProps (void)
{
	calcParallelogramArea();
	calcParallelogramPerimeter();
}

static void promptParallelogramDims (void)
{
	setParallelogramDims();
}

static void logParallelogramInfo (void)
{
	if (!_parallelogram_perimeter_defined_ || !_parallelogram_area_defined_) {
		char errmsg[] = "logParallelogramInfo: "
				"ParallelogramUndefinedPropertiesError\n";
		fprintf(stderr, "%s", errmsg);
		exit(EXIT_FAILURE);
	}
	printf("polygon: parallelogram\n");
	printf("perimeter: %.15e\n", _parallelogram_perimeter_);
	printf("area: %.15e\n", _parallelogram_area_);
	printf("\n");
}

void polygon (enum polygon kind)
{
	switch (kind) {
		case TRIANGLE:
			promptTriangleDims();
			calcTriangleProps();
			logTriangleInfo();
			break;
		case RECTANGLE:
			promptRectangleDims();
			calcRectangleProps();
			logRectangleInfo();
			break;
		case TRAPEZOID:
			promptTrapezoidDims();
			calcTrapezoidProps();
			logTrapezoidInfo();
			break;
		case PARALLELOGRAM:
			promptParallelogramDims();
			calcParallelogramProps();
			logParallelogramInfo();
			break;
		default:
			printf("UNEXPECTED POLYGON KIND\n");
	}
}

/*

Polygons					May 20, 2024

source: Polygon.cpp
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
