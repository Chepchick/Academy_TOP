﻿#include <iostream>
using std::ostream;
using std::istream;

class Fraction {
private:
	int integer_fraction;
	int numerator;
	int denominator;

	void setIntegerFraction(int);
	void setNumerator(int);
	void setDenominator(int);

	int getIntegerFraction() const;
	int getNumerator() const;
	int getDenominator() const;

	friend static void сalculatingAndSetingIntegerFraction(Fraction&);
	friend static int getGreatestCommonDivisor(const int, const int);
	static int getFractionPartOfDoubleValue(const double, int&);	

public:
	Fraction(int = 0, int = 0, int = 1);	
	Fraction(const Fraction&);	

	Fraction& operator=(const Fraction&);

	friend Fraction operator+(const Fraction&, const Fraction&);
	friend Fraction operator-(const Fraction&, const Fraction&);
	friend Fraction operator*(const Fraction&, const Fraction&);
	friend Fraction operator/(const Fraction&, const Fraction&);

	friend Fraction& operator+=(Fraction&, const Fraction&);
	friend Fraction& operator-=(Fraction&, const Fraction&);
	friend Fraction& operator*=(Fraction&, const Fraction&);
	friend Fraction& operator/=(Fraction&, const Fraction&);

	friend bool operator==(const Fraction&, const Fraction&);
	friend bool operator!=(const Fraction&, const Fraction&);
	friend bool operator>(const Fraction&, const Fraction&);
	friend bool operator<(const Fraction&, const Fraction&);
	friend bool operator>=(const Fraction&, const Fraction&);
	friend bool operator<=(const Fraction&, const Fraction&);

	friend ostream& operator<<(ostream&, const Fraction&);
	friend istream& operator>>(istream&, Fraction&);

	friend static void fractionReduction(Fraction&);
	static Fraction& power(Fraction&, int);
	static Fraction& square(Fraction&);
	double convertToDecimalFraction();
	static Fraction getFromDecimalFraction(double value);	
};
