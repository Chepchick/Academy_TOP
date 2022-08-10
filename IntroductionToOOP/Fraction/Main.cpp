#include <iostream>
#include "Fraction.h"
using namespace std;

#define separation "--------------------------------------------------------------------------------\n"
int main() {
	setlocale(LC_ALL, "ru");

	Fraction A(0,2,3), B(0,1,4), C;
	cin >> C;
	cout << A << "     " << B << "     " << C << endl;
	Fraction::fractionReduction(C);
	cout << separation;	
	cout << A + B << endl;
	cout << separation;
	cout << A - C << endl;
	cout << separation;
	cout << A * B << endl;
	cout << separation;
	cout << A / C << endl;
	/*cout << separation; ???
	cout << A += B;*/
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