#include <iostream>
#include <iomanip>
#include "Fraction.h"
using namespace std;

ostream& operator<<(ostream& output, const Fraction& frac) {	
	output << frac.integer_fraction << "(" << frac.numerator << "/" << frac.denominator << ")";
	return output;
}
istream& operator>>(istream& input, Fraction& frac) {
	input >> setw(1) >> frac.integer_fraction;
	input.ignore(1);
	input >> setw(1) >> frac.numerator;
	input.ignore(1);
	input >> setw(1) >> frac.denominator;
	return input;
}

//private
void Fraction::setIntegerFraction(int value) {
		integer_fraction = value;		
	}
void Fraction::setNumerator(int value) {
		numerator = value;		
	}
void Fraction::setDenominator(int value) {
	if (value) denominator = value;
	else cout << "Значение знаменателя не может быть равным нулю" << endl;	
}

const int Fraction::getIntegerFraction() const {
		return integer_fraction;
}
const int Fraction::getNumerator() const {
		return numerator;
}
const int Fraction::getDenominator() const {
		return denominator;
}

void Fraction::сalculatingAndSetingIntegerFraction(Fraction& frac) {	
	if (frac.numerator > frac.denominator){
		frac.setIntegerFraction(frac.numerator / frac.denominator);
		frac.setNumerator(frac.numerator - (frac.integer_fraction * frac.denominator));
		frac.setDenominator(frac.denominator == 1 ? 0 : frac.denominator);
	}
	else if (frac.numerator == frac.denominator) {
		frac.setIntegerFraction(frac.integer_fraction + 1);
		frac.setNumerator(0);
		frac.setDenominator(0);
	}
}
int Fraction::getGreatestCommonDivisor(int first_value, int second_value) {
	while (first_value != second_value)	{
		first_value > second_value ? first_value -= second_value : second_value -= first_value;
	}	
	return first_value;
}

//public
Fraction::Fraction(int integer_fraction, int numerator, int denominator){		
		setIntegerFraction(integer_fraction);
		setNumerator(numerator);
		setDenominator(denominator);
	}
Fraction::~Fraction(){}

Fraction::Fraction(const Fraction& other) {		
		this->setIntegerFraction(other.integer_fraction);
		this->setNumerator(other.numerator);
		this->setDenominator(other.denominator);
	}
Fraction& Fraction::operator=(const Fraction& other) {		
		this->setNumerator(other.numerator);
		this->setDenominator(other.denominator);
		this->setIntegerFraction(other.integer_fraction);
		return *this;
	}

const Fraction Fraction::operator+(const Fraction& other) {	
	Fraction temp_fraction;

	temp_fraction.setNumerator(((this->integer_fraction * this->denominator + this->numerator) * other.denominator) +
					  ((other.integer_fraction * other.denominator + other.numerator) * this->denominator));

	temp_fraction.setDenominator(this->denominator * other.denominator);

	fractionReduction(temp_fraction);
	сalculatingAndSetingIntegerFraction(temp_fraction);
	return temp_fraction;
}
const Fraction Fraction::operator-(const Fraction& other) {	
	Fraction temp_fraction;
	temp_fraction.setNumerator(fabs(((this->integer_fraction * this->denominator + this->numerator) * other.denominator) -
		((other.integer_fraction * other.denominator + other.numerator) * this->denominator)));
	temp_fraction.setDenominator(this->denominator * other.denominator);

	fractionReduction(temp_fraction);
	сalculatingAndSetingIntegerFraction(temp_fraction);
	return temp_fraction;
}
const Fraction Fraction::operator*(const Fraction& other) {	
	Fraction temp_fraction;

	temp_fraction.setNumerator((this->integer_fraction * this->denominator + this->numerator) *
		(other.integer_fraction * other.denominator + other.numerator));
	temp_fraction.setDenominator(this->denominator * other.denominator);

	fractionReduction(temp_fraction);
	сalculatingAndSetingIntegerFraction(temp_fraction);
	return temp_fraction;
}
const Fraction Fraction::operator/(const Fraction& other) {	
	Fraction temp_fraction;

	temp_fraction.setNumerator((this->integer_fraction * this->denominator + this->numerator) * other.denominator);
	temp_fraction.setDenominator((other.integer_fraction * other.denominator + other.numerator) * this->denominator);

	fractionReduction(temp_fraction);
	сalculatingAndSetingIntegerFraction(temp_fraction);
	return temp_fraction;
}

