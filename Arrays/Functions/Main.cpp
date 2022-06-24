#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void fillRand(int*&, const int );
void fillRand(float*&, const int );
void fillRand(double*&, const int );
void fillRand(char*&, const int );


template<typename T> void print(T*&, const int );

template<typename T> T getSum(T*&, const int );

template<typename T> T getAvg(T*&, const int );

template<typename T> T getMinValueIn(T*&, const int );

template<typename T> T getMaxValueIn(T*&, const int);

template<typename T> void shiftLeft(T*&, const int , int);

template<typename T> void shiftRight(T*&, const int , int );

template<typename T> void sort (T*&, const int , bool );


int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int size = 10;
	int* array = new int [size];
	
	
	//инициализация и вывод на консоль массива
	fillRand(array, size);
	print(array, size);
	cout << endl << endl;

	//вывод суумы элементов массива
	int sum = getSum(array, size);
	cout << "Сумма элементов массива равна: " << sum;
	cout << endl << endl;

	//вывод среднего арифметического элементов массива
	int avg = getAvg(array, size);
	cout << "Среднее арифметическое элементов массива равно: " << avg;
	cout << endl << endl;

	//вывод максимального элемента массива
	int max = getMaxValueIn(array, size);
	cout << "Максимальный элемент массива равен: " << max;
	cout << endl << endl;

	//вывод минимального элемента массива
	int min = getMinValueIn(array, size);
	cout << "Минимальный элемент массива равен: " << min;
	cout << endl << endl;

	//сдвиг массива вправо
	cout << "Cдвиг массива вправо ";
	shiftRight(array, size, 4);
	print(array, size);
	cout << endl << endl;

	//сдвиг массива влево
	cout << "Cдвиг массива влево ";
	shiftLeft(array, size, 4);
	print(array, size);
	cout << endl << endl;

	//сортировка по возрастанию
	cout << "Cортировка по возрастанию ";
	sort(array, size, true);
	print(array, size);
	cout << endl << endl;

	//сортировка по убыванию
	cout << "Cортировка по убыванию ";
	sort(array, size, false);
	print(array, size);
	cout << endl << endl;
	return 0;
}

void fillRand(int*& arr, const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 100;
	}

}
void fillRand(float*& arr, const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = (float)(rand() % 1000);
		arr[i] /= 10;
	}

}
void fillRand(double*& arr, const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = (double)(rand() % 10000);
		arr[i] /= 100;
	}

}
void fillRand(char*& arr, const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 255;
	}
}

template<typename T> void print(T*& arr, const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "  ";
	}
}

template<typename T> T getSum(T*& arr, const int SIZE) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
	}
	return sum;
}

template<typename T> T getAvg(T*& arr, const int SIZE) {
	
	return getSum (arr, SIZE) / SIZE;
}

template<typename T> T getMinValueIn(T*& arr, const int SIZE) {
	int min = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}

template<typename T> T getMaxValueIn(T*& arr, const int SIZE) {
	int max = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

template<typename T> void shiftLeft(T*& arr, const int SIZE, int number_of_shift) {
	for (int i = 0; i < number_of_shift; i++)
	{
		int buffer = arr[0];
		for (int j = 0; j < SIZE - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[SIZE - 1] = buffer;
	}
}

template<typename T> void shiftRight(T*& arr, const int SIZE, int number_of_shift) {
	for (int i = 0; i < number_of_shift; i++)
	{
		int buffer = arr[SIZE - 1];
		for (int j = SIZE - 1; j >= 0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = buffer;
	}
}

template<typename T> void sort(T*& arr, const int SIZE, bool type_of_sorting) {

	if (type_of_sorting) {
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = i; j < SIZE; j++)
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
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = i; j < SIZE; j++)
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


