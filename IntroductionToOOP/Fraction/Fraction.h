#include <iostream>
#include <sstream>
using namespace std;

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
	template<typename T> inline static int getFractionPartOfDoubleValue(const T value, int& size) {
		string string_value = to_string(value);
		string fraction_part_of_string_value;
		char* index_ptr{ &string_value.front() };
		char* end_ptr{ &string_value.back() };

		for (; index_ptr < end_ptr; index_ptr++){
			if (*index_ptr == ',') {
				for (index_ptr++; index_ptr < end_ptr; index_ptr++)	{
					fraction_part_of_string_value += *index_ptr;
				}
				break;
			}
		}
		size = fraction_part_of_string_value.size();
		int fraction_part{ 0 };

		if (size) fraction_part = stoi(fraction_part_of_string_value);
		
		return value < 0 ? -fraction_part : fraction_part;		
	}	

public:
	Fraction(int, int, int);	
	Fraction();
		
	friend const Fraction operator+(const Fraction&, const Fraction&);	
	template<typename  var> friend const Fraction operator+(const Fraction& fraction, const var value) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return temp_fraction + fraction;
	}	
	template<typename var> friend const Fraction operator+(const var value, const Fraction& fraction) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return temp_fraction + fraction;
	}	
	
	friend const Fraction operator-(const Fraction&, const Fraction&);	
	template<typename var> friend const Fraction operator-(const Fraction& fraction, const var value) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);		
		return fraction - temp_fraction;
	}
	template<typename var> friend const Fraction operator-(const var value, const Fraction& fraction) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);		
		return temp_fraction - fraction;
	}

	friend const Fraction operator*(const Fraction&, const Fraction&);	
	template<typename var> friend const Fraction operator*(const Fraction& fraction, const var value) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return fraction * temp_fraction;
	}
	template<typename var> friend const Fraction operator*(const var value, const Fraction& fraction) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return temp_fraction * fraction;
	}

	friend const Fraction operator/(const Fraction&, const Fraction&);	
	template<typename var> friend const Fraction operator/(const Fraction& fraction, const var value) {
		Fraction temp_fraction = temp_fraction.getFromDecimalFraction(value);
		return fraction / temp_fraction;
	}
	template<typename var> friend const Fraction operator/(const var value, const Fraction& fraction) {
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

	static void fractionReduction(Fraction&);
	static Fraction& power(Fraction&, int);
	static Fraction& square(Fraction&);
	double convertToDecimalFraction();
	template<typename T> static Fraction getFromDecimalFraction(T value) {
		Fraction temp_fraction;
		int size_of_fraction_part{ 0 };

		int fraction_part_of_double_value = getFractionPartOfDoubleValue(value, size_of_fraction_part);

		temp_fraction.setIntegerFraction((int)value);
		temp_fraction.setNumerator(fraction_part_of_double_value);
		temp_fraction.setDenominator(pow(10, size_of_fraction_part));
		fractionReduction(temp_fraction);

		return temp_fraction;
	}
};
