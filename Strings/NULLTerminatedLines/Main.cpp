#include <iostream>
using namespace std;

int stringLength(const char str[]);	//возвращает длину строки в символах
void to_upper(char str[]);			//переводит строку в верхний регистр
void to_lower(char str[]);			//переводит строку в нижний регистр
void shrink(char str[]);	//Удаляет лишние пробелы из предложения
bool is_palindrome(const char str[]);	//Проверяет, является ли строка палиндромом
bool is_dec_number(const char str[]);	//Проверяет, является ли строка целым десятичным числом
int  to_dec_number(char str[]);			//Если строка является целым десятичным числом, возвращает ее числовое значение
bool is_bin_number(const char str[]);	//Проверяет, является ли строка двоичным числом
int  bin_to_dec(char str[]);			//Если строка является двоичным числом, возвращает ее десятичное значение
bool is_hex_number(const char str[]);	//Проверяет, является ли строка шестнадцатеричным числом
int  hex_to_dec(char str[]);			//Если строка является шестнадцатеричным числом, возвращает ее десятичное значение

int main() {
	setlocale(LC_ALL, "");

	char str[] = "SoMe    mEn   iNteRpreT nIne   meMos";
	cout << str << endl;

	int strLength = stringLength(str);
	cout << "Длина строки равна: " << strLength << endl;
	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;	
	shrink(str);
	cout << str << endl;
	cout << "Строка является полиндромом ?: " << is_palindrome(str) << endl;
	cout << endl;

	char intStr[] = "45266";
	cout << is_dec_number(intStr) << endl;
	int val = to_dec_number(intStr);
	cout << val << endl << endl;

	char binStr[] = "11010011";
	cout << is_bin_number(binStr) << endl;
	int valBin = bin_to_dec(binStr);
	cout << valBin << endl << endl;

	char hexStr[] = "A450B";
	cout << is_hex_number(hexStr) << endl;
	int valHex = hex_to_dec(hexStr);
	cout << valHex << endl << endl;
	
	system("pause");
	
	return 0;
}

