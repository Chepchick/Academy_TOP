#include <iostream>
#include <vector>
#include"Dyn2DArray.h"
using namespace std;

int main(){
	setlocale(LC_ALL, "ru");
#define USER_INPUT 0;

	int rows{5};
	int columns{6};

	Dyn2DArray arr{ rows, columns };
	arr.fillRandom(1, 10);
	cout <<"Первый массив:\n" << arr;

	arr.deleteColumn(2);
	cout << arr;
	
	arr.addColumn(0);
	cout << arr;

	arr.deleteRow(2);
	cout << arr;
	
	arr.addRow(2);
	cout << arr;

#if USER_INPUT == 1
	std::cout << "Введите количество строк второго массива: ";
	std::cin >> rows;
	std::cout << "Введите количество колонок второго массива: ";
	std::cin >> columns;
#endif

	Dyn2DArray arr1{ rows, columns };
#if USER_INPUT == 1
	cin >> arr1;		
#endif
	arr1.fillRandom(1,30);
	cout << "\nВторой массив:\n" << arr1;

	cout << "arr == arr1: " << (arr == arr1) << endl;	

	cout <<"Количество строк второго массива: " << arr1.getRows() << endl;
	cout << "Количество колонок второго массива: " << arr1.getColumns() << endl;

	cout << "Очистка первого массива: " << endl;
	arr.clear();
	cout << arr << endl;
	cout << "Первый массив пуст? " << arr.isEmpty() << endl;

	cout << "Удаление элемента из второго массива под индексом [2,3] " << endl;
	arr1.erase(2, 3);
	cout << arr1 << endl;

	cout << "Вставка значения 456 во второй массив под индексом [2,3] " << endl;
	arr1.insert(2, 3, 456);
	cout << arr1 << endl;

	cout << "Сортировка второго массива по строчно по возрвстанию" << endl;
	arr1.sortRowsAscending();
	cout << arr1 << endl;

	cout << "Сортировка второго массива по строчно по убыванию" << endl;
	arr1.sortRowsDescending();
	cout << arr1 << endl;

	cout << "Сортировка второго массива по колонкам по возрвстанию" << endl;
	arr1.sortColumnsAscending();
	cout << arr1 << endl;

	cout << "Сортировка второго массива по колонкам по убыванию" << endl;
	arr1.sortColumnsDescending();
	cout << arr1 << endl;

	cout << "Сортировка второго массива целиком по возрвстанию" << endl;
	arr1.wholeSortAscending();
	cout << arr1 << endl;

	cout << "Сортировка второго массива целиком по убыванию" << endl;
	arr1.wholeSortDescending();
	cout << arr1 << endl;

	cout << "Удаление дупликатов из второго массива " << endl;
	arr1.removeDuplicateValues();
	cout << arr1 << endl;

	cout << "Сумма всех эдементов второго массива: " << arr1.getSum() << endl;
	
	return 0;
}
