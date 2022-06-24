#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void FillRand(int arr[], const int SIZE);
void FillRand(float arr[], const int SIZE);
void FillRand(double arr[], const int SIZE);
void FillRand(char arr[], const int SIZE);
template <typename T> void Print(T arr[], const int SIZE);
template <typename T> T Sum(T arr[], const int SIZE);
template <typename T> T Avg(T arr[], const int SIZE);
template <typename T> T minVlaueIn(T arr[], const int SIZE);
template <typename T> T maxVlaueIn(T arr[], const int SIZE);
template <typename T> void shiftLeft(T arr[], const int SIZE, int number_of_shift);
template <typename T> void shiftRight(T arr[], const int SIZE, int number_of_shift);
template <typename T> void Sort(T arr[], const int SIZE, bool type_of_sorting);



int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	const int SIZE = 10;
	char array[SIZE];

	//инициализация и вывод на консоль массива
	FillRand(array, SIZE);
	Print(array, SIZE);
	cout << endl << endl;

	//вывод суумы элементов массива
	auto sum = Sum(array, SIZE);
	cout << "Сумма элементов массива равна: " << sum;
	cout << endl << endl;

	//вывод среднего арифметического элементов массива
	auto avg = Avg(array, SIZE);
	cout << "Среднее арифметическое элементов массива равно: " << avg;
	cout << endl << endl;

	//вывод максимального элемента массива
	auto max = maxVlaueIn(array, SIZE);
	cout << "Максимальный элемент массива равен: " << max;
	cout << endl << endl;

	//вывод минимального элемента массива
	auto min = minVlaueIn(array, SIZE);
	cout << "Минимальный элемент массива равен: " << min;
	cout << endl << endl;

	//сортировка по возрастанию
	cout << "Cортировка по возрастанию ";
	Sort(array, SIZE, true);
	Print(array, SIZE);
	cout << endl << endl;

	//сортировка по убыванию
	cout << "Cортировка по убыванию ";
	Sort(array, SIZE, false);
	Print(array, SIZE);
	cout << endl << endl;

	//сдвиг массива вправо
	cout << "Cдвиг массива вправо ";
	shiftRight(array, SIZE, 4);
	Print(array, SIZE);
	cout << endl << endl;

	//сдвиг массива влево
	cout << "Cдвиг массива влево ";
	shiftLeft(array, SIZE, 4);
	Print(array, SIZE);
	cout << endl << endl;

	return 0;
}

void FillRand(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 100;
	}

}
void FillRand(float arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = (float)(rand() % 1000);
		arr[i] /= 10;
	}

}
void FillRand(double arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = (double)(rand() % 10000);
		arr[i] /= 100;
	}

}
void FillRand(char arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 255;
	}
}
template <typename T> void Print(T arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "  ";
	}
}
template <typename T> T Sum(T arr[], const int SIZE) {
	T sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
	}
	return sum;
}
template <typename T> T Avg(T arr[], const int SIZE) {
	T sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
	}
	return sum / SIZE;
}
template <typename T> T minVlaueIn(T arr[], const int SIZE) {
	T min = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}
template <typename T> T maxVlaueIn(T arr[], const int SIZE) {
	T max = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}
template <typename T> void shiftLeft(T arr[], const int SIZE, int number_of_shift) {
	for (int i = 0; i < number_of_shift; i++)
	{
		T buffer = arr[0];
		for (int j = 0; j < SIZE - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[SIZE - 1] = buffer;
	}
}
template <typename T> void shiftRight(T arr[], const int SIZE, int number_of_shift) {
	for (int i = 0; i < number_of_shift; i++)
	{
		T buffer = arr[SIZE - 1];
		for (int j = SIZE - 1; j >= 0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = buffer;
	}
}
template <typename T> void Sort(T arr[], const int SIZE, bool type_of_sorting) {

	if (type_of_sorting) {
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = i; j < SIZE; j++)
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
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = i; j < SIZE; j++)
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

