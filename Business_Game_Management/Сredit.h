#pragma once
class Credit
{
	int credit_amount{ int() };
	int credit_period{ 12 };

	void setCreditPeriod(const int);

public:
	Credit(){};
	Credit(int);

	void setCreditAmount(const int);
	int getCreditAmount() const;
	int getCreditPeriod() const;

	void recalculateTheCreditPeriod();
};