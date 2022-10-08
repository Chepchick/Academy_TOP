#include <iostream>
#include "Flat.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	//устанавливаем цену квадратного метра:
	Flat::setCostPerSquareMeter(138.34);
	//выбираем две квартиры
	Flat TwoRoom(12.2, 8.6);
	Flat ThreeRoom(14.8, 13.3);
	//сравниваем по площади:
	cout << (TwoRoom == ThreeRoom);
	//сравниваем по цене:
	cout << (TwoRoom > ThreeRoom);
	return 0;
}