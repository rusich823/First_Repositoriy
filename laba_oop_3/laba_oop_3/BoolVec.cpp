#include "BoolVec.h"
#include <stdint.h>
#include <cstring>


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
BoolVec::BoolVec(const BoolVec& other) : vectorData_(nullptr),numBits_(other.numBits_),numBytes_(other.numBytes_)
{ 
	if (numBytes_ > 0) {
		vectorData_ = new uint8_t[numBytes_];
		for (uint32_t i = 0; i < numBytes_; i++) {
			vectorData_[i] = other.vectorData_[i];
		}
	}
}
BoolVec::BoolVec(const char* bitstring) {
	if (bitstring == nullptr) return;
	numBits_=strlen(bitstring);
	numBytes_= numBits_ / 8;
	if (numBits_ % 8) numBytes_++;
	if (numBytes_ > 0)
	 vectorData_ = new uint8_t[numBytes_]();
	for (uint32_t i = 0; i < numBits_; i++){
		setValue(i, bitstring[i] == '1');
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
BoolVec& BoolVec::operator=(const BoolVec& other) {
	if (this != &other) {
		delete[] vectorData_;
		numBits_ = other.numBits_;
		numBytes_ = other.numBytes_;

	    if(numBytes_>0) vectorData_ = new uint8_t[numBytes_];
		
		else vectorData_ = nullptr;

		for (uint32_t i = 0; i < numBytes_; i++) {
			vectorData_[i] = other.vectorData_[i];
		}
	}
	return *this;
}

void BoolVec::swap(BoolVec& other) {
	uint32_t numByt = numBytes_;
	numBytes_ = other.numBytes_;
	other.numBytes_ = numByt;

	uint32_t numBit = numBits_;
	numBits_ = other.numBits_;
	other.numBits_ = numBit;

	uint8_t* vectorDat =vectorData_ ;
	vectorData_ = other. vectorData_;
	other.vectorData_ = vectorDat;
}
void BoolVec::invert() {
	for (uint32_t i = 0; i < numBytes_; i++) {
		vectorData_[i] = ~vectorData_[i];
	}
}



BoolVec BoolVec::operator~()const {
	BoolVec res = *this;
	for (uint32_t i = 0; i < numBytes_; i++) {
		res.vectorData_[i] = ~res.vectorData_[i];
	}
	return res;
}

BoolVec BoolVec::operator&(const BoolVec& other) const{
	uint32_t minBits;
	if (numBits_ < other.numBits_)
		 minBits = numBits_;
	else  minBits = other.numBits_;
	BoolVec res(minBits, false);

	for (uint32_t i = 0; i < res.numBytes_; i++) {
		res.vectorData_[i] = vectorData_[i] & other.vectorData_[i];
	}
	return res;
}

BoolVec BoolVec::operator|(const BoolVec& other) const {
	uint32_t minBits;
	if (numBits_ < other.numBits_)
		minBits = numBits_;
	else  minBits = other.numBits_;
	BoolVec res(minBits, false);

	for (uint32_t i = 0; i < res.numBytes_; i++) {
		res.vectorData_[i] = vectorData_[i] | other.vectorData_[i];
	}
	return res;
}
BoolVec BoolVec::operator^ (const BoolVec& other) const {
	uint32_t minBits;
	if (numBits_ < other.numBits_)
		minBits = numBits_;
	else  minBits = other.numBits_;
	BoolVec res(minBits, false);

	for (uint32_t i = 0; i < res.numBytes_; i++) {
		res.vectorData_[i] = vectorData_[i] ^ other.vectorData_[i];
	}
	return res;
}

BoolVec BoolVec::operator<<(const uint32_t shift) const {
	BoolVec res (numBits_, false);;
	if (shift < numBits_) {
		for (uint32_t i = shift; i < numBits_; i++) {
			res.setValue(i - shift, (*this)[i]);
		}
	}
	return res;
}
BoolVec BoolVec::operator>>(const uint32_t shift) const {
	BoolVec res(numBits_, false);;
	if (shift < numBits_) {
		for (uint32_t i = 0; i < numBits_-shift; i++) {
			res.setValue(i + shift, (*this)[i]);
		}
	}
	return res;
}