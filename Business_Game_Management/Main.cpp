#include "PrintConsole.h"

using namespace PrintConsole;

int main() {
	setlocale(0, "");
	consoleSetup();
	BasicData basic_data;

	switch (startMenu())
	{
	case'1':
		startNewGame(basic_data);
		break;
	case'2':
		loadGame();
		break;
	case'3':
		exitGame();
		break;
	default:
		break;
	}

	do
	{
		firstAction(basic_data);
		secondAct(basic_data);
		thirdAct(basic_data);
		fourthAct(basic_data);
		fifthAct(basic_data);
		sixthAct(basic_data);
		seventhAct(basic_data);
		eighthAct(basic_data);
		ninthAct(basic_data);

		printEndOfMonthMessage(basic_data);
		updateBasicData(basic_data);

	} while (victoryNotAchieved(basic_data));

	printFinalResult(basic_data);
	

	return 0;
}