#include <iostream>
using namespace std;

void HanoyTower(int number, int from, int to)
{
	if (number == 1)
	{
		cout << "Переместить диск №" << number << " со столбика " << from << " на столбик " << to << endl;
	}
	else {

		int temp = 6 - from - to;
		HanoyTower(number - 1, from, temp);
		cout << "Переместить диск №" << number << " со столбика " << from << " на столбик " << to << endl;
		HanoyTower(number - 1, temp, to);
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	HanoyTower(4, 1, 2);

	return 0;
}

