#pragma once
#include <limits>

// Common constants
constexpr unsigned int MAX_GOLD = std::numeric_limits<unsigned int>::max();

struct PlayerStats {
    int hp;
    int attack;
    int defense;
    float crit;
};

struct EnemyStats {
    int hp;
    int attack;
    int defense;
    int expReward;
    unsigned int goldReward;
};

/*
    Player stats
*/
// hp attack defense crit
inline constexpr PlayerStats WARRIOR_STATS  = {120, 12, 8, 0.0f};
inline constexpr PlayerStats MAGE_STATS     = {70, 18, 3, 0.0f};
inline constexpr PlayerStats ROGUE_STATS    = {90, 14, 5, 0.3f};

/*
    Enemy stats
*/
// hp attack defense exp_reward gold_reward
inline constexpr EnemyStats GOBLIN_STATS    = {20, 8, 2, 30, 5};
inline constexpr EnemyStats SKELETON_STATS  = {15, 10, 4, 25, 4};
inline constexpr EnemyStats TROLL_STATS     = {40, 14, 6, 60, 10};

// Boss stats
inline constexpr EnemyStats GOBLIN_CHIEF_STATS      = {50, 12, 5, 80, 15};
inline constexpr EnemyStats STONE_GOLEM_STATS       = {80, 18, 10, 150, 25};
inline constexpr EnemyStats DARK_NECROMANCER_STATS  = {120, 22, 8, 300, 50};

inline constexpr short  IRON_SWORD_DAMAGE   = 5;