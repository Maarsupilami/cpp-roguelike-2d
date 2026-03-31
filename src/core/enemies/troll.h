#pragma once
#include "enemy.h"
#include "game_constants.h"
#include "items/potion.h"
#include "items/magic_scroll.h"
#include "items/weapon_types/sword/iron_sword.h"

class Troll : public Enemy {
    public:
        Troll(std::string name)
            :   Enemy(
                    name,
                    TROLL_STATS.hp,
                    TROLL_STATS.attack,
                    TROLL_STATS.defense,
                    TROLL_STATS.expReward,
                    TROLL_STATS.goldReward
                ) {
                    lootTable.addNothing(70.0f);
                    lootTable.add(20.0f, [] { return std::make_unique<HealthPotion>(); });
                    lootTable.add(10.0f, [] { return std::make_unique<IronSword>(); });
                    lootTable.add(5.0f, [] { return std::make_unique<MagicScroll>(); });
                }
};