#define TASK_

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
for (int i = min_row; i < max_row; i++)
{
    for (int j = min_col; j < max_col; j++)
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

#endif //TASK_3

#if TASK_4

#endif //TASK_4

#if TASK_5

#endif //TASK_5

#if TASK_6

#endif //TASK_6

#if TASK_7

#endif //TASK_7

