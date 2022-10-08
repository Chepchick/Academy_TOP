#include <iostream>
#include <vector>
#include"Dyn2DArray.h"
using namespace std;

int main(){
	setlocale(LC_ALL, " ");
	int rows{3};
	int columns{4};

	Dyn2DArray arr{ rows, columns };
	arr.fillRandom(1, 10);
	cout << arr;

	Dyn2DArray arr1{ rows, columns };
	cin >> arr1;
	cout << arr1;

	arr1.deleteColumn(2);
	cout << arr1;
	
	arr1.addColumn(0);
	cout << arr1;

	arr1.deleteRow(2);
	cout << arr1;
	
	arr1.addRow(2);
	cout << arr1;








	return 0;
}
