#pragma once
#include "item.h"

class Enemy;

enum class WeaponType {
    SWORD
};

class Weapon : public Item {
    protected:
        WeaponType weaponType;
        int value;
    public:
        Weapon(std::string name, WeaponType weaponType, int value)
            :   Item(name, ItemType::WEAPON),
                value(value),
                weaponType(weaponType) {};
        WeaponType getWeaponType() const { return weaponType; };
        int getValue() const { return value; };
        virtual void use(Player& player, Enemy* enemy = nullptr) = 0;
        virtual ~Weapon() = default;
};