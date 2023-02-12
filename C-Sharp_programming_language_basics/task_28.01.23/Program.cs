#define TASK_1
//Используя числа 16 и 2 получить следующие числа:

//Для получения значения используйте операторы сдига для получения близких значений. Не достающую разницу нужно будет сложить или вычесть
//значениями полученными тоже с помощью операторов сдвига.

#if TASK_1 //127

int a = 16, b = 2;
int c = a << 3;
int d = b >> 1;
int e = c - d;
Console.WriteLine($"a << 3 = {c}; b >> 1 = {d}; {c} - {d} = {e} ");

#endif //TASK_1


#if TASK_2 //255

int a = 16, b = 2;
int c = a << 4;
int d = b >> 1;
int e = c - d;
Console.WriteLine($"a << 4 = {c}; b >> 1 = {d}; {c} - {d} = {e} ");

#endif //TASK_2


#if TASK_3 //528

int a = 16, b = 2;
int c = a << 5;
int d = b << 3;
int e = c + d;
Console.WriteLine($"a << 5 = {c}; b << 3 = {d}; {c} + {d} = {e} ");

#endif //TASK_3

#if TASK_4 //614 - я в ступоре, не могу придумать как его получить

int a = 16, b = 2;
var c = a << 1;
int d = b << 2;
int e = (d + c) << 1;

Console.WriteLine($"a << 3 = {c}; b >> 1 = {d}; {c} + {d} = {e} ");

#endif //TASK_4