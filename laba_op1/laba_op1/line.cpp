#include <iostream>
#include "line.h"
#include <math.h>


line::line(const float a, const float b, const float c)
{
	a_ = a;
	b_ = b;
	c_ = c;
}


void line::input()
{
	std::cin >> a_ >> b_ >> c_;
}

void line::output() const
{
	std::cout << a_ << "x + " << b_ << "y + " << c_ << " = 0" << std::endl;
}




bool line::Perpendicul(const float a, const float c) const
{
	return (a != 0 && c != 0);
}
bool line::isThroughOrigin() const {
	return (c_ == 0.0);
}


bool line::operator||(const line& other) const {
	return (a_ * other.get_b() == b_ * other.get_a());
}


bool line::pendicu_2_line(const line& other) const
{
	return std::abs((a_ * other.a_) + (b_ * other.b_)) == 0;
}

float line::atngular_kof(const float a) const
{
	if (a != 0) {
		std::cout << "K =" << a;
		return 0;
	}
	std::cout << "K = 0";
	return 1;
}

float line::distan(const float a, const float c) const
{
	return std::abs(c_) / std::sqrt(a_ * a_ + b_ * b_);
}
float line::right_angle(const line& other) const
{
	float denominator = std::sqrt(a_ * a_ + b_ * b_) * std::sqrt(other.a_ * other.a_ + other.b_ * other.b_);

	if (denominator < 1e-5f) {
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