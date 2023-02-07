#define TASK_
using static System.Console;

#if TASK_1
//Объявить одномерный(5 элементов) массив с именем A и двумерный массив (3 строки, 4 столбца) дроб -
//ных чисел с именем B. Заполнить одномерный массив А числами, введенными с клавиатуры пользователем,
//а двумерный массив В случайными числами с помощью циклов. Вывести на экран значения массивов: массива А
//в одну строку, массива В — в виде матрицы. Найти в данных массивах общий максимальный элемент, минимальный
//элемент, общую сумму всех элементов, общее произведение всех элементов, сумму четных элементов массива А,
//сумму нечетных столбцов массива В.

using System.Security.Cryptography;

int [] A = new int[5];
Console.WriteLine("Введите пять значений типа int для массива");
for (int i = 0; i < A.Length; i++) { 
    A[i] = Convert.ToInt32(Console.ReadLine());
}

Console.WriteLine("Значения одномерного массива");
foreach (int item in A) Console.Write(item + " ");
Console.WriteLine();

Console.Write("Значения двумерного массива\n");
double[,] B = new double[3, 4];
Random random = new Random();
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 4; j++)
    {
        B[i, j] = random.NextDouble();
        Console.Write(Math.Round(B[i, j], 3) + "  ");
    }
    Console.WriteLine();
}

double max = A[0];
foreach (int item in A) {
    if (max < item) max = item;
}
Console.WriteLine($"Максимальный элемент одномерного массива равен {max}");

max = B[0,0];
for (int i = 0; i < B.GetLength(0); i++) {
    for (int j = 0; j < B.GetLength(1); j++) {
        if (max < B[i,j]) max = B[i, j];
    }    
}
Console.WriteLine($"Максимальный элемент двумерного массива равен {Math.Round(max, 3)}");


double min = A[0];
foreach (int item in A) {
    if (min > item) min = item;
}
Console.WriteLine($"Минимальный элемент одномерного массива равен {min}");

min = B[0,0];
for (int i = 0; i < B.GetLength(0); i++) {
    for (int j = 0; j < B.GetLength(1); j++) {
        if (min > B[i, j]) min = B[i, j];
    }
}
Console.WriteLine($"Минимальный элемент двумерного массива равен {Math.Round(min, 3)}");


double sum = 0;
foreach (int item in A) {
    sum += item;
}
Console.WriteLine($"Общая сумма элементов одномерного массива равна {sum}");

sum = 0;
for (int i = 0; i < B.GetLength(0); i++) { 
    for (int j = 0; j < B.GetLength(1); j++) { 
        sum+= B[i, j];
    } 
}
Console.WriteLine($"Общая сумма элементов двумерного массива равна {Math.Round(sum, 3)}");


double mult = 1;
foreach (int item in A) {
    mult *= item;
}
Console.WriteLine($"Общее произведение элементов одномерного массива равна {mult}");

mult = 1.0;
for (int i = 0; i < B.GetLength(0); i++) {
    for (int j = 0; j < B.GetLength(1); j++) {
        mult *= B[i, j];
    }
}
Console.WriteLine($"Общее произведение элементов двумерного массива равна {Math.Round(mult, 9)}");


int even_sum = 0;
foreach (int item in A) {
    if(item%2 == 0) even_sum += item;
}
Console.WriteLine($"Сумма четных элементов одномерного массива {even_sum}");

double odd_sum = 0.0;
for (int i = 0; i < B.GetLength(0); i++) {
    for (int j = 0; j < B.GetLength(1); j++)
    {
        if(j%2 == 1) odd_sum += B[i, j];
    }
}
Console.WriteLine($"Сумма нечетных столбцов массива  {Math.Round(odd_sum, 3)}");

#endif //TASK_1

#if TASK_2
//Дан двумерный массив размерностью 5×5, заполненный случайными числами из диапазона от –100 до 100.
//Определить сумму элементов массива, расположенных между минимальным и максимальным элементами.

