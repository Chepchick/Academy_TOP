#include <iostream>
#include <ctime>
using namespace std;

//////////////////////////////////////////////////////////
//методы для одномерных массивов
int* getNewFillIntegerArray(int);//инициализирует указатель ссылкой на массив,
//заполненный случайными целыми числами
void printArray(int*, int);//выводит массив на консоль

void push_back(int*&, int&, int);//добавляет указанное значение в конец одномерного динамиечского массива
void push_front(int*&, int&, int);//добавляет указанное значение в начало одномерного динамиечского массива
void insert(int*&, int&, int, int);//вставляет указанное значение в динамиечский массив по указанному индексу
void pop_back(int*&, int&);//удаляет последний элемент массива
void pop_front(int*&, int&);//удаляет нулевой элемент массива
void erase(int*&, int&, int);//удаляет значение из одномерного динамиечского массива по указанному индексу

//////////////////////////////////////////////////////////
//методы для двумерных массивов

int** getNewFillTwoDimensionalIntegerArray(int rows, int cols);// заполнение двумерного массива
void printTwoDimensionalArray(int** arr, int rows, int cols);// вывод массива на консоль

void pushRowUp(int**& arr, int& rows, int cols);//добавление пустой строки вверх двумерного массива
void pushRowDown(int**& arr, int& rows, int cols);//добавление пустой строки вниз двумерного массива
void pushColumnLeft(int**& arr, int rows, int& cols);//добавление пустой колонки слева двумерного массива
void pushColumnRight(int**& arr, int rows, int& cols);//добавление пустой колонки справа двумерного массива
void insertCol(int**& arr, int rows, int& cols, int index);//добавление пустой колонки в двумерный массив по индексу
void insertRow(int**& arr, int& rows, int cols, int index);//добавление пустой строки в двумерный массив по индексу
void eraseRow(int**& arr, int& rows, int cols, int index);//удаление строки из двумерного массива по индексу
void eraseCol(int**& arr, int rows, int& cols, int index);//удаление колонки из двумерного массива по индексу
void popRowUp(int**& arr, int& rows, int cols);//удаление верхеней строки двумерного массива
void popRowDown(int**& arr, int& rows, int cols);//удаление нижней строки двумерного массива
void popColumnLeft(int**& arr, int rows, int& cols);//удаление левой колонки двумерного массива
void popColumnRight(int**& arr, int rows, int& cols);//удаление правой колонки двумерного массива

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

///////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////
int** getNewFillTwoDimensionalIntegerArray(int rows, int cols)
{
	if (rows < 2 || cols < 2)
	{
		cout << "Ошибка! Параметры размерности не могут быть меньше 2" << endl;
	}
	else
	{
		int** newArray = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = new int[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				newArray[i][j] = 1 + rand() % 9;
			}
		}
		return newArray;
	}
}
void printTwoDimensionalArray(int** arr, int rows, int cols) {

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void pushRowUp(int**& arr, int& rows, int cols) {

	int** newArray = new int* [rows];
	for (int i = 0; i < rows + 1; i++)
	{
		newArray[i] = new int[cols]{};
	}

	for (int i = 1; i < rows + 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newArray[i][j] = arr[i - 1][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	rows++;

}
void pushRowDown(int **& arr, int& rows, int cols) {

	int** newArray = new int* [rows];
	for (int i = 0; i < rows + 1; i++)
	{
		newArray[i] = new int[cols]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newArray[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	rows++;
}
void pushColumnLeft(int**& arr, int rows, int& cols) {

	int** newArray = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		newArray[i] = new int[cols + 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 1; j < cols + 1; j++)
		{
			newArray[i][j] = arr[i][j - 1];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	cols++;

}
void pushColumnRight(int**& arr, int rows, int& cols) {

	int** newArray = new int * [rows];
	for (int i = 0; i < rows; i++)
	{
		newArray[i] = new int[cols + 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newArray[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	cols++;

}
void insertCol(int**& arr, int rows, int& cols, int index) {

	int shiftCol;
	int** newArray = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		newArray[i] = new int[cols + 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		shiftCol = 0;
		for (int j = 0; j < cols; j++)
		{
			if (j == index) shiftCol = 1;
			newArray[i][j + shiftCol] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	cols++;

}
void insertRow(int**& arr, int& rows, int cols, int index) {

	int shiftRow = 0;
	int** newArray = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++)
	{
		newArray[i] = new int[cols]{};
	}

	for (int i = 0; i < rows; i++)
	{
		if (i == index) shiftRow = 1;
		for (int j = 0; j < cols; j++)
		{
			newArray[i + shiftRow][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	rows++;

}
void eraseRow(int**& arr, int& rows, int cols, int index) {

	int shiftRow = 0;
	int** newArray = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		newArray[i] = new int[cols]{};
	}

	for (int i = 0; i < rows - 1; i++)
	{
		if (i == index) shiftRow = 1;
		for (int j = 0; j < cols; j++)
		{
			newArray[i][j] = arr[i + shiftRow][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	rows--;

}
void eraseCol(int**& arr, int rows, int& cols, int index) {

	int shiftCol;
	int** newArray = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		newArray[i] = new int[cols - 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		shiftCol = 0;
		for (int j = 0; j < cols - 1; j++)
		{
			if (j == index) shiftCol = 1;
			newArray[i][j] = arr[i][j + shiftCol];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	cols--;

}
void popRowUp(int**& arr, int& rows, int cols) {

	int** newArray = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		newArray[i] = new int[cols]{};
	}

	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newArray[i][j] = arr[i + 1][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	rows--;

}
void popRowDown(int**& arr, int& rows, int cols) {

	int** newArray = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		newArray[i] = new int[cols]{};
	}

	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newArray[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	rows--;

}
void popColumnLeft(int**& arr, int rows, int& cols) {

	int** newArray = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		newArray[i] = new int[cols - 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			newArray[i][j] = arr[i][j + 1];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	cols--;

}
void popColumnRight(int**& arr, int rows, int& cols) {

	int** newArray = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		newArray[i] = new int[cols - 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			newArray[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	arr = newArray;
	cols--;

}