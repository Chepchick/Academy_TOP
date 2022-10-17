#include <iostream>
#include "MedalRow.h"
#include "MedalTable.h"


int main()
{
	setlocale(LC_ALL, "ru");
	MedalsTable mt1(12);
	std::cout << "Medals table #1:\n";
	mt1["RUS"][MedalRow::GOLD] = 10;
	mt1["RUS"][MedalRow::SILVER] = 5;
	mt1["RUS"][MedalRow::BRONZE] = 8;
	mt1["ENG"][MedalRow::GOLD] = 3;
	mt1["ENG"][MedalRow::SILVER] = 8;
	mt1["ENG"][MedalRow::BRONZE] = 4;
	mt1["AUD"][MedalRow::GOLD] = 4;
	mt1["AUD"][MedalRow::SILVER] = 2;
	mt1["AUD"][MedalRow::BRONZE] = 9;
	std::cout << mt1;
	std::cout << "\nMedals table #2:\n";
	const MedalsTable mt2{ mt1 };
	std::cout << mt2;
	// раскомментировав следующую строку можно протестировать
	// проверку отсутствия страны в константной таблице
	// медалей
	// программа аварийно завершиться, что нормально!
	/*std::cout << mt2["SLO"];*/

	std::cout << "У " << mt1["RUS"].getCountry()<< " больше всего " << mt1("RUS") << " медалей" << std::endl;
	std::cout << "У " << mt1["ENG"].getCountry() << " больше всего " << mt1("ENG") << " медалей" << std::endl;
	std::cout << "У " << mt1["AUD"].getCountry() << " больше всего " << mt1("AUD") << " медалей" << std::endl;

	return 0;
}