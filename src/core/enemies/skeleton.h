#pragma once
#include "enemy.h"
#include "game_constants.h"
#include "items/potion.h"
#include "items/magic_scroll.h"
#include "items/weapon_types/sword/iron_sword.h"

class Skeleton : public Enemy{
    public:
        Skeleton(std::string name)
            :   Enemy(
                    name,
                    SKELETON_STATS.hp,
                    SKELETON_STATS.attack,
                    SKELETON_STATS.defense,
                    SKELETON_STATS.expReward,
                    SKELETON_STATS.goldReward
                ) {
                    lootTable.addNothing(70.0f);
                    lootTable.add(20.0f, [] { return std::make_unique<HealthPotion>(); });
                    lootTable.add(10.0f, [] { return std::make_unique<IronSword>(); });
                    lootTable.add(5.0f, [] { return std::make_unique<MagicScroll>(); });
                }
};