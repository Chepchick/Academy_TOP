#include <iostream>
#include "Fraction.h"
using namespace std;


#define delimiter_line "--------------------------------------------------------------------------------\n"
int main() {
	setlocale(LC_ALL, "ru");

	Fraction A(0,2,3), B(0,1,4), C;
	cout << "Введите значение дроби: ";
	cin >> C;
	cout << endl;
	cout << A << "     " << B << "     " << C << endl;	
	cout << delimiter_line;
	cout << A + B << endl;
	cout << A * C << endl;
	cout << A * C - B << endl;
	cout << A + B << endl;

	bool res = A == B;
	cout << res << endl;
	res = A != B;
	cout << res << endl;
	res = A < B;
	cout << res << endl;
	res = A > B;
	cout << res << endl;

	Fraction D(0, 1, 3);
	cout << D << endl;
	cout << Fraction::power(D, 3) << endl;
	cout << Fraction::square(D) << endl;	
	
	





	return 0;
}