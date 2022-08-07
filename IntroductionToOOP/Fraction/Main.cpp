#include <iostream>
#include "Fraction.h"
using namespace std;

#define separation "--------------------------------------------------------------------------------\n"
int main() {
	setlocale(LC_ALL, "ru");

	Fraction A(2,3), B(1,4), C;	
	cout << A << "     " << B << "      " << C << endl;
	cout << separation;
	C = A + B;
	cout << C << endl;
	cout << separation;
	cout << A - B << endl;
	cout << separation;
	cout << A * B << endl;
	cout << separation;
	cout << A / B << endl;
	cout << separation;

	bool res = A == B;
	cout << res << endl;
	res = A != B;
	cout << res << endl;
	res = A < B;
	cout << res << endl;
	res = A > B;
	cout << res << endl;

	return 0;
}