Fraction& Fraction::operator+=(const Fraction& other){
	this->setNumerator(((this->integer_fraction * this->denominator + this->numerator) * other.denominator) +
		((other.integer_fraction * other.denominator + other.numerator) * this->denominator));
	this->setDenominator(this->denominator * other.denominator);

	fractionReduction(*this);
	сalculatingAndSetingIntegerFraction(*this);
	
	return *this;
}
Fraction& Fraction::operator-=(const Fraction& other) {
	this->setNumerator(((this->integer_fraction * this->denominator + this->numerator) * other.denominator) -
		((other.integer_fraction * other.denominator + other.numerator) * this->denominator));
	this->setDenominator(this->denominator * other.denominator);

	fractionReduction(*this);
	сalculatingAndSetingIntegerFraction(*this);

	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other) {
	this->setNumerator((this->integer_fraction * this->denominator + this->numerator) *
		(other.integer_fraction * other.denominator + other.numerator));
	this->setDenominator(this->denominator * other.denominator);

	fractionReduction(*this);
	сalculatingAndSetingIntegerFraction(*this);

	return *this;
}
Fraction& Fraction::operator/=(const Fraction& other) {
	this->setNumerator((this->integer_fraction * this->denominator + this->numerator) * other.denominator);
	this->setDenominator((other.integer_fraction * other.denominator + other.numerator) * this->denominator);

	fractionReduction(*this);
	сalculatingAndSetingIntegerFraction(*this);

	return *this;
}

bool Fraction::operator==(const Fraction& other) {
	return (this->numerator * other.denominator) == (other.numerator * this->denominator);
}
bool Fraction::operator!=(const Fraction& other) {
	return !(this->operator==(other));
}
bool Fraction::operator>(const Fraction& other) {
	return ((this->integer_fraction * this->denominator + this->numerator) * other.denominator) >
		   ((other.integer_fraction * other.denominator + other.numerator) * this->denominator);
}
bool Fraction::operator<(const Fraction& other) {
	return !(this->operator>(other));
}
bool Fraction::operator>=(const Fraction& other) {
	return this->operator>(other) || this->operator==(other);
}
bool Fraction::operator<=(const Fraction& other) {
	return !(this->operator>(other)) || this->operator==(other);
}

void Fraction::fractionReduction(Fraction& frac) {	
	int greatest_common_divisor = getGreatestCommonDivisor(frac.numerator, frac.denominator);
	frac.setNumerator(frac.numerator / greatest_common_divisor);
	frac.setDenominator(frac.denominator / greatest_common_divisor);	
}
Fraction& Fraction::power(Fraction& frac, int value) {
	if (value < 0) {
		int temp_numerator = frac.getIntegerFraction() * frac.getDenominator() + frac.getNumerator();
		frac.setNumerator(frac.getDenominator());
		frac.setDenominator(temp_numerator);

		for (size_t i = 1; i < fabs(value); i++) frac *= frac;
	}
	else if (value == 0) {
		frac.setIntegerFraction(1);
		frac.setNumerator(0);
		frac.setDenominator(1);
	}	
	else {
		for (size_t i = 1; i < value; i++) frac *= frac;
	}
	return frac;	
}
Fraction& Fraction::square(Fraction& frac) {
	frac.setNumerator(sqrt(frac.getIntegerFraction() * frac.getDenominator() + frac.getNumerator()));
	frac.setDenominator(sqrt(frac.getDenominator()));

	fractionReduction(frac);
	сalculatingAndSetingIntegerFraction(frac);
	return frac;
}
double Fraction::convertToDecimalFraction() {
	return this->getNumerator() / this->getDenominator();
}
//Fraction Fraction::getFromDecimalFraction(double value) {
//	
//}