#pragma once
#include "monster.h"
#include "structs.h"

class BossMonster : public Monster
{


	void create_monster(PlayerStats* stats) override;
};