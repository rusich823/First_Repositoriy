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
