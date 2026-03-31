#include "../../weapon.h"

class Sword : public Weapon {
    public:
        Sword(std::string name, int value)
            :   Weapon(name, WeaponType::SWORD, value) {}
};