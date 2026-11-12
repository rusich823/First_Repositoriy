#include "BoolVec.h"
#include <stdint.h>

BoolVec::BoolVec(const uint32_t numBits, const bool initialValue) {
	numBits_ = numBits;
	numBytes_ = numBits_ / 8;
	if (numBits_ % 8) numBytes_++;

	if (numBytes_ > 0) {
		vectorData_ = new uint8_t[numBytes_];
		if (initialValue == true) {
			for (uint32_t i = 0; i < numBytes_; i++) {
				vectorData_[i] = 255;
			}
		}
		else {
			for (uint32_t i = 0; i < numBytes_; i++) {
				vectorData_[i] = 0;
			}
		}
	}
}

BoolVec::~BoolVec() {
	delete[] vectorData_;
}

uint32_t BoolVec::size() const {
	return numBits_;
}

bool BoolVec::operator[](const uint32_t bitIndex) const {
	uint32_t byteIndex = bitIndex / 8;
	uint32_t bitWithinByte = bitIndex % 8;

	return vectorData_[byteIndex] & (1 << bitWithinByte);
}

BoolVec::BitReference BoolVec::operator[](const uint32_t bitIndex) {
	uint32_t byteIndex = bitIndex / 8;
	uint32_t bitWithinByte = bitIndex % 8;

	return BitReference(&vectorData_[byteIndex], bitWithinByte);
}

void BoolVec::setValue(const uint32_t bitIndex, const bool newValue) {
	uint32_t byteIndex = bitIndex / 8;
	uint32_t bitWithinByte = bitIndex % 8;

	if (newValue)
		vectorData_[byteIndex] |= (1 << bitWithinByte);
	else
		vectorData_[byteIndex] &= ~(1 << bitWithinByte);
}

BoolVec::BitReference::BitReference(uint8_t* bytePtr, uint32_t bitIndex)
	: bytePtr_(bytePtr), bitIndex_(bitIndex) {
}

BoolVec::BitReference::operator bool() {
	return *bytePtr_ & (1 << bitIndex_);
}

void BoolVec::BitReference::operator=(const bool newValue) {
	if (newValue)
		*bytePtr_ |= (1 << bitIndex_);
	else
		*bytePtr_ &= ~(1 << bitIndex_);
}

std::istream& operator>>(std::istream& inputStream, BoolVec& boolVec) {
	uint32_t numBits;
	inputStream >> numBits;

	boolVec = BoolVec(numBits, false);

	for (uint32_t bitIndex = 0; bitIndex < numBits; bitIndex++) {
		char bitChar;
		inputStream >> bitChar;
		boolVec.setValue(bitIndex, bitChar == '1');
	}

	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const BoolVec& boolVec) {
	uint32_t numBits = boolVec.size();

	for (uint32_t bitIndex = 0; bitIndex < numBits; bitIndex++) {
		outputStream << (boolVec[bitIndex] ? "1" : "0");
	}

	return outputStream;
}
