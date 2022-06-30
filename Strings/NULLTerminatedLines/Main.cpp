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

int stringLength(const char str[])
{
	int characterCount = 0;

	while (str[characterCount] != 0) characterCount++;

	return characterCount;
	
}
void to_upper(char str[]) {

	char char_a = 97, char_z = 122;
	int shift_to_uppercase = 32;

	for (int characterCount = 0; str[characterCount] != 0; characterCount++)
	{//если символ попадает в диапазон от а до z то он меняется на прописной символ
		if (str[characterCount] >= char_a && str[characterCount] <= char_z) {
			str[characterCount] -= shift_to_uppercase;
		}		
	}
}
void to_lower(char str[]) {

	char char_A = 65, char_Z = 90;
	int shift_to_lowercase = 32;

	for (int characterCount = 0; str[characterCount] != 0; characterCount++)
	{	//если символ попадает в диапазон от A до Z то он меняется на строчный символ
		if (str[characterCount] >= char_A && str[characterCount] <= char_Z) {
			str[characterCount] += shift_to_lowercase;
		}		
	}
}
void shrink(char str[]) {

	char char_space = 32;
	//перебор строки цыклом
	for (int characterCount = 0; str[characterCount] != 0; characterCount++)
	{
		//если в строке встречается два пробела подряд
		if (str[characterCount] == char_space && str[characterCount + 1] == char_space)
		{
			//смещает все последующие символы на 1 элемент назад
			for (int i = characterCount; str[i] != 0; i++)
			str[i] = str[i + 1];
			
			characterCount--;
		}
	}
}
bool is_palindrome(const char str[]) {
	char char_space = 32;// символ пробела
	int strLength = stringLength(str);// длина строки	
	//два счетчика: один с начала строки на увеличение, второй - с конца на убывание; пока не сравняются
	for (int strStartCounter = 0, strEndCounter = strLength - 1; strStartCounter >= strEndCounter; strStartCounter++, strEndCounter--) {

		// счетчик пропускает пробелы с начала строки
		if (str[strStartCounter] == char_space) { 
			while (str[strStartCounter] == char_space)
			{
				strStartCounter++;
			}			
		}
		// счетчик пропускает пробелы с конца строки
		if (str[strEndCounter] == char_space) {
			while (str[strEndCounter] == char_space )
			{
				strEndCounter--;
			}
		}

		//если символы не совпадают, выход из цыкла со значением false
		if (str[strStartCounter] != str[strEndCounter]) return false;		
	}
	return true;
}
bool is_dec_number(const char str[]) {
	char char_Zero = 48, char_Nine = 57;

	//перебор всей строки циклом
	for (int characterCount = 0; str[characterCount] != 0; characterCount++)
	{
		//если хотя бы один символ строки не соответствует числовоу значению в десятичной системе - выход из цыкла со значнием false
		if (str[characterCount] < char_Zero || str[characterCount] > char_Nine)
			return false;
	}
	// иначе вовод значения true
	return true;
}
int  to_dec_number(char str[]) {
	//проверка, является ли строка целым десятичным числом
	if (is_dec_number(str))
	{
		int arraySize = stringLength(str);// размер массива в зависимости от длины строки
		int* arrayOfIntegerValues = new int[arraySize];//массив для значений
		int value = 0;
		//заполнение в обратном порядке массива десятичными значениями, эквевалентными символьным значениям в таблице ASCII
		for (int characterCount = 0, valueCount = arraySize - 1; str[characterCount] != 0;)
		{
			arrayOfIntegerValues [valueCount--] = int(str[characterCount++]) - 48;
		}
		//суммированиее элементов массива, помноженных на 10 в степени, соответствующей позиции элемента в десятичном числе 
		for (int i = 0; i < arraySize; i++)
		{
			value += arrayOfIntegerValues[i] * pow(10, i);
		}

		delete[]arrayOfIntegerValues;
		arrayOfIntegerValues = nullptr;
		return value;
	}
	return -1;
}
bool is_bin_number(const char str[]) {
	char char_Zero = 48, char_One = 49;
	//перебор всей строки циклом
	for (int characterCount = 0; str[characterCount] != 0; characterCount++)
	{
		//если хотя бы один символ строки не соответствует числовому значению 1 или 0, выход из цыкла со значнием false
		if(str[characterCount] < char_Zero || str[characterCount] > char_One) return false ;
	}
	// иначе вовод значения true
	return true;
}
int  bin_to_dec(char str[]) {
	char char_Zero = 48;
	//проверка, является ли строка двоичным числом
	if (is_bin_number(str))
	{
		int arraySize = stringLength(str);// размер массива в зависимости от длины строки
		int* arrayOfIntegerValues = new int[arraySize];//массив для значений

		//заполнение в обратном порядке массива двоиными значениями, эквевалентными символьным значениям в таблице ASCII
		for (int characterCount = 0, valueCount = arraySize - 1; str[characterCount] != 0;)
		{
			str[characterCount++] == char_Zero ? arrayOfIntegerValues[valueCount--] = 0: arrayOfIntegerValues[valueCount--] = 1;
		}

		//суммированиее элементов массива, помноженных на 2 в степени, соответствующей позиции элемента в двоичном числе 
		int value = 0;
		for (int i = 0; i < arraySize; i++)
		{
			value += arrayOfIntegerValues[i] * pow(2, i);
		}

		delete[]arrayOfIntegerValues;
		arrayOfIntegerValues = nullptr;
		return value;
	}
	return -1;
}
bool is_hex_number(const char str[]) {
	char char_Zero = 48, char_Nine = 57;
	char char_A = 65, char_F = 70;
	char char_a = 97, char_f = 102;

	//перебор всей строки циклом
	for (int characterCount = 0; str[characterCount] != 0; characterCount++)
	{
		//если хотя бы один символ строки не соответствует числовому значению от 0 
		//до F(f) в 16-ой системе исчисления, выход из цыкла со значнием false
		if ((str[characterCount] < char_Zero || str[characterCount] > char_Nine)
			&& (str[characterCount] < char_A || str[characterCount] > char_F)
			&& (str[characterCount] < char_a || str[characterCount] > char_f)) {
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
		int* arrayOfIntegerValues = new int[arraySize];//массив для значений
		char char_Zero = 48, char_Nine = 57;
		char char_A = 65, char_F = 70;
		
		//перебор строки циклом
		for (int characterСount = 0, valueCount = arraySize - 1; str[characterСount] != 0;)
		{
			
			if (str[characterСount] >= char_Zero && str[characterСount] <= char_Nine) {//если символ строки соответствует числовому значению от 0 до 9
				//присваивает в массив эквивалент символа в числе
				arrayOfIntegerValues[valueCount--] = int(str[characterСount++]) - 48;
			}
			else {//если символ строки соответствует числовому значению от A(a) до F(f) в 16-ой системе
				
				arrayOfIntegerValues[valueCount--] = (str[characterСount] >= char_A && str[characterСount] <= char_F) ? int(str[characterСount++] - 55) : int(str[characterСount++] - 87);
			}
		}

		int valueInHexNotation = 0;
		for (int i = 0; i < arraySize; i++)
		{
			valueInHexNotation += arrayOfIntegerValues[i] * pow(16, i);
		}

		delete[]arrayOfIntegerValues;
		arrayOfIntegerValues = nullptr;
		return valueInHexNotation;
	}
	return -1;
}
