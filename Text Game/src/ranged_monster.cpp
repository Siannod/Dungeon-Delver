#pragma once
#include "ranged_monster.h"

void RangedMonster::create_monster(PlayerStats* player_stats)
{
	stats.name = "Ranged";
	stats.range = 5;
	stats.MAX_HEALTH = player_stats->MAX_HEALTH + random(5, 12 + (player_stats->level) + player_stats->stats.at("Dexterity"));
	stats.health = stats.MAX_HEALTH;
	stats.damage.push_back(random(6, 8 + player_stats->level));
}