#include <iostream>
#include "Fraction.h"
#include <sstream>
using namespace std;


#define delimiter_line "------------------------------\n"
int main() {
	setlocale(LC_ALL, "ru");

	Fraction A(0,2,3), B(0,1,4), C;
	cout << "Введите значение дроби: ";
	cin >> C;
	cout << endl;
	cout << A << "     " << B << "     " << C << endl;	
	cout << delimiter_line;

	cout << A + B << endl;
	cout << B - C << endl;
	cout << A * C << endl;
	cout << A / B << endl;
	cout << delimiter_line;

	cout << (A += B) << endl;
	cout << (A -= B) << endl;
	cout << (A *= B) << endl;
	cout << (A /= B) << endl;
	cout << delimiter_line;

	cout << (A == B) << endl;
	cout << (C != B) << endl;
	cout << (A < C) << endl;
	cout << (B > A) << endl;
	cout << (A <= A) << endl;
	cout << delimiter_line;

	cout << Fraction::power(A,3) << endl;
	cout << Fraction::square(A) << endl;
	cout << delimiter_line;

	double dec_fraction = B.convertToDecimalFraction();
	A = Fraction::getFromDecimalFraction(dec_fraction);
	cout << dec_fraction << endl;
	cout << A << endl;	
	
	return 0;
}