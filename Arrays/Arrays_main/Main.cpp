#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    const int SIZE = 5;
    int array[SIZE]; // объявление массива

    for (int i = 0; i < SIZE; i++) { // инициализация массива вручную
        cout << "Введите значение " << i + 1 << "-го элемента массива: " << endl;
        cin >> array[i];
    }
    cout << endl << endl;

    // выводим массив на кансоль в прямом порядке
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // выводим массив на кансоль в обратном порядке
    for (int i = SIZE - 1; i >= 0; i--) {
        cout << array[i] << " ";
    }
    cout << endl;

    // находим сумму всех элементов массива
    int result = 0;
    for (int i = 0; i < SIZE; i++) {
        result += array[i];
    }

    cout << "Сумма всех элементов массива равна: " << result << endl;

    // находим среднее арифметическое всех элементов массива
    cout << "Среднее арифметическое всех элементов массива равно: " << (double)result / SIZE << endl;

    // находим и выводим на консоль минимальный и максимальный элемент массива
    int min = array[0], max = array[0];
    for (int i = 1; i < SIZE; i++) {
        if (max < array[i]) max = array[i];
        if (min > array[i]) min = array[i];
    }
    cout << "Максимальное значение массива равно: " << max << endl;
    cout << "Минимальное значение массива равно: " << min << endl;

    return 0;
}