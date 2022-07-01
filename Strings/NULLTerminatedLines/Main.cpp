#include <iostream>
using namespace std;

int stringLength(const char []);	//возвращает длину строки в символах
void to_upper(char []);			//переводит строку в верхний регистр
void to_lower(char []);			//переводит строку в нижний регистр
void shrink(char []);	//Удаляет лишние пробелы из предложения
bool is_palindrome(const char []);	//Проверяет, является ли строка палиндромом
bool is_dec_number(const char []);	//Проверяет, является ли строка целым десятичным числом
int  to_dec_number(char []);			//Если строка является целым десятичным числом, возвращает ее числовое значение
bool is_bin_number(const char []);	//Проверяет, является ли строка двоичным числом
int  bin_to_dec(char []);			//Если строка является двоичным числом, возвращает ее десятичное значение
bool is_hex_number(const char []);	//Проверяет, является ли строка шестнадцатеричным числом
int  hex_to_dec(char []);			//Если строка является шестнадцатеричным числом, возвращает ее десятичное значение

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
	cout << "Строка является десятичным числом ?: " << is_dec_number(intStr) << endl;
	int valDec = to_dec_number(intStr);
	cout << valDec << endl << endl;

	char binStr[] = "11010011";
	cout << "Строка является двоичным числом ?: " << is_bin_number(binStr) << endl;
	int valBin = bin_to_dec(binStr);
	cout << valBin << endl << endl;

	char hexStr[] = "A450B";
	cout << "Строка является гексоганальным числом?: " << is_hex_number(hexStr) << endl;
	int valHex = hex_to_dec(hexStr);
	cout << valHex << endl << endl;
	
	system("pause");
	
	return 0;
}

