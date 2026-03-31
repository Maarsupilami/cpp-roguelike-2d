#pragma once
#include "player.h"
#include "game_constants.h"

class Warrior : public Player {
    private:
        void levelUp() override {
            level++;
            maxHp += 10;
            hp = maxHp;
            attackPower += 2;
            defense += 2;
            std::cout << name << " leveled up! Now level " << level << "!\n"; 
        }

    public:
        Warrior(std::string name)
            :   Player(
                    name,
                    WARRIOR_STATS.hp,
                    WARRIOR_STATS.attack,
                    WARRIOR_STATS.defense,
                    WARRIOR_STATS.crit) {}
};