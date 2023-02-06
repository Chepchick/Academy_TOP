#include "PrintConsole.h"

char PrintConsole::startMenu() {
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t   ����� ���������� � ���� ���������� !\n";
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t\t  1 ������ ����\n";
	cout << "\t\t\t\t\t\t  2 ��������� ����������\n";
	cout << "\t\t\t\t\t\t  3 ����� �� ����\n";
	cout << endl;
	cout << "\t\t\t\t\t\t(�������� ����� �� ����)\n";
	char ch{ char() };
	do {
		ch = _getch();
		if (ch != '1' && ch != '2' && ch != '3') cout << "������ �� ���������� ������";
	} while (ch != '1' && ch != '2' && ch != '3');
	return ch;
}
void PrintConsole::startNewGame(BasicData& basic_data) {
	system("cls");
	basic_data.month_number = 0;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\t     ������ ����� ����\n";
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t\t������� ���������� �������: ";
	cin >> basic_data.number_of_players;
	basic_data.senior_player_number = getSeniorPlayerNumber(basic_data);
	cout << "\n\t\t\t\t\t������� ����� ���������� (����������� �������) \n";
	string name;
	string admissible{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };

	for (int i = 0; i < basic_data.number_of_players; i++)
	{
		do
		{
			cout << "\t\t\t\t\t\t    ��� " << i + 1 << "-�� ���������: ";
			cin >> name;
			if (!name.find_first_not_of(admissible)) {
				printDisappearingMessage("\t\t\t\t\t\t    ������������ ������������ �������", 2000);
			}
			else { basic_data.participating_players.addNewPlayer(name); }
		} while (!name.find_first_not_of(admissible));
	}
}
void PrintConsole::loadGame() {};
void PrintConsole::exitGame() {
	exit(1);
}

void PrintConsole::consoleSetup() {
	SetConsoleTitle(L"Game MANAGEMENT");
	system("mode con cols=120 lines=30");
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE);
	system("CLS");
	SetConsoleTextAttribute(hStdOut,
		BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |
		FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void PrintConsole::printHead(BasicData& basic_data) {
	cout << endl;
	cout << "\t\t\t\t\t\t  ������� ����� - " << basic_data.month_number + 1 << "-�\n";
	cout << "\t\t\t\t\t\t������� ����� - ����� " << basic_data.participating_players[basic_data.senior_player_number]->getName() << endl << endl;
}
void PrintConsole::printPlayerResources(BasicData& basic_data) {
	cout << endl;
	cout << "\t\t\t\t\t\t    ������� �������" << endl << endl;
	for (int player_index = 0; player_index < basic_data.participating_players.getNumber(); player_index++)
	{
		cout << " ��� ������ " << basic_data.participating_players[player_index]->getName() << endl;
		cout << " ���������� ������� ������ " << basic_data.participating_players[player_index]->getNumberOfUsualFactories() << endl;
		cout << " ���������� ������������������ ������ " << basic_data.participating_players[player_index]->getNumberOfAutomatedFactory() << endl;
		cout << " ���������� ��� � ������ " << basic_data.participating_players[player_index]->getPlayerESM() << endl;
		cout << " ���������� ��� � ������ " << basic_data.participating_players[player_index]->getPlayerEGP() << endl;
		cout << " ���������� �������� ����� � ������ " << basic_data.participating_players[player_index]->getCash() << endl;
		if (basic_data.participating_players[player_index]->player_credits->getSize() == 0)
			cout << " ������� �����������" << endl;
		else {
			for (int credit_index = 0; credit_index < basic_data.participating_players[player_index]->player_credits->getSize(); credit_index++) {
				cout << " ������ #" << credit_index + 1 << " �� ����� " << basic_data.participating_players[player_index]->player_credits->getCredit(credit_index)->getCreditAmount() <<
					",��������� ������� ���������� ����� " << basic_data.participating_players[player_index]->player_credits->getCredit(credit_index)->getCreditPeriod() << " �������" << endl;
			}
		}
		if (basic_data.participating_players[player_index]->player_construction->getSize() == 0)
			cout << " ������� �����������" << endl;
		else {
			for (int �onstruction_index = 0; �onstruction_index < basic_data.participating_players[player_index]->player_construction->getSize(); �onstruction_index++) {
				cout << " ������� #" << �onstruction_index + 1 << " - " << rusNameObjectForPlayerResourses(basic_data.participating_players[player_index]->player_construction->getBuildingSite(�onstruction_index)->getObjectType()) << ", ���������� ����� " << basic_data.participating_players[player_index]->player_construction->getBuildingSite(�onstruction_index)->getConstructionPeriod() << " �����" << endl;
			}
		}
		cout << endl;
	}
}
string PrintConsole::rusNameObjectForPlayerResourses(int object_type) {
	switch (object_type)
	{
	case 0:
		return "������� �������";
		break;
	case 1:
		return "������������������ �������";
		break;
	case 2:
		return "������������� ������� �������";
		break;

	default:
		break;
	}
}
void PrintConsole::printDisappearingMessage(string message, int time) {
	cout << message;
	Sleep(time);
	CONSOLE_SCREEN_BUFFER_INFO bi;
	COORD coord_cur;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
	coord_cur.X = 0;
	coord_cur.Y = bi.dwCursorPosition.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_cur);
	for (int i = bi.dwCursorPosition.X; i >= 0; i--) cout << ' ';
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_cur);
}
void PrintConsole::printEndOfMonthMessage(BasicData& basic_data) {
	system("cls");
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t����� #" << basic_data.month_number + 1 << " - �������" << endl;
	system("pause");
}

