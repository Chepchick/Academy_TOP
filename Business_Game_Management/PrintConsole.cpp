#include "PrintConsole.h"

char PrintConsole::startMenu() {
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t   ДОБРО ПОЖАЛОВАТЬ В ИГРУ МЕНЕДЖМЕНТ !\n";
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t\t  1 Начать игру\n";
	cout << "\t\t\t\t\t\t  2 Загрузить сохранение\n";
	cout << "\t\t\t\t\t\t  3 Выйти из игры\n";
	cout << endl;
	cout << "\t\t\t\t\t\t(выберите пункт из меню)\n";
	char ch{ char() };
	do {
		ch = _getch();
		if (ch != '1' && ch != '2' && ch != '3') cout << "Введен не корректный символ";
	} while (ch != '1' && ch != '2' && ch != '3');
	return ch;
}
void PrintConsole::startNewGame(BasicData& basic_data) {
	system("cls");
	basic_data.month_number = 0;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\t     НАЧАЛО НОВОЙ ИГРЫ\n";
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t\tУкажите количество игроков: ";
	cin >> basic_data.number_of_players;
	basic_data.senior_player_number = getSeniorPlayerNumber(basic_data);
	cout << "\n\t\t\t\t\tВведите имена участников (английскими буквами) \n";
	string name;
	string admissible{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };

	for (int i = 0; i < basic_data.number_of_players; i++)
	{
		do
		{
			cout << "\t\t\t\t\t\t    Имя " << i + 1 << "-го участника: ";
			cin >> name;
			if (!name.find_first_not_of(admissible)) {
				printDisappearingMessage("\t\t\t\t\t\t    Использованы недопустимые символы", 2000);
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
	cout << "\t\t\t\t\t\t  ТЕКУЩИЙ МЕСЯЦ - " << basic_data.month_number + 1 << "-й\n";
	cout << "\t\t\t\t\t\tстарший игрок - игрок " << basic_data.participating_players[basic_data.senior_player_number]->getName() << endl << endl;
}
void PrintConsole::printPlayerResources(BasicData& basic_data) {
	cout << endl;
	cout << "\t\t\t\t\t\t    РЕСУРСЫ ИГРОКОВ" << endl << endl;
	for (int player_index = 0; player_index < basic_data.participating_players.getNumber(); player_index++)
	{
		cout << " Имя игрока " << basic_data.participating_players[player_index]->getName() << endl;
		cout << " Количество обычных фабрик " << basic_data.participating_players[player_index]->getNumberOfUsualFactories() << endl;
		cout << " Количество автоматезированных фабрик " << basic_data.participating_players[player_index]->getNumberOfAutomatedFactory() << endl;
		cout << " Количество ЕСМ у игрока " << basic_data.participating_players[player_index]->getPlayerESM() << endl;
		cout << " Количество ЕГП у игрока " << basic_data.participating_players[player_index]->getPlayerEGP() << endl;
		cout << " Количество наличных денег у игрока " << basic_data.participating_players[player_index]->getCash() << endl;
		if (basic_data.participating_players[player_index]->player_credits->getSize() == 0)
			cout << " Кредиты отсутствуют" << endl;
		else {
			for (int credit_index = 0; credit_index < basic_data.participating_players[player_index]->player_credits->getSize(); credit_index++) {
				cout << " Кредит #" << credit_index + 1 << " на сумму " << basic_data.participating_players[player_index]->player_credits->getCredit(credit_index)->getCreditAmount() <<
					",погашения кредита произойдет через " << basic_data.participating_players[player_index]->player_credits->getCredit(credit_index)->getCreditPeriod() << " месяцев" << endl;
			}
		}
		if (basic_data.participating_players[player_index]->player_construction->getSize() == 0)
			cout << " Стройки отсутствуют" << endl;
		else {
			for (int сonstruction_index = 0; сonstruction_index < basic_data.participating_players[player_index]->player_construction->getSize(); сonstruction_index++) {
				cout << " Стройка #" << сonstruction_index + 1 << " - " << rusNameObjectForPlayerResourses(basic_data.participating_players[player_index]->player_construction->getBuildingSite(сonstruction_index)->getObjectType()) << ", построится через " << basic_data.participating_players[player_index]->player_construction->getBuildingSite(сonstruction_index)->getConstructionPeriod() << " месяц" << endl;
			}
		}
		cout << endl;
	}
}
string PrintConsole::rusNameObjectForPlayerResourses(int object_type) {
	switch (object_type)
	{
	case 0:
		return "обычная фабрика";
		break;
	case 1:
		return "автоматизированная фабрика";
		break;
	case 2:
		return "реконструкция обычной фабрики";
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
	cout << "\t\t\t\tМЕСЯЦ #" << basic_data.month_number + 1 << " - ОКОНЧЕН" << endl;
	system("pause");
}

void PrintConsole::firstAction(BasicData& basic_data) {
	system("cls");
	printPlayerResources(basic_data);
	system("pause");
	system("cls");
	printHead(basic_data);
	cout << "\t\t\t\t\t\t  ЕЖЕМЕСЯЧНЫЕ ОПЕРАЦИИ\n";
	cout << "\t\t\t\t\t       ВЫПЛАТЫ ПОСТОЯННЫХ ИЗДЕРЖЕК\n";
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
			cout << " ВНИМАНИЕ!!! Игрок номер" << cur_player_index + 1 << " под именем " << basic_data.participating_players[cur_player_index]->getName() <<
				" объявляется банкротом и выбывает из игры\n";
			basic_data.participating_players.playerRemoval(cur_player_index);
		}
		else {
			cout << " Игрок " << basic_data.participating_players[cur_player_index]->getName() << " выплатил ежемесячные издержки\n";
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

	cout << "\t\t\t\t\t\t  ЕЖЕМЕСЯЧНЫЕ ОПЕРАЦИИ\n";
	cout << "\t\t\t\t\t     ОПРЕДЕЛЕНИЕ ОБСТАНОВКИ НА РЫНКЕ\n";
	cout << endl << endl << endl;

	printDisappearingMessage(" Происходит обновление текущего уровня цен. Ожидайте", 3000);

	cout << " Текущий уровень предложения - " << Bank::getCurrentSupplyLevel() << endl << endl;
	Bank::setCurrentPrice(Bank::getCurrentSupplyLevel());

	printDisappearingMessage(" Происходит обновление цен на текущем уровне. Ожидайте", 4000);

	cout << " Количество игроков, которым БАНК может продать ЕСМ - " << Bank::getTheNumberOfESMsSale(Bank::getNumberOfPlayersBuyingECMs()) << endl;
	cout << " Минимальная цена, по которой можно купить ЕСМ у БАНКА - " << Bank::getMinimumESMPrice() << endl;
	cout << " Количество игроков, у которых БАНК может купить ЕГП - " << Bank::getTheNumberOfEGPsBuy(Bank::getNumberOfPlayersSellingEGPs()) << endl;
	cout << " Максимальная цена, по которой можно продать ЕГП БАНКУ - " << Bank::getMaximumEGPPrice() << endl << endl;
	system("pause");
}
void PrintConsole::thirdAct(BasicData& basic_data) {
	system("cls");
	printHead(basic_data);
	cout << "\t\t\t\t\t\t  ЕЖЕМЕСЯЧНЫЕ ОПЕРАЦИИ\n";
	cout << "\t\t\t\t       ЗАЯВКИ НА ПОКУПКУ СЫРЬЯ И МАТЕРИАЛОВ У БАНКА";
	cout << endl << endl;
	cout << " Количество игроков, которым БАНК может продать ЕСМ - " << Bank::getTheNumberOfESMsSale(Bank::getNumberOfPlayersBuyingECMs()) << endl;
	cout << " Минимальная цена, по которой можно купить ЕСМ у БАНКА - " << Bank::getMinimumESMPrice() << endl;
	cout << endl;
	printDisappearingMessage(" Происходит подготовка бумаг для оформления заявок. Ожидайте ", 8000);

	ApplicationList* completed_applications = fillingApplicationsForESM(basic_data);

	system("cls");
	printHead(basic_data);
	cout << endl;
	cout << "\t\t\t\t  ВЫПОЛНЕНИЕ ОБЯЗАТЕЛЬСТВ ПО ЗАЯВКАМ НА СЫРЬЁ И МАТЕРИАЛЫ\n";
	cout << endl;
	printDisappearingMessage(" Происходит обработка заявок Банком. Ожидайте. ", 4000);

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
		cout << "\t\t\t\t\t\t   ЗАПОЛНЕНИЕ ЗАЯВКИ" << std::endl << std::endl;
		cout << "\t\t\t\t\t\t  Заполняет игрок - " << basic_data.participating_players[cur_player_index]->getName() << std::endl;
		cout << "\t\t\t\t\t\t    Ожидание игрока\n\n";
		Sleep(1000);
		int num_egp{ int() };
		int cost_egp{ int() };
		cout << " Внимание!!! Суммарная стоимость покупаемых у Банка ЕСМ, не должна превышать количество наличных на счету у игрока." << endl;
		cout << " В противном случае игрок дисквалифицируется за невозможность оплатить заказ." << endl;
		cout << " Игрок, указавший цену покупки ЕСМ ниже закупочной или количество покупаемых ЕСМ равное 0, не участвует в торгах." << endl << endl << endl;
		cout << " Введите желаемое количество ЕСМ для покупки: ";
		cin >> num_egp;
		cout << " Введите цену по которой вы готовы купить ЕСМ (не ниже " << Bank::getMinimumESMPrice() << " за еденицу ): ";
		cin >> cost_egp;
		completed_applications->addNewApplication(num_egp, cost_egp, basic_data.participating_players[cur_player_index]);

		cur_player_index = ++cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << endl << " Заявка принята к рассмотрению. ";
		Sleep(2000);
	}
	return completed_applications;
}
void PrintConsole::fulfilmentOfApplicationsESMs(BasicData& basic_data, ApplicationList& application_list) {
	for (int i = 0; i < application_list.getNumberOfApplictions(); i++)
	{
		cout << " Заявка одобрена игроку - " << application_list[i]->getApplicant() << endl;
		cout << " На покупку ЕСМ в количестве: " << application_list[i]->getNumberOfUnitsRequested() << endl;
		cout << " По цене за еденицу: " << application_list[i]->getPricePerUnit() << endl;
		printDisappearingMessage(" Происходит выполнение транзакции. Ожидайте ", 4000);

		application_list.getPlayer(i)->ESMapplicationExecution(application_list[i]);
		if (application_list.getPlayer(i)->isBankrupt()) {
			cout << " Тразакция не выполнена из-за недостаточного количества средств на счету игрока." << endl;
			cout << " ИГРОК ОБЪЯВЛЯЕТСЯ БАНКРОТОМ И ДИСКВАЛИФИЦИРУЕТСЯ ИЗ ИГРЫ!!!" << endl << endl;
			basic_data.participating_players.playerRemoval(i);
		}
		else {
			cout << "Тразакция успешно выполнена." << endl << endl;
		}
		Sleep(2000);
	}
	system("pause");
}
void PrintConsole::fourthAct(BasicData& basic_data) {
	system("cls");
	printHead(basic_data);
	cout << "\t\t\t\t\t\t  ЕЖЕМЕСЯЧНЫЕ ОПЕРАЦИИ\n";
	cout << "\t\t\t\t\t    ПРОИЗВОДСТВО ГОТОВОЙ ПРОДУКЦИИ" << endl << endl;
	cout << " Выберете стоимость производства, в зависимости от типа фабрики на которой хотите запустить производство" << endl;
	cout << "  2000 - производство 1 ЕСМ за раз на обычной или автоматезированной фабрике" << endl;
	cout << "  3000 - производство 2 ЕСМ за раз на автоматезированной фабрике" << endl << endl;
	cout << " Выберете количество ЕСМ, которые вы хотите переработать в продукцию." << endl;
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
		cout << "\t\t\t\t\t\t  ЕЖЕМЕСЯЧНЫЕ ОПЕРАЦИИ\n";
		cout << "\t\t\t\t\t    ПРОИЗВОДСТВО ГОТОВОЙ ПРОДУКЦИИ" << endl << endl;
		cout << " Нажмите n, если не желаете производить продукцию в этом месяце" << endl;
		cout << " Игрок - " << basic_data.participating_players[cur_player_index]->getName() << ", выберете стоимость производства продукции (1 - 2000, 2 - 3000) " << endl << endl;


		switch (_getch())
		{
		case '1':
			cout << " Выбрано производство продукции на обычных и автоматезированных фабриках" << endl;
			cout << " Стоимость производства одной ЕГП - 2000" << endl << endl;
			cout << " Количество ЕСМ для переработки не должно превышать имеющегося количества ЕСМ у игрока" << endl;
			number_of_factories = basic_data.participating_players[cur_player_index]->getNumberOfUsualFactories() + basic_data.participating_players[cur_player_index]->getNumberOfAutomatedFactory();
			selected_number_of_ECMs = getSelectedNumberOfECMs(basic_data.participating_players[cur_player_index]);
			the_cost_of_production_in_factory = 2000;

			do
			{
				if (selected_number_of_ECMs <= number_of_factories) {
					basic_data.participating_players[cur_player_index]->setCash(basic_data.participating_players[cur_player_index]->getCash() - (selected_number_of_ECMs * the_cost_of_production_in_factory));
					if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
						cout << "ВНИМАНИЕ!!! Игрок - " << basic_data.participating_players[cur_player_index]->getName() <<
							" объявляется банкротом и выбывает из игры из-за недостатка средств для оплаты производства ЕГП\n";
						basic_data.participating_players.playerRemoval(cur_player_index);
					}
					else {
						cout << "Фабрики игрока успешно произвели " << selected_number_of_ECMs << " ЕГП" << endl;
						Sleep(2000);
					}
					basic_data.participating_players[cur_player_index]->setPlayerESM(basic_data.participating_players[cur_player_index]->getPlayerESM() - selected_number_of_ECMs);
					basic_data.participating_players[cur_player_index]->setPlayerEGP(basic_data.participating_players[cur_player_index]->getPlayerEGP() + selected_number_of_ECMs);
				}
				else {
					cout << "У вас не хватает фабрик для переработки такого количества ЕСМ" << endl;
					Sleep(2000);
					goto BEGIN;
				}
			} while (selected_number_of_ECMs > number_of_factories);

			break;
		case '2':
			cout << " Выбрано производство продукции на автоматезированных фабриках" << endl;
			cout << " Стоимость производства двух ЕГП - 3000" << endl << endl;
			cout << " Количество ЕСМ для переработки не должно превышать имеющегося количества ЕСМ у игрока" << endl;
			do
			{
				selected_number_of_ECMs = getSelectedNumberOfECMs(basic_data.participating_players[cur_player_index]);
				if (!isDivisibleByTwo(selected_number_of_ECMs)) cout << " Выбранное значение не кратно 2" << endl;
			} while (!isDivisibleByTwo(selected_number_of_ECMs));
			number_of_factories = basic_data.participating_players[cur_player_index]->getNumberOfAutomatedFactory();
			selected_number_of_ECMs /= 2;
			the_cost_of_production_in_factory = 3000;

			do
			{
				if (selected_number_of_ECMs <= number_of_factories) {
					basic_data.participating_players[cur_player_index]->setCash(basic_data.participating_players[cur_player_index]->getCash() - (selected_number_of_ECMs * the_cost_of_production_in_factory));
					if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
						cout << "ВНИМАНИЕ!!! Игрок - " << basic_data.participating_players[cur_player_index]->getName() <<
							" объявляется банкротом и выбывает из игры из-за недостатка средств для оплаты производства ЕГП\n";
						basic_data.participating_players.playerRemoval(cur_player_index);
					}
					else {
						cout << "Фабрики игрока успешно произвели " << selected_number_of_ECMs << " ЕГП" << endl;
						Sleep(2000);
					}
					basic_data.participating_players[cur_player_index]->setPlayerESM(basic_data.participating_players[cur_player_index]->getPlayerESM() - selected_number_of_ECMs);
					basic_data.participating_players[cur_player_index]->setPlayerEGP(basic_data.participating_players[cur_player_index]->getPlayerEGP() + selected_number_of_ECMs);
				}
				else {
					cout << "У вас не хватает фабрик для переработки такого количества ЕСМ" << endl;
					Sleep(2000);
					goto BEGIN;
				}
			} while (selected_number_of_ECMs > number_of_factories);

			break;
		case 'n':
		case 'N':
			cout << " В этом месяце игрок - " << basic_data.participating_players[cur_player_index]->getName() << " не производит продукцию" << endl << endl;
			Sleep(2000);
			break;
		default:
			printDisappearingMessage("Введен не корректный символ", 2000);
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
		cout << " Укажите желаемое количество ЕСМ для переработки в ЕГП: ";
		cin >> selected_number_of_ECMs;
		cout << endl;
		if (selected_number_of_ECMs <= player->getPlayerESM() && selected_number_of_ECMs >= 0) {
			return selected_number_of_ECMs;
		}
		else {
			cout << " Введенное количество ЕСМ превышает имеющиеся количество ЕСМ у игрока" << endl;
		}

	} while (selected_number_of_ECMs > player->getPlayerESM());
}
void PrintConsole::fifthAct(BasicData& basic_data) {

	system("cls");
	printHead(basic_data);

	cout << "\t\t\t\t\t\t  ЕЖЕМЕСЯЧНЫЕ ОПЕРАЦИИ\n";
	cout << "\t\t\t\t\tЗАЯВКИ НА ПРОДАЖУ ГОТОВОЙ ПРОДУКЦИИ БАНКУ";
	cout << endl << endl;
	cout << " Количество игроков, у которых БАНК может купить ЕГП - " << Bank::getTheNumberOfEGPsBuy(Bank::getNumberOfPlayersSellingEGPs()) << endl;
	cout << " Максимальная цена, по которой можно продать ЕГП БАНКУ - " << Bank::getMaximumEGPPrice() << endl << endl;
	cout << endl;
	printDisappearingMessage(" Происходит подготовка бумаг для оформления заявок. Ожидайте ", 8000);

	ApplicationList* completed_applications = fillingApplicationsForEGP(basic_data);

	system("cls");
	printHead(basic_data);
	cout << endl;
	cout << "\t\t\t\t  ВЫПОЛНЕНИЕ ОБЯЗАТЕЛЬСТВ ПО ЗАЯВКАМ НА ГОТОВУЮ ПРОДУКЦИЮ\n";
	cout << endl;
	printDisappearingMessage(" Происходит обработка заявок Банком. Ожидайте. ", 4000);

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
		cout << "\t\t\t\t\t\t   ЗАПОЛНЕНИЕ ЗАЯВКИ" << std::endl << std::endl;
		cout << "\t\t\t\t\t\t  Заполняет игрок - " << basic_data.participating_players[cur_player_index]->getName() << std::endl;
		cout << "\t\t\t\t\t\t    Ожидание игрока\n\n";
		Sleep(1000);
		int num_esm{ int() };
		int cost_esm{ int() };
		cout << " Внимание!!! Суммарное количество продаваемых Банку ЕГП, не должно превышать количество имеющихся ЕГП у игрока." << endl;
		cout << " Заявка с ценой продажи ЕГП выше установленной Банком или количеством продаваймых ЕГП равном 0, не участвует в торгах." << endl << endl << endl;
		do
		{
			cout << " Введите желаемое количество ЕГП для продажи: ";
			cin >> num_esm;
			if (basic_data.participating_players[cur_application_index]->getPlayerEGP() < num_esm)
				cout << " Указанное количество ЕСМ превышает количество имеющеесе у игрока" << endl;
		} while (basic_data.participating_players[cur_application_index]->getPlayerEGP() < num_esm);

		cout << " Введите цену по которой вы готовы продать ЕГП (не выше " << Bank::getMaximumEGPPrice() << " за еденицу ): ";
		cin >> cost_esm;
		cout << endl;
		completed_applications->addNewApplication(num_esm, cost_esm, basic_data.participating_players[cur_player_index]);

		cur_player_index = ++cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << " Заявка принята к рассмотрению. ";
		Sleep(1000);
	}
	return completed_applications;
}
void PrintConsole::sixthAct(BasicData& basic_data) {
	system("cls");
	printHead(basic_data);

	cout << "\t\t\t\t\t\t  ЕЖЕМЕСЯЧНЫЕ ОПЕРАЦИИ\n";
	cout << "\t\t\t\t\t\tВЫПЛАТА ССУДНОГО ПРОЦЕНТА\n";

	int cur_player_index{ basic_data.senior_player_number };
	do
	{
		cur_player_index = cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << " Оплачивает игрок - " << basic_data.participating_players[cur_player_index]->getName() << endl;
		printDisappearingMessage(" Происходит выполнение транзакции. Ожидайте. ", 3000);

		if (basic_data.participating_players[cur_player_index]->player_credits->getSize() == 0)
			cout << " У игрока " << basic_data.participating_players[cur_player_index]->getName() << " нет кредитов" << endl;
		else {
			basic_data.participating_players[cur_player_index]->payInterestOnTheCredit();
			if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
				cout << " ВНИМАНИЕ!!! Игрок номер " << cur_player_index + 1 << " под именем " << basic_data.participating_players[cur_player_index]->getName() <<
					" объявляется банкротом и выбывает из игры\n";
				basic_data.participating_players.playerRemoval(cur_player_index);
			}
			else {
				cout << " Игрок номер " << cur_player_index + 1 << " под именем " << basic_data.participating_players[cur_player_index]->getName() << " выплатил ссудный процент по всем кредитам\n";
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

	cout << "\t\t\t\t\t\t  ЕЖЕМЕСЯЧНЫЕ ОПЕРАЦИИ\n";
	cout << "\t\t\t\t\t\t    ПОГАШЕНИЕ КРЕДИТА\n";

	int cur_player_index{ basic_data.senior_player_number };
	do
	{
		cur_player_index = cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << " Погашение кредита номер " << cur_player_index + 1 << "  игроком - " << basic_data.participating_players[cur_player_index]->getName() << endl;
		printDisappearingMessage(" Происходит выполнение транзакции. Ожидайте. ", 3000);

		if (basic_data.participating_players[cur_player_index]->player_credits->getSize() == 0)
			cout << " У игрока " << basic_data.participating_players[cur_player_index]->getName() << " нет кредитов" << endl;
		else {

			for (int i = 0; i < basic_data.participating_players[cur_player_index]->player_credits->getSize(); i++)
			{
				if (basic_data.participating_players[cur_player_index]->player_credits->getCredit(i)->getCreditPeriod() > 0) {
					cout << " Срок " << i + 1 << "-го кредита у игрока " << basic_data.participating_players[cur_player_index]->getName() << " ещё не истек" << endl;
				}
				else {
					basic_data.participating_players[cur_player_index]->creditRepayment(i);
					cout << " У игрока " << basic_data.participating_players[cur_player_index]->getName() << " закрылся кредит номер " << i + 1 << endl;
				}
			}

			if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
				cout << " ВНИМАНИЕ!!! Игрок номер" << cur_player_index + 1 << " под именем " << basic_data.participating_players[cur_player_index]->getName() <<
					" объявляется банкротом и выбывает из игры\n";
				basic_data.participating_players.playerRemoval(cur_player_index);
			}
			else {
				cout << " Игрок - " << basic_data.participating_players[cur_player_index]->getName() << " успешно погасил кредит" << endl;
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

	cout << "\t\t\t\t\t\t  ЕЖЕМЕСЯЧНЫЕ ОПЕРАЦИИ\n";
	cout << "\t\t\t\t\t\t    ПОЛУЧЕНИЕ КРЕДИТА\n";
	cout << endl;
	int cur_player_index{ basic_data.senior_player_number };
	do
	{
		cur_player_index = cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << " Игрок " << basic_data.participating_players[cur_player_index]->getName() << ". Желаете взять кредит в Банке? (y - да, n-нет): ";
		char choice{ char() };
		do
		{
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				int credit_amount{ 0 };
				do
				{
					cout << " Укажите сумму которую вы хотите взять в кредит: ";
					cin >> credit_amount;
					cout << endl;

					if (basic_data.participating_players[cur_player_index]->creditRequirementsAreMet(credit_amount)) {
						basic_data.participating_players[cur_player_index]->borrowFromTheBank(credit_amount);
						cout << " Вам одобрен кредит на сумму " << credit_amount << ", сроком на 12 месяцев" << endl;
					}
					else {
						cout << " Запрашиваемая вами сумма превышает лимит, установленный для вас Банком или равна 0" << endl;
					}
				} while (!basic_data.participating_players[cur_player_index]->creditRequirementsAreMet(credit_amount));
			}
			else if (choice == 'n' || choice == 'N') {

				cout << " Игрок - " << basic_data.participating_players[cur_player_index]->getName() << " отказался от кредита." << endl;
				continue;
			}
			else cout << " Введен не корректный символ" << endl;
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

	cout << "\t\t\t\t\t\t  ЕЖЕМЕСЯЧНЫЕ ОПЕРАЦИИ\n";
	cout << "\t\t\t\t\t   ЗАЯВКИ НА СТРОИТЕЛЬСТВО ФАБРИКИ\n";
	cout << endl;
	int cur_player_index{ basic_data.senior_player_number };

	do
	{
		cur_player_index = cur_player_index < basic_data.participating_players.getNumber() ? cur_player_index : 0;
		cout << " Игрок - " << basic_data.participating_players[cur_player_index]->getName() << ". Желаете начать строительство фабрики? (y - да, n-нет): ";
		char choice{ char() };
		do
		{
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				int object_type{ 0 };
				do
				{
					cout << " Укажите наименование работ (1 - обычная фабрика, 2 - автоматизированная фабрика, 3 - реконструкция обычной фабрики): ";
					cin >> object_type;
					cout << endl;

					if (object_type == 1 || object_type == 2 || object_type == 3) {
						basic_data.participating_players[cur_player_index]->orderTheConstructionOfFactory(object_type);
						cout << " Игрок начал " << rusNameObjectForPartNine(object_type) << ", сроком на " << basic_data.participating_players[cur_player_index]->player_construction->getTheLastConstructionSiteAdded()->getConstructionPeriod() << " месяцев" << endl;
					}
					else {
						cout << " Введен не корректный символ" << endl;
					}
				} while (!(object_type == 1 || object_type == 2 || object_type == 3 || object_type == 0));

			}
			else cout << " Игрок отказывается от строительства" << endl;

		} while (!((choice == 'y' || choice == 'Y') || (choice == 'n' || choice == 'N')));

		if (basic_data.participating_players[cur_player_index]->player_construction->getSize()) {
			
			basic_data.participating_players[cur_player_index]->paymentForTheSecondPartOfTheConstruction();
			if (basic_data.participating_players[cur_player_index]->isBankrupt()) {
				cout << "ВНИМАНИЕ!!! Игрок - " << basic_data.participating_players[cur_player_index]->getName() <<
					" объявляется банкротом и выбывает из игры из-за недостатка средств для оплаты второй части стройки\n";
				basic_data.participating_players.playerRemoval(cur_player_index);
			}
			else {
				cout << "Поздравляю, строительство окончено" << endl;
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
		return "строительство обычной фабрики";
		break;
	case 2:
		return "строительство автоматизированной фабрики";
		break;
	case 3:
		return "реконструкцию обычной фабрики";
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
		cout << "\t\t\t\t\t\tИГРА ЗАКОНЧИЛАСЬ НИЧЬЕЙ" << endl;
		cout << endl << endl << endl << endl << endl;
	}
	else {
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\tИГРОК ПОД ИМЕНЕМ " << basic_data.participating_players[0]->getName() << " ОДЕРЖАЛ ПОБЕДУ!!!" << endl << endl;
		cout << "\tКоличество обычных фабрик " << basic_data.participating_players[0]->getNumberOfUsualFactories() << endl;
		cout << "\tКоличество автоматезированных фабрик " << basic_data.participating_players[0]->getNumberOfAutomatedFactory() << endl;
		cout << "\tКоличество ЕСМ у игрока " << basic_data.participating_players[0]->getPlayerESM() << endl;
		cout << "\tКоличество ЕГП у игрока " << basic_data.participating_players[0]->getPlayerEGP() << endl;
		cout << "\tКоличество наличных денег у игрока " << basic_data.participating_players[0]->getCash() << endl;
		if (basic_data.participating_players[0]->player_credits->getSize() == 0)
			cout << "\tКредиты отсутствуют" << endl;
		else {
			for (int credit_index = 0; credit_index < basic_data.participating_players[0]->player_credits->getSize(); credit_index++) {
				cout << "\tКредит %" << credit_index + 1 << " на сумму " << basic_data.participating_players[0]->player_credits->getCredit(credit_index)->getCreditAmount() <<
					", погашения кредита произойдет через" << basic_data.participating_players[0]->player_credits->getCredit(credit_index)->getCreditPeriod() << " месяцев" << endl;
			}
		}
		if (basic_data.participating_players[0]->player_construction->getSize() == 0)
			cout << "\tСтройки отсутствуют" << endl;
		else {
			for (int сonstruction_index = 0; сonstruction_index < basic_data.participating_players[0]->player_construction->getSize(); сonstruction_index++) {
				cout << "\tСтройка #" << сonstruction_index + 1 << " - " << rusNameObjectForPlayerResourses(basic_data.participating_players[0]->player_construction->getBuildingSite(сonstruction_index)->getObjectType()) << ", построится через" << basic_data.participating_players[0]->player_construction->getBuildingSite(сonstruction_index)->getConstructionPeriod() << " месяц" << endl;
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
		cout << " Заявка одобрена игроку - " << application_list[i]->getApplicant() << endl;
		cout << " На продажу ЕГП в количестве: " << application_list[i]->getNumberOfUnitsRequested() << endl;
		cout << " По цене за еденицу: " << application_list[i]->getPricePerUnit() << endl << endl;
		printDisappearingMessage(" Происходит выполнение транзакции. Ожидайте ", 4000);
		cout << "Тразакция успешно выполнена. " << endl << endl;
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