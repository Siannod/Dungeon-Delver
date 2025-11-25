#pragma once
#include "monster.h"

class RangedMonster : public Monster
{
public:

	void create_monster(PlayerStats* stats) override;

	RangedMonster(PlayerStats* stats_ptr, int size, std::vector<std::vector<std::string>>* field_ptr) : Monster(stats_ptr, size, field_ptr)
	{

	}
};