int [,] arr = new int[5,5];
Random Random = new Random();
for (int i = 0; i < arr.GetLength(0); i++) { 
    for (int j = 0; j < arr.GetLength(1); j++)
    {
        arr[i,j] = Random.Next(-100,100);
        Console.Write(arr[i,j] + "\t");
    }
    Console.WriteLine();
}

int min = arr[0, 0];
int min_row = 0, min_col = 0;
int max = arr[0, 0];
int max_row = 0, max_col = 0;

for (int i = 0; i < arr.GetLength(0); i++)
{
    for (int j = 0; j < arr.GetLength(1); j++)
    {
        if (min > arr[i, j]) {
            
            min = arr[i, j];
            min_row = i;
            min_col= j;
        }
        if (max < arr[i, j])
        {
            max = arr[i, j];
            max_row= i;
            max_col= j;
        }
    }
}
Console.WriteLine($"Минимальное значение массива {min}, его координаты {min_row + 1} , {min_col + 1}");
Console.WriteLine($"Максимальное значение массива {max}, его координаты {max_row + 1 } , {max_col + 1}");

if (min_row > max_row) {
    swap(ref min_row, ref max_row);
    swap(ref min_col, ref max_col);
}
else if (min_row == max_row && min_col > max_col)
{
    swap(ref min_row, ref max_row);
    swap(ref min_col, ref max_col);
}

int sum = 0;
for (int i = min_row; i <= max_row; i++)
{
    for (int j = (i == min_row ? min_col : 0); j < (i == max_row ? max_col : arr.GetLength(1)); j++)
    {
        sum+= arr[i, j];
    }
}
Console.WriteLine($"Сумма элементов массива между ({min_row + 1} , {min_col + 1}) и ({max_row + 1} , {max_col + 1}) равна {sum}");


void swap(ref int x, ref int y)
{
    int temp = x; x = y;
    y = temp;
}
#endif //TASK_2

#if TASK_3
//Пользователь вводит строку с клавиатуры. Необходимо зашифровать данную строку используя шифр Цезаря.
Write("Введите строку для шифровки: ");
string? message = ReadLine();
char[] arr_mess = message.ToArray();

Write("Введите ключ для шифрования: ");
int? key = Convert.ToInt32(ReadLine());

for (int i = 0; i < arr_mess.Length; i++)
    arr_mess[i] = Convert.ToChar(Convert.ToInt32(arr_mess[i]) + key);

Write("Зашифрованное сообщение: ");
for (int i = 0; i < arr_mess.Length; i++) Write(arr_mess[i]);


WriteLine();
for (int i = 0; i < arr_mess.Length; i++)
    arr_mess[i] = Convert.ToChar(Convert.ToInt32(arr_mess[i]) - key);

Write("Разшифрованное сообщение: ");
for (int i = 0; i < arr_mess.Length; i++) Write(arr_mess[i]);

#endif //TASK_3

#if TASK_4
//Создайте приложение, которое производит операции над матрицами:
//-Умножение матрицы на число;
//-Сложение матриц;
//-Произведение матриц.

Write("Задайте разер матриц (не меньше 2): ");
int size = Convert.ToInt32(ReadLine());

int [,] matrixA = new int [size,size];
int[,] matrixB = new int[size, size];

Random rnd = new Random();

for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {

        matrixA[i, j] = rnd.Next(0, 9);
        matrixB[i, j] = rnd.Next(0, 9);        
    }   
}

for (int i = 0; i < size; i++) { 
    for (int j = 0; j < size; j++) {
        Write(matrixA[i,j]+ " "); 
    }
    WriteLine();
}
WriteLine();

for (int i = 0; i < size; i++) { 
    for (int j = 0; j < size; j++) {
        Write(matrixB[i,j]+ " ");
    }
    WriteLine();
}
WriteLine();
WriteLine("Умножение матрици на число");
Write("Задайте число на которое необходимо умножить матрицу A: ");
int value = Convert.ToInt32(ReadLine());

