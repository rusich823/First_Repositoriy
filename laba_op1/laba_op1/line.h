#pragma once

struct Point {
	float x;
	float y;
};

class line {
public:
	line() = default;
	line(float a , float b , float c );

	void input();
	void output() const;


	bool isThroughOrigin() const;
	bool Perpendicul() const;
	bool operator||(const line& other) const;
	bool pendicu_2_line(const line& other) const;
	bool hasPoint(const Point& p) const;

	float atngular_kof() const;
	float distan() const;
	float right_angle(const line& other) const;	


	void set_a(float a);
	void set_b(float b);
	void set_c(float c);


	float get_a() const;
	float get_b() const;
	float get_c() const;
private:
	float a_ = 0.0;
	float b_ = 0.0;
	float c_ = 0.0;
};