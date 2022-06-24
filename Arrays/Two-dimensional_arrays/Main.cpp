#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void FillRand(int*, const int, const int);
void FillRand(float*, const int, const int);
void FillRand(double*, const int, const int);
void FillRand(char*, const int, const int);

template <typename T> void Print(T*, const int, const int);
template <typename T> T Sum(T*, const int, const int);
template <typename T> double Avg(T*, const int, const int);
template <typename T> T minVlaueIn(T*, const int, const int);
template <typename T> T maxVlaueIn(T*, const int, const int);
template <typename T> void shiftLeft(T*, const int, const int, int);
template <typename T> void shiftRight(T*, const int, const int, int);
template <typename T> void GeneralSort(T*, const int, const int, bool type_of_sorting = true);
template <typename T> void LineByLineSorting(T*, const int, const int, bool type_of_sorting = true);





int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	const int ROWS = 5, COLUMNS = 5;
	int array[ROWS][COLUMNS];

	//инициализация и вывод на консоль массива
	FillRand(*array, ROWS, COLUMNS);
	Print(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//вывод суумы элементов массива
	auto sum = Sum(*array, ROWS, COLUMNS);
	cout << "Сумма элементов массива равна: " << sum;
	cout << endl << endl;

	//вывод среднего арифметического элементов массива
	auto avg = Avg(*array, ROWS, COLUMNS);
	cout << "Среднее арифметическое элементов массива равно: " << avg;
	cout << endl << endl;

	//вывод максимального элемента массива
	auto max = maxVlaueIn(*array, ROWS, COLUMNS);
	cout << "Максимальный элемент массива равен: " << max;
	cout << endl << endl;

	//вывод минимального элемента массива
	auto min = minVlaueIn(*array, ROWS, COLUMNS);
	cout << "Минимальный элемент массива равен: " << min;
	cout << endl << endl;

	//сдвиг массива вправо
	int shift = 1;
	cout << "Cдвиг массива вправо на " << shift << " элемента " << endl;
	shiftRight(*array, ROWS, COLUMNS, shift);
	Print(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//сдвиг массива влево
	shift = 1;
	cout << "Cдвиг массива влево на " << shift << " элемента " << endl;
	shiftLeft(*array, ROWS, COLUMNS, shift);
	Print(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по строчно по возрастанию
	cout << "Сортировка массива по строчно по возрастанию " << endl;
	LineByLineSorting(*array, ROWS, COLUMNS);
	Print(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по строчно по убыванию
	cout << "Сортировка массива по строчно по убыванию " << endl;
	LineByLineSorting(*array, ROWS, COLUMNS, false);
	Print(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по возрастанию
	cout << "Cортировка всего массива по возрастанию" << endl;
	GeneralSort(*array, ROWS, COLUMNS);
	Print(*array, ROWS, COLUMNS);
	cout << endl << endl;

	//сортировка по убыванию
	cout << "Cортировка всего массива по убыванию " << endl;
	GeneralSort(*array, ROWS, COLUMNS, false);
	Print(*array, ROWS, COLUMNS);
	cout << endl << endl;


	return 0;
}

void FillRand(int* arr, const int ROWS, const int COLUMNS) {

	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(float* arr, const int ROWS, const int COLUMNS) {
	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		arr[i] = (float)(rand() % 1000) / 10;
	}
}
void FillRand(double* arr, const int ROWS, const int COLUMNS) {
	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		arr[i] = (double)(rand() % 10000) / 100;
	}
}
void FillRand(char* arr, const int ROWS, const int COLUMNS) {
	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		arr[i] = rand() % 256;
	}
}
template <typename T> void Print(T* arr, const int ROWS, const int COLUMNS) {
	for (register int i = 0; i < ROWS * COLUMNS; i++)
	{
		if (i != 0 && i % COLUMNS == 0) cout << endl;
		cout << arr[i] << "\t";
	}
}
template <typename T> T Sum(T* arr, const int ROWS, const int COLUMNS) {
	T sum = 0;
	for (int i = 0; i < ROWS * COLUMNS; i++)
	{
		sum += arr[i];
	}
	return sum;
}
template <typename T> double Avg(T* arr, const int ROWS, const int COLUMNS) {
	return (double)Sum(arr, ROWS, COLUMNS) / (ROWS * COLUMNS);
}
template <typename T> T minVlaueIn(T* arr, const int ROWS, const int COLUMNS) {
	T min = arr[0];
	for (int i = 1; i < ROWS * COLUMNS; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}
template <typename T> T maxVlaueIn(T* arr, const int ROWS, const int COLUMNS) {
	T max = arr[0];
	for (int i = 1; i < ROWS * COLUMNS; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}
template <typename T> void shiftLeft(T* arr, const int ROWS, const int COLUMNS, int number_of_shift) {
	for (int m = 0; m < ROWS * COLUMNS; m++)
	{
		if (m % COLUMNS == 0)
		{
			for (int i = 0; i < number_of_shift; i++)
			{
				T buffer = arr[m];
				for (int j = m; j < m + COLUMNS - 1; j++)
				{
					arr[j] = arr[j + 1];
				}
				arr[m + COLUMNS - 1] = buffer;
			}
		}
	}


}
template <typename T> void shiftRight(T* arr, const int ROWS, const int COLUMNS, int number_of_shift) {

	for (int m = 0; m < ROWS * COLUMNS; m++)
	{
		if (m % COLUMNS == 0)
		{
			for (int i = 0; i < number_of_shift; i++)
			{
				T buffer = arr[m + COLUMNS - 1];
				for (int j = m + COLUMNS - 1; j > m; j--)
				{
					arr[j] = arr[j - 1];
				}
				arr[m] = buffer;
			}
		}
	}

}
template <typename T> void GeneralSort(T* arr, const int ROWS, const int COLUMNS, bool type_of_sorting) {

	if (type_of_sorting) {
		for (int i = 0; i < ROWS * COLUMNS; i++)
		{
			for (int j = i; j < ROWS * COLUMNS; j++)
			{
				if (arr[i] > arr[j])
				{
					T buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < ROWS * COLUMNS; i++)
		{
			for (int j = i; j < ROWS * COLUMNS; j++)
			{
				if (arr[i] < arr[j])
				{
					T buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
				}
			}
		}
	}
}
template <typename T> void LineByLineSorting(T* arr, const int ROWS, const int COLUMNS, bool type_of_sorting) {

	if (type_of_sorting)
	{
		for (int m = 0; m < ROWS * COLUMNS; m++)
		{
			if (m % COLUMNS == 0)
			{
				for (int i = m; i < m + COLUMNS; i++)
				{
					for (int j = i; j < m + COLUMNS; j++)
					{
						if (arr[i] > arr[j])
						{
							T buffer = arr[i];
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
		for (int m = 0; m < ROWS * COLUMNS; m++)
		{
			if (m % COLUMNS == 0)
			{
				for (int i = m; i < m + COLUMNS; i++)
				{
					for (int j = i; j < m + COLUMNS; j++)
					{
						if (arr[i] < arr[j])
						{
							T buffer = arr[i];
							arr[i] = arr[j];
							arr[j] = buffer;
						}
					}
				}
			}
		}
	}


};

