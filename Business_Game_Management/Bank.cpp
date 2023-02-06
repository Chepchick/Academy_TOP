#include "Bank.h"

//private:
void Bank::setCurrentSupplyLevel(const int value) {
	current_supply_level = value;
};
void Bank::setNumberOfPlayersBuyingECMs(const float value) {
	number_of_players_buying_ECMs = value;
};
void Bank::setNumberOfPlayersSellingEGPs(const float value) {
	number_of_players_selling_EGPs = value;
};
void Bank::setMinimumESMPrice(const int value) {
	minimum_ESM_price = value;
};
void Bank::setMaximumEGPPrice(const int value) {
	maximum_EGP_price = value;
};

//public:
int Bank::getCurrentSupplyLevel() { return current_supply_level; };
float Bank::getNumberOfPlayersBuyingECMs() { return number_of_players_buying_ECMs; };
float Bank::getNumberOfPlayersSellingEGPs() { return number_of_players_selling_EGPs; };
int Bank::getMinimumESMPrice() { return minimum_ESM_price; };
int Bank::getMaximumEGPPrice() { return maximum_EGP_price; };

// методы по определению уровн€ цен
void Bank::updateSupplyLevel() {
	setCurrentSupplyLevel(getNewSupplyLevel(getCurrentSupplyLevel()));
}
int Bank::getNewSupplyLevel(int old_level) {
	srand(time(NULL));
	return level_transition_table[old_level - 1][rand() % 12];
}
void Bank::setCurrentPrice(int curent_level) {

	setNumberOfPlayersBuyingECMs(price_level_table[curent_level - 1][BankDecisionsOn::number_of_ESM_buyers]);
	setMinimumESMPrice(price_level_table[curent_level - 1][BankDecisionsOn::the_minimum_price_of_ESM]);
	setNumberOfPlayersSellingEGPs(price_level_table[curent_level - 1][BankDecisionsOn::number_of_EGP_sellers]);
	setMaximumEGPPrice(price_level_table[curent_level - 1][BankDecisionsOn::the_maximum_price_of_EGP]);
}

//методы по обработке за€вок
void Bank::processingOfApplicationsESMs(ApplicationList*& completed_applications) {

	deletionOfIlliquidApplicationsESMs(completed_applications);
	completed_applications->sortListApplicationsESMs();
	int number_of_applications = completed_applications->getNumberOfApplictions();
	int number_of_unnecessary_applications = number_of_applications > getTheNumberOfESMsSale(number_of_applications) ? number_of_applications - getTheNumberOfESMsSale(number_of_applications) : 0;
	for (int i = completed_applications->getNumberOfApplictions() - 1; number_of_unnecessary_applications > 0; i--, number_of_unnecessary_applications--) {
		std::cout << " «а€вка игрока " << completed_applications->getPlayer(i)->getName() << " не прошла отборочный этап"<< std::endl;
		completed_applications->deleteApplication(i);
		Sleep(2000);
	}
	std::cout << std::endl << std::endl;
}
void Bank::processingOfApplicationsEGPs(ApplicationList*& completed_applications) {

	deletionOfIlliquidApplicationsEGPs(completed_applications);
	completed_applications->sortListApplicationsEGPs();
	int number_of_applications = completed_applications->getNumberOfApplictions();
	int number_of_unnecessary_applications = number_of_applications > getTheNumberOfEGPsBuy(number_of_applications) ? number_of_applications - getTheNumberOfESMsSale(number_of_applications) : 0;
	for (int i = completed_applications->getNumberOfApplictions() - 1; number_of_unnecessary_applications > 0; i--, number_of_unnecessary_applications--) {
		std::cout << "«а€вка игрока " << completed_applications->getPlayer(i)->getName() << " не выиграла в конкурсе" << std::endl << std::endl;
		completed_applications->deleteApplication(i);
		system("pause");
	}
	std::cout << std::endl << std::endl;

}

void Bank::deletionOfIlliquidApplicationsESMs(ApplicationList* completed_applications) {
	
	for (int i = 0; i < completed_applications->getNumberOfApplictions(); i++)
	{
		if (completed_applications->getApplication(i)->getNumberOfUnitsRequested() <= 0 &&
			completed_applications->getApplication(i)->getPricePerUnit() < Bank::getMinimumESMPrice())
		{
			completed_applications->deleteApplication(i);
		}		
	}
}
void Bank::deletionOfIlliquidApplicationsEGPs(ApplicationList* completed_applications) {
	for (int i = 0; i < completed_applications->getNumberOfApplictions(); i++)
	{
		if (completed_applications->getApplication(i)->getNumberOfUnitsRequested() <= 0 &&
			completed_applications->getApplication(i)->getPricePerUnit() > Bank::getMaximumEGPPrice())
		{
			completed_applications->deleteApplication(i);
		}
	}
}

int Bank::getTheNumberOfESMsSale(int numbers_of_application) {
	if (ceil(Bank::getNumberOfPlayersBuyingECMs()) >= numbers_of_application) return (int)floor(Bank::getNumberOfPlayersBuyingECMs());
	else return (int)ceil(Bank::getNumberOfPlayersBuyingECMs());
}
int Bank::getTheNumberOfEGPsBuy(int numbers_of_application){
	if (ceil(Bank::getNumberOfPlayersSellingEGPs()) >= numbers_of_application) return (int)floor(Bank::getNumberOfPlayersSellingEGPs());
	else return (int)ceil(Bank::getNumberOfPlayersSellingEGPs());
}

// методы по работе с кредитами
Credit* Bank::giveCredit(const int credit_amount) {	
	return new Credit(credit_amount);
}