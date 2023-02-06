#pragma once
#include "PlayerList.h"

static struct BasicData
{
	int month_number{ int() };
	int number_of_players{ int() };
	int senior_player_number{ int() };
	PlayerList participating_players;
};


