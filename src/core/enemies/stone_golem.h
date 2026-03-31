#pragma once
#include "enemy.h"
#include "game_constants.h"
#include "items/potion.h"
#include "items/magic_scroll.h"
#include "items/weapon_types/sword/iron_sword.h"

class StoneGolem : public Enemy{
    public:
        StoneGolem(std::string name)
            :   Enemy(
                    name,
                    STONE_GOLEM_STATS.hp,
                    STONE_GOLEM_STATS.attack,
                    STONE_GOLEM_STATS.defense,
                    STONE_GOLEM_STATS.expReward,
                    STONE_GOLEM_STATS.goldReward
                ) {
                    lootTable.addNothing(70.0f);
                    lootTable.add(20.0f, [] { return std::make_unique<HealthPotion>(); });
                    lootTable.add(10.0f, [] { return std::make_unique<IronSword>(); });
                    lootTable.add(5.0f, [] { return std::make_unique<MagicScroll>(); });
                }
};