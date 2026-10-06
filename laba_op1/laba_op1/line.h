#pragma once
class line {
public:
	line(float a = 0.0, float b = 0.0, float c = 0.0);

	void input();
	void output() const;


	bool isThroughOrigin() const;
	bool Perpendicul(const float a, const float c) const;
	bool operator||(const line& other) const;
	bool pendicu_2_line(const line& other) const;

	float get_a() const;
	float get_b() const;
	float get_c() const;
private:
	float a_ = 0.0;
	float b_ = 0.0;
	float c_ = 0.0;
};