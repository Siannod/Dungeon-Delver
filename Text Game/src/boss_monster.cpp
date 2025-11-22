#pragma once
#include "boss_monster.h"

void BossMonster::create_monster(PlayerStats* player_stats)
{
	int level = (*player_stats).level;
	//HEALTH
	stats.MAX_HEALTH = player_stats->MAX_HEALTH + random(3, 10 * (player_stats->level) + player_stats->stats.at("Strength"));
	stats.health = stats.MAX_HEALTH;
	//RANGE
	int temp = random(0, 1);
	if (temp == 0)
	{
		stats.range = 1;
	}
	else
	{
		stats.range = 7;
	}
	//DAMAGE
	if (stats.range == 1)
	{
		stats.damage = random(3, 6 + player_stats->level);
	}
	else
	{
		stats.damage = random(2, 4 + player_stats->level);
	}
}