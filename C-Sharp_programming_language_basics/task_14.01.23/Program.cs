#define TASK_1

//1.Сжать массив, удалив из него все 0 и, заполнить освободившиеся справа элементы значениями –1
#if TASK_1
Random rnd = new Random();
int[] arr = new int[rnd.Next(10,20)];
for (int i = 0; i < arr.Length; i++) {
    arr[i] = rnd.Next(0, 4); 
}

for (int i = arr.Length - 1; i >= 0 ; i--) {
	try {
        swap(ref arr[Array.IndexOf(arr, 0)], ref arr[i]);
        arr[i] = -1;        
    }
	catch (Exception) { continue; }    
}

for (int i = 0; i < arr.Length; i++) {
    Console.Write(arr[i] + " ");
}

void swap(ref int a,ref int b)
{
    int temp = a; a = b;
    b= temp;
}

#endif //TASK_1

//2.Преобразовать массив так, чтобы сначала шли все отрицательные элементы, а потом положительные
//(0 считать положительным)
#if TASK_2

Random rnd = new Random();
int[] arr = new int[rnd.Next(10,20)];
for (int i = 0; i < arr.Length; i++) {
    arr[i] = rnd.Next(-10, 10); 
}

for (int i = 0, j = arr.Length - 1; i < j ;) {

    while (arr[i] < 0) i++;
    while (arr[j] >= 0) j--;
    swap(ref arr[i], ref arr[j--]);
}

for (int i = 0; i < arr.Length; i++) {
    Console.Write(arr[i] + " ");
}

void swap(ref int a,ref int b)
{
    int temp = a; a = b;
    b= temp;
}

#endif //TASK_2

//3.Написать программу, которая предлагает пользователю ввести число и считает, сколько раз это число
//встречается в массиве.
#if TASK_3

Random rnd = new Random();
int[] arr = new int[rnd.Next(10, 30)];
for (int i = 0; i < arr.Length; i++)
{
    arr[i] = rnd.Next(0, 10);
    Console.Write(arr[i] + " ");
}
Console.WriteLine();
Console.Write("Введите число: ");
int val = int.Parse(Console.ReadLine());
int count = 0;

for (int i = 0; i < arr.Length; i++) if (arr[i] == val) count++;

Console.Write($"Число {val} встречается в массиве {count} раза ");

#endif //TASK_3

//4.В двумерном массиве порядка M на N поменяйте местами заданные столбцы
#if TASK_4
using System.Drawing;

Random rnd = new Random();
int col = 5;
int row = 6;
int[,] two_dem_arr = new int[col,row];

for (int i = 0; i < two_dem_arr.GetLength(0); i++)
{
    for (int j = 0; j < two_dem_arr.GetLength(1); j++)
    {
        two_dem_arr[i, j] = rnd.Next(0, 20);
        Console.Write(two_dem_arr[i, j] + "\t");
    }
    Console.WriteLine();
}
int col_a = 0;
int col_b = 0;
do
{
    try
    {
        Console.Write("Введите номер столобца, который нужно заменить: ");
        col_a = int.Parse(Console.ReadLine()) - 1;
        if (col_a < 1 || col_a > two_dem_arr.GetLength(0))
            Exception("Указанный индекс столбца выходит за предлы массива.");        
    }
    catch (Exception v)
    {
        Console.WriteLine($"Error! {v.Message}");
    }
} while (col_a < 1 || col_a > two_dem_arr.GetLength(0));

do
{
    try
    {
        Console.Write("Введите номер столобца,на который нужно заменить: ");
        col_b = int.Parse(Console.ReadLine()) - 1;
        if (col_b < 1 || col_b > two_dem_arr.GetLength(0))
            Exception("Указанный индекс столбца выходит за предлы массива.");
    }
    catch (Exception v)
    {
        Console.WriteLine($"Error! {v.Message}");
    }
} while (col_b < 1 || col_b > two_dem_arr.GetLength(0));


for (int i = 0; i < two_dem_arr.GetLength(0); i++)
{
    swap(ref two_dem_arr[i, col_a], ref two_dem_arr[i, col_b]);
}

Console.WriteLine();
for (int i = 0; i < two_dem_arr.GetLength(0); i++)
{
    for (int j = 0; j < two_dem_arr.GetLength(1); j++)    {
        
        Console.Write(two_dem_arr[i, j] + "\t");
    }
    Console.WriteLine();
}

void swap(ref int a, ref int b)
{
    int temp = a; a = b;
    b = temp;
}
void Exception(string v)
{
    throw new ArgumentOutOfRangeException();
}

#endif //TASK_4