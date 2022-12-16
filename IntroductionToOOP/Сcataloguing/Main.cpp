#include <iostream>
#include <cstdio>
using namespace std;


int main()
{ 
    setlocale(0, "");

    FILE* cur_file;
    if (cur_file = fopen("test", "w") == NULL) {
        cout << "Невозможно открыть файл\n";
        exit(1);
    }



    return 0;
}
