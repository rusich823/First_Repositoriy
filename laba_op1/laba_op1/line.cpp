#include <iostream>
#include "line.h"
#include <math.h>


Line::Line(const float a, const float b, const float c)
{
	a_ = a;
	b_ = b;
	c_ = c;
}


void Line::input()
{
	std::cin >> a_ >> b_ >> c_;
}

void Line::output() const
{
	std::cout << a_ << "x + " << b_ << "y + " << c_ << " = 0" << std::endl;
}


bool Line::hasPoint(const float x, const float y) const {

	float result = (a_ * x) + (b_ * y) + c_;

	return std::abs(result) < 0.000001f;
}



bool Line::perpendicul() const
{
	return (a_ != 0 && c_ != 0);
}

bool Line::isThroughOrigin() const {

	return (c_ == 0.0);
}


bool Line::operator||(const Line& other) const {

	return (a_ * other.b_ == b_ * other.a_);

}


bool Line::pendicu_2_line(const Line& other) const
{
	return std::abs((a_ * other.a_) + (b_ * other.b_)) == 0;
}

float Line::atngular_kof() const
{
	if (a_ != 0.0f) {

		return ( - a_ / b_);
	
	}
	
	return 0.0f;
}

float Line::distan() const
{
	return std::abs(c_) / std::sqrt(a_ * a_ + b_ * b_);
}


float Line::right_angle(const Line& other) const
{
	float denominator = std::sqrt(a_ * a_ + b_ * b_) * std::sqrt(other.a_ * other.a_ + other.b_ * other.b_);

	if (denominator == 0.0f) {
		return 0.0f;
	}

	float numerator = std::abs((a_ * other.a_) + (b_ * other.b_));

	float cos_alpha = numerator / denominator;

	if (cos_alpha > 1.0f) {
		cos_alpha = 1.0f;
	}

	if (cos_alpha < -1.0f) {
		cos_alpha = -1.0f;
	}
	float angle_in_radians = std::acos(cos_alpha);

	float angle_in_degrees = angle_in_radians * 180.0f / 3.14159265f;

	return angle_in_degrees;
}

float Line::get_a() const {
	return a_;
}

float Line::get_b() const {
	return b_;
}

float Line::get_c() const {
	return c_;
}

void Line::set_a(float a) {
	a_ = a;
}

void Line::set_b(float b) {
	b_ = b;
}

void Line::set_c(float c) {
	c_ = c;
}