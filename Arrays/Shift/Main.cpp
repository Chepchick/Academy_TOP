#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    //объявляем, инициализируем и выводим массив на консоль

    const int SIZE = 10;
    int array[SIZE], newArray[SIZE];

    for (int i = 0; i < SIZE; i++) {
        array[i] = i + 1;
        cout << array[i] << " ";
    }
    cout << endl;

    int shift;
    cout << "Введите величину сдвига массива вправо: ";
    cin >> shift;

    for (int i = 0; i < shift; i++) {
        newArray[i] = array[SIZE - shift + i];
    }
    for (int i = shift; i < SIZE; i++) {
        newArray[i] = array[i - shift];
    }
    for (int i = 0; i < SIZE; i++) {
        cout << newArray[i] << " ";
    }
    cout << endl << endl;

    //сбрасываем значения исходного массива к начальным
    for (int i = 0; i < SIZE; i++) {
        array[i] = i + 1;
        newArray[i] = 0;
    }

    cout << "Введите величину сдвига массива влево: ";
    cin >> shift;

    for (int i = 0; i < shift; i++) {
        newArray[SIZE - shift + i] = array[i];
    }
    for (int i = 0; i < SIZE - shift; i++) {
        newArray[i] = array[shift + i];
    }
    for (int i = 0; i < SIZE; i++) {
        cout << newArray[i] << " ";
    }

    return 0;
}