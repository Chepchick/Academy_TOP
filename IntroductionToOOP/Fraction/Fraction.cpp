#include <iostream>
#include <iomanip>
#include <sstream>
#include "Fraction.h"

using namespace std;

//private
void Fraction::setIntegerFraction(int value) {
	integer_fraction = value ? fabs(value) : 0;	
}
void Fraction::setNumerator(int value) {
	if (fraction_is_negativ) {
		fraction_is_negativ = value < 0 ? false : true;
	}
	else {
		fraction_is_negativ = value < 0 ? true : false;
	}
	
	numerator = value ? fabs(value) : 0;
}
void Fraction::setDenominator(int value) {
	denominator = value ? fabs(value) : 1;

	if (fraction_is_negativ) {
		fraction_is_negativ = value < 0 ? false : true;
	} else {
		fraction_is_negativ = value < 0 ? true : false;
	}

	if (numerator == 0) denominator = 1;
}

int Fraction::getIntegerFraction() const {
	return integer_fraction;
}
int Fraction::getNumerator() const {
	return numerator;
}
int Fraction::getDenominator() const {
	return denominator;
}

short Fraction::sign() const {
	return fraction_is_negativ ? -1 : 1;
}
void сalculatingAndSetingIntegerFraction(Fraction& frac) {
	if (frac.numerator > frac.denominator) {
		frac.setIntegerFraction(frac.numerator / frac.denominator);
		frac.setNumerator(frac.numerator - (frac.integer_fraction * frac.denominator));
		/*frac.setDenominator(frac.denominator == 1 ? 0 : frac.denominator);*/
	}
	else if (frac.numerator == frac.denominator) {
		frac.setIntegerFraction(frac.integer_fraction + 1);
		frac.setNumerator(0);
		frac.setDenominator(1);
	}
}
int getGreatestCommonDivisor(int first_value, int second_value) {
	while (first_value != second_value) {
		first_value > second_value ? first_value -= second_value : second_value -= first_value;
	}
	return first_value;
}

//public
Fraction::Fraction(int int_fract, int num, int den)
{
	fraction_is_negativ = false ;
	setIntegerFraction(int_fract);
	setNumerator(num);
	setDenominator(den);
}
Fraction::Fraction() : Fraction{ 0,0,1 } {};

const Fraction operator+(const Fraction& left, const Fraction& right) {
	Fraction temp_fraction;
	
	temp_fraction.setNumerator(((left.getIntegerFraction() * left.getDenominator() + left.getNumerator()) * right.getDenominator()) * left.sign() +
							  ((right.getIntegerFraction() * right.getDenominator() + right.getNumerator()) * left.getDenominator()) * right.sign());
	temp_fraction.setDenominator(left.getDenominator() != right.getDenominator() ? left.getDenominator() * right.getDenominator(): left.getDenominator());

	сalculatingAndSetingIntegerFraction(temp_fraction);
	Fraction::fractionReduction(temp_fraction);
	return temp_fraction;
}
const Fraction operator-(const Fraction& left, const Fraction& right) {
	Fraction temp_fraction;
	
	temp_fraction.setNumerator(((left.getIntegerFraction() * left.getDenominator() + left.getNumerator()) * right.getDenominator()) * left.sign() -
							  ((right.getIntegerFraction() * right.getDenominator() + right.getNumerator()) * left.getDenominator()) * right.sign());
	temp_fraction.setDenominator(left.getDenominator() != right.getDenominator() ? left.getDenominator() * right.getDenominator() : left.getDenominator());

	сalculatingAndSetingIntegerFraction(temp_fraction);
	Fraction::fractionReduction(temp_fraction);
	return temp_fraction;
}
const Fraction operator*(const Fraction& left, const Fraction& right) {
	Fraction temp_fraction;	

	temp_fraction.setNumerator((left.sign() * (left.getIntegerFraction() * left.getDenominator() + left.getNumerator())) *
							  (right.sign() * (right.getIntegerFraction() * right.getDenominator() + right.getNumerator())));
	temp_fraction.setDenominator(left.getDenominator() * right.getDenominator());

	сalculatingAndSetingIntegerFraction(temp_fraction);
	Fraction::fractionReduction(temp_fraction);
	return temp_fraction;
}
const Fraction operator/(const Fraction& left, const Fraction& right) {
	Fraction temp_fraction;
	
	temp_fraction.setNumerator((left.sign() * (left.getIntegerFraction() * left.getDenominator() + left.getNumerator())) * (right.sign() * right.getDenominator()));
	temp_fraction.setDenominator((right.getIntegerFraction() * right.getDenominator() + right.getNumerator()) * left.getDenominator());

	сalculatingAndSetingIntegerFraction(temp_fraction);
	Fraction::fractionReduction(temp_fraction);
	return temp_fraction;
}

