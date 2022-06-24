#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int** NewFillIntegerMatrix(int size);
double** NewFillDoubleMatrix(int size);
float** NewFillFloatMatrix(int size);
template<typename T> void DeleteMatrix(T** matrix, int size);//удаление динамического массива
template<typename T> void PrintMatrix(T** matrix, int size);//вывод матрицы на консоль
////////////////////////////////////////////////////////////

template<typename T> T** SummationOfMatrix(T** matrixOne, T** matrixTwo, int size);//сложение матриц
template<typename T> T** SubtractionOfMatrix(T** matrixOne, T** matrixTwo, int size);//вычетание матриц
template<typename T> T** MultiplicationOfMatrix(T** matrixOne, T** matrixTwo, int size);//умножение матриц
template<typename T> T GetDetermenat(T** matrix, int size);//вычисление детерменанта
template<typename T> T** GetReversedMatrix(T** matrix, int size); //обращение матрицы

/////////////////////////////////////////////////////////////////////////////////////////////////////
//вспомогательный функции

//функция для получения массива без определенной строки и столбца
template<typename T> T** GetMatrixWithoutRowAndColumn(T** matrix, T** newMatrix, int size, int row, int col);
template<typename T> T** GetTransposedMatrix(T** matrix, int size);//транспонироване матрицы
template<typename T> T GetMinor(T** matrix, int size, int numberOfRow, int numderOfCol);//вычисление минора для элемента матрицы 


int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int size = 4;

	int** arrayOne = NewFillIntegerMatrix(size);
	PrintMatrix(arrayOne, size);
	cout << endl << endl;

	int** arrayTwo = NewFillIntegerMatrix(size);
	PrintMatrix(arrayTwo, size);
	cout << endl << endl;

	int** arrayOfResult = SummationOfMatrix(arrayOne, arrayTwo, size);
	PrintMatrix(arrayOfResult, size);
	cout << endl << endl;

	arrayOfResult = SubtractionOfMatrix(arrayOne, arrayTwo, size);
	PrintMatrix(arrayOfResult, size);
	cout << endl << endl;

	arrayOfResult = MultiplicationOfMatrix(arrayOne, arrayTwo, size);
	PrintMatrix(arrayOfResult, size);
	cout << endl << endl;

	DeleteMatrix(arrayOne, size);
	DeleteMatrix(arrayTwo, size);
	DeleteMatrix(arrayOfResult, size);


	cout << "Введите размер квадратной матрицы: ";
	cin >> size;

	float** array = NewFillFloatMatrix(size);
	PrintMatrix(array, size);
	cout << endl << endl;


	auto determenant = GetDetermenat(array, size);
	cout << "Детерменант матрицы равен: " << determenant << endl << endl;



	float** reversedMatrix = new float* [size];
	for (int i = 0; i < size; i++)
	{
		reversedMatrix[i] = new float[size];
	}

	reversedMatrix = GetReversedMatrix(array, size);
	PrintMatrix(reversedMatrix, size);

	DeleteMatrix(array, size);
	DeleteMatrix(reversedMatrix, size);

	return 0;
}

