#include "Player.h"

//public:
Player::Player(string name) {
	setName(name);
	player_credits = new CreditList;
	player_construction = new BuildingSiteList;
}

void Player::setName(const string name) {	
	this->name = name;
}
string Player::getName() const {
	return name;
}

void Player::setNumberOfUsualFactories(const int value) {
	usual_factory = value < 0 ? 0 : value;
}
int Player::getNumberOfUsualFactories() const {
	return usual_factory;
}

void Player::setNumberOfAutomatedFactory(const int value) {
	automated_factory = value < 0 ? 0 : value;
}
int Player::getNumberOfAutomatedFactory() const {
	return automated_factory;
}

void Player::setPlayerESM(const int value) {
	esm = value < 0 ? -1 : value;
}
int Player::getPlayerESM() const {
	return esm;
}

void Player::setPlayerEGP(const int value) {
	egp = value < 0 ? -1 : value;
}
int Player::getPlayerEGP() const {
	return egp;
}

void Player::setCash(const int value) {
	cash = value < 0 ? -1 : value;
}
int Player::getCash() const {
	return cash;
}

bool Player::isBankrupt() {
	if (getCash() == -1) return true;
	else return false;
}

// Методы выплатам постоянных издержек
void Player::paymentOfCostsForESM() {
	setCash(getCash() - (getPlayerESM() * 300));
}
void Player::paymentOfCostsForEGP() {
	setCash(getCash() - (getPlayerEGP() * 500));
}
void Player::paymentOfCostsForUsualFactory() {
	setCash(getCash() - (getNumberOfUsualFactories() * 1000));
}
void Player::paymentOfCostsForAutomatedFactory() {
	setCash(getCash() - (getNumberOfAutomatedFactory() * 1500));
}

// Методы для оформления заявки
int Player::getRequiredNumberOfECM(Application* app)const {
	return app->getNumberOfUnitsRequested();
}
int Player::getOfferedPriceOfECM(Application* app)const {
	return app->getPricePerUnit();
}
void Player::ESMapplicationExecution(Application* app) {
	setPlayerESM(getPlayerESM() + app->getNumberOfUnitsRequested());
	setCash(getCash() - (app->getNumberOfUnitsRequested() * app->getPricePerUnit()));
}
void Player::EGPapplicationExecution(Application* app) {
	setPlayerEGP(getPlayerEGP() - app->getNumberOfUnitsRequested());
	setCash(getCash() + (app->getNumberOfUnitsRequested() * app->getPricePerUnit()));
}

//Методы по работе с кредитами
void Player::borrowFromTheBank(const int credit_amount) {
	player_credits->addNewCredit(credit_amount);
	setCash(getCash() + credit_amount);
}
int Player::getTotalCredits() const{
	int totatl_credits{0};
	for (int i = 0; i < player_credits->getSize(); i++)	{
		totatl_credits = player_credits->getCredit(i)->getCreditAmount();
	}
	return totatl_credits;	
}
bool Player::creditRequirementsAreMet(const int credit_amount) const {
	return getTotalCredits() + credit_amount <= getNumberOfUsualFactories() * 5000 + getNumberOfAutomatedFactory() * 10000 && credit_amount > 0;
}
void Player::payInterestOnTheCredit(){
	int totatl_credits{ 0 };
	for (int i = 0; i < player_credits->getSize(); i++) {
		totatl_credits = player_credits->getCredit(i)->getCreditAmount();
	}
	setCash(getCash() - 0.01 * totatl_credits);
}
void Player::creditRepayment(int index) {
	setCash(getCash() - player_credits->getCredit(index)->getCreditAmount());
	player_credits->deleteCredit(index);
}

//Методы по работе со строительством фабрик
void Player::orderTheConstructionOfFactory(int object_type) {
	player_construction->addNewBuildingSite(object_type);
	setCash(getCash() - (player_construction->getTheLastConstructionSiteAdded()->getConstructionCost()/2));
}

void Player::paymentForTheSecondPartOfTheConstruction() {
	for (int construction_index = 0; construction_index < player_construction->getSize(); construction_index++)
	{
		if (player_construction->getBuildingSite(construction_index)->getConstructionPeriod() == 1) {
			std::cout << " Происхрдит оплата второй части заказа на строительство" << std::endl;
			setCash(getCash() - player_construction->getBuildingSite(construction_index)->getConstructionCost() / 2);
		}
	}
}