#pragma once
#include <string>

class Player;
class Enemy;

enum class ItemType {
    POTION,
    WEAPON,
    ARMOR,
    SCROLL
};

class Item{
    protected:
        std::string name;
        ItemType itemType;
        int quantity = 1;

    public:
        Item(std::string name, ItemType itemType)
            :   name(name), itemType(itemType) {}

        std::string getName() { return name; };
        ItemType getItemType() const { return itemType; };
        int getQuantity() const { return quantity; };
        void addQuantity(int amount) { quantity += amount; };
        virtual std::string getDescription() const { return ""; };
        virtual void use(Player& player, Enemy* enemy = nullptr) = 0;
        virtual ~Item() = default;
};