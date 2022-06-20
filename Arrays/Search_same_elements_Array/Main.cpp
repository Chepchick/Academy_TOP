#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    const int SIZE = 10;
    int basicArray[SIZE], valueArray[SIZE / 2], countArray[SIZE / 2];
    int sizeCount = 0;


    for (int i = 0; i < SIZE; i++) {
        basicArray[i] = 1 + rand() % 5;
        cout << basicArray[i] << " ";
    }
    cout << endl << endl;


    for (int i = 0; i < SIZE; i++) {
        int repitCount = 0;
        bool repitDetector = false;

        for (int j = 0; j < SIZE; j++) {

            if (i != j)
            {
                if (basicArray[i] == basicArray[j])
                {
                    repitCount++;
                    int n;
                    for (n = 0; n <= sizeCount; n++)
                    {
                        if (valueArray[n - 1] == basicArray[i]) {
                            repitDetector = true;
                            break;
                        }
                    }

                    if (repitDetector == 0)
                    {
                        valueArray[sizeCount] = basicArray[i];
                        sizeCount++;
                    }
                    countArray[n] = repitCount;
                }
            }
        }
    }

    for (int i = 0; i < sizeCount; i++)
        cout << " В массиве число " << valueArray[i] << " повторяется " << countArray[i] << " раз(а)" << endl;





    return 0;
}