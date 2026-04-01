#include <gtest/gtest.h>
#include "classes/warrior.h"
#include "classes/mage.h"
#include "classes/rogue.h"
#include "enemies/goblin.h"
#include "items/potion.h"
#include "items/weapon_types/sword/iron_sword.h"
#include "enemies/skeleton.h"
#include "enemies/troll.h"
#include "enemies/goblin_chief.h"
#include "enemies/stone_golem.h"
#include "enemies/dark_necromancer.h"
#include "game_constants.h"

// ─── Character base behaviour ────────────────────────────────────────────────

TEST(CharacterTest, TakeDamageReducesHp) {
    Warrior w("T");
    w.takeDamage(10);
    EXPECT_EQ(w.getHp(), WARRIOR_STATS.hp - 10);
}

TEST(CharacterTest, HpDoesNotGoBelowZero) {
    Warrior w("T");
    w.takeDamage(9999);
    EXPECT_EQ(w.getHp(), 0);
}

TEST(CharacterTest, HealDoesNotExceedMaxHp) {
    Warrior w("T");
    w.takeDamage(20);
    w.heal(9999);
    EXPECT_EQ(w.getHp(), w.getMaxHp());
}

TEST(CharacterTest, IsAliveAfterPartialDamage) {
    Warrior w("T");
    w.takeDamage(10);
    EXPECT_TRUE(w.isAlive());
}

TEST(CharacterTest, IsDeadAfterFatalDamage) {
    Warrior w("T");
    w.takeDamage(9999);
    EXPECT_FALSE(w.isAlive());
}

// ─── Player classes ──────────────────────────────────────────────────────────

TEST(WarriorTest, InitialStats) {
    Warrior w("Hero");
    EXPECT_EQ(w.getHp(),      WARRIOR_STATS.hp);
    EXPECT_EQ(w.getMaxHp(),   WARRIOR_STATS.hp);
    EXPECT_EQ(w.getAttack(),  WARRIOR_STATS.attack);
    EXPECT_EQ(w.getDefense(), WARRIOR_STATS.defense);
    EXPECT_EQ(w.getLevel(),   1);
}

TEST(MageTest, InitialStats) {
    Mage m("Hero");
    EXPECT_EQ(m.getHp(),      MAGE_STATS.hp);
    EXPECT_EQ(m.getMaxHp(),   MAGE_STATS.hp);
    EXPECT_EQ(m.getAttack(),  MAGE_STATS.attack);
    EXPECT_EQ(m.getDefense(), MAGE_STATS.defense);
    EXPECT_EQ(m.getLevel(),   1);
}

TEST(RogueTest, InitialStats) {
    Rogue r("Hero");
    EXPECT_EQ(r.getHp(),      ROGUE_STATS.hp);
    EXPECT_EQ(r.getMaxHp(),   ROGUE_STATS.hp);
    EXPECT_EQ(r.getAttack(),  ROGUE_STATS.attack);
    EXPECT_EQ(r.getDefense(), ROGUE_STATS.defense);
    EXPECT_EQ(r.getLevel(),   1);
}

TEST(PlayerTest, StartsWithZeroXpAndGold) {
    Warrior w("Hero");
    EXPECT_EQ(w.getExperience(), 0);
    EXPECT_EQ(w.getGold(),       0u);
}

TEST(PlayerTest, AddExperienceAccumulates) {
    Warrior w("Hero");
    w.addExperience(50);
    w.addExperience(30);
    EXPECT_EQ(w.getExperience(), 80);
}

TEST(PlayerTest, AddGoldAccumulates) {
    Warrior w("Hero");
    w.addGold(10);
    w.addGold(5);
    EXPECT_EQ(w.getGold(), 15u);
}

TEST(PlayerTest, LevelUpOnXpThreshold) {
    Warrior w("Hero");
    w.addExperience(100);   // threshold for level 1 -> 2 is 100 * 1
    EXPECT_EQ(w.getLevel(), 2);
}

TEST(PlayerTest, LevelUpIncreasesMaxHp) {
    Warrior w("Hero");
    int hpBefore = w.getMaxHp();
    w.addExperience(100);
    EXPECT_GT(w.getMaxHp(), hpBefore);
}

// ─── Enemies ─────────────────────────────────────────────────────────────────

TEST(GoblinTest, InitialStats) {
    Goblin g("Fallen");
    EXPECT_EQ(g.getHp(),         GOBLIN_STATS.hp);
    EXPECT_EQ(g.getAttack(),     GOBLIN_STATS.attack);
    EXPECT_EQ(g.getDefense(),    GOBLIN_STATS.defense);
    EXPECT_EQ(g.getExpReward(),  GOBLIN_STATS.expReward);
    EXPECT_EQ(g.getGoldReward(), GOBLIN_STATS.goldReward);
}

