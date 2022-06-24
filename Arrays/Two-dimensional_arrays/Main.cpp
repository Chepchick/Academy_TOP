#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void fillRand(int**&, int, int);
void fillRand(float**&, int, int);
void fillRand(double**&, int, int);
void fillRand(char**&, int, int);

template<typename T> void printArray(T**&, int, int);
template<typename T> T getSum(T**&, int, int);
template<typename T> T getAvg(T**&, int, int);
template<typename T> T getMinVlaueIn(T**&, int, int);
template<typename T> T getMaxVlaueIn(T**&, int, int);
template<typename T> void shiftLeft(T**&, int, int, int);
template<typename T> void shiftRight(T**&, int, int, int);
template<typename T> void generalSort(T**&, int, int, bool type_of_sorting = true);
template<typename T> void lineByLineSorting(T**&, int, int, bool type_of_sorting = true);

int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int ROWS = 5, COLUMNS = 5;
	int** array = new int* [ROWS];
	for (int i = 0; i < COLUMNS; i++)
	{
		array[i] = new int[COLUMNS];
	}

	//инициализация и вывод на консоль массива
	fillRand(array, ROWS, COLUMNS);
	printArray(array, ROWS, COLUMNS);
	cout << endl << endl;

	//вывод суумы элементов массива
	auto sum = getSum(array, ROWS, COLUMNS);
	cout << "Сумма элементов массива равна: " << sum;
	cout << endl << endl;

	//вывод среднего арифметического элементов массива
	auto avg = getAvg(array, ROWS, COLUMNS);
	cout << "Среднее арифметическое элементов массива равно: " << avg;
	cout << endl << endl;

	//вывод максимального элемента массива
	auto max = getMaxVlaueIn(array, ROWS, COLUMNS);
	cout << "Максимальный элемент массива равен: " << max;
	cout << endl << endl;

	//вывод минимального элемента массива
	auto min = getMinVlaueIn(array, ROWS, COLUMNS);
	cout << "Минимальный элемент массива равен: " << min;
	cout << endl << endl;

	//сдвиг массива вправо
	int shift = 1;
	cout << "Cдвиг массива вправо на " << shift << " элемента " << endl;
	shiftRight(array, ROWS, COLUMNS, shift);
	printArray(array, ROWS, COLUMNS);
	cout << endl << endl;

	//сдвиг массива влево
	shift = 1;
	cout << "Cдвиг массива влево на " << shift << " элемента " << endl;
	shiftLeft(array, ROWS, COLUMNS, shift);
	printArray(array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по строчно по возрастанию
	cout << "Сортировка массива по строчно по возрастанию " << endl;
	lineByLineSorting(array, ROWS, COLUMNS, true);
	printArray(array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по строчно по убыванию
	cout << "Сортировка массива по строчно по убыванию " << endl;
	lineByLineSorting(array, ROWS, COLUMNS, false);
	printArray(array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по возрастанию
	cout << "Cортировка всего массива по возрастанию" << endl;
	generalSort(array, ROWS, COLUMNS, true);
	printArray(array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по убыванию
	cout << "Cортировка всего массива по убыванию " << endl;
	generalSort(array, ROWS, COLUMNS, false);
	printArray(array, ROWS, COLUMNS);
	cout << endl << endl;


	return 0;
}

void fillRand(int**& arr, int ROWS, int COLS) {

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void fillRand(float**& arr, int ROWS, int COLS) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = (float)(rand() % 1000) / 10;
		}
	}
}
void fillRand(double**& arr, int ROWS, int COLS) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = (double)(rand() % 10000) / 100;
		}
	}
}
void fillRand(char**& arr, int ROWS, int COLS) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 256;
		}
	}
}

template<typename T> void printArray(T**& arr, int ROWS, int COLS) {
	for (register int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
template<typename T> T getSum(T**& arr, int ROWS, int COLS) {
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}
template<typename T> T getAvg(T**& arr, int ROWS, int COLS) {
	return (double)(getSum(arr, ROWS, COLS) / (ROWS * COLS));
}
template<typename T> T getMinVlaueIn(T**& arr, int ROWS, int COLS) {
	int min = arr[0][0];
	for (int i = 1; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (min > arr[i][j]) min = arr[i][j];
		}
		
	}
	return min;
}
template<typename T> T getMaxVlaueIn(T**& arr, int ROWS, int COLS) {
	int max = arr[0][0];
	for (int i = 1; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (max < arr[i][j]) max = arr[i][j];
		}

	}
	return max;
}
template<typename T> void shiftLeft(T**& arr, int ROWS, int COLS, int number_of_shift) {
	int buffer;
	
	for (int i = 0; i < ROWS; i++)
	{
		for (int m = 0; m < number_of_shift; m++)
		{
			buffer = arr[i][0];
			for (int j = 0; j < COLS - 1; j++)
			{
				arr[i][j] = arr[i][j + 1];
			}
			arr[i][COLS - 1] = buffer;
		}		
	}
}
template<typename T> void shiftRight(T**& arr, int ROWS, int COLS, int number_of_shift) {

	for (int i = 0; i < ROWS; i++)
	{
		for (int m = 0; m < number_of_shift; m++)
		{
			int buffer = arr[i][COLS - 1];
			for (int j = COLS - 1; j > 0; j--)
			{
				arr[i][j] = arr[i][j - 1];
			}
			arr[i][0] = buffer;
		}
	}

}
template<typename T> void generalSort(T**& arr, int ROWS, int COLS, bool type_of_sorting) {

	if (type_of_sorting)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				for (int m = i; m < ROWS; m++)
				{
					for (int n = j; n < COLS; n++)
					{
						if (arr[i][j] > arr[m][n])
						{
							int buffer = arr[i][j];
							arr[i][j] = arr[m][n];
							arr[m][n] = buffer;
						}
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				for (int m = i; m < ROWS; m++)
				{
					for (int n = j; n < COLS; n++)
					{
						if (arr[i][j] < arr[m][n])
						{
							int buffer = arr[i][j];
							arr[i][j] = arr[m][n];
							arr[m][n] = buffer;
						}
					}
				}
			}
		}
	}
}
template<typename T> void lineByLineSorting(T**& arr, int ROWS, const int COLS, bool type_of_sorting) {

	if (type_of_sorting)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				for (int m = j; m < COLS; m++)
				{
					if (arr[i][j] > arr[i][m])
					{
						int buffer = arr[i][j];
						arr[i][j] = arr[i][m];
						arr[i][m] = buffer;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				for (int m = j; m < COLS; m++)
				{
					if (arr[i][j] < arr[i][m])
					{
						int buffer = arr[i][j];
						arr[i][j] = arr[i][m];
						arr[i][m] = buffer;
					}
				}
			}
		}
	}


};

