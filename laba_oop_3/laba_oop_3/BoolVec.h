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
	uint32_t weight() const;


	bool equality() const;

	bool operator[](const uint32_t bitIndex) const;
	BitReference operator[](const uint32_t bitIndex);
	BoolVec& operator=(const BoolVec& other);
	BoolVec operator~()const;
	BoolVec operator&(const BoolVec& other) const;
	BoolVec operator|(const BoolVec& other) const;
	BoolVec operator^ (const BoolVec& other) const;
	BoolVec operator<<(const uint32_t shift) const;
	BoolVec operator>>(const uint32_t shift) const;
	BoolVec& operator&=(const BoolVec& other);
	BoolVec& operator|=(const BoolVec& other);
	BoolVec& operator^=(const BoolVec& other);
	BoolVec& operator<<=(const uint32_t shift);
	BoolVec& operator>>=(const uint32_t shift);

	void setValue(const uint32_t bitIndex, const bool newValue);
	void swap(BoolVec& other);
	void invert();
	void invert_id(const uint32_t index1);
	void add_all(bool value);
	void add_id(const uint32_t index1, bool value);
	void add_k_id(const uint32_t index1, const uint32_t k, bool value);
	void sdvig();
	void swap_bit(const uint32_t index1,const uint32_t index2);
	void revers();



private:
	uint8_t* vectorData_ = nullptr;
	uint32_t numBits_ = 0;
	uint32_t numBytes_ = 0;
};

class BoolVec::BitReference
{
public:
	BitReference(uint8_t* bytePtr, uint32_t bitIndex);

	operator bool() const;
	void operator=(const bool newValue);
	BitReference& operator=(const BitReference& other);
	BitReference& operator&=(const bool val);
	BitReference& operator|=(const bool val);
	BitReference& operator^=(const bool val);

	bool operator~() const;
	bool operator&(const bool val) const;
	bool operator|(const bool val) const;
	bool operator^(const bool val) const;
	bool operator==(const bool val) const;
	bool operator!=(const bool val) const;


private:
	uint8_t* bytePtr_;
	uint32_t bitIndex_;
};

std::istream& operator>>(std::istream& inputStream, BoolVec& boolVec);
std::ostream& operator<<(std::ostream& outputStream, const BoolVec& boolVec);