TEST(SkeletonTest, InitialStats) {
    Skeleton s("Bones");
    EXPECT_EQ(s.getHp(),         SKELETON_STATS.hp);
    EXPECT_EQ(s.getAttack(),     SKELETON_STATS.attack);
    EXPECT_EQ(s.getDefense(),    SKELETON_STATS.defense);
    EXPECT_EQ(s.getExpReward(),  SKELETON_STATS.expReward);
    EXPECT_EQ(s.getGoldReward(), SKELETON_STATS.goldReward);
}

TEST(TrollTest, InitialStats) {
    Troll t("Mauler");
    EXPECT_EQ(t.getHp(),         TROLL_STATS.hp);
    EXPECT_EQ(t.getAttack(),     TROLL_STATS.attack);
    EXPECT_EQ(t.getDefense(),    TROLL_STATS.defense);
    EXPECT_EQ(t.getExpReward(),  TROLL_STATS.expReward);
    EXPECT_EQ(t.getGoldReward(), TROLL_STATS.goldReward);
}

TEST(GoblinChiefTest, InitialStats) {
    GoblinChief gc("Shaman");
    EXPECT_EQ(gc.getHp(),         GOBLIN_CHIEF_STATS.hp);
    EXPECT_EQ(gc.getAttack(),     GOBLIN_CHIEF_STATS.attack);
    EXPECT_EQ(gc.getDefense(),    GOBLIN_CHIEF_STATS.defense);
    EXPECT_EQ(gc.getExpReward(),  GOBLIN_CHIEF_STATS.expReward);
    EXPECT_EQ(gc.getGoldReward(), GOBLIN_CHIEF_STATS.goldReward);
}

TEST(StoneGolemTest, InitialStats) {
    StoneGolem sg("Golem");
    EXPECT_EQ(sg.getHp(),         STONE_GOLEM_STATS.hp);
    EXPECT_EQ(sg.getAttack(),     STONE_GOLEM_STATS.attack);
    EXPECT_EQ(sg.getDefense(),    STONE_GOLEM_STATS.defense);
    EXPECT_EQ(sg.getExpReward(),  STONE_GOLEM_STATS.expReward);
    EXPECT_EQ(sg.getGoldReward(), STONE_GOLEM_STATS.goldReward);
}

TEST(DarkNecromancerTest, InitialStats) {
    DarkNecromancer dn("Malachar");
    EXPECT_EQ(dn.getHp(),         DARK_NECROMANCER_STATS.hp);
    EXPECT_EQ(dn.getAttack(),     DARK_NECROMANCER_STATS.attack);
    EXPECT_EQ(dn.getDefense(),    DARK_NECROMANCER_STATS.defense);
    EXPECT_EQ(dn.getExpReward(),  DARK_NECROMANCER_STATS.expReward);
    EXPECT_EQ(dn.getGoldReward(), DARK_NECROMANCER_STATS.goldReward);
}

TEST(DarkNecromancerTest, SummonSkeletonIsAlive) {
    DarkNecromancer dn("Malachar");
    auto skeleton = dn.summonSkeleton();
    EXPECT_TRUE(skeleton->isAlive());
    EXPECT_EQ(skeleton->getHp(), SKELETON_STATS.hp);
}

// ─── Combat damage range ─────────────────────────────────────────────────────

TEST(CombatTest, WarriorDamageVsGoblinIsInRange) {
    Warrior attacker("T");
    Goblin target("T");
    int dmg = attacker.calculateDamage(target);
    EXPECT_GE(dmg, WARRIOR_STATS.attack - GOBLIN_STATS.defense / 2 - 3);
    EXPECT_LE(dmg, WARRIOR_STATS.attack - GOBLIN_STATS.defense / 2 + 3);
}

TEST(CombatTest, MageDamageVsGoblinIsInRange) {
    Mage attacker("T");
    Goblin target("T");
    int dmg = attacker.calculateDamage(target);
    EXPECT_GE(dmg, MAGE_STATS.attack - GOBLIN_STATS.defense / 2 - 3);
    EXPECT_LE(dmg, MAGE_STATS.attack - GOBLIN_STATS.defense / 2 + 3);
}

TEST(CombatTest, RogueDamageVsGoblinIsNeverNegative) {
    Rogue attacker("T");
    Goblin target("T");
    // run multiple times to account for crit randomness
    for (int i = 0; i < 100; i++) {
        EXPECT_GE(attacker.calculateDamage(target), 0);
    }
}

TEST(CombatTest, RogueCritDamageNeverExceedsDoubleMax) {
    Rogue attacker("T");
    Goblin target("T");
    int maxNormal = ROGUE_STATS.attack - GOBLIN_STATS.defense / 2 + 3;
    for (int i = 0; i < 100; i++) {
        EXPECT_LE(attacker.calculateDamage(target), maxNormal * 2);
    }
}

// ─── Level up stat increases per class ───────────────────────────────────────

