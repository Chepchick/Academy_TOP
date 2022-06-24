#include <iostream>
#include <ctime>
using namespace std;

int* getNewFillIntegerArray(int);//инициализирует указатель ссылкой на массив,
//заполненный случайными целыми числами
void printArray(int*, int);//выводит массив на консоль

//////////////////////////////////////////////////////////
void push_back(int*&, int&, int);//добавляет указанное значение в конец динамиечского массива
void push_front(int*&, int&, int);//добавляет указанное значение в начало динамиечского массива
void insert(int*&, int&, int, int);//вставляет указанное значение в динамиечский массив по указанному индексу
void pop_back(int*&, int&);//удаляет последний элемент массива
void pop_front(int*&, int&);//удаляет нулевой элемент массива
void erase(int*&, int&, int);//удаляет значение из динамиечский массив по указанному индексу

int main() {
	setlocale(LC_ALL, " ");
	srand(time(NULL));

	int size = 10;//размер массива
	int value = 146;//новое вводимое значение
	int index = 4;// индекс под которым вводится новое значение в массив

	int* basicArray = getNewFillIntegerArray(size);
	printArray(basicArray, size);
	cout << endl << endl;

	int evenArraySize = 0;//размер массива с четными числами
	int oddArraySize = 0;//размер массива с нечетными числами

	for (int i = 0; i < size; i++)
		basicArray[i] % 2 == 0 ? evenArraySize++ : oddArraySize++;

	//объявляем два массива размерами по количеству четных и нечетных чисел
	int* even = new int[evenArraySize];
	int* odd = new int[oddArraySize];

	//инициализируем массивы
	for (int i = 0, j = 0, m = 0; i < size; i++)
		(basicArray[i] % 2 == 0 ? even[j++] : odd[m++]) = basicArray[i];

	printArray(even, evenArraySize);
	cout << endl;
	printArray(odd, oddArraySize);
	cout << endl << endl;
	///////////////////////////////////////////////////////////////////////

	insert(basicArray, size, value, index);
	printArray(basicArray, size);
	cout << endl << endl;

	push_back(basicArray, size, value);
	printArray(basicArray, size);
	cout << endl << endl;

	push_front(basicArray, size, value);
	printArray(basicArray, size);
	cout << endl << endl;

	pop_front(basicArray, size);
	printArray(basicArray, size);
	cout << endl << endl;

	pop_back(basicArray, size);
	printArray(basicArray, size);
	cout << endl << endl;

	erase(basicArray, size, index);
	printArray(basicArray, size);
	cout << endl << endl;




	return 0;
}

int* getNewFillIntegerArray(int size) {
	if (size < 1)
	{
		cout << "Ошибка! Параметр size не может быть меньше 1" << endl;
	}
	else
	{
		int* array = new int[size];

		for (int i = 0; i < size; i++)
		{
			array[i] = 1 + rand() % 9;
		}
		return array;
	}
}
void printArray(int* arr, int size) {

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}
/////////////////////////////////////////////////////////
void push_back(int*& arr, int& size, int number) {

	int* newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size] = number;

	size++;

	delete[]arr;

	arr = newArray;



}
void push_front(int*& arr, int& size, int number) {

	int* newArray = new int[size + 1];

	newArray[0] = number;
	for (int i = 1; i < size + 1; i++)
	{
		newArray[i] = arr[i - 1];
	}

	size++;

	delete[]arr;

	arr = newArray;
}
void insert(int*& arr, int& size, int number, int index) {

	int* newArray = new int[size + 1];

	int i = 0;
	for (; i < index; i++)
	{
		newArray[i] = arr[i];
	}

	newArray[i] = number;

	for (; i < size; i++)
	{
		newArray[i + 1] = arr[i];
	}

	size++;

	delete[]arr;

	arr = newArray;
}
void pop_back(int*& arr, int& size) {

	int* newArray = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
	{
		newArray[i] = arr[i];
	}
	size--;

	delete[]arr;

	arr = newArray;
}
void pop_front(int*& arr, int& size) {

	int* newArray = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
	{
		newArray[i] = arr[i + 1];
	}

	size--;

	delete[]arr;

	arr = newArray;
}
void erase(int*& arr, int& size, int index) {

	int* newArray = new int[size - 1];

	int i = 0;
	for (; i < index; i++)
	{
		newArray[i] = arr[i];
	}

	for (; i < size; i++)
	{
		newArray[i] = arr[i + 1];
	}

	size--;

	delete[]arr;

	arr = newArray;
}
