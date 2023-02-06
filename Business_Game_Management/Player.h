#pragma once
#include <iostream>
#include <Windows.h>
#include "Application.h"
#include "CreditList.h"
#include "BuildingSiteList.h";

using std::string;

class Player
{
private:	
	string name{ "not available" };
	int usual_factory{ 2 };
	int automated_factory{ int()};
	int esm{ 4 };
	int egp{ 2 };
	int cash{ 10000 };

public:
	CreditList* player_credits{ nullptr };
	BuildingSiteList* player_construction{ nullptr };

	void setNumberOfUsualFactories(const int);
	void setNumberOfAutomatedFactory(const int);
	void setPlayerESM(const int);
	void setPlayerEGP(const int);	
	void setCash(const int);
	
	Player() {};
	Player(string);
	void setName(const string);
	string getName() const;
	int getNumberOfUsualFactories() const;
	int getNumberOfAutomatedFactory() const;
	int getPlayerESM() const;
	int getPlayerEGP() const;
	int getCash() const;

	bool isBankrupt();

	// Методы для выплат постоянных издержек	
	void paymentOfCostsForESM();
	void paymentOfCostsForEGP();
	void paymentOfCostsForUsualFactory();
	void paymentOfCostsForAutomatedFactory();

	// Методы для оформления заявки	
	int getRequiredNumberOfECM(Application*)const;	
	int getOfferedPriceOfECM(Application*)const;
	void ESMapplicationExecution(Application*);
	void EGPapplicationExecution(Application*);

	//Методы по работе с кредитами
	void borrowFromTheBank(const int);
	bool creditRequirementsAreMet(const int) const;
	int getTotalCredits()const;
	void payInterestOnTheCredit();
	void creditRepayment(int);

	//Методы по работе со строительством фабрик
	void orderTheConstructionOfFactory(int);
	void paymentForTheSecondPartOfTheConstruction();
};

