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
int getSum(int [], const int );
//int getSum(float[], const int);
//int getSum(double[], const int);
int getAvg(int [], const int );
//int getAvg(float[], const int);
//int getAvg(double[], const int);
int getMinValueIn(int [], const int );
//int getMinValueIn(float[], const int);
//int getMinValueIn(double[], const int);
int getMaxValueIn(int [], const int);
//int getMaxValueIn(float[], const int SZE);
//int getMaxValueIn(double[], const int SZE);
void shiftLeft(int [], const int , int);
//void shiftLeft(float[], const int, int nuber_of_shift);
//void shiftLeft(double[], const int, int nuber_of_shift);
void shiftRight(int [], const int , int );
//void shiftRight(float[], const int, int);
//void shiftRight(double[], const int, int);
void sort (int [], const int , bool );
//void sort(float[], const int, bool);
//void sort(double[], const int, bool);

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
	int sum = getSum(array, SIZE);
	cout << "Сумма элементов массива равна: " << sum;
	cout << endl << endl;

	//вывод среднего арифметического элементов массива
	int avg = getAvg(array, SIZE);
	cout << "Среднее арифметическое элементов массива равно: " << avg;
	cout << endl << endl;

	//вывод максимального элемента массива
	int max = getMaxValueIn(array, SIZE);
	cout << "Максимальный элемент массива равен: " << max;
	cout << endl << endl;

	//вывод минимального элемента массива
	int min = getMinValueIn(array, SIZE);
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

int getSum(int arr[], const int SIZE) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
	}
	return sum;
}
//float getSum(float arr[], const int SIZE) {
//	float getSum = 0;
//	for (int i = 0; i < SIZE; i++)
//	{
//		getSum += arr[i];
//	}
//	return getSum;
//}
//double getSum(double arr[], const int SIZE) {
//	double getSum = 0;
//	for (int i = 0; i < SIZE; i++)
//	{
//		getSum += arr[i];
//	}
//	return getSum;
//}

int getAvg(int arr[], const int SIZE) {
	
	return getSum (arr, SIZE) / SIZE;
}
//float getAvg(float arr[], const int SIZE) {
//
//	return getSum(arr, SIZE) / SIZE;
//}
//double getAvg(double arr[], const int SIZE) {
//
//	return getSum(arr, SIZE) / SIZE;
//}

int getMinValueIn(int arr[], const int SIZE) {
	int min = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}
//float getMinValueIn(float arr[], const int SIZE) {
//	float min = arr[0];
//	for (int i = 1; i < SIZE; i++)
//	{
//		if (min > arr[i]) min = arr[i];
//	}
//	return min;
//}
//double getMinValueIn(double arr[], const int SIZE) {
//	double min = arr[0];
//	for (int i = 1; i < SIZE; i++)
//	{
//		if (min > arr[i]) min = arr[i];
//	}
//	return min;
//}

int getMaxValueIn(int arr[], const int SIZE) {
	int max = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}
//float getMaxValueIn(float arr[], const int SIZE) {
//	float max = arr[0];
//	for (int i = 1; i < SIZE; i++)
//	{
//		if (max < arr[i]) max = arr[i];
//	}
//	return max;
//}
//double getMaxValueIn(double arr[], const int SIZE) {
//	double max = arr[0];
//	for (int i = 1; i < SIZE; i++)
//	{
//		if (max < arr[i]) max = arr[i];
//	}
//	return max;
//}

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
//void shiftLeft(float arr[], const int SIZE, int number_of_shift) {
//	for (int i = 0; i < number_of_shift; i++)
//	{
//		float buffer = arr[0];
//		for (int j = 0; j < SIZE - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[SIZE - 1] = buffer;
//	}
//}
//void shiftLeft(double arr[], const int SIZE, int number_of_shift) {
//	for (int i = 0; i < number_of_shift; i++)
//	{
//		double buffer = arr[0];
//		for (int j = 0; j < SIZE - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[SIZE - 1] = buffer;
//	}
//}

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
//void shiftRight(float arr[], const int SIZE, int number_of_shift) {
//	for (int i = 0; i < number_of_shift; i++)
//	{
//		float buffer = arr[SIZE - 1];
//		for (int j = SIZE - 1; j >= 0; j--)
//		{
//			arr[j] = arr[j - 1];
//		}
//		arr[0] = buffer;
//	}
//}
//void shiftRight(double arr[], const int SIZE, int number_of_shift) {
//	for (int i = 0; i < number_of_shift; i++)
//	{
//		double buffer = arr[SIZE - 1];
//		for (int j = SIZE - 1; j >= 0; j--)
//		{
//			arr[j] = arr[j - 1];
//		}
//		arr[0] = buffer;
//	}
//}

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
//void sort(float arr[], const int SIZE, bool type_of_sorting) {
//
//	if (type_of_sorting) {
//		for (int i = 0; i < SIZE; i++)
//		{
//			for (int j = i; j < SIZE; j++)
//			{
//				if (arr[i] > arr[j])
//				{
//					float buffer = arr[i];
//					arr[i] = arr[j];
//					arr[j] = buffer;
//				}
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < SIZE; i++)
//		{
//			for (int j = i; j < SIZE; j++)
//			{
//				if (arr[i] < arr[j])
//				{
//					float buffer = arr[i];
//					arr[i] = arr[j];
//					arr[j] = buffer;
//				}
//			}
//		}
//	}
//}
//void sort(double arr[], const int SIZE, bool type_of_sorting) {
//
//	if (type_of_sorting) {
//		for (int i = 0; i < SIZE; i++)
//		{
//			for (int j = i; j < SIZE; j++)
//			{
//				if (arr[i] > arr[j])
//				{
//					double buffer = arr[i];
//					arr[i] = arr[j];
//					arr[j] = buffer;
//				}
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < SIZE; i++)
//		{
//			for (int j = i; j < SIZE; j++)
//			{
//				if (arr[i] < arr[j])
//				{
//					double buffer = arr[i];
//					arr[i] = arr[j];
//					arr[j] = buffer;
//				}
//			}
//		}
//	}
//}