TEST(WarriorTest, LevelUpStats) {
    Warrior w("T");
    int atkBefore = w.getAttack();
    int defBefore = w.getDefense();
    w.addExperience(100);
    EXPECT_EQ(w.getAttack(),  atkBefore + 2);
    EXPECT_EQ(w.getDefense(), defBefore + 2);
    EXPECT_EQ(w.getMaxHp(),   WARRIOR_STATS.hp + 10);
}

TEST(MageTest, LevelUpStats) {
    Mage m("T");
    int atkBefore = m.getAttack();
    int defBefore = m.getDefense();
    m.addExperience(100);
    EXPECT_EQ(m.getAttack(),  atkBefore + 4);
    EXPECT_EQ(m.getDefense(), defBefore + 1);
    EXPECT_EQ(m.getMaxHp(),   MAGE_STATS.hp + 7);
}

TEST(RogueTest, LevelUpStats) {
    Rogue r("T");
    int atkBefore = r.getAttack();
    int defBefore = r.getDefense();
    r.addExperience(100);
    EXPECT_EQ(r.getAttack(),  atkBefore + 3);
    EXPECT_EQ(r.getDefense(), defBefore + 1);
    EXPECT_EQ(r.getMaxHp(),   ROGUE_STATS.hp + 8);
}

TEST(PlayerTest, LevelUpHealsToFullHp) {
    Warrior w("T");
    w.takeDamage(50);
    w.addExperience(100);
    EXPECT_EQ(w.getHp(), w.getMaxHp());
}

// ─── Items ───────────────────────────────────────────────────────────────────

TEST(HealthPotionTest, HealsPlayer) {
    Warrior w("T");
    w.takeDamage(50);
    int hpBefore = w.getHp();
    HealthPotion potion;
    potion.use(w);
    EXPECT_EQ(w.getHp(), hpBefore + 30);
}

TEST(HealthPotionTest, DoesNotExceedMaxHp) {
    Warrior w("T");
    w.takeDamage(10);
    HealthPotion potion;
    potion.use(w);
    EXPECT_LE(w.getHp(), w.getMaxHp());
}

TEST(IronSwordTest, EquipsToMainHand) {
    Warrior w("T");
    w.addItem(std::make_unique<IronSword>());
    bool result = w.equip("Iron Sword", SlotType::MainHand);
    EXPECT_TRUE(result);
    EXPECT_NE(w.getEquipped(SlotType::MainHand), nullptr);
}

TEST(IronSwordTest, EquipRemovesFromInventory) {
    Warrior w("T");
    w.addItem(std::make_unique<IronSword>());
    w.equip("Iron Sword", SlotType::MainHand);
    EXPECT_EQ(w.getInventory().size(), 0u);
}

TEST(IronSwordTest, EquipFailsIfNotInInventory) {
    Warrior w("T");
    bool result = w.equip("Iron Sword", SlotType::MainHand);
    EXPECT_FALSE(result);
}

TEST(IronSwordTest, SwapWeaponPutsOldBackInInventory) {
    Warrior w("T");
    w.addItem(std::make_unique<IronSword>());
    w.equip("Iron Sword", SlotType::MainHand);
    w.addItem(std::make_unique<IronSword>());
    w.equip("Iron Sword", SlotType::MainHand);
    EXPECT_EQ(w.getInventory().size(), 1u);
}

// ─── Stacking inventory ───────────────────────────────────────────────────────

TEST(InventoryTest, PotionsStackOnAdd) {
    Warrior w("T");
    w.addItem(std::make_unique<HealthPotion>());
    w.addItem(std::make_unique<HealthPotion>());
    EXPECT_EQ(w.getInventory().size(), 1u);
    EXPECT_EQ(w.getInventory()[0]->getQuantity(), 2);
}

TEST(InventoryTest, WeaponsDoNotStack) {
    Warrior w("T");
    w.addItem(std::make_unique<IronSword>());
    w.addItem(std::make_unique<IronSword>());
    EXPECT_EQ(w.getInventory().size(), 2u);
}

TEST(InventoryTest, UseItemDecrementsQuantity) {
    Warrior w("T");
    w.takeDamage(50);
    w.addItem(std::make_unique<HealthPotion>());
    w.addItem(std::make_unique<HealthPotion>());
    w.useItem(0);
    EXPECT_EQ(w.getInventory().size(), 1u);
    EXPECT_EQ(w.getInventory()[0]->getQuantity(), 1);
}

TEST(InventoryTest, UseLastPotionRemovesFromInventory) {
    Warrior w("T");
    w.takeDamage(50);
    w.addItem(std::make_unique<HealthPotion>());
    w.useItem(0);
    EXPECT_EQ(w.getInventory().size(), 0u);
}

TEST(InventoryTest, UseItemOutOfRangeReturnsFalse) {
    Warrior w("T");
    EXPECT_FALSE(w.useItem(0));
}