Fraction& Fraction::operator+=(const Fraction& other) {
	
	this->setNumerator(((this->getIntegerFraction() * this->getDenominator() + this->getNumerator()) * other.getDenominator() * this->sign()) +
								   ((other.getIntegerFraction() * other.getDenominator() + other.getNumerator()) * this->getDenominator() * other.sign()));
	this->setDenominator(this->getDenominator() * other.getDenominator());

	сalculatingAndSetingIntegerFraction(*this);
	Fraction::fractionReduction(*this);

	return *this;
}
Fraction& Fraction::operator-=(const Fraction& other) {
	
	this->setNumerator(((this->getIntegerFraction() * this->getDenominator() + this->getNumerator()) * other.getDenominator() * this->sign()) -
								   ((other.getIntegerFraction() * other.getDenominator() + other.getNumerator()) * this->getDenominator() * other.sign()));
	this->setDenominator(this->getDenominator() * other.getDenominator());

	сalculatingAndSetingIntegerFraction(*this);
	Fraction::fractionReduction(*this);

	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other) {	

	this->setNumerator((this->getIntegerFraction() * this->getDenominator() + this->getNumerator()) *
		other.sign() * (other.getIntegerFraction() * other.getDenominator() + other.getNumerator()));
	this->setDenominator(this->getDenominator() * other.getDenominator());

	сalculatingAndSetingIntegerFraction(*this);
	Fraction::fractionReduction(*this);

	return *this;
}
Fraction& Fraction::operator/=(const Fraction& other) {

	short this_sign = this->sign();
	short other_sign = other.sign();

	this->setNumerator((this->getIntegerFraction() * this->getDenominator() + this->getNumerator()) * other.getDenominator() * other.sign());
	this->setDenominator((other.getIntegerFraction() * other.getDenominator() + other.getNumerator()) * this->getDenominator());

	сalculatingAndSetingIntegerFraction(*this);
	Fraction::fractionReduction(*this);

	return *this;
}

bool operator==(const Fraction& left, const Fraction& right) {	

	return (left.getNumerator() * right.getDenominator() * left.sign()) == (right.getNumerator() * left.getDenominator() * right.sign());
}
bool operator!=(const Fraction& left, const Fraction& right) {
	return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right) {
	
	return ((left.getIntegerFraction() * left.getDenominator() + left.getNumerator()) * right.getDenominator() * left.sign()) >
		  ((right.getIntegerFraction() * right.getDenominator() + right.getNumerator()) * left.getDenominator() * right.sign());
}
bool operator<(const Fraction& left, const Fraction& right) {
	return !(left > right);
}
bool operator>=(const Fraction& left, const Fraction& right) {
	return left > right || left == right;
}
bool operator<=(const Fraction& left, const Fraction& right) {
	return !(left > right) || left == right;
}

void Fraction::fractionReduction(Fraction& frac) {
	if (frac.numerator) {
		int greatest_common_divisor = getGreatestCommonDivisor(frac.numerator, frac.denominator);
		frac.setNumerator(frac.numerator / greatest_common_divisor);
		frac.setDenominator(frac.denominator / greatest_common_divisor);
	}
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
		Fraction temp(frac);
		for (size_t i = 1; i < value; i++) frac *= temp;
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
	short this_sign = this->fraction_is_negativ ? -1 : 1;
	double res = (double)this->getNumerator() * this_sign / this->getDenominator();
	return res;
}

ostream& operator<<(ostream& output, const Fraction& frac) {
	char sign = frac.fraction_is_negativ ? '-' : ' ';
	output << sign << frac.integer_fraction << "(" << frac.numerator << "/" << frac.denominator << ")";
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