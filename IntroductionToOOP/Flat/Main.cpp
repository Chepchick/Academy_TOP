#include <iostream>
#include "Flat.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	//������������� ���� ����������� �����:
	Flat::setCostPerSquareMeter(138.34);
	//�������� ��� ��������
	Flat TwoRoom(12.2, 8.6);
	Flat ThreeRoom(14.8, 13.3);
	//���������� �� �������:
	cout << (TwoRoom == ThreeRoom);
	//���������� �� ����:
	cout << (TwoRoom > ThreeRoom);
	return 0;
}