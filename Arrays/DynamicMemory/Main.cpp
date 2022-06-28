#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class OperationsWithArrays { // объявление класса для операций с массивами

public:
	//заполнение одномерного массива
	int* getNewFillIntegerArray(int size)
	{

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
	float* getNewFillFloatArray(float size) {

		if (size < 1)
		{
			cout << "Ошибка! Параметр size не может быть меньше 1" << endl;
		}
		else
		{
			float* array = new float[size];

			for (int i = 0; i < size; i++)
			{
				array[i] = 1 + rand() % 9;
			}
			return array;
		}
	}
	double* getNewFillDoubleArray(double size) {

		if (size < 1)
		{
			cout << "Ошибка! Параметр size не может быть меньше 1" << endl;
		}
		else
		{
			double* array = new double[size];

			for (int i = 0; i < size; i++)
			{
				array[i] = 1 + rand() % 9;
			}
			return array;
		}
	}

	// заполнение двумерного массива
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
	float** getNewFillTwoDimensionalFloatArray(int rows, int cols)
	{
		if (rows < 2 || cols < 2)
		{
			cout << "Ошибка! Параметры размерности не могут быть меньше 2" << endl;
		}
		else
		{
			float** newArray = new float* [rows];
			for (int i = 0; i < rows; i++)
			{
				newArray[i] = new float[cols];
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
	double** getNewFillTwoDimensionalDoubleArray(int rows, int cols)
	{
		if (rows < 2 || cols < 2)
		{
			cout << "Ошибка! Параметры размерности не могут быть меньше 2" << endl;
		}
		else
		{
			double** newArray = new double* [rows];
			for (int i = 0; i < rows; i++)
			{
				newArray[i] = new double[cols];
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

	// вывод массива на консоль
	template<typename T> void printArray(T* arr, int size) {

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	template<typename T> void printTwoDimensionalArray(T** arr, int rows, int cols) {

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// манипуляции с элементами в одномерном массиве

	//добавление элемента в конец массива
	template <typename T> void pushBack(T*& arr, int& size, T number) {

		T* newArray = new T[size + 1];

		for (int i = 0; i < size; i++)
		{
			newArray[i] = arr[i];
		}
		newArray[size] = number;

		size++;

		delete[]arr;

		arr = newArray;
	}

	//добавление элемента в начало массива
	template <typename T> void pushFront(T*& arr, int& size, T number) {

		T* newArray = new T[size + 1];

		newArray[0] = number;
		for (int i = 1; i < size + 1; i++)
		{
			newArray[i] = arr[i - 1];
		}

		size++;

		delete[]arr;

		arr = newArray;
	}

	//добавление элемента в массив по индексу
	template <typename T> void insert(T*& arr, int& size, T number, int index) {

		T* newArray = new T[size + 1];

		int shift = 0;
		for (int i = 0; i < size; i++)
		{
			if (i == index) shift = 1;
			newArray[i + shift] = arr[i];			
		}
		newArray[index] = number;
		delete[]arr;
		arr = newArray;
		size++;
	}

	//удаление последнеко элемента массива
	template <typename T> void popBack(T*& arr, int& size) {

		T* newArray = new T[size - 1];

		for (int i = 0; i < size - 1; i++)
		{
			newArray[i] = arr[i];
		}
		size--;

		delete[]arr;

		arr = newArray;
	}

	//удаление первого элемента массива
	template <typename T> void popFront(T*& arr, int& size) {

		T* newArray = new T[size - 1];

		for (int i = 0; i < size - 1; i++)
		{
			newArray[i] = arr[i + 1];
		}

		size--;

		delete[]arr;

		arr = newArray;
	}

	//удаление элемента из массива по индексу
	template <typename T> void erase(T*& arr, int& size, int index) {

		T* newArray = new T[size - 1];
		int shift = 0;
		
		for (int i = 0; i < size - 1; i++)
		{
			if (i == index) shift = 1;
			newArray[i] = arr[i + shift];
		}
		delete[]arr;
		arr = newArray;
		size--;
	}

	///////////////////////////////////////////////////////////////////////////////////////////
	// манипуляции со строками и колонками в двумерном массиве

	//добавление пустой строки вверх двумерного массива
	template <typename T> void pushRowUp(T**& arr, int& rows, int cols) {

		T** newArray = new T * [rows + 1];
		for (int i = 1; i < rows + 1; i++)
		{
			newArray[i] = arr[i - 1];
		}
		delete[]arr;
		arr = newArray;
		arr[0] = new T[cols]{};
		rows++;

	}

	//добавление пустой строки вниз двумерного массива
	template <typename T> void pushRowDown(T**& arr, int& rows, int cols) {

		T** newArray = new T * [rows + 1];
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = arr[i];
		}
		delete[]arr;
		arr = newArray;
		arr[rows] = new T[cols] {};
		rows++;
	}

	//добавление пустой колонки слева двумерного массива
	template <typename T> void pushColumnLeft(T**& arr, int rows, int& cols) {

		T** newArray = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = new T[cols + 1]{};
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				newArray[i][j + 1] = arr[i][j];
			}
		}
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}		
		arr = newArray;
		cols++;

	}

	//добавление пустой колонки справа двумерного массива
	template <typename T> void pushColumnRight(T**& arr, int rows, int& cols) {

		T** newArray = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = new T[cols + 1]{};
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

	//добавление пустой колонки в двумерный массив по индексу
	template <typename T> void insertCol(T**& arr, int rows, int& cols, int index) {

		int shiftCol;
		T** newArray = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = new T[cols + 1]{};
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

	//добавление пустой строки в двумерный массив по индексу
	template <typename T> void insertRow(T**& arr, int& rows, int cols, int index) {

		int shift = 0;
		T** newArray = new T * [rows + 1];
		for (int i = 0; i < (rows == index ? rows + 1 : rows); i++)
		{
			if (i == index)
			{ 
				shift = 1;
				newArray[i] = new T[cols]{};
			}
			newArray[i + shift] = arr[i];
		}
		delete[]arr;
		arr = newArray;
		rows++;
	}

	//удаление строки из двумерного массива по индексу
	template <typename T> void eraseRow(T**& arr, int& rows, int cols, int index) {

		int shift = 0;
		T** newArray = new T * [rows - 1];
		for (int i = 0; i < rows - 1; i++)
		{
			if (i == index) shift = 1;
			newArray[i] = arr[i + shift];
		}
		delete[]arr[index];
		delete[]arr;
		arr = newArray;
		rows--;

	}

	//удаление колонки из двумерного массива по индексу
	template <typename T> void eraseCol(T**& arr, int rows, int& cols, int index) {

		int shiftCol;
		T** newArray = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = new T[cols - 1]{};
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

	//удаление верхеней строки двумерного массива
	template <typename T> void popRowUp(T**& arr, int& rows, int cols) {

		T** newArray = new T* [rows - 1];
		for (int i = 0; i < rows - 1; i++)
		{
			newArray[i] = arr[i + 1];
		}
		delete[]arr[0];
		delete[]arr;		
		arr = newArray;
		rows--;
	}

	//удаление нижней строки двумерного массива
	template <typename T> void popRowDown(T**& arr, int& rows, int cols) {

		T** newArray = new T * [rows - 1];
		for (int i = 0; i < rows - 1; i++)
		{
			newArray[i] = arr[i];
		}
		/*delete[] arr[rows];???*/
		delete[]arr;
		arr = newArray;
		rows--;
	}

	//удаление левой колонки двумерного массива
	template <typename T> void popColumnLeft(T**& arr, int rows, int& cols) {

		T** newArray = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = new T[cols - 1]{};
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

	//удаление правой колонки двумерного массива
	template <typename T> void popColumnRight(T**& arr, int rows, int& cols) {

		T** newArray = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = new T[cols - 1]{};
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
};

int main() {
	srand(time(NULL));

	OperationsWithArrays myOperations; //создание экземпляра класса
	int size = 10; // размер одномерного массива
	int number = 584;// вставляемое число
	int index = 3;// номер индекса под которым всталяется число	

	//объявление и инициализация одномерного массива целыми случайными числами
	int* arr = myOperations.getNewFillIntegerArray(size);
	myOperations.printArray(arr, size);// вывод на консоль одномерного массива

	//добавление элемента в начало одномерного массива
	myOperations.pushFront(arr, size, number);
	myOperations.printArray(arr, size);

	//добавление элемента в конец одномерного массива
	myOperations.pushBack(arr, size, number);
	myOperations.printArray(arr, size);

	//добавление элемента в одномерный массив по индексу
	myOperations.insert(arr, size, number, index);
	myOperations.printArray(arr, size);

	//удаление элемента из одномерного массива по индексу
	myOperations.erase(arr, size, index);
	myOperations.printArray(arr, size);

	//удаление последнеко элемента одномерного массива
	myOperations.popBack(arr, size);
	myOperations.printArray(arr, size);

	//удаление первого элемента одномерного массива
	myOperations.popFront(arr, size);
	myOperations.printArray(arr, size);
	cout << endl << endl;

	//////////////////////////////////////////////////////////////////////////////////////
	int rows = 4;// количество строк двумерного массива
	int cols = 4;// количество колонок двумерного массива

	// объявление нового двумерного массива и инициализация его целыми случайными числами
	int** newArr = myOperations.getNewFillTwoDimensionalIntegerArray(rows, cols);

	// добавление пустой строки вверху массива
	myOperations.insertRow(newArr, rows, cols, 0);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;
	//добаление пустой строки внизу массива
	myOperations.insertRow(newArr, rows, cols, rows);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;
	//добаление пустой колонки слева
	myOperations.insertCol(newArr, rows, cols, 0);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;
	//добаление пустой колонки справа
	myOperations.insertCol(newArr, rows, cols, cols);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;
	//добаление пустой колонки по индексу
	myOperations.insertCol(newArr, rows, cols, 3);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;
	//добаление пустой строки по индексу
	myOperations.insertRow(newArr, rows, cols, 3);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;

	//удаление строки по индексу
	myOperations.eraseRow(newArr, rows, cols, 3);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;
	//удаление колонки по индексу
	myOperations.eraseCol(newArr, rows, cols, 3);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;
	// удаление строки вверху массива
	myOperations.eraseRow(newArr, rows, cols, 0);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;
	// удаление строки внизу массива
	myOperations.eraseRow(newArr, rows, cols, rows - 1);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;
	// удаление левой колонки массива
	myOperations.eraseCol(newArr, rows, cols, 0);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);
	cout << endl;
	// удаление правой колонки массива
	myOperations.eraseCol(newArr, rows, cols, cols - 1);
	myOperations.printTwoDimensionalArray(newArr, rows, cols);

	return 0;
}