#include <iostream>
#include <iomanip>
#include "Fraction.h"
using namespace std;

ostream& operator<<(ostream& output, const Fraction& frac) {
	cout << "Вызван оператор вывода  ";
	output << frac.integer_fraction << "(" << frac.numerator << "/" << frac.denominator << ")";
	return output;
}
istream& operator>>(istream& input, const Fraction& frac) {
	input >> frac.numerator;
	input >> frac.denominator;
	input >> frac.integer_fraction;	
	return input;
}

//private
void Fraction::setIntegerFraction(int value) {
		integer_fraction = value;
	}
void Fraction::setNumerator(int value) {
		numerator = value;
		cout << "     Для объекта " << this << " вызван setNumerator, в чеслитель присвоено значение " << numerator << endl;
	}
void Fraction::setDenominator(int value) {
		if (value != 0) {
			denominator = value;
		}
		else {
			cout << "Ошибка! Знаменатель не может быть равным 0" << endl;
		}
		cout << "     Для объекта " << this << " вызван setDenominator, в знаменатель присвоено значение " << denominator << endl;
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

int Fraction::getGreatestCommonDivisor(const int first_value, const int second_value) {
		int number_of_devisors_for_the_first_value = 0;
		int number_of_devisors_for_the_second_value = 0;

		for (int i = 1; i <= first_value; i++) {
			if (first_value % i == 0) number_of_devisors_for_the_first_value++;
		}
		int* array_of_divisors_of_the_first_value = new int[number_of_devisors_for_the_first_value] {};

		for (int i = 1; i <= second_value; i++) {
			if (second_value % i == 0) number_of_devisors_for_the_second_value++;
		}
		int* array_of_divisors_of_the_second_value = new int[number_of_devisors_for_the_second_value] {};


		for (int i = 1, count_devisors = 0; i <= first_value; i++) {
			if (first_value % i == 0) {
				array_of_divisors_of_the_first_value[count_devisors++] = i;
			}
		}
		for (int i = 1, count_devisors = 0; i <= second_value; i++) {
			if (second_value % i == 0) {
				array_of_divisors_of_the_second_value[count_devisors++] = i;
			}
		}


		for (int i = number_of_devisors_for_the_first_value - 1; i >= 0; i--)
		{
			for (int j = number_of_devisors_for_the_second_value - 1; j >= 0; j--)
			{
				if (array_of_divisors_of_the_first_value[i] == array_of_divisors_of_the_second_value[j]) {
					int greatest_common_divisor = array_of_divisors_of_the_first_value[i];
					delete[]array_of_divisors_of_the_first_value;
					delete[]array_of_divisors_of_the_second_value;
					return greatest_common_divisor;
				}
			}
		}
		return 1;
	}

//public
Fraction::Fraction(int numerator, int denominator, int integer_fraction)
	{
		cout << "Вызван конструктор, создан объект " << this << endl;
		setNumerator(numerator);
		setDenominator(denominator);
		setIntegerFraction(integer_fraction);
	}
Fraction::~Fraction() {
		cout << "Вызван деструктор, удален объект " << this << endl;
	}

Fraction::Fraction(const Fraction& other)
	{
		cout << "Вызван конструктор копирования из объекта " << &other << " в объект " << this << endl;
		this->setNumerator(other.numerator);
		this->setDenominator(other.denominator);
		this->setIntegerFraction(other.integer_fraction);
	}
Fraction& Fraction::operator=(const Fraction& other)
	{
		cout << "Вызван оператор = из объекта " << &other << " в объект " << this << endl;
		this->setNumerator(other.numerator);
		this->setDenominator(other.denominator);
		this->setIntegerFraction(other.integer_fraction);
		return *this;
	}

Fraction Fraction::operator+(const Fraction& other) {
	cout << "Вызван оператор + для объектов " << this << " и " << &other << endl;
	Fraction temp;

	temp.numerator = ((this->integer_fraction * this->denominator + this->numerator) * other.denominator) +
		((other.integer_fraction * other.denominator + other.numerator) * this->denominator);
	temp.denominator = this->denominator * other.denominator;

	if (temp.numerator > temp.denominator)
	{
		temp.integer_fraction = temp.numerator / temp.denominator;
		temp.numerator = (this->numerator * other.numerator) - temp.integer_fraction * temp.denominator;
	}
	FractionReduction(temp);
	return temp;
}
Fraction Fraction::operator-(const Fraction& other) {
	cout << "Вызван оператор - для объектов " << this << " и " << &other << endl;
	Fraction temp;
	temp.numerator = int (fabs(((this->integer_fraction * this->denominator + this->numerator) * other.denominator) -
		((other.integer_fraction * other.denominator + other.numerator) * this->denominator)));
	temp.denominator = this->denominator * other.denominator;

	if (temp.numerator > temp.denominator)
	{
		temp.integer_fraction = temp.numerator / temp.denominator;
		temp.numerator = (this->numerator * other.numerator) - temp.integer_fraction * temp.denominator;
	}
	FractionReduction(temp);
	return temp;
}
Fraction Fraction::operator*(const Fraction& other) {
	cout << "Вызван оператор * для объектов " << this << " и " << &other << endl;
	Fraction temp;

	temp.numerator = (this->integer_fraction * this->denominator + this->numerator) *
		(other.integer_fraction * other.denominator + other.numerator);
	temp.denominator = this->denominator * other.denominator;

	if (temp.numerator > temp.denominator)
	{
		temp.integer_fraction = temp.numerator / temp.denominator;
		temp.numerator = (this->numerator * other.numerator) - temp.integer_fraction * temp.denominator;
	}
	FractionReduction(temp);
	return temp;
}
Fraction Fraction::operator/(const Fraction& other) {
	cout << "Вызван оператор / для объектов " << this << " и " << &other << endl;
	Fraction temp;
	temp.numerator = (this->integer_fraction * this->denominator + this->numerator) * other.denominator;
	temp.denominator = (other.integer_fraction * other.denominator + other.numerator) * this->denominator;
	if (temp.numerator > temp.denominator)
	{
		temp.integer_fraction = temp.numerator / temp.denominator;
		temp.numerator = (this->numerator * other.denominator) - temp.integer_fraction * temp.denominator;
	}
	FractionReduction(temp);
	return temp;
}

bool Fraction::operator==(const Fraction& other) {
	return (this->numerator * other.denominator) == (other.numerator * this->denominator);
}
bool Fraction::operator!=(const Fraction& other) {
	return !(this->operator==(other));
}
bool Fraction::operator>(const Fraction& other) {
	if ((this->integer_fraction > other.integer_fraction) ||
		((this->numerator / this->denominator) > (other.numerator / other.denominator))) return true;
	else {
		if (this->denominator == other.denominator) {
			return this->numerator > other.numerator;
		}
		else if (this->numerator == other.numerator) {
			return this->denominator < other.denominator;
		}
		else {
			return (this->numerator * other.denominator) > (other.numerator * this->denominator);
		}
	}
}
bool Fraction::operator<(const Fraction& other) {
	return !(this->operator>(other));
}

void Fraction::FractionReduction(Fraction& fraction) {
	int greatest_common_divisor = getGreatestCommonDivisor(fraction.numerator, fraction.denominator);
	fraction.setNumerator(fraction.numerator / greatest_common_divisor);
	fraction.setDenominator(fraction.denominator / greatest_common_divisor);
}