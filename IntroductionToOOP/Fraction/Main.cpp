#include <iostream>
#include "Fraction.h"

using namespace std;

#define delimiter_line "------------------------------\n"
#define BASIC_PART


int main() {
	setlocale(LC_ALL, "ru");

#ifdef BASIC_PART
	Fraction A(0,2,3), B(0,1,4), C;
	cout << "Введите значение дроби в формате - целая часть, числитель, знаменатель: ";
	cin >> C;
	cout << endl;
	cout << A << "     " << B << "     " << C << endl;	
	cout << delimiter_line;

	cout << 5 - A << endl;
	cout << (B - C - 3) / B << endl;
	cout << 2 - A * C << endl;
	cout << A / B << endl;
	cout << 6 + A - 2 << endl;
	cout << 4 * B / 3 << endl;	
	cout << delimiter_line;

	cout << (A += B) << endl;
	cout << (C -= A) << endl;
	cout << (B *= C) << endl;
	cout << (A /= C) << endl;
	cout << delimiter_line;

	cout << (A == B) << endl;
	cout << (C != B) << endl;
	cout << (A < C) << endl;
	cout << (B > A) << endl;
	cout << (A <= A) << endl;
	cout << delimiter_line;

	Fraction D(0,-3,8);
	cout << Fraction::power(D,2) << endl;
	cout << Fraction::square(D) << endl;
	cout << delimiter_line;

	Fraction F(0,-13, 5);
	double dec_fraction = F.convertToDecimalFraction();
	F = Fraction::getFromDecimalFraction(dec_fraction);
	cout << dec_fraction << endl;
	cout << F << endl;
	cout << delimiter_line;

	Fraction E();
	dec_fraction = 3.845;
	F = Fraction::getFromDecimalFraction(dec_fraction);
	cout << dec_fraction << endl;
	cout << F << endl;


#endif // BASIC_PART

	

	return 0;
}