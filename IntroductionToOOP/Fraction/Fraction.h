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
	Fraction();
		
	friend const Fraction operator+(const Fraction&, const Fraction&);
	friend const Fraction operator+(const Fraction&, const int);
	friend const Fraction operator+(const int, const Fraction&);	
	template<typename float_val> friend const Fraction operator+(const Fraction& fraction, const float_val value) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return temp_fraction + fraction;
	}
	/*template<> inline friend const Fraction operator+ <long>(const Fraction& left, const long right) {
		Fraction temp_fraction;
		
			temp_fraction.setNumerator((left.getIntegerFraction() * left.getDenominator() + left.getNumerator()) * left.sign() + right * left.getDenominator());
			temp_fraction.setDenominator(left.getDenominator());
			
			сalculatingAndSetingIntegerFraction(temp_fraction);
			fractionReduction(temp_fraction);
		
			return temp_fraction;
	}*/
	template<typename float_val> friend const Fraction operator+(const float_val value, const Fraction& fraction) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return temp_fraction + fraction;
	}
	/*template<> inline friend const Fraction operator+ <long>(const long left, const Fraction& right) {
		Fraction temp_fraction;
		
			temp_fraction.setNumerator((right.getIntegerFraction() * right.getDenominator() + right.getNumerator()) * right.sign() + left * right.getDenominator());
			temp_fraction.setDenominator(right.getDenominator());
			
			сalculatingAndSetingIntegerFraction(temp_fraction);
			fractionReduction(temp_fraction);
			return temp_fraction;
	}*/
	
	friend const Fraction operator-(const Fraction&, const Fraction&);
	friend const Fraction operator-(const Fraction&, const int);
	friend const Fraction operator-(const int, const Fraction&);
	template<typename float_val> friend const Fraction operator-(const Fraction& fraction, const float_val value) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);		
		return fraction - temp_fraction;
	}
	template<typename float_val> friend const Fraction operator-(const float_val value, const Fraction& fraction) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);		
		return temp_fraction - fraction;
	}

	friend const Fraction operator*(const Fraction&, const Fraction&);
	friend const Fraction operator*(const Fraction&, const int);
	friend const Fraction operator*(const int, const Fraction&);
	template<typename float_val> friend const Fraction operator*(const Fraction& fraction, const float_val value) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return fraction * temp_fraction;
	}
	template<typename float_val> friend const Fraction operator*(const float_val value, const Fraction& fraction) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return temp_fraction * fraction;
	}

	friend const Fraction operator/(const Fraction&, const Fraction&);
	friend const Fraction operator/(const Fraction&, const int);
	friend const Fraction operator/(const int, const Fraction&);
	template<typename float_val> friend const Fraction operator/(const Fraction& fraction, const float_val value) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return fraction / temp_fraction;
	}
	template<typename float_val> friend const Fraction operator/(const float_val value, const Fraction& fraction) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return temp_fraction / fraction;
	}

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
