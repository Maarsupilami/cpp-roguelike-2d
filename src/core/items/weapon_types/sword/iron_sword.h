#pragma once
#include "sword.h"
#include "player.h"
#include "game_constants.h"

class IronSword : public Sword {
    protected:
        SlotType slotType = SlotType::MainHand;
        
    public:
        IronSword()
            :   Sword(
                    "Iron Sword",
                    IRON_SWORD_DAMAGE) {};
        
        void use(Player& player, Enemy* enemy = nullptr) {
            player.equip(name, slotType);
        };
};