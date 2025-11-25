#pragma once
#include "monster.h"
#include "structs.h"


//INHERITED MONSTER CLASS THAT HAS MORE HEALTH AND STRONGER/MORE ATTACKS
class BossMonster : public Monster
{
public:

	void create_monster(PlayerStats* stats) override;

	bool player_in_range(int player_x, int player_y);

	int calculate_damage();

	BossMonster(PlayerStats* stats_ptr, int size, std::vector<std::vector<std::string>>* field_ptr) : Monster(stats_ptr, size, field_ptr)
	{
		
	}

};