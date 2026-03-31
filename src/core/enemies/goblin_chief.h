#pragma once
#include "enemy.h"
#include "game_constants.h"
#include "items/potion.h"
#include "items/magic_scroll.h"
#include "items/weapon_types/sword/iron_sword.h"

class GoblinChief : public Enemy{
    public:
        GoblinChief(std::string name)
            :   Enemy(
                    name,
                    GOBLIN_CHIEF_STATS.hp,
                    GOBLIN_CHIEF_STATS.attack,
                    GOBLIN_CHIEF_STATS.defense,
                    GOBLIN_CHIEF_STATS.expReward,
                    GOBLIN_CHIEF_STATS.goldReward
                ) {
                    lootTable.addNothing(70.0f);
                    lootTable.add(20.0f, [] { return std::make_unique<HealthPotion>(); });
                    lootTable.add(10.0f, [] { return std::make_unique<IronSword>(); });
                    lootTable.add(5.0f, [] { return std::make_unique<MagicScroll>(); });
                }
};