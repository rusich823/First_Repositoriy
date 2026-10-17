#pragma once


class Line {
public:
	Line() = default;
	Line(float a , float b , float c );

	void input();
	void output() const;


	bool isThroughOrigin() const;
	bool perpendicul() const;
	bool operator||(const Line& other) const;
	bool pendicu_2_line(const Line& other) const;
	bool hasPoint(const float x, const float y) const;

	float atngular_kof() const;
	float distan() const;
	float right_angle(const Line& other) const;	


	void set_a(const float a);
	void set_b(const float b);
	void set_c(const float c);


	float get_a() const;
	float get_b() const;
	float get_c() const;
private:
	float a_ = 0.0;
	float b_ = 0.0;
	float c_ = 0.0;
};