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

BoolVec::BitReference::operator bool() const {
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

void BoolVec::invert_id(const uint32_t index1) {
	if (index1 < numBits_) {
		if ((*this)[index1] == false) this->setValue(index1, true);
		else
		{
			this->setValue(index1, false);
		}
	}
}
void BoolVec::add_all(bool value) {
	for (uint32_t i = 0; i < numBits_; i++) {
		(*this)[i] = value;
	}
}
void BoolVec::add_id(const uint32_t index1, bool value) {
	if (index1 < numBits_) (*this)[index1] = value;

}
void BoolVec::add_k_id(const uint32_t index1, const uint32_t k, bool value)
{
	if (index1 < numBits_) {
		for (uint32_t i = index1;   i < index1 + k && i < numBits_; i++) {
			(*this)[i] = value;
		}
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
BoolVec& BoolVec::operator&=(const BoolVec& other) {
	*this = *this & other;
	return *this;
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
BoolVec& BoolVec::operator|=(const BoolVec& other) {
	*this = *this | other;
	return *this;
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
BoolVec& BoolVec::operator^=(const BoolVec& other) {
	*this = *this ^ other;
	return *this;
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
BoolVec& BoolVec::operator<<=(const uint32_t shift) {
	*this = *this << shift;
	return *this;
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
BoolVec& BoolVec::operator>>=(const uint32_t shift) {
	*this = *this >> shift;
	return *this;
}

uint32_t BoolVec::weight() const {
	uint32_t count = 0;
	for (uint32_t i = 0; i < numBits_; i++) {
		if ((*this)[i] == 1) count++;
	}
	return count;
}


BoolVec::BitReference& BoolVec::BitReference::operator=(const BitReference& other)
{
	*this = (bool)other;
	return *this;
}
BoolVec::BitReference& BoolVec::BitReference::operator&=(const bool val) {
	*this = (bool)*this & val;
	return *this;
}
BoolVec::BitReference& BoolVec::BitReference::operator|=(const bool val) {
	*this = (bool)*this | val;
	return *this;

}
BoolVec::BitReference& BoolVec::BitReference::operator^=(const bool val) {
	*this = (bool)*this ^ val;
	return *this;
}
bool BoolVec::BitReference::operator~() const {
	if ((bool)*this == 0) return true;
	return false;
}
bool BoolVec::BitReference::operator&(const bool val) const {
	return  ((bool)*this & val);
}

bool BoolVec::BitReference::operator|(const bool val) const {
	return  ((bool)*this | val);
}

bool BoolVec::BitReference::operator^(const bool val) const {
	return  ((bool)*this ^ val);
}
bool BoolVec::BitReference::operator==(const bool val) const {
	return ((bool)*this == val);
}
bool BoolVec::BitReference::operator!=(const bool val) const {
	return !((bool)*this == val);
}
void BoolVec::sdvig() {
	uint32_t ves = this->weight();
	this->add_all(false);
	this->add_k_id(numBits_-ves,ves,true);
	//for (uint32_t i = 0; i < ves; i++) {
		//(*this)[numBits_- 1 - i] = true;
	//}
	//
}
bool BoolVec::equality() const {

	if (numBits_ % 2 == 0) {
		uint32_t ves = this->weight();
		if ((numBits_ / 2) != ves) return false;
		return true;
	}
	return false;
}
void BoolVec::swap_bit(const uint32_t index1, const uint32_t index2) {
	if (index1 < numBits_ && index2 < numBits_)
	{
		bool copy = (*this)[index1];
		(*this)[index1] = (*this)[index2];
		(*this)[index2] = copy;
	}
}
void BoolVec::revers() {
	for (uint32_t i = 0; i < numBits_ / 2; i++) {
		this->swap_bit(i,numBits_-1-i);
	}
}