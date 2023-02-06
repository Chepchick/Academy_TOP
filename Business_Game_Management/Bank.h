#pragma once
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "ApplicationList.h"

static class Bank
{
private:
	static void setCurrentSupplyLevel(const int);
	static void setNumberOfPlayersBuyingECMs(const float);
	static void setNumberOfPlayersSellingEGPs(const float);
	static void setMinimumESMPrice(const int);
	static void setMaximumEGPPrice(const int);

public:
	static int getCurrentSupplyLevel();
	static float getNumberOfPlayersBuyingECMs();
	static float getNumberOfPlayersSellingEGPs();
	static int getMinimumESMPrice();
	static int getMaximumEGPPrice();

	// методы по определению уровня цен
	static void updateSupplyLevel();
	static int getNewSupplyLevel(int old_level);
	static void setCurrentPrice(int level);

	//методы по обработке заявок
	static void processingOfApplicationsESMs(ApplicationList*&);
	static void processingOfApplicationsEGPs(ApplicationList*&);

	static void deletionOfIlliquidApplicationsESMs(ApplicationList*);
	static void deletionOfIlliquidApplicationsEGPs(ApplicationList*);

	static int getTheNumberOfESMsSale(int);
	static int getTheNumberOfEGPsBuy(int);

	// методы по работе с кредитами
	static Credit* giveCredit(const int);
};

static int current_supply_level{ 3 };
static float number_of_players_buying_ECMs{ float() };
static float number_of_players_selling_EGPs{ float() };
static int minimum_ESM_price{ int() };
static int maximum_EGP_price{ int() };

static enum  BankDecisionsOn
{
	number_of_ESM_buyers,
	the_minimum_price_of_ESM,
	number_of_EGP_sellers,
	the_maximum_price_of_EGP
};
static const float price_level_table[5][4]{
	{1.0, 800, 3.0,	6500},
	{1.5, 650, 2.5,	6000},
	{2.0, 500, 2.0,	5500},
	{2.5, 400, 1.5,	5000},
	{3.0, 300, 1.0,	4500}
};
static const int level_transition_table[5][12]{
	{1,1,1,1,2,2,2,2,3,3,4,5},
	{1,1,1,2,2,2,2,3,3,3,4,5},
	{1,2,2,2,3,3,3,3,4,4,4,5},
	{1,2,3,3,3,4,4,4,4,5,5,5},
	{1,2,3,3,4,4,4,4,5,5,5,5}
};