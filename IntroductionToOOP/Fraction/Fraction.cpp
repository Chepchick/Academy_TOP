﻿#include <iostream>
#include <iomanip>
#include <sstream>

#include "Fraction.h"
using namespace std;


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

int Fraction::getIntegerFraction() const {
		return integer_fraction;
}
int Fraction::getNumerator() const {
		return numerator;
}
int Fraction::getDenominator() const {
		return denominator;
}

void сalculatingAndSetingIntegerFraction(Fraction& frac) {	
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
int getGreatestCommonDivisor(int first_value, int second_value) {
	while (first_value != second_value)	{
		first_value > second_value ? first_value -= second_value : second_value -= first_value;
	}	
	return first_value;
}
int Fraction::getFractionPartOfDoubleValue(const double value, int& size) {
	ostringstream ostr;
	ostr << value;
	string string_value = ostr.str();

	string fraction_part_of_string_value;
	int frac_part(0);

	size_t count(0);
	while (string_value[count] != '.')count++;
	for (; string_value[count + 1] != 0; count++) {
		fraction_part_of_string_value += string_value[count + 1];
	}
	for (size_t i = 0; i < fraction_part_of_string_value.size(); i++) {
		frac_part += (int)(fraction_part_of_string_value[i] - '0') * pow(10, fraction_part_of_string_value.size() - i - 1);
	}
	size = fraction_part_of_string_value.size();
	return frac_part;
}

//public
Fraction::Fraction(int integer_fraction, int numerator, int denominator){		
		setIntegerFraction(integer_fraction);
		setNumerator(numerator);
		setDenominator(denominator);
	}

Fraction::Fraction(const Fraction& other) {		
		setIntegerFraction(other.integer_fraction);
		setNumerator(other.numerator);
		setDenominator(other.denominator);
	}
Fraction& Fraction::operator=(const Fraction& other) {		
		setNumerator(other.numerator);
		setDenominator(other.denominator);
		setIntegerFraction(other.integer_fraction);

		return *this;
	}

Fraction operator+(const Fraction& left, const Fraction& right) {
	Fraction temp_fraction;

	temp_fraction.setNumerator(((left.integer_fraction * left.denominator + left.numerator) * right.denominator) +
		((right.integer_fraction * right.denominator + right.numerator) * left.denominator));

	temp_fraction.setDenominator(left.denominator * right.denominator);

	fractionReduction(temp_fraction);
	сalculatingAndSetingIntegerFraction(temp_fraction);
	return temp_fraction;
}
Fraction operator-(const Fraction& left, const Fraction& right) {
	Fraction temp_fraction;
	temp_fraction.setNumerator(fabs(((left.integer_fraction * left.denominator + left.numerator) * right.denominator) -
		((right.integer_fraction * right.denominator + right.numerator) * left.denominator)));
	temp_fraction.setDenominator(left.denominator * right.denominator);

	fractionReduction(temp_fraction);
	сalculatingAndSetingIntegerFraction(temp_fraction);
	return temp_fraction;
}
Fraction operator*(const Fraction& left, const Fraction& right) {
	Fraction temp_fraction;

	temp_fraction.setNumerator((left.integer_fraction * left.denominator + left.numerator) *
		(right.integer_fraction * right.denominator + right.numerator));
	temp_fraction.setDenominator(left.denominator * right.denominator);

	fractionReduction(temp_fraction);
	сalculatingAndSetingIntegerFraction(temp_fraction);
	return temp_fraction;
}
Fraction operator/(const Fraction& left, const Fraction& right) {
	Fraction temp_fraction;

	temp_fraction.setNumerator((left.integer_fraction * left.denominator + left.numerator) * right.denominator);
	temp_fraction.setDenominator((right.integer_fraction * right.denominator + right.numerator) * left.denominator);

	fractionReduction(temp_fraction);
	сalculatingAndSetingIntegerFraction(temp_fraction);
	return temp_fraction;
}

Fraction& operator+=(Fraction& left, const Fraction& right){
	left.setNumerator(((left.integer_fraction * left.denominator + left.numerator) * right.denominator) +
		((right.integer_fraction * right.denominator + right.numerator) * left.denominator));
	left.setDenominator(left.denominator * right.denominator);

	fractionReduction(left);
	сalculatingAndSetingIntegerFraction(left);
	
	return left;
}
Fraction& operator-=(Fraction& left, const Fraction& right) {
	left.setNumerator(fabs(((left.integer_fraction * left.denominator + left.numerator) * right.denominator) -
		((right.integer_fraction * right.denominator + right.numerator) * left.denominator)));
	left.setDenominator(left.denominator * right.denominator);

	fractionReduction(left);
	сalculatingAndSetingIntegerFraction(left);

	return left;
}
Fraction& operator*=(Fraction& left, const Fraction& right) {
	left.setNumerator((left.integer_fraction * left.denominator + left.numerator) *
		(right.integer_fraction * right.denominator + right.numerator));
	left.setDenominator(left.denominator * right.denominator);

	fractionReduction(left);
	сalculatingAndSetingIntegerFraction(left);

	return left;
}
Fraction& operator/=(Fraction& left, const Fraction& right) {
	left.setNumerator((left.integer_fraction * left.denominator + left.numerator) * right.denominator);
	left.setDenominator((right.integer_fraction * right.denominator + right.numerator) * left.denominator);

	fractionReduction(left);
	сalculatingAndSetingIntegerFraction(left);

	return left;
}

bool operator==(const Fraction& left, const Fraction& right) {
	return (left.numerator * right.denominator) == (right.numerator * left.denominator);
}
bool operator!=(const Fraction& left, const Fraction& right) {
	return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right) {
	return ((left.integer_fraction * left.denominator + left.numerator) * right.denominator) >
		   ((right.integer_fraction * right.denominator + right.numerator) * left.denominator);
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

void fractionReduction(Fraction& frac) {	
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
	double res = (double)this->getNumerator() / this->getDenominator();
	return res;
}
Fraction Fraction::getFromDecimalFraction(double value) {
	Fraction temp_fraction;
	int size_of_fraction_part(0);

	int fraction_part_of_double_value = getFractionPartOfDoubleValue(value, size_of_fraction_part);

	temp_fraction.setIntegerFraction((int)value);
	temp_fraction.setNumerator(fraction_part_of_double_value);
	temp_fraction.setDenominator(pow(10, size_of_fraction_part));

	return temp_fraction;
}


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