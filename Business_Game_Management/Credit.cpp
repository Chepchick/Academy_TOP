#include "Ñredit.h"

//private:
void Credit::setCreditPeriod(const int value) {
	credit_period = value < 0 ? 0 : value;
}

//public:
Credit::Credit(int credit_amount) {
	setCreditAmount(credit_amount);
}

void Credit::setCreditAmount(const int value) {
	credit_amount = value < 0 ? 0 : value;
}

int Credit::getCreditAmount() const {
	return credit_amount;
}
int Credit::getCreditPeriod() const {
	return credit_period;
}

void Credit::recalculateTheCreditPeriod() {
	setCreditPeriod(getCreditPeriod() - 1);
}