void PrintConsole::firstAction(BasicData& basic_data) {
	system("cls");
	printPlayerResources(basic_data);
	system("pause");
	system("cls");
	printHead(basic_data);
	cout << "\t\t\t\t\t\t  ����������� ��������\n";
	cout << "\t\t\t\t\t       ������� ���������� ��������\n";
	cout << endl << endl << endl;

	int cur_player_index{ basic_data.senior_player_number };
	do
	{
		cur_player_index = cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;

		basic_data.participating_players[cur_player_index]->paymentOfCostsForUsualFactory();
		basic_data.participating_players[cur_player_index]->paymentOfCostsForAutomatedFactory();
		basic_data.participating_players[cur_player_index]->paymentOfCostsForESM();
		basic_data.participating_players[cur_player_index]->paymentOfCostsForEGP();
		if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
			cout << " ��������!!! ����� �����" << cur_player_index + 1 << " ��� ������ " << basic_data.participating_players[cur_player_index]->getName() <<
				" ����������� ��������� � �������� �� ����\n";
			basic_data.participating_players.playerRemoval(cur_player_index);
		}
		else {
			cout << " ����� " << basic_data.participating_players[cur_player_index]->getName() << " �������� ����������� ��������\n";
		}
		Sleep(1000);

		cur_player_index++;
	} while (basic_data.senior_player_number != (basic_data.participating_players.getNextPlayerIndex(basic_data.participating_players, cur_player_index - 1)));
	cout << endl;
	system("pause");
	system("cls");
	printPlayerResources(basic_data);
	system("pause");
}
void PrintConsole::secondAct(BasicData& basic_data) {
	system("cls");
	printHead(basic_data);

	cout << "\t\t\t\t\t\t  ����������� ��������\n";
	cout << "\t\t\t\t\t     ����������� ���������� �� �����\n";
	cout << endl << endl << endl;

	printDisappearingMessage(" ���������� ���������� �������� ������ ���. ��������", 3000);

	cout << " ������� ������� ����������� - " << Bank::getCurrentSupplyLevel() << endl << endl;
	Bank::setCurrentPrice(Bank::getCurrentSupplyLevel());

	printDisappearingMessage(" ���������� ���������� ��� �� ������� ������. ��������", 4000);

	cout << " ���������� �������, ������� ���� ����� ������� ��� - " << Bank::getTheNumberOfESMsSale(Bank::getNumberOfPlayersBuyingECMs()) << endl;
	cout << " ����������� ����, �� ������� ����� ������ ��� � ����� - " << Bank::getMinimumESMPrice() << endl;
	cout << " ���������� �������, � ������� ���� ����� ������ ��� - " << Bank::getTheNumberOfEGPsBuy(Bank::getNumberOfPlayersSellingEGPs()) << endl;
	cout << " ������������ ����, �� ������� ����� ������� ��� ����� - " << Bank::getMaximumEGPPrice() << endl << endl;
	system("pause");
}
void PrintConsole::thirdAct(BasicData& basic_data) {
	system("cls");
	printHead(basic_data);
	cout << "\t\t\t\t\t\t  ����������� ��������\n";
	cout << "\t\t\t\t       ������ �� ������� ����� � ���������� � �����";
	cout << endl << endl;
	cout << " ���������� �������, ������� ���� ����� ������� ��� - " << Bank::getTheNumberOfESMsSale(Bank::getNumberOfPlayersBuyingECMs()) << endl;
	cout << " ����������� ����, �� ������� ����� ������ ��� � ����� - " << Bank::getMinimumESMPrice() << endl;
	cout << endl;
	printDisappearingMessage(" ���������� ���������� ����� ��� ���������� ������. �������� ", 8000);

	ApplicationList* completed_applications = fillingApplicationsForESM(basic_data);

	system("cls");
	printHead(basic_data);
	cout << endl;
	cout << "\t\t\t\t  ���������� ������������ �� ������� �� ���ܨ � ���������\n";
	cout << endl;
	printDisappearingMessage(" ���������� ��������� ������ ������. ��������. ", 4000);

	Bank::processingOfApplicationsESMs(completed_applications);
	fulfilmentOfApplicationsESMs(basic_data, *completed_applications);

	system("cls");
	printPlayerResources(basic_data);
	system("pause");
}
ApplicationList* PrintConsole::fillingApplicationsForESM(BasicData& basic_data) {
	ApplicationList* completed_applications = new ApplicationList;
	int cur_player_index{ basic_data.senior_player_number };

	for (int cur_application_index = 0; cur_application_index < basic_data.number_of_players; cur_application_index++)
	{
		system("cls");
		printHead(basic_data);
		cout << "\t\t\t\t\t\t   ���������� ������" << std::endl << std::endl;
		cout << "\t\t\t\t\t\t  ��������� ����� - " << basic_data.participating_players[cur_player_index]->getName() << std::endl;
		cout << "\t\t\t\t\t\t    �������� ������\n\n";
		Sleep(1000);
		int num_egp{ int() };
		int cost_egp{ int() };
		cout << " ��������!!! ��������� ��������� ���������� � ����� ���, �� ������ ��������� ���������� �������� �� ����� � ������." << endl;
		cout << " � ��������� ������ ����� ������������������ �� ������������� �������� �����." << endl;
		cout << " �����, ��������� ���� ������� ��� ���� ���������� ��� ���������� ���������� ��� ������ 0, �� ��������� � ������." << endl << endl << endl;
		cout << " ������� �������� ���������� ��� ��� �������: ";
		cin >> num_egp;
		cout << " ������� ���� �� ������� �� ������ ������ ��� (�� ���� " << Bank::getMinimumESMPrice() << " �� ������� ): ";
		cin >> cost_egp;
		completed_applications->addNewApplication(num_egp, cost_egp, basic_data.participating_players[cur_player_index]);

		cur_player_index = ++cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << endl << " ������ ������� � ������������. ";
		Sleep(2000);
	}
	return completed_applications;
}
void PrintConsole::fulfilmentOfApplicationsESMs(BasicData& basic_data, ApplicationList& application_list) {
	for (int i = 0; i < application_list.getNumberOfApplictions(); i++)
	{
		cout << " ������ �������� ������ - " << application_list[i]->getApplicant() << endl;
		cout << " �� ������� ��� � ����������: " << application_list[i]->getNumberOfUnitsRequested() << endl;
		cout << " �� ���� �� �������: " << application_list[i]->getPricePerUnit() << endl;
		printDisappearingMessage(" ���������� ���������� ����������. �������� ", 4000);

		application_list.getPlayer(i)->ESMapplicationExecution(application_list[i]);
		if (application_list.getPlayer(i)->isBankrupt()) {
			cout << " ��������� �� ��������� ��-�� �������������� ���������� ������� �� ����� ������." << endl;
			cout << " ����� ����������� ��������� � ������������������ �� ����!!!" << endl << endl;
			basic_data.participating_players.playerRemoval(i);
		}
		else {
			cout << "��������� ������� ���������." << endl << endl;
		}
		Sleep(2000);
	}
	system("pause");
}
void PrintConsole::fourthAct(BasicData& basic_data) {
	system("cls");
	printHead(basic_data);
	cout << "\t\t\t\t\t\t  ����������� ��������\n";
	cout << "\t\t\t\t\t    ������������ ������� ���������" << endl << endl;
	cout << " �������� ��������� ������������, � ����������� �� ���� ������� �� ������� ������ ��������� ������������" << endl;
	cout << "  2000 - ������������ 1 ��� �� ��� �� ������� ��� ������������������ �������" << endl;
	cout << "  3000 - ������������ 2 ��� �� ��� �� ������������������ �������" << endl << endl;
	cout << " �������� ���������� ���, ������� �� ������ ������������ � ���������." << endl;
	cout << endl;
	system("pause");

	int number_of_factories{ int() };
	int the_cost_of_production_in_factory{ int() };
	int selected_number_of_ECMs{ int() };

	int cur_player_index{ basic_data.senior_player_number };
	do
	{
		cur_player_index = cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
	BEGIN:
		system("cls");
		printHead(basic_data);
		cout << "\t\t\t\t\t\t  ����������� ��������\n";
		cout << "\t\t\t\t\t    ������������ ������� ���������" << endl << endl;
		cout << " ������� n, ���� �� ������� ����������� ��������� � ���� ������" << endl;
		cout << " ����� - " << basic_data.participating_players[cur_player_index]->getName() << ", �������� ��������� ������������ ��������� (1 - 2000, 2 - 3000) " << endl << endl;


		switch (_getch())
		{
		case '1':
			cout << " ������� ������������ ��������� �� ������� � ������������������ ��������" << endl;
			cout << " ��������� ������������ ����� ��� - 2000" << endl << endl;
			cout << " ���������� ��� ��� ����������� �� ������ ��������� ���������� ���������� ��� � ������" << endl;
			number_of_factories = basic_data.participating_players[cur_player_index]->getNumberOfUsualFactories() + basic_data.participating_players[cur_player_index]->getNumberOfAutomatedFactory();
			selected_number_of_ECMs = getSelectedNumberOfECMs(basic_data.participating_players[cur_player_index]);
			the_cost_of_production_in_factory = 2000;

			do
			{
				if (selected_number_of_ECMs <= number_of_factories) {
					basic_data.participating_players[cur_player_index]->setCash(basic_data.participating_players[cur_player_index]->getCash() - (selected_number_of_ECMs * the_cost_of_production_in_factory));
					if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
						cout << "��������!!! ����� - " << basic_data.participating_players[cur_player_index]->getName() <<
							" ����������� ��������� � �������� �� ���� ��-�� ���������� ������� ��� ������ ������������ ���\n";
						basic_data.participating_players.playerRemoval(cur_player_index);
					}
					else {
						cout << "������� ������ ������� ��������� " << selected_number_of_ECMs << " ���" << endl;
						Sleep(2000);
					}
					basic_data.participating_players[cur_player_index]->setPlayerESM(basic_data.participating_players[cur_player_index]->getPlayerESM() - selected_number_of_ECMs);
					basic_data.participating_players[cur_player_index]->setPlayerEGP(basic_data.participating_players[cur_player_index]->getPlayerEGP() + selected_number_of_ECMs);
				}
				else {
					cout << "� ��� �� ������� ������ ��� ����������� ������ ���������� ���" << endl;
					Sleep(2000);
					goto BEGIN;
				}
			} while (selected_number_of_ECMs > number_of_factories);

			break;
		case '2':
			cout << " ������� ������������ ��������� �� ������������������ ��������" << endl;
			cout << " ��������� ������������ ���� ��� - 3000" << endl << endl;
			cout << " ���������� ��� ��� ����������� �� ������ ��������� ���������� ���������� ��� � ������" << endl;
			do
			{
				selected_number_of_ECMs = getSelectedNumberOfECMs(basic_data.participating_players[cur_player_index]);
				if (!isDivisibleByTwo(selected_number_of_ECMs)) cout << " ��������� �������� �� ������ 2" << endl;
			} while (!isDivisibleByTwo(selected_number_of_ECMs));
			number_of_factories = basic_data.participating_players[cur_player_index]->getNumberOfAutomatedFactory();
			selected_number_of_ECMs /= 2;
			the_cost_of_production_in_factory = 3000;

			do
			{
				if (selected_number_of_ECMs <= number_of_factories) {
					basic_data.participating_players[cur_player_index]->setCash(basic_data.participating_players[cur_player_index]->getCash() - (selected_number_of_ECMs * the_cost_of_production_in_factory));
					if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
						cout << "��������!!! ����� - " << basic_data.participating_players[cur_player_index]->getName() <<
							" ����������� ��������� � �������� �� ���� ��-�� ���������� ������� ��� ������ ������������ ���\n";
						basic_data.participating_players.playerRemoval(cur_player_index);
					}
					else {
						cout << "������� ������ ������� ��������� " << selected_number_of_ECMs << " ���" << endl;
						Sleep(2000);
					}
					basic_data.participating_players[cur_player_index]->setPlayerESM(basic_data.participating_players[cur_player_index]->getPlayerESM() - selected_number_of_ECMs);
					basic_data.participating_players[cur_player_index]->setPlayerEGP(basic_data.participating_players[cur_player_index]->getPlayerEGP() + selected_number_of_ECMs);
				}
				else {
					cout << "� ��� �� ������� ������ ��� ����������� ������ ���������� ���" << endl;
					Sleep(2000);
					goto BEGIN;
				}
			} while (selected_number_of_ECMs > number_of_factories);

			break;
		case 'n':
		case 'N':
			cout << " � ���� ������ ����� - " << basic_data.participating_players[cur_player_index]->getName() << " �� ���������� ���������" << endl << endl;
			Sleep(2000);
			break;
		default:
			printDisappearingMessage("������ �� ���������� ������", 2000);
			goto BEGIN;
			break;
		}
	} while (basic_data.senior_player_number != (basic_data.participating_players.getNextPlayerIndex(basic_data.participating_players, cur_player_index++)));



	system("cls");
	printPlayerResources(basic_data);
	system("pause");
}
int PrintConsole::getSelectedNumberOfECMs(Player* player) {

	int selected_number_of_ECMs;
	do
	{
		cout << " ������� �������� ���������� ��� ��� ����������� � ���: ";
		cin >> selected_number_of_ECMs;
		cout << endl;
		if (selected_number_of_ECMs <= player->getPlayerESM() && selected_number_of_ECMs >= 0) {
			return selected_number_of_ECMs;
		}
		else {
			cout << " ��������� ���������� ��� ��������� ��������� ���������� ��� � ������" << endl;
		}

	} while (selected_number_of_ECMs > player->getPlayerESM());
}
void PrintConsole::fifthAct(BasicData& basic_data) {

	system("cls");
	printHead(basic_data);

	cout << "\t\t\t\t\t\t  ����������� ��������\n";
	cout << "\t\t\t\t\t������ �� ������� ������� ��������� �����";
	cout << endl << endl;
	cout << " ���������� �������, � ������� ���� ����� ������ ��� - " << Bank::getTheNumberOfEGPsBuy(Bank::getNumberOfPlayersSellingEGPs()) << endl;
	cout << " ������������ ����, �� ������� ����� ������� ��� ����� - " << Bank::getMaximumEGPPrice() << endl << endl;
	cout << endl;
	printDisappearingMessage(" ���������� ���������� ����� ��� ���������� ������. �������� ", 8000);

	ApplicationList* completed_applications = fillingApplicationsForEGP(basic_data);

	system("cls");
	printHead(basic_data);
	cout << endl;
	cout << "\t\t\t\t  ���������� ������������ �� ������� �� ������� ���������\n";
	cout << endl;
	printDisappearingMessage(" ���������� ��������� ������ ������. ��������. ", 4000);

	Bank::processingOfApplicationsEGPs(completed_applications);
	fulfilmentOfApplicationsEGPs(basic_data, *completed_applications);

	system("cls");
	printPlayerResources(basic_data);
	system("pause");
}
ApplicationList* PrintConsole::fillingApplicationsForEGP(BasicData& basic_data) {
	ApplicationList* completed_applications = new ApplicationList;
	int cur_player_index{ basic_data.senior_player_number };

	for (int cur_application_index = 0; cur_application_index < basic_data.number_of_players; cur_application_index++)
	{
		system("cls");
		printHead(basic_data);
		cout << "\t\t\t\t\t\t   ���������� ������" << std::endl << std::endl;
		cout << "\t\t\t\t\t\t  ��������� ����� - " << basic_data.participating_players[cur_player_index]->getName() << std::endl;
		cout << "\t\t\t\t\t\t    �������� ������\n\n";
		Sleep(1000);
		int num_esm{ int() };
		int cost_esm{ int() };
		cout << " ��������!!! ��������� ���������� ����������� ����� ���, �� ������ ��������� ���������� ��������� ��� � ������." << endl;
		cout << " ������ � ����� ������� ��� ���� ������������� ������ ��� ����������� ����������� ��� ������ 0, �� ��������� � ������." << endl << endl << endl;
		do
		{
			cout << " ������� �������� ���������� ��� ��� �������: ";
			cin >> num_esm;
			if (basic_data.participating_players[cur_application_index]->getPlayerEGP() < num_esm)
				cout << " ��������� ���������� ��� ��������� ���������� ��������� � ������" << endl;
		} while (basic_data.participating_players[cur_application_index]->getPlayerEGP() < num_esm);

		cout << " ������� ���� �� ������� �� ������ ������� ��� (�� ���� " << Bank::getMaximumEGPPrice() << " �� ������� ): ";
		cin >> cost_esm;
		cout << endl;
		completed_applications->addNewApplication(num_esm, cost_esm, basic_data.participating_players[cur_player_index]);

		cur_player_index = ++cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << " ������ ������� � ������������. ";
		Sleep(1000);
	}
	return completed_applications;
}
void PrintConsole::sixthAct(BasicData& basic_data) {
	system("cls");
	printHead(basic_data);

	cout << "\t\t\t\t\t\t  ����������� ��������\n";
	cout << "\t\t\t\t\t\t������� �������� ��������\n";

	int cur_player_index{ basic_data.senior_player_number };
	do
	{
		cur_player_index = cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << " ���������� ����� - " << basic_data.participating_players[cur_player_index]->getName() << endl;
		printDisappearingMessage(" ���������� ���������� ����������. ��������. ", 3000);

		if (basic_data.participating_players[cur_player_index]->player_credits->getSize() == 0)
			cout << " � ������ " << basic_data.participating_players[cur_player_index]->getName() << " ��� ��������" << endl;
		else {
			basic_data.participating_players[cur_player_index]->payInterestOnTheCredit();
			if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
				cout << " ��������!!! ����� ����� " << cur_player_index + 1 << " ��� ������ " << basic_data.participating_players[cur_player_index]->getName() <<
					" ����������� ��������� � �������� �� ����\n";
				basic_data.participating_players.playerRemoval(cur_player_index);
			}
			else {
				cout << " ����� ����� " << cur_player_index + 1 << " ��� ������ " << basic_data.participating_players[cur_player_index]->getName() << " �������� ������� ������� �� ���� ��������\n";
			}
		}
		cout << endl;
	} while (basic_data.senior_player_number != (basic_data.participating_players.getNextPlayerIndex(basic_data.participating_players, cur_player_index++)));

	system("cls");
	printPlayerResources(basic_data);
	system("pause");
}
void PrintConsole::seventhAct(BasicData& basic_data) {
	system("cls");
	printHead(basic_data);

	cout << "\t\t\t\t\t\t  ����������� ��������\n";
	cout << "\t\t\t\t\t\t    ��������� �������\n";

	int cur_player_index{ basic_data.senior_player_number };
	do
	{
		cur_player_index = cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << " ��������� ������� ����� " << cur_player_index + 1 << "  ������� - " << basic_data.participating_players[cur_player_index]->getName() << endl;
		printDisappearingMessage(" ���������� ���������� ����������. ��������. ", 3000);

		if (basic_data.participating_players[cur_player_index]->player_credits->getSize() == 0)
			cout << " � ������ " << basic_data.participating_players[cur_player_index]->getName() << " ��� ��������" << endl;
		else {

			for (int i = 0; i < basic_data.participating_players[cur_player_index]->player_credits->getSize(); i++)
			{
				if (basic_data.participating_players[cur_player_index]->player_credits->getCredit(i)->getCreditPeriod() > 0) {
					cout << " ���� " << i + 1 << "-�� ������� � ������ " << basic_data.participating_players[cur_player_index]->getName() << " ��� �� �����" << endl;
				}
				else {
					basic_data.participating_players[cur_player_index]->creditRepayment(i);
					cout << " � ������ " << basic_data.participating_players[cur_player_index]->getName() << " �������� ������ ����� " << i + 1 << endl;
				}
			}

			if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
				cout << " ��������!!! ����� �����" << cur_player_index + 1 << " ��� ������ " << basic_data.participating_players[cur_player_index]->getName() <<
					" ����������� ��������� � �������� �� ����\n";
				basic_data.participating_players.playerRemoval(cur_player_index);
			}
			else {
				cout << " ����� - " << basic_data.participating_players[cur_player_index]->getName() << " ������� ������� ������" << endl;
			}
		}
		cout << endl;
	} while (basic_data.senior_player_number != (basic_data.participating_players.getNextPlayerIndex(basic_data.participating_players, cur_player_index++)));

	system("cls");
	printPlayerResources(basic_data);
	system("pause");
}
void PrintConsole::eighthAct(BasicData& basic_data) {
	system("cls");
	printHead(basic_data);

	cout << "\t\t\t\t\t\t  ����������� ��������\n";
	cout << "\t\t\t\t\t\t    ��������� �������\n";
	cout << endl;
	int cur_player_index{ basic_data.senior_player_number };
	do
	{
		cur_player_index = cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << " ����� " << basic_data.participating_players[cur_player_index]->getName() << ". ������� ����� ������ � �����? (y - ��, n-���): ";
		char choice{ char() };
		do
		{
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				int credit_amount{ 0 };
				do
				{
					cout << " ������� ����� ������� �� ������ ����� � ������: ";
					cin >> credit_amount;
					cout << endl;

					if (basic_data.participating_players[cur_player_index]->creditRequirementsAreMet(credit_amount)) {
						basic_data.participating_players[cur_player_index]->borrowFromTheBank(credit_amount);
						cout << " ��� ������� ������ �� ����� " << credit_amount << ", ������ �� 12 �������" << endl;
					}
					else {
						cout << " ������������� ���� ����� ��������� �����, ������������� ��� ��� ������ ��� ����� 0" << endl;
					}
				} while (!basic_data.participating_players[cur_player_index]->creditRequirementsAreMet(credit_amount));
			}
			else if (choice == 'n' || choice == 'N') {

				cout << " ����� - " << basic_data.participating_players[cur_player_index]->getName() << " ��������� �� �������." << endl;
				continue;
			}
			else cout << " ������ �� ���������� ������" << endl;
		} while (!((choice == 'y' || choice == 'Y') || (choice == 'n' || choice == 'N')));
		Sleep(1000);
		cout << endl;
		cur_player_index++;
	} while (basic_data.senior_player_number != (basic_data.participating_players.getNextPlayerIndex(basic_data.participating_players, cur_player_index - 1)));

	system("cls");
	printPlayerResources(basic_data);
	system("pause");
}
void PrintConsole::ninthAct(BasicData& basic_data) {
	system("cls");
	printHead(basic_data);

	cout << "\t\t\t\t\t\t  ����������� ��������\n";
	cout << "\t\t\t\t\t   ������ �� ������������� �������\n";
	cout << endl;
	int cur_player_index{ basic_data.senior_player_number };

	do
	{
		cur_player_index = cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << " ����� - " << basic_data.participating_players[cur_player_index]->getName() << ". ������� ������ ������������� �������? (y - ��, n-���): ";
		char choice{ char() };
		do
		{
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				int object_type{ 0 };
				do
				{
					cout << " ������� ������������ ����� (1 - ������� �������, 2 - ������������������ �������, 3 - ������������� ������� �������): ";
					cin >> object_type;
					cout << endl;

					if (object_type == 1 || object_type == 2 || object_type == 3) {
						basic_data.participating_players[cur_player_index]->orderTheConstructionOfFactory(object_type);
						cout << " ����� ����� " << rusNameObjectForPartNine(object_type) << ", ������ �� " << basic_data.participating_players[cur_player_index]->player_construction->getTheLastConstructionSiteAdded()->getConstructionPeriod() << " �������" << endl;
					}
					else {
						cout << " ������ �� ���������� ������" << endl;
					}
				} while (!(object_type == 1 || object_type == 2 || object_type == 3 || object_type == 0));

			}
			else cout << " ����� ������������ �� �������������" << endl;

		} while (!((choice == 'y' || choice == 'Y') || (choice == 'n' || choice == 'N')));

		if (basic_data.participating_players[cur_player_index]->player_construction->getSize()) {
			
			basic_data.participating_players[cur_player_index]->paymentForTheSecondPartOfTheConstruction();
			if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
				cout << "��������!!! ����� - " << basic_data.participating_players[cur_player_index]->getName() <<
					" ����������� ��������� � �������� �� ���� ��-�� ���������� ������� ��� ������ ������ ����� �������\n";
				basic_data.participating_players.playerRemoval(cur_player_index);
			}
			else {
				cout << "����������, ������������� ��������" << endl;
				Sleep(2000);
			}
		}

		Sleep(1000);
		cout << endl;
		cur_player_index++;
	} while (basic_data.senior_player_number != (basic_data.participating_players.getNextPlayerIndex(basic_data.participating_players, cur_player_index - 1)));

	system("cls");
	printPlayerResources(basic_data);
	system("pause");
}
string PrintConsole::rusNameObjectForPartNine(int object_type) {
	switch (object_type)
	{
	case 1:
		return "������������� ������� �������";
		break;
	case 2:
		return "������������� ������������������ �������";
		break;
	case 3:
		return "������������� ������� �������";
		break;

	default:
		break;
	}
}