int stringLength(const char arrayOfCharacters[])
{
	int charCount = 0;

	while (arrayOfCharacters[charCount] != 0) charCount++;

	return charCount;
	
}
void to_upper(char arrayOfCharacters[]) {

	char char_a = 97, char_z = 122;
	int shift_to_uppercase = 32;

	for (int charCount = 0; arrayOfCharacters[charCount] != 0; charCount++)
	{//если символ попадает в диапазон от а до z то он меняется на прописной символ
		if (arrayOfCharacters[charCount] >= char_a && arrayOfCharacters[charCount] <= char_z) {
			arrayOfCharacters[charCount] -= shift_to_uppercase;
		}		
	}
}
void to_lower(char arrayOfCharacters[]) {

	char char_A = 65, char_Z = 90;
	int shift_to_lowercase = 32;

	for (int charCount = 0; arrayOfCharacters[charCount] != 0; charCount++)
	{	//если символ попадает в диапазон от A до Z то он меняется на строчный символ
		if (arrayOfCharacters[charCount] >= char_A && arrayOfCharacters[charCount] <= char_Z) {
			arrayOfCharacters[charCount] += shift_to_lowercase;
		}		
	}
}
void shrink(char arrayOfCharacters[]) {

	char char_space = 32;
	//перебор строки цыклом
	for (int charCount = 0; arrayOfCharacters[charCount] != 0; charCount++)
	{
		//если в строке встречается два пробела подряд
		if (arrayOfCharacters[charCount] == char_space && arrayOfCharacters[charCount + 1] == char_space)
		{
			//смещает все последующие символы на 1 элемент назад
			for (int i = charCount; arrayOfCharacters[i] != 0; i++)
			arrayOfCharacters[i] = arrayOfCharacters[i + 1];
			
			charCount--;
		}
	}
}
bool is_palindrome(const char arrayOfCharacters[]) {
	char char_space = 32;// символ пробела
	int strLength = stringLength(arrayOfCharacters);// длина строки	
	//два счетчика: один с начала строки на увеличение, второй - с конца на убывание; пока не сравняются
	for (int strStartCounter = 0, strEndCounter = strLength - 1; strStartCounter >= strEndCounter; strStartCounter++, strEndCounter--) {

		// счетчик пропускает пробелы с начала строки
		if (arrayOfCharacters[strStartCounter] == char_space) { 
			while (arrayOfCharacters[strStartCounter] == char_space)
			{
				strStartCounter++;
			}			
		}
		// счетчик пропускает пробелы с конца строки
		if (arrayOfCharacters[strEndCounter] == char_space) {
			while (arrayOfCharacters[strEndCounter] == char_space )
			{
				strEndCounter--;
			}
		}

		//если символы не совпадают, выход из цыкла со значением false
		if (arrayOfCharacters[strStartCounter] != arrayOfCharacters[strEndCounter]) return false;		
	}
	return true;
}
bool is_dec_number(const char arrayOfCharacters[]) {
	char char_Zero = 48, char_Nine = 57;

	//перебор всей строки циклом
	for (int charCount = 0; arrayOfCharacters[charCount] != 0; charCount++)
	{
		//если хотя бы один символ строки не соответствует числовоу значению в десятичной системе - выход из цыкла со значнием false
		if (arrayOfCharacters[charCount] < char_Zero || arrayOfCharacters[charCount] > char_Nine)
			return false;
	}
	// иначе вовод значения true
	return true;
}
int  to_dec_number(char arrayOfCharacters[]) {
	//проверка, является ли строка целым десятичным числом
	if (is_dec_number(arrayOfCharacters))
	{
		int arraySize = stringLength(arrayOfCharacters);// размер массива в зависимости от длины строки
		int* arrayOfIntegerValues = new int[arraySize];//массив для значений
		//заполнение в обратном порядке массива десятичными значениями, эквевалентными символьным значениям в таблице ASCII
		for (int charCount = 0, valueCount = arraySize - 1; arrayOfCharacters[charCount] != 0;)
		{
			arrayOfIntegerValues [valueCount--] = int(arrayOfCharacters[charCount++]) - 48;
		}

		//суммированиее элементов массива, помноженных на 10 в степени, соответствующей позиции элемента в десятичном числе 
		int valueInDecNotation = 0;
		for (int dropPosition = 0; dropPosition < arraySize; dropPosition++)
		{
			valueInDecNotation += arrayOfIntegerValues[dropPosition] * pow(10, dropPosition);
		}

		delete[]arrayOfIntegerValues;
		arrayOfIntegerValues = nullptr;
		return valueInDecNotation;
	}
	return -1;
}
bool is_bin_number(const char arrayOfCharacters[]) {
	char char_Zero = 48, char_One = 49;
	//перебор всей строки циклом
	for (int charCount = 0; arrayOfCharacters[charCount] != 0; charCount++)
	{
		//если хотя бы один символ строки не соответствует числовому значению 1 или 0, выход из цыкла со значнием false
		if(arrayOfCharacters[charCount] < char_Zero || arrayOfCharacters[charCount] > char_One) return false ;
	}
	// иначе вовод значения true
	return true;
}
int  bin_to_dec(char arrayOfCharacters[]) {
	char char_Zero = 48;
	//проверка, является ли строка двоичным числом
	if (is_bin_number(arrayOfCharacters))
	{
		int arraySize = stringLength(arrayOfCharacters);// размер массива в зависимости от длины строки
		int* arrayOfIntegerValues = new int[arraySize];//массив для значений

		//заполнение в обратном порядке массива двоиными значениями, эквевалентными символьным значениям в таблице ASCII
		for (int charCount = 0, valueCount = arraySize - 1; arrayOfCharacters[charCount] != 0;)
		{
			arrayOfCharacters[charCount++] == char_Zero ? arrayOfIntegerValues[valueCount--] = 0: arrayOfIntegerValues[valueCount--] = 1;
		}

		//суммированиее элементов массива, помноженных на 2 в степени, соответствующей позиции элемента в двоичном числе 
		int valueInBinNotation = 0;
		for (int dropPosition = 0; dropPosition < arraySize; dropPosition++)
		{
			valueInBinNotation += arrayOfIntegerValues[dropPosition] * pow(2, dropPosition);
		}

		delete[]arrayOfIntegerValues;
		arrayOfIntegerValues = nullptr;
		return valueInBinNotation;
	}
	return -1;
}
bool is_hex_number(const char arrayOfCharacters[]) {
	char char_Zero = 48, char_Nine = 57;
	char char_A = 65, char_F = 70;
	char char_a = 97, char_f = 102;

	//перебор всей строки циклом
	for (int charCount = 0; arrayOfCharacters[charCount] != 0; charCount++)
	{
		//если хотя бы один символ строки не соответствует числовому значению от 0 
		//до F(f) в 16-ой системе исчисления - выход из цыкла со значнием false
		if ((arrayOfCharacters[charCount] < char_Zero || arrayOfCharacters[charCount] > char_Nine)
			&& (arrayOfCharacters[charCount] < char_A || arrayOfCharacters[charCount] > char_F)
			&& (arrayOfCharacters[charCount] < char_a || arrayOfCharacters[charCount] > char_f)) {
			return false;
		}
	}
	// иначе вовод значения true
	return true;
}
int  hex_to_dec(char arrayOfCharacters[]) {
	if (is_hex_number(arrayOfCharacters))
	{
		int arraySize = stringLength(arrayOfCharacters);// размер массива в зависимости от длины строки
		int* arrayOfIntegerValues = new int[arraySize];//массив для значений
		char char_Zero = 48, char_Nine = 57;
		char char_A = 65, char_F = 70;
		
		//перебор строки циклом
		for (int charCount = 0, valueCount = arraySize - 1; arrayOfCharacters[charCount] != 0;)
		{
			
			if (arrayOfCharacters[charCount] >= char_Zero && arrayOfCharacters[charCount] <= char_Nine) {//если символ строки соответствует числовому значению от 0 до 9
				//присваивает в массив эквивалент символа в числе
				arrayOfIntegerValues[valueCount--] = int(arrayOfCharacters[charCount++]) - 48;
			}
			else {//если символ строки соответствует числовому значению от A(a) до F(f) в 16-ой системе
				
				arrayOfIntegerValues[valueCount--] = (arrayOfCharacters[charCount] >= char_A && arrayOfCharacters[charCount] <= char_F) ? int(arrayOfCharacters[charCount++] - 55) : int(arrayOfCharacters[charCount++] - 87);
			}
		}

		int valueInHexNotation = 0;
		for (int dropPosition = 0; dropPosition < arraySize; dropPosition++)
		{
			valueInHexNotation += arrayOfIntegerValues[dropPosition] * pow(16, dropPosition);
		}

		delete[]arrayOfIntegerValues;
		arrayOfIntegerValues = nullptr;
		return valueInHexNotation;
	}
	return -1;
}
