#include <iostream>
#include "line.h"
#include <locale>

int main() {
	setlocale(LC_ALL, ".UTF8");

	
	line line1;
	std::cout << "Введите a1, b1, c1: " << std::endl;
	line1.input();
	line1.output();

	
	std::cout << "K = " << line1.atngular_kof() << std::endl;
	std::cout << "Origin = " << line1.isThroughOrigin() << std::endl;
	std::cout << "Ox = " << line1.Perpendicul() << std::endl;
	std::cout << "Dist = " << line1.distan() << std::endl;

	
	Point p;
	std::cout << "Ввелите точку x y: " << std::endl;
	std::cin >> p.x >> p.y;
	std::cout << std::boolalpha;
	std::cout << "Пренадлежность = " << line1.hasPoint(p) << std::endl;

	
	line line2;
	std::cout << "Введите a2, b2, c2: " << std::endl;
	line2.input();
	line2.output();

	std::cout << std::boolalpha;
	std::cout << "Паралельность = " << (line1 || line2) << std::endl;
	std::cout << "Перпендикулярность двух линний = " << line1.pendicu_2_line(line2) << std::endl;
	std::cout << "Угол = " << line1.right_angle(line2) << std::endl;

	return 0;
}
