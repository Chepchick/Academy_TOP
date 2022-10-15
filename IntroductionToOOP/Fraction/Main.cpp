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
	cout <<"A =" << A << "  " << "B =" << B << "  " << "C =" << C << endl;
	cout << delimiter_line;

	cout << "5 - A = " << 5 - A << endl;
	cout << "(B - C - 3) / B = " << (B - C - 3) / B << endl;
	cout << "2 - A * C = " << 2 - A * C << endl;
	cout << "A / B = " << A / B << endl;
	cout << "6 + A - 2 = " << 6 + A - 2 << endl;
	cout << "4 * B / 3 = " << 4 * B / 3 << endl;
	cout << delimiter_line;

	cout << "(A += B) = " << (A += B) << endl;
	cout << "(C -= A) = " << (C -= A) << endl;
	cout << "(B *= C) = " << (B *= C) << endl;
	cout << "(A /= C) = " << (A /= C) << endl;
	cout << delimiter_line;

	cout << "(A == B) = " << (A == B) << endl;
	cout << "(C != B) = " << (C != B) << endl;
	cout << "(A < C) = " << (A < C) << endl;
	cout << "(B > A) = " << (B > A) << endl;
	cout << "(A <= A) = " << (A <= A) << endl;
	cout << delimiter_line;

	Fraction D(0,-3,8);
	cout << "дробь D 0(-3,8) в степени 3 = " << Fraction::power(D,3) << endl;
	cout << "квадратный корень из дроби D = " << Fraction::square(D) << endl;
	cout << delimiter_line;

	Fraction F(0,13,5);
	double dec_fraction = F.convertToDecimalFraction();
	F = Fraction::getFromDecimalFraction(dec_fraction);
	cout << "F(0,13,5) => double = " << dec_fraction << endl;
	cout << "double => F = " << F << endl;
	cout << delimiter_line;

	Fraction E;
	dec_fraction = 3.845;
	E = Fraction::getFromDecimalFraction(dec_fraction);
	cout << dec_fraction << endl;
	cout << "double 3.845 => F = " << E << endl;
	cout << delimiter_line;

	Fraction M(0, 1, 4);
	double db{ 0.2 };
	float fl{ 0.8 };
	int it{ 2 };
	long lg{ 2 };
	Fraction G = ((M * db + it) - fl) / lg;	
	cout << "M(0, 1, 4), db{ 0.2 }, fl{ 0.8 }, it{ 2 }, long lg{ 2 }" << endl;
	cout <<	"((M * db + it) - fl) / lg = " << G;


#endif // BASIC_PART

	

	
	return 0;
}