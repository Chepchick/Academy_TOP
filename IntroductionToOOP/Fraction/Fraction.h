#include <iostream>
using std::ostream;
using std::istream;

class Fraction {
	friend ostream& operator<<(ostream&, const Fraction&);
	friend istream& operator>>(istream&, Fraction&);

private:
	int integer_fraction;
	int numerator;
	int denominator;

	void setIntegerFraction(int);
	void setNumerator(int);
	void setDenominator(int);

	const int getIntegerFraction() const;
	const int getNumerator() const;
	const int getDenominator() const;

	static void сalculatingAndSetingIntegerFraction(Fraction&);
	static int getGreatestCommonDivisor(const int, const int);
public:
	Fraction(int = 0, int = 0, int = 1);
	Fraction(const Fraction&);
	~Fraction();

	Fraction& operator=(const Fraction&);

	const Fraction operator+(const Fraction&);
	const Fraction operator-(const Fraction&);
	const Fraction operator*(const Fraction&);
	const Fraction operator/(const Fraction&);

	Fraction& operator+=(const Fraction&);
	Fraction& operator-=(const Fraction&);
	Fraction& operator*=(const Fraction&);
	Fraction& operator/=(const Fraction&);

	bool operator==(const Fraction&);
	bool operator!=(const Fraction&);
	bool operator>(const Fraction&);
	bool operator<(const Fraction&);
	bool operator>=(const Fraction&);
	bool operator<=(const Fraction&);

	static void fractionReduction(Fraction&);
	static Fraction& power(Fraction&, int);
	static Fraction& square(Fraction&);
	double convertToDecimalFraction();
	/*static Fraction getFromDecimalFraction(double value);*/
};
