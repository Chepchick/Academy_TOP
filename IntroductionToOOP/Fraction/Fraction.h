#include <iostream>
using std::ostream;
using std::istream;

class Fraction {
private:
	int integer_fraction;
	int numerator;
	int denominator;
	bool fraction_is_negativ;

	void setIntegerFraction(int);
	void setNumerator(int);
	void setDenominator(int);

	int getIntegerFraction() const;
	int getNumerator() const;
	int getDenominator() const;


	short sign() const;
	friend static void сalculatingAndSetingIntegerFraction(Fraction&);
	friend static int getGreatestCommonDivisor(const int, const int);
	static int getFractionPartOfDoubleValue(const double, int&);
	

public:
	Fraction(int, int, int);
	template <typename T1, typename T2, typename T3> Fraction(T1, T2, T3) = delete;	
	Fraction();
		
	friend const Fraction operator+(const Fraction&, const Fraction&);
	friend const Fraction operator+(const Fraction&, const int);
	friend const Fraction operator+(const int, const Fraction&);
	
	friend const Fraction operator-(const Fraction&, const Fraction&);
	friend const Fraction operator-(const Fraction&, const int);
	friend const Fraction operator-(const int, const Fraction&);

	friend const Fraction operator*(const Fraction&, const Fraction&);
	friend const Fraction operator*(const Fraction&, const int);
	friend const Fraction operator*(const int, const Fraction&);

	friend const Fraction operator/(const Fraction&, const Fraction&);
	friend const Fraction operator/(const Fraction&, const int);
	friend const Fraction operator/(const int, const Fraction&);

	Fraction& operator+=(const Fraction&);
	Fraction& operator-=(const Fraction&);
	Fraction& operator*=(const Fraction&);
	Fraction& operator/=(const Fraction&);

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
