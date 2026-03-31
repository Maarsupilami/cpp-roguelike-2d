#pragma once
#include "player.h"
#include "game_constants.h"
#include <cstdlib>

class Rogue : public Player {
    private:
        void levelUp() override {
            level++;
            maxHp += 8;
            hp = maxHp;
            attackPower += 3;
            defense += 1;
            critChance *= 1.05;
            std::cout << name << " leveled up! Now level " << level << "!\n"; 
        }

    public:
        Rogue(std::string name)
            :   Player(
                    name,
                    ROGUE_STATS.hp,
                    ROGUE_STATS.attack,
                    ROGUE_STATS.defense,
                    ROGUE_STATS.crit) {}
        
        int calculateDamage(const Character& target) const override {
            int baseDamage = attackPower - (target.getDefense() / 2) + (rand() % 7 - 3);
            float roll = (float)rand() / RAND_MAX;
            if (roll < critChance) return baseDamage * 2;
            return baseDamage;
        }
};