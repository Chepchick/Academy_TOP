#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void showGain(const int, const char);
void newResult();

int main() {
	setlocale(0,"");
	srand(time(NULL));

	const int SIZE_REEL{ 8 };
	char simbols[SIZE_REEL]{ 134, 170, 135, 137, 175, 167};

	const int SIZE_DISPLAY{ 3 };
	char display[SIZE_DISPLAY]{};

	for (size_t i{ 0 }; i < SIZE_DISPLAY; i++)
	{
		display[i] = simbols[rand() % 4];
		cout << display[i] << " ";
	}
	cout  << endl;

	char repit_simbol{ char()};
	size_t repit_counter{ size_t() };

	for (size_t i{ 0 }; i < SIZE_DISPLAY; i++)
	{
		for (size_t j{ 0 }; j < SIZE_DISPLAY; j++)
		{
			if (display[i] == display[j] && i!=j)
			{
				repit_simbol = display[i];
				repit_counter++;
				break;
			}
		}
	}

	if (repit_simbol) {	showGain(repit_counter, repit_simbol); }
	else { cout << "Вы ни чего не выиграли" << endl; }	
	cout << endl;

	return 0;
}

void showGain(const int counter, const char simbol) {
	switch (counter)
	{
	case 2:
		cout << "Ваш выигрыш -  два раза " << simbol;
		break;
	case 3:
		cout << "БИНГО!!! Ваш выигрыш -  целых три раза " << simbol;
		break;
	default:
		cout << "Вы ни чего не выиграли";
		break;
	}
}