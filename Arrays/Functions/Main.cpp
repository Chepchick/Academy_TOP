#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void fillRand(int [], const int );
void fillRand(float [], const int );
void fillRand(double [], const int );
void fillRand(char [], const int );
void print(int [], const int );
void print(float[], const int);
void print(double[], const int);
void print(char[], const int);
int sum(int [], const int );
int sum(float[], const int);
int sum(double[], const int);
int avg(int [], const int );
int avg(float[], const int);
int avg(double[], const int);
int minValueIn(int [], const int );
int minValueIn(float[], const int);
int minValueIn(double[], const int);
int maxValueIn(int [], const int SZE);
int maxValueIn(float[], const int SZE);
int maxValueIn(double[], const int SZE);
void shiftLeft(int [], const int , int nuber_of_shift);
void shiftLeft(float[], const int, int nuber_of_shift);
void shiftLeft(double[], const int, int nuber_of_shift);
void shiftRight(int [], const int , int );
void shiftRight(float[], const int, int);
void shiftRight(double[], const int, int);
void sort (int [], const int , bool );
void sort(float[], const int, bool);
void sort(double[], const int, bool);

int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	const int SIZE = 10;
	int array[SIZE];

	//инициализация и вывод на консоль массива
	fillRand(array, SIZE);
	print(array, SIZE);
	cout << endl << endl;

	//вывод суумы элементов массива
	int sum = sum(array, SIZE);
	cout << "Сумма элементов массива равна: " << sum;
	cout << endl << endl;

	//вывод среднего арифметического элементов массива
	int avg = avg(array, SIZE);
	cout << "Среднее арифметическое элементов массива равно: " << avg;
	cout << endl << endl;

	//вывод максимального элемента массива
	int max = maxValueIn(array, SIZE);
	cout << "Максимальный элемент массива равен: " << max;
	cout << endl << endl;

	//вывод минимального элемента массива
	int min = minValueIn(array, SIZE);
	cout << "Минимальный элемент массива равен: " << min;
	cout << endl << endl;

	//сортировка по возрастанию
	cout << "Cортировка по возрастанию ";
	sort(array, SIZE, true);
	print(array, SIZE);
	cout << endl << endl;

	//сортировка по убыванию
	cout << "Cортировка по убыванию ";
	sort(array, SIZE, false);
	print(array, SIZE);
	cout << endl << endl;

	//сдвиг массива вправо
	cout << "Cдвиг массива вправо ";
	shiftRight(array, SIZE, 4);
	print(array, SIZE);
	cout << endl << endl;

	//сдвиг массива влево
	cout << "Cдвиг массива влево ";
	shiftLeft(array, SIZE, 4);
	print(array, SIZE);
	cout << endl << endl;

	return 0;
}

void fillRand(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 100;
	}

}
void fillRand(float arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = (float)(rand() % 1000);
		arr[i] /= 10;
	}

}
void fillRand(double arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = (double)(rand() % 10000);
		arr[i] /= 100;
	}

}
void fillRand(char arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 255;
	}
}

void print(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "  ";
	}
}
void print(float arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "  ";
	}
}
void print(double arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "  ";
	}
}
void print(char arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "  ";
	}
}

int sum(int arr[], const int SIZE) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
	}
	return sum;
}
float sum(float arr[], const int SIZE) {
	float sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double sum(double arr[], const int SIZE) {
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int Avg(int arr[], const int SIZE) {
	
	return sum (arr, SIZE) / SIZE;
}
float Avg(float arr[], const int SIZE) {

	return sum(arr, SIZE) / SIZE;
}
double Avg(double arr[], const int SIZE) {

	return sum(arr, SIZE) / SIZE;
}

int minValueIn(int arr[], const int SIZE) {
	int min = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}
float minValueIn(float arr[], const int SIZE) {
	float min = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}
double minValueIn(double arr[], const int SIZE) {
	double min = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}

int maxValueIn(int arr[], const int SIZE) {
	int max = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}
float maxValueIn(float arr[], const int SIZE) {
	float max = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}
double maxValueIn(double arr[], const int SIZE) {
	double max = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

void shiftLeft(int arr[], const int SIZE, int number_of_shift) {
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
void shiftLeft(float arr[], const int SIZE, int number_of_shift) {
	for (int i = 0; i < number_of_shift; i++)
	{
		float buffer = arr[0];
		for (int j = 0; j < SIZE - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[SIZE - 1] = buffer;
	}
}
void shiftLeft(double arr[], const int SIZE, int number_of_shift) {
	for (int i = 0; i < number_of_shift; i++)
	{
		double buffer = arr[0];
		for (int j = 0; j < SIZE - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[SIZE - 1] = buffer;
	}
}

void shiftRight(int arr[], const int SIZE, int number_of_shift) {
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
void shiftRight(float arr[], const int SIZE, int number_of_shift) {
	for (int i = 0; i < number_of_shift; i++)
	{
		float buffer = arr[SIZE - 1];
		for (int j = SIZE - 1; j >= 0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = buffer;
	}
}
void shiftRight(double arr[], const int SIZE, int number_of_shift) {
	for (int i = 0; i < number_of_shift; i++)
	{
		double buffer = arr[SIZE - 1];
		for (int j = SIZE - 1; j >= 0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = buffer;
	}
}

void sort(int arr[], const int SIZE, bool type_of_sorting) {

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
void sort(float arr[], const int SIZE, bool type_of_sorting) {

	if (type_of_sorting) {
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = i; j < SIZE; j++)
			{
				if (arr[i] > arr[j])
				{
					float buffer = arr[i];
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
					float buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
				}
			}
		}
	}
}
void sort(double arr[], const int SIZE, bool type_of_sorting) {

	if (type_of_sorting) {
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = i; j < SIZE; j++)
			{
				if (arr[i] > arr[j])
				{
					double buffer = arr[i];
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
					double buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
				}
			}
		}
	}
}