for (int i = 0; i < size; i++)
{
    for (int j = 0; j < size; j++)
    {
        Write(matrixA[i, j] * value + " ");
    }
    WriteLine();
}
WriteLine();
WriteLine("Сложение двух матриц");
for (int i = 0; i < size; i++)
{
    for (int j = 0; j < size; j++)
    {
        Write(matrixA[i, j] + matrixB[i, j] + " ");
    }
    WriteLine();
}
WriteLine();

WriteLine("Результат умножения двух матриц");
int[,] matrixС = new int[size, size];

for (int i = 0; i < size; i++)
{
    for (int j = 0; j < size; j++)
    {
        for (int k = 0; k < size; k++)
        {
            matrixС[i, j] += matrixA[i, k] * matrixB[k, j];
        }
    }
}

for (int i = 0; i < size; i++)
{
    for (int j = 0; j < size; j++)
    {
        Write(matrixС[i, j]+ " ");
    }
    WriteLine();
}

#endif //TASK_4

#if TASK_5
//Пользователь с клавиатуры вводит в строку арифметическое выражение. Приложение должно посчитать 
//его результат. Необходимо поддерживать только две операции: + и –

do
{
    Write("Введите арифметическое выражение в формате (a +/- b): ");
    string? arithmetic_expression = ReadLine();
    char[] arr_expression = arithmetic_expression.ToCharArray();

    bool operator_presence = false;
    int first_value_size = 0;
    int secon_value_size = 0;

    for (int i = 0; i < arr_expression.Length; i++)
    {
        if (arr_expression[i] == '+' || arr_expression[i] == '-')
        {
            operator_presence = true;
            continue;
        }
        if (!operator_presence) first_value_size++;
        if (operator_presence) secon_value_size++;
    }

    char[] first_value_arr = new char[first_value_size];
    char[] secon_value_arr = new char[secon_value_size];   
    operator_presence = false;

    for (int i = 0, j = 0; i < arr_expression.Length; i++)
    {
        if (arr_expression[i] == '+' || arr_expression[i] == '-')
        {
            operator_presence = true;            
            continue;
        }
        if (!operator_presence) first_value_arr[i] = arr_expression[i];
        if (operator_presence)
        {
            secon_value_arr[j] = arr_expression[i];
            j++;
        }
    }

    int first_value = Convert.ToInt32(new String(first_value_arr));
    int secon_value = Convert.ToInt32(new String(secon_value_arr));

    if (arithmetic_expression.Contains('+'))
    {
        WriteLine($"{first_value} + {secon_value} = {first_value + secon_value}");
    }
    else
    {
        WriteLine($"{first_value} - {secon_value} = {first_value - secon_value}");
    }
    ReadLine();
    Console.Clear(); 
} while (true);

#endif //TASK_5

#if TASK_6
//Пользователь с клавиатуры вводит некоторый текст. Приложение должно изменять регистр первой буквы 
//каждого предложения на букву в верхнем регистре.

//Write("Введите предложение: ");
//string message = ReadLine();
string message = "таким. образом.   заглавная.  строка повторяется.     трижды. а вторая.  она же заключительная";
char[] message_arr = message.ToCharArray();

message_arr[0] = Char.ToUpper(message_arr[0]);
for (int i = 0; i < message_arr.Length; i++){
    if (message_arr[i] == '.')
    {
        while (message_arr[++i] == ' ');
        message_arr[i] = Char.ToUpper(message[i]);
    }
}
string msg = new string(message_arr);
WriteLine(msg);

#endif //TASK_6

#if TASK_7
//Создайте приложение, проверяющее текст на недопустимые слова. Если недопустимое слово найдено, оно 
//должно быть заменено на набор символов *. По итогам работы приложения необходимо показать статистику 
//действий. 

//Write("Введите текст: ");
//string? text = ReadLine();
string? text = "Я люблю море. Я лечу на море. Я умею плавать в море. Какое чистое море! Хочу на море. Завтра поедем на море. Акулы плавают в море";

//Write("Введите не желательное слово: ");
//string? word = ReadLine();
string? word = "море";

string replacement = new string('*', word.Length);

text = text?.Replace(word, replacement);

WriteLine(text);

#endif //TASK_7

