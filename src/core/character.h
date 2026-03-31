#pragma once            // prevents the file being included twice
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

class Character{
    protected:
        std::string name;
        int level;
        int hp;
        int maxHp;
        int attackPower;
        int defense;

    public:
        Character(std::string name, int hp, int attackPower, int defense)
            :   name(name),
                level(1),
                hp(hp),
                maxHp(hp),
                attackPower(attackPower),
                defense(defense) {}

        bool isAlive() const { return hp > 0; }

        void takeDamage(int amount) {
            hp = std::max(0, hp - amount);
        }

        void heal(int amount) {
            hp = std::min(maxHp, hp + amount);
        }

        void addAttack(int amount) {
            attackPower += amount;
        }

        void printHpBar() const {
            int barWidth = 10;
            int filled = (hp * barWidth) / maxHp;
            std::cout << name << " [";
            for (int i = 0; i < barWidth; i++)
                std::cout << (i < filled ? '#' : '-');
            std::cout << "] " << hp << "/" << maxHp << " HP\n";
        }

        std::string getName() const { return name; }
        int getLevel() const { return level; }
        int getHp() const { return hp; }
        int getMaxHp() const { return maxHp; }
        int getAttack() const { return attackPower; }
        int getDefense() const { return defense; }

        virtual int calculateDamage(const Character& target) const {
            return attackPower - (target.getDefense() / 2) + (rand() % 7 - 3);
        }

        virtual ~Character() = default;
};