int stringLength(const char str[])
{
	int count = 0;

	while (str[count] != 0) count++;

	return count;
	
}
void to_upper(char str[]) {
	for (int count = 0; str[count] != 0; count++)
	{
		if (str[count] >= 97 && str[count] <= 122) {
			str[count] -= 32;
		}		
	}
}
void to_lower(char str[]) {
	for (int count = 0; str[count] != 0; count++)
	{
		if (str[count] >= 65 && str[count] <= 90) {
			str[count] += 32;
		}		
	}
}
void shrink(char str[]) {

	char space = 32;
	//перебор строки цыклом
	for (int count = 0; str[count] != 0; count++)
	{
		//если в строке встречается два пробела подряд
		if (str[count] == space && str[count + 1] == space)
		{
			//смещает все последующие символы на 1 элемент назад
			for (int i = count; str[i] != 0; i++)
			str[i] = str[i + 1];

			count--;
		}
	}
}
bool is_palindrome(const char str[]) {
	char space = 32;// символ пробела
	int strLength = stringLength(str);// длина строки	
	//два счетчика: один с начала строки на увеличение, второй - с конца на убывание; пока не сравняются
	for (int startCount = 0, endCount = strLength - 1; startCount >= endCount; startCount++, endCount--)
	{	
		// счетчик пропускает пробелы с начала строки
		if (str[startCount] == space) { 
			while (str[startCount] == space)
			{
				startCount++;
			}			
		}
		// счетчик пропускает пробелы с конца строки
		if (str[endCount] == space) {
			while (str[endCount] == space )
			{
				endCount--;
			}
		}

		//если символы не совпадают, выход из цыкла со значением false
		if (str[startCount] != str[endCount]) return false;		
	}
	return true;
}
bool is_dec_number(const char str[]) {
	//перебор всей строки циклом
	for (int i = 0; str[i] != 0; i++)
	{
		//если хотя бы один символ строки не соответствует числовоу значению в десятичной системе - выход из цыкла со значнием false
		if (str[i] < 48 || str[i] > 57) return false;		
	}
	// иначе вовод значения true
	return true;
}
int  to_dec_number(char str[]) {
	//проверка, является ли строка целым десятичным числом
	if (is_dec_number(str))
	{
		int arraySize = stringLength(str);// размер массива в зависимости от длины строки
		int* intValueArray = new int[arraySize];//массив для значений
		int value = 0;
		//заполнение в обратном порядке массива десятичными значениями, эквевалентными символьным значениям в таблице ASCII
		for (int i = 0, valueCount = arraySize - 1; i < arraySize;)
		{
			intValueArray [valueCount--] = int(str[i++]) - 48;
		}
		//суммированиее элементов массива, помноженных на 10 в степени, соответствующей позиции элемента в десятичном числе 
		for (int i = 0; i < arraySize; i++)
		{
			value += intValueArray[i] * pow(10, i);
		}

		delete[]intValueArray;
		intValueArray = nullptr;
		return value;
	}
	return -1;
}
bool is_bin_number(const char str[]) {
	//перебор всей строки циклом
	for (int i = 0; str[i] != 0;i++)
	{
		//если хотя бы один символ строки не соответствует числовому значению 1 или 0, выход из цыкла со значнием false
		if(str[i] < 48 || str[i] > 49) return false ;
	}
	// иначе вовод значения true
	return true;
}
int  bin_to_dec(char str[]) {
	//проверка, является ли строка двоичным числом
	if (is_bin_number(str))
	{
		int arraySize = stringLength(str);// размер массива в зависимости от длины строки
		int* intValueArray = new int[arraySize];//массив для значений

		//заполнение в обратном порядке массива двоиными значениями, эквевалентными символьным значениям в таблице ASCII
		for (int i = 0, valueCount = arraySize - 1; i < arraySize;)
		{
			str[i++] == 48? intValueArray[valueCount--] = 0: intValueArray[valueCount--] = 1;
		}

		//суммированиее элементов массива, помноженных на 2 в степени, соответствующей позиции элемента в двоичном числе 
		int value = 0;
		for (int i = 0; i < arraySize; i++)
		{
			value += intValueArray[i] * pow(2, i);
		}

		delete[]intValueArray;
		intValueArray = nullptr;
		return value;
	}
	return -1;
}
bool is_hex_number(const char str[]) {
	//перебор всей строки циклом
	for (int i = 0; str[i] != 0; i++)
	{
		//если хотя бы один символ строки не соответствует числовому значению от 1 до F(f) в 16-ой системе исчисления, выход из цыкла со значнием false
		if ((str[i] < 48 || str[i] > 57) && (str[i] < 65 || str[i] > 70) && (str[i] < 97 || str[i] > 102)) {
			return false;
		}
	}
	// иначе вовод значения true
	return true;
}
int  hex_to_dec(char str[]) {
	if (is_hex_number(str))
	{
		int arraySize = stringLength(str);// размер массива в зависимости от длины строки
		int* intValueArray = new int[arraySize];//массив для значений
		
		//перебор строки циклом
		for (int i = 0, valueCount = arraySize - 1; i < arraySize;)
		{
			//если символ строки соответствует числовому значению от 1 до 9
			if (str[i] >= 48 && str[i] <= 57) {
				//присваивает в массив эквивалент символа в числе
				intValueArray[valueCount--] = int(str[i++]) - 48;
			}
			else {
				//если символ строки соответствует числовому значению от A(a) до F(f) в 16-ой системе
				intValueArray[valueCount--] = (str[i] >= 65 && str[i] <= 70) ? int(str[i++] - 54) : int(str[i++] - 86);
			}
		}

		int value = 0;
		for (int i = 0; i < arraySize; i++)
		{
			value += intValueArray[i] * pow(16, i);
		}

		delete[]intValueArray;
		intValueArray = nullptr;
		return value;
	}
	return -1;
}
