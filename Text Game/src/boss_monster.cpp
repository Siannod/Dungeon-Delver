#pragma once
#include "boss_monster.h"

void BossMonster::create_monster(PlayerStats* player_stats) 
{
	int level = (*player_stats).level;
	//HEALTH
	stats.name = "boss";
	stats.MAX_HEALTH = player_stats->MAX_HEALTH + random(10, 15 * (player_stats->level) + player_stats->stats.at("Strength"));
	stats.health = stats.MAX_HEALTH;
	stats.MAX_MOVES = 7;
	stats.moves_left = stats.MAX_MOVES;
	stats.range = 1;
	//DAMAGE
	stats.damage.push_back(random(5 + player_stats->level, 8 + player_stats->level)); //CALCULATE MELEE DAMAGE
	stats.damage.push_back(random(4 + player_stats->level, 6 + player_stats->level)); //CALCULATE RANGED DAMAGE
}

bool BossMonster::player_in_range(int player_x, int player_y)
{
	diff.x = abs(player_x - monster.x);
	diff.y = abs(player_y - monster.y);
	if ((diff.x <= 2 * 5 && diff.y == 0) || (diff.x == 0 && diff.y <= 1 * 5)) //BOSS HAS RANGED AND MELEE ATTACKS
	{
		return true;
	}
	return false;
}

int BossMonster::calculate_damage()
{
	int damage = 0;
	if (diff.x == 2 || diff.y == 1) //PLAYER IN MELEE RANGE
	{
		damage = random(2, stats.damage[0]);
		return damage;
	}
	else //PLAYER IN RANGED RANGE
	{
		damage = random(2, stats.damage[1]);
		return damage;
	}
}