void PrintConsole::updateBasicData(BasicData& basic_data) {
	for (int player_index = 0; player_index < basic_data.participating_players.getNumber(); player_index++) {
		for (int credit_index = 0; credit_index < basic_data.participating_players[player_index]->player_credits->getSize(); credit_index++) {
			basic_data.participating_players[player_index]->player_credits->getCredit(credit_index)->recalculateTheCreditPeriod();
		}
	}
	for (int player_index = 0; player_index < basic_data.participating_players.getNumber(); player_index++) {
		for (int building_site_index = 0; building_site_index < basic_data.participating_players[player_index]->player_construction->getSize(); building_site_index++) {
			basic_data.participating_players[player_index]->player_construction->getBuildingSite(building_site_index)->recalculateTheConstructionPeriod();
		}
	}
	basic_data.month_number++;
	basic_data.number_of_players = basic_data.participating_players.getNumber();
	basic_data.senior_player_number = getSeniorPlayerNumber(basic_data);
	Bank::updateSupplyLevel();
}
void PrintConsole::printFinalResult(BasicData& basic_data) {
	system("cls");
	if (basic_data.participating_players.getNumber() == 0) {
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t���� ����������� ������" << endl;
		cout << endl << endl << endl << endl << endl;
	}
	else {
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t����� ��� ������ " << basic_data.participating_players[0]->getName() << " ������� ������!!!" << endl << endl;
		cout << "\t���������� ������� ������ " << basic_data.participating_players[0]->getNumberOfUsualFactories() << endl;
		cout << "\t���������� ������������������ ������ " << basic_data.participating_players[0]->getNumberOfAutomatedFactory() << endl;
		cout << "\t���������� ��� � ������ " << basic_data.participating_players[0]->getPlayerESM() << endl;
		cout << "\t���������� ��� � ������ " << basic_data.participating_players[0]->getPlayerEGP() << endl;
		cout << "\t���������� �������� ����� � ������ " << basic_data.participating_players[0]->getCash() << endl;
		if (basic_data.participating_players[0]->player_credits->getSize() == 0)
			cout << "\t������� �����������" << endl;
		else {
			for (int credit_index = 0; credit_index < basic_data.participating_players[0]->player_credits->getSize(); credit_index++) {
				cout << "\t������ %" << credit_index + 1 << " �� ����� " << basic_data.participating_players[0]->player_credits->getCredit(credit_index)->getCreditAmount() <<
					", ��������� ������� ���������� �����" << basic_data.participating_players[0]->player_credits->getCredit(credit_index)->getCreditPeriod() << " �������" << endl;
			}
		}
		if (basic_data.participating_players[0]->player_construction->getSize() == 0)
			cout << "\t������� �����������" << endl;
		else {
			for (int �onstruction_index = 0; �onstruction_index < basic_data.participating_players[0]->player_construction->getSize(); �onstruction_index++) {
				cout << "\t������� #" << �onstruction_index + 1 << " - " << rusNameObjectForPlayerResourses(basic_data.participating_players[0]->player_construction->getBuildingSite(�onstruction_index)->getObjectType()) << ", ���������� �����" << basic_data.participating_players[0]->player_construction->getBuildingSite(�onstruction_index)->getConstructionPeriod() << " �����" << endl;
			}
		}
		cout << endl << endl;
		system("pause");
	}

}
bool PrintConsole::victoryNotAchieved(BasicData& basic_data) {
	return basic_data.participating_players.getNumber() >= 1;
}

