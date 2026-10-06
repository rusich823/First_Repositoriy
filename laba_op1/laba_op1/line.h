#pragma once
class line {
public:
	line(float a = 0.0, float b = 0.0, float c = 0.0);

	void input();
	void output() const;




	float get_a() const;
	float get_b() const;
	float get_c() const;
private:
	float a_ = 0.0;
	float b_ = 0.0;
	float c_ = 0.0;
};