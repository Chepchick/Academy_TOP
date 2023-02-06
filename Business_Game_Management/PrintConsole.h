#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "BasicData.h"
#include "Bank.h"
#include "Player.h"
#include "PlayerList.h"
#include "Application.h"
#include "ApplicationList.h"

using namespace std;

namespace PrintConsole {
	char startMenu();
	void startNewGame(BasicData&);
	void loadGame();
	void exitGame();

	void consoleSetup();
	void printHead(BasicData&);
	void printPlayerResources(BasicData&);

	void firstAction(BasicData&);
	void secondAct(BasicData&);
	void thirdAct(BasicData&);
	ApplicationList* fillingApplicationsForESM(BasicData&);
	void fulfilmentOfApplicationsESMs(BasicData&, ApplicationList&);
	void fourthAct(BasicData&);
	void fifthAct(BasicData&);
	void sixthAct(BasicData&);
	void seventhAct(BasicData&);
	void eighthAct(BasicData&);
	void ninthAct(BasicData&);

	void updateBasicData(BasicData&);
	void printFinalResult(BasicData&);
	bool victoryNotAchieved(BasicData&);

	int getSeniorPlayerNumber(BasicData&);
	ApplicationList* fillingApplicationsForEGP(BasicData&);
	void fulfilmentOfApplicationsEGPs(BasicData&, ApplicationList&);
	Player* findApplicant(BasicData&, int&, Application*, int);	
	int getSelectedNumberOfECMs(Player*);
	string rusNameObjectForPartNine(int);
	string rusNameObjectForPlayerResourses(int);
	void printEndOfMonthMessage(BasicData&);
	void printDisappearingMessage(string, int);



	bool isDivisibleByTwo(int);


	 
}

