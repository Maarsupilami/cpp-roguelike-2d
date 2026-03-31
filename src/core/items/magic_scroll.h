#pragma once
#include "item.h"
#include "player.h"
#include "enemy.h"

class MagicScroll : public Item {
    private:
        int damage = 25;
    public:
        MagicScroll() : Item("Magic Scroll", ItemType::SCROLL) {};

        std::string getDescription() const override { return "(deals 25 damage)"; }

        void use(Player& player, Enemy* enemy) override {
            if (enemy != nullptr) {
                enemy->takeDamage(damage);
            }
        };
};