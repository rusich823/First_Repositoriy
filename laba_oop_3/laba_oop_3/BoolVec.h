#pragma once
#include <stdint.h>
#include <iostream>

class BoolVec
{
public:
	class BitReference;

	BoolVec() = default;
	BoolVec(const uint32_t numBits, const bool initialValue = false);
	BoolVec(const BoolVec& other);
	BoolVec(const char* bitstring);
	~BoolVec();

	uint32_t size() const;

	bool operator[](const uint32_t bitIndex) const;
	BitReference operator[](const uint32_t bitIndex);
	BoolVec& operator=(const BoolVec& other);
	BoolVec operator~()const;
	BoolVec operator&(const BoolVec& other) const;

	void setValue(const uint32_t bitIndex, const bool newValue);
	void swap(BoolVec& other);
	void invert();
	



private:
	uint8_t* vectorData_ = nullptr;
	uint32_t numBits_ = 0;
	uint32_t numBytes_ = 0;
};

class BoolVec::BitReference
{
public:
	BitReference(uint8_t* bytePtr, uint32_t bitIndex);

	operator bool();
	void operator=(const bool newValue);

private:
	uint8_t* bytePtr_;
	uint32_t bitIndex_;
};

std::istream& operator>>(std::istream& inputStream, BoolVec& boolVec);
std::ostream& operator<<(std::ostream& outputStream, const BoolVec& boolVec);
