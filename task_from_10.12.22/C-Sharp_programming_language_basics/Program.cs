#define TASK_

#if TASK_1
//Пользователь вводит с клавиатуры число в диапа зоне от 1 до 100. Если число кратно 3 нужно
//вывести слово Fizz. Если 5 - Buzz. Если 3 и 5 - Fizz Buzz. Если не кратно не 3 и 5 - вывести само число.
//Если пользователь ввел значение не в диапазоне от 1 до 100 требуется вывести сообщение об ошибке.

int num = 0;
Console.WriteLine("Введите число от 1 до 100:");
do
{
    num = Convert.ToInt32(Console.ReadLine());
    if (num < 1 && num > 100) Console.WriteLine("Введено значение вне диапазона\n");
} while (num < 1 && num > 100);

if (num % 3 == 0) Console.WriteLine("Fizz");
if (num % 5 == 0) Console.WriteLine("Buzz");
if (num % 3 == 0 && num % 5 == 0) Console.WriteLine("Fizz Buzz");
else Console.WriteLine(num);

#endif //TASK_1

#if TASK_2
//Пользователь вводит с клавиатуры два числа. Первое число — это значение
//второе число процент, который необходимо посчитать. Например, мы ввели с клавиатуры 90 и 10.
//Требуется вывести на экран 10 процентов от 90. Результат: 9.

Console.WriteLine("Введите два числа");
Console.Write("Первое: ");
float value = Convert.ToInt32(Console.ReadLine());
Console.Write("Второе: ");
float percent = Convert.ToInt32(Console.ReadLine());

Console.Write($"{percent} процентов от числа {value} состовляют {(value / 100) * percent}");

#endif //TASK_2

#if TASK_3
//Пользователь вводит с клавиатуры четыре цифры. Необходимо создать число, содержащее эти цифры.
//Например, если с клавиатуры введено 1, 5, 7, 8 тогда нужно сформировать число 1578.

Console.WriteLine("Введите четыре числа");
Console.Write("Первое: ");
string? first = Console.ReadLine();
Console.Write("Второе: ");
string? second = Console.ReadLine();
Console.Write("Третье: ");
string? third = Console.ReadLine();
Console.Write("Четвертое: ");
string? fourth = Console.ReadLine();

string result = first+second+third+fourth;
Console.WriteLine(Convert.ToInt32(result));

#endif //TASK_3

#if TASK_4
//Пользователь вводит шестизначное число. После чего пользователь вводит номера разрядов для обмена цифр.
//Например, если пользователь ввёл один и шесть — это значит, что надо обменять местами первую и шестую
//цифры. Число 723895 должно превратиться в 523897. Если пользователь ввел не шестизначное число тре-
//буется вывести сообщение об ошибке.

char[] six_digits_array;
do { 
    Console.Write("Введите шестизначное число:");
    string? six_digits_str = Console.ReadLine();
    six_digits_array = six_digits_str.ToCharArray();
    if (six_digits_array.Length != 6) Console.WriteLine("Разрядность числа не равна шести"); 
} while (six_digits_array.Length != 6);

Console.Write("Введите первый номер разряда:");
int first = Convert.ToInt32(Console.ReadLine());
Console.Write("Введите второй номер разряда:");
int second = Convert.ToInt32(Console.ReadLine());

char temp = six_digits_array[first - 1];
six_digits_array[first - 1] = six_digits_array[second - 1];
six_digits_array[second - 1] = temp;

Console.WriteLine(six_digits_array);

#endif //TASK_4

#if TASK_5
//Пользователь вводит с клавиатуры дату. Приложение должно отобразить название сезона и дня недели.
//Например, если введено 22.12.2021, приложение должно отобразить Winter Wednesday.

Console.WriteLine("введите дату в формате (дд.мм.гггг)");
string? str_date = Console.ReadLine();
DateTime date = DateTime.Parse(str_date);

Console.Write(date.DayOfWeek + "\t");
string season = "default";
if (date.DayOfYear >=60 && date.DayOfYear <= 151) season = "Spring";
else if (date.DayOfYear >= 152 && date.DayOfYear <= 243) season = "Summer";
else if (date.DayOfYear >= 244 && date.DayOfYear <= 334) season = "Autumn";
else season = "Winter";
Console.Write(season);

#endif //TASK_5

#if TASK_6
//Пользователь вводит с клавиатуры показания температуры. В зависимости от выбора пользователя про-
//грамма переводит температуру из Фаренгейта в Цельсий или наоборот.

Console.WriteLine("Введите значение градусов");
int grades = Convert.ToInt32(Console.ReadLine());
Console.WriteLine("Чтобы перевести значение из градусов Фаренгейта в Цельсий нажмите 1");
Console.WriteLine("Чтобы перевести значение из градусов Цельсия в Фаренгейт нажмите 2");

switch (Console.ReadLine())
{
    case "1":
        Console.WriteLine($"Значение градусов Цельсия: {(grades - 32) * 5 / 9}");
        break;
    case "2":
        Console.WriteLine($"Значение градусов Фаренгейта: {(grades * 9/5) + 32}");
        break;

    default:
        Console.WriteLine("Выбор не корректен");
        break;
}
#endif //TASK_6

#if TASK_7
//Пользователь вводит с клавиатуры два числа. Нужно показать все четные числа в указанном диапазоне. Если
//границы диапазона указаны неправильно требуется произвести нормализацию границ. Например, пользователь
//ввел 20 и 11, требуется нормализация, после которой начало диапазона станет равно 11, а конец 20.

Console.WriteLine("Введите два числа - границы диапазона");
Console.Write("Первое: ");
int min = Convert.ToInt32(Console.ReadLine());
Console.Write("Второе: ");
int max = Convert.ToInt32(Console.ReadLine());
if (min > max) swap(ref min, ref max);

int cur_val = min % 2 == 0 ? min : min + 1;

while (cur_val <= max)
{
    Console.Write(cur_val + " ");
    cur_val += 2;
}

void swap(ref int x, ref int y)
{
    int temp = x; x = y;
    y = temp;
}
#endif //TASK_7