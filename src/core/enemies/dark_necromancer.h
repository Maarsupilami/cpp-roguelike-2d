#pragma once
#include "enemy.h"
#include "game_constants.h"
#include "items/magic_scroll.h"
#include "skeleton.h"
#include <memory>
#include "items/potion.h"
#include "items/weapon_types/sword/iron_sword.h"

class DarkNecromancer : public Enemy{
    public:
        DarkNecromancer(std::string name)
            :   Enemy(
                    name,
                    DARK_NECROMANCER_STATS.hp,
                    DARK_NECROMANCER_STATS.attack,
                    DARK_NECROMANCER_STATS.defense,
                    DARK_NECROMANCER_STATS.expReward,
                    DARK_NECROMANCER_STATS.goldReward
                ) {
                    lootTable.addNothing(70.0f);
                    lootTable.add(20.0f, [] { return std::make_unique<HealthPotion>(); });
                    lootTable.add(10.0f, [] { return std::make_unique<IronSword>(); });
                    lootTable.add(5.0f, [] { return std::make_unique<MagicScroll>(); });
                }
        
        std::unique_ptr<Enemy> summonSkeleton() {
            return std::make_unique<Skeleton>("Bone Warrior");
        }
};