int** NewFillIntegerMatrix(int size) {
	if (size < 1)
	{
		cout << "Ошибка! Параметр size не может быть меньше 1" << endl;
	}
	else
	{
		int** array = new int* [size];
		for (register int i = 0; i < size; i++)
		{
			array[i] = new int[size];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				array[i][j] = 1 + rand() % 9;
			}
		}
		return array;
	}
}
double** NewFillDoubleMatrix(int size) {

	if (size < 1)
	{
		cout << "Ошибка! Параметр size не может быть меньше 1" << endl;
	}
	else
	{
		double** array = new double* [size];

		for (register int i = 0; i < size; i++)
		{
			array[i] = new double[size];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				array[i][j] = (double)(1 + rand() % 10000) / 1000;
			}
		}
		return array;
	}
}
float** NewFillFloatMatrix(int size) {

	if (size < 1)
	{
		cout << "Ошибка! Параметр size не может быть меньше 1" << endl;
	}
	else
	{
		float** array = new float* [size];

		for (register int i = 0; i < size; i++)
		{
			array[i] = new float[size];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				array[i][j] = (float)(1 + rand() % 10);
			}
		}
		return array;
	}
}
template<typename T> void DeleteMatrix(T** matrix, int size) {
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}
template<typename T> void PrintMatrix(T** matrix, int size) {
	for (register int i = 0; i < size; i++)
	{
		for (register int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << "   ";
		}
		cout << endl << endl;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////

template<typename T> T** SummationOfMatrix(T** matrixOne, T** matrixTwo, int size) {

	T** arrayOfResults = new T * [size];

	for (register int i = 0; i < size; i++)
	{
		arrayOfResults[i] = new T[size];
	}

	for (register int i = 0; i < size; i++)
	{
		for (register int j = 0; j < size; j++)
		{
			arrayOfResults[i][j] = matrixOne[i][j] + matrixTwo[i][j];
		}
	}
	return arrayOfResults;
}
template<typename T> T** SubtractionOfMatrix(T** matrixOne, T** matrixTwo, int size) {
	T** arrayOfResults = new T * [size];

	for (register int i = 0; i < size; i++)
	{
		arrayOfResults[i] = new T[size];
	}

	for (register int i = 0; i < size; i++)
	{
		for (register int j = 0; j < size; j++)
		{
			arrayOfResults[i][j] = matrixOne[i][j] - matrixTwo[i][j];
		}
	}
	return arrayOfResults;
}
template<typename T> T** MultiplicationOfMatrix(T** matrixOne, T** matrixTwo, int size) {
	T** arrayOfResults = new T * [size];

	for (register int i = 0; i < size; i++)
	{
		arrayOfResults[i] = new T[size];
	}

	for (register int i = 0; i < size; i++)
	{
		for (register int j = 0; j < size; j++)
		{
			arrayOfResults[i][j] = matrixOne[i][j] * matrixTwo[i][j];
		}
	}
	return arrayOfResults;
}
template<typename T> T GetDetermenat(T** matrix, int size) {

	T determenant = 0, ratio = 1;

	T** newArr = new T * [size];
	for (register int i = 0; i < size; i++)
	{
		newArr[i] = new T[size];
	}

	if (size == 1) {
		//расчет детерменанта матрицы из одного элемента

		return matrix[0][0];
	}
	if (size == 2) {

		//расчет детерменанта матрицы размеров 2Х2
		return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
	}
	if (size > 2) {
		for (register int i = 0; i < size; i++)
		{
			// при размере матрицы больше 2, суммируем произведения каждого элемента исходной матрицы в 0 - строке и i-ом столбце
			// на детерминант матрицы (получаем путем рекурсии метода GetDetermenat с параметрами  размера уменьшеного на 1), полученной
			// без 0-ой строки и i-го столбца (получаем путем рекурсии метода GetMatrixWithoutRowAndColumn) и коэффициента ratio, меняющего знак
			// в зависимости от четности или нечетности колонки

			GetMatrixWithoutRowAndColumn(matrix, newArr, size, 0, i);
			determenant += ratio * matrix[0][i] * GetDetermenat(newArr, size - 1);
			ratio = -ratio;
		}
	}
	//удаляем динамический массив newMatrix

	return determenant;
}
template<typename T> T** GetReversedMatrix(T** matrix, int size) {
	// объявляем двумерный массив под транспнированную матрицу
	T** TransposedMatrix = new T * [size];
	for (register int i = 0; i < size; i++)
	{
		TransposedMatrix[i] = new T[size];
	}
	// объявляем двумерный массив под обратную матрицу
	T** ReversedMatrix = new T * [size];
	for (register int i = 0; i < size; i++)
	{
		ReversedMatrix[i] = new T[size];
	}
	// инициализируем тринспониованную матрицу и получаем детерменант исходной матрицы
	TransposedMatrix = GetTransposedMatrix(matrix, size);
	T determenantOfBasicMatrix = GetDetermenat(matrix, size);

	//каждый элемент обратной матрицы инициализируем результатом деления
	//минора для элемента транспонированной матрицы на детерменант исходной матрицы

	for (register int i = 0; i < size; i++)
	{
		for (register int j = 0; j < size; j++)
		{
			ReversedMatrix[i][j] = GetMinor(TransposedMatrix, size, i, j) / determenantOfBasicMatrix;
		}
	}

	return ReversedMatrix;
}

////////////////////////////////////////////////////////////////////////
template<typename T> T** GetMatrixWithoutRowAndColumn(T** matrix, T** newMatrix, int size, int row, int col) {

	int shiftRow = 0, shiftCol;
	for (register int i = 0; i < size - 1; i++)
	{
		if (i == row) shiftRow = 1;

		shiftCol = 0;
		for (register int j = 0; j < size - 1; j++)
		{
			if (j == col) shiftCol = 1;
			newMatrix[i][j] = matrix[i + shiftRow][j + shiftCol];
			//если счетчик строки или колонки совпадет со значениями, которые ввели мы,
			//то он их пропустит, увеличевшись на 1
		}
	}
	return newMatrix;
}
template<typename T> T** GetTransposedMatrix(T** matrix, int size) {

	T** newArr = new T * [size];
	for (register int i = 0; i < size; i++)
	{
		newArr[i] = new T[size];
	}
	// объявляем новый динамический массив в который, поменяв строки и столбцы местами,
	// вставляем старый
	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			newArr[i][j] = matrix[j][i];
		}
	}


	return newArr;

}
template<typename T> T GetMinor(T** matrix, int size, int numberOfRow, int numderOfCol) {
	T minor = 0;

	T** newArr = new T * [size];
	for (register int i = 0; i < size; i++)
	{
		newArr[i] = new T[size];
	}

	if (size == 1) { // если размер матрицы равен 1, то минором является сам элемент
		return matrix[0][0];
	}
	if (size == 2) { // если размер 2х2, то минором элемента исходной матрицы будет элемент, оставшийся после удаления из исходной
					 //  матрицы строки и столбца в котором расположен исходный элемент

		GetMatrixWithoutRowAndColumn(matrix, newArr, size, numberOfRow, numderOfCol);
		if (((numberOfRow + 1) + (numderOfCol + 1)) % 2 == 0)
		{
			minor = GetMinor(newArr, size - 1, numberOfRow, numderOfCol);
		}
		else
		{
			minor = -(GetMinor(newArr, size - 1, numberOfRow, numderOfCol));
		}

		return minor;
	}
	if (size > 2) { // если размер исходной матрицы больше трех, то минором элемента для этой матрицы будет 
					// детерменант матрицы полученной при удалении из исходной, строки и столбца в которых находился исходный элемент
		GetMatrixWithoutRowAndColumn(matrix, newArr, size, numberOfRow, numderOfCol);
		if (((numberOfRow + 1) + (numderOfCol + 1)) % 2 == 0)
		{
			minor = GetDetermenat(newArr, size - 1);
		}
		else
		{
			minor = -(GetDetermenat(newArr, size - 1));
		}

		return minor;
	}

	for (int i = 0; i < size; i++)
	{
		delete[] newArr[i];
	}
	delete[] newArr;
}
////////////////////////////////////////////////////////////////////////