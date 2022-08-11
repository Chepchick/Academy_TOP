#include <iostream>
#include "Fraction.h"
using namespace std;

#define delimiter_line "--------------------------------------------------------------------------------\n"
int main() {
	setlocale(LC_ALL, "ru");

	Fraction A(0,2,3), B(0,1,4), C;
	cin >> C;
	cout << A << "     " << B << "     " << C << endl;
	Fraction::fractionReduction(C);
	cout << delimiter_line;	
	cout << A + B << endl;
	cout << delimiter_line;
	cout << A - C << endl;
	cout << delimiter_line;
	cout << A * B << endl;
	cout << delimiter_line;
	cout << A / C << endl;
	cout << delimiter_line;
	/*cout << A += B;
	cout << delimiter_line;*/
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