#include "Application.h"

Application::Application(int num_units, int cost_egp, std::string applicant) {
	setApplicant(applicant);
	setNumberOfUnitsRequested(num_units);
	setPricePerUnit(cost_egp);
}

void Application::setApplicant(std::string name) {
	applicant = name;
}
std::string Application::getApplicant() const {
	return applicant;
}
void Application::setNumberOfUnitsRequested(const int value) {
	number_of_units = value < 0 ? 0 : value;
}
int Application::getNumberOfUnitsRequested() const {
	return number_of_units;
}
void Application::setPricePerUnit(const int value) {
	unit_cost = value < 0 ? 0 : value;
}
int Application::getPricePerUnit() const {
	return unit_cost;
}