int PrintConsole::getSeniorPlayerNumber(BasicData& basic_data) {
	return basic_data.month_number % basic_data.number_of_players;
}
void PrintConsole::fulfilmentOfApplicationsEGPs(BasicData& basic_data, ApplicationList& application_list) {
	for (int i = 0; i < application_list.getNumberOfApplictions(); i++)
	{
		cout << " ������ �������� ������ - " << application_list[i]->getApplicant() << endl;
		cout << " �� ������� ��� � ����������: " << application_list[i]->getNumberOfUnitsRequested() << endl;
		cout << " �� ���� �� �������: " << application_list[i]->getPricePerUnit() << endl << endl;
		printDisappearingMessage(" ���������� ���������� ����������. �������� ", 4000);
		cout << "��������� ������� ���������. " << endl << endl;
		application_list.getPlayer(i)->EGPapplicationExecution(application_list[i]);
	}
}
Player* PrintConsole::findApplicant(BasicData& basic_data, int& current_number_of_applicant, Application* approved_applications, int number_of_applications) {
	for (int i = 0; i < number_of_applications; i++)
	{
		for (int j = 0; j < basic_data.participating_players.getNumber(); j++)
		{
			if (approved_applications[i].getApplicant() == basic_data.participating_players[j]->getName()) {
				current_number_of_applicant = j;
				return basic_data.participating_players[j];
			}
		}
	}
}
bool PrintConsole::isDivisibleByTwo(int value) {
	return value % 2 == 0;
}