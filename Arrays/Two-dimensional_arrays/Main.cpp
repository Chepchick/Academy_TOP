#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void fillRand(int*, const int, const int);
void fillRand(float*, const int, const int);
void fillRand(double*, const int, const int);
void fillRand(char*, const int, const int);

void printArray(int*, const int, const int);
void printArray(float*, const int, const int);
void printArray(double*, const int, const int);
void printArray(char*, const int, const int);

int getSum(int*, const int, const int);
double getAvg(double*, const int, const int);
int getMinVlaueIn(int*, const int, const int);
int getMaxVlaueIn(int*, const int, const int);
void shiftLeft(int*, const int, const int, int);
void shiftRight(int*, const int, const int, int);
void generalSort(int*, const int, const int, bool type_of_sorting = true);
void lineByLineSorting(int*, const int, const int, bool type_of_sorting = true);





int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	const int ROWS = 5, COLUMNS = 5;
	int array[ROWS][COLUMNS];

	//инициализация и вывод на консоль массива
	fillRand(*array, ROWS, COLUMNS);
	printArray(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//вывод суумы элементов массива
	auto sum = getSum(*array, ROWS, COLUMNS);
	cout << "Сумма элементов массива равна: " << sum;
	cout << endl << endl;

	//вывод среднего арифметического элементов массива
	auto avg = getAvg(*array, ROWS, COLUMNS);
	cout << "Среднее арифметическое элементов массива равно: " << avg;
	cout << endl << endl;

	//вывод максимального элемента массива
	auto max = getMaxVlaueIn(*array, ROWS, COLUMNS);
	cout << "Максимальный элемент массива равен: " << max;
	cout << endl << endl;

	//вывод минимального элемента массива
	auto min = getMinVlaueIn(*array, ROWS, COLUMNS);
	cout << "Минимальный элемент массива равен: " << min;
	cout << endl << endl;

	//сдвиг массива вправо
	int shift = 1;
	cout << "Cдвиг массива вправо на " << shift << " элемента " << endl;
	shiftRight(*array, ROWS, COLUMNS, shift);
	printArray(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//сдвиг массива влево
	shift = 1;
	cout << "Cдвиг массива влево на " << shift << " элемента " << endl;
	shiftLeft(*array, ROWS, COLUMNS, shift);
	printArray(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по строчно по возрастанию
	cout << "Сортировка массива по строчно по возрастанию " << endl;
	lineByLineSorting(*array, ROWS, COLUMNS);
	printArray(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по строчно по убыванию
	cout << "Сортировка массива по строчно по убыванию " << endl;
	lineByLineSorting(*array, ROWS, COLUMNS, false);
	printArray(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по возрастанию
	cout << "Cортировка всего массива по возрастанию" << endl;
	generalSort(*array, ROWS, COLUMNS);
	printArray(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по убыванию
	cout << "Cортировка всего массива по убыванию " << endl;
	generalSort(*array, ROWS, COLUMNS, false);
	printArray(*array, ROWS, COLUMNS);
	cout << endl << endl;


	return 0;
}

void fillRand(int* arr, const int ROWS, const int COLS) {

	for (int i = 0; i < ROWS * COLS; i++)
	{
		arr[i] = rand() % 100;
	}
}
void fillRand(float* arr, const int ROWS, const int COLS) {
	for (int i = 0; i < ROWS * COLS; i++)
	{
		arr[i] = (float)(rand() % 1000) / 10;
	}
}
void fillRand(double* arr, const int ROWS, const int COLS) {
	for (int i = 0; i < ROWS * COLS; i++)
	{
		arr[i] = (double)(rand() % 10000) / 100;
	}
}
void fillRand(char* arr, const int ROWS, const int COLS) {
	for (int i = 0; i < ROWS * COLS; i++)
	{
		arr[i] = rand() % 256;
	}
}

void printArray(int* arr, const int ROWS, const int COLS) {
	for (register int i = 0; i < ROWS * COLS; i++)
	{
		if (i != 0 && i % COLS == 0) cout << endl;
		cout << arr[i] << "\t";
	}
}
int getSum(int* arr, const int ROWS, const int COLS) {
	int sum = 0;
	for (int i = 0; i < ROWS * COLS; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double getAvg(int* arr, const int ROWS, const int COLS) {
	return (double)(getSum(arr, ROWS, COLS) / (ROWS * COLS));
}
int getMinVlaueIn(int* arr, const int ROWS, const int COLS) {
	int min = arr[0];
	for (int i = 1; i < ROWS * COLS; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}
int getMaxVlaueIn(int* arr, const int ROWS, const int COLS) {
	int max = arr[0];
	for (int i = 1; i < ROWS * COLS; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}
void shiftLeft(int* arr, const int ROWS, const int COLS, int number_of_shift) {
	for (int m = 0; m < ROWS * COLS; m++)
	{
		if (m % COLS == 0)
		{
			for (int i = 0; i < number_of_shift; i++)
			{
				int buffer = arr[m];
				for (int j = m; j < m + COLS - 1; j++)
				{
					arr[j] = arr[j + 1];
				}
				arr[m + COLS - 1] = buffer;
			}
		}
	}


}
void shiftRight(int* arr, const int ROWS, const int COLS, int number_of_shift) {

	for (int m = 0; m < ROWS * COLS; m++)
	{
		if (m % COLS == 0)
		{
			for (int i = 0; i < number_of_shift; i++)
			{
				int buffer = arr[m + COLS - 1];
				for (int j = m + COLS - 1; j > m; j--)
				{
					arr[j] = arr[j - 1];
				}
				arr[m] = buffer;
			}
		}
	}

}
void generalSort(int* arr, const int ROWS, const int COLS, bool type_of_sorting) {

	if (type_of_sorting) {
		for (int i = 0; i < ROWS * COLS; i++)
		{
			for (int j = i; j < ROWS * COLS; j++)
			{
				if (arr[i] > arr[j])
				{
					int buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < ROWS * COLS; i++)
		{
			for (int j = i; j < ROWS * COLS; j++)
			{
				if (arr[i] < arr[j])
				{
					int buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
				}
			}
		}
	}
}
void lineByLineSorting(int* arr, const int ROWS, const int COLS, bool type_of_sorting) {

	if (type_of_sorting)
	{
		for (int m = 0; m < ROWS * COLS; m++)
		{
			if (m % COLS == 0)
			{
				for (int i = m; i < m + COLS; i++)
				{
					for (int j = i; j < m + COLS; j++)
					{
						if (arr[i] > arr[j])
						{
							int buffer = arr[i];
							arr[i] = arr[j];
							arr[j] = buffer;
						}
					}
				}
			}
		}
	}
	else
	{
		for (int m = 0; m < ROWS * COLS; m++)
		{
			if (m % COLS == 0)
			{
				for (int i = m; i < m + COLS; i++)
				{
					for (int j = i; j < m + COLS; j++)
					{
						if (arr[i] < arr[j])
						{
							int buffer = arr[i];
							arr[i] = arr[j];
							arr[j] = buffer;
						}
					}
				}
			}
		}
	}


};

