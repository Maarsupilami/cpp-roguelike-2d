#pragma once
#include <functional>
#include <memory>
#include <vector>
#include <cstdlib>
#include "item.h"

struct LootEntry {
    float weight;
    std::function<std::unique_ptr<Item>()> factory;
};

class LootTable {
    private:
        std::vector<LootEntry> entries;
        float totalWeight = 0.0f;

    public:
        void add(float weight, std::function<std::unique_ptr<Item>()> factory) {
            entries.push_back({ weight, std::move(factory) });
            totalWeight += weight;
        };

        void addNothing(float weight) {
            entries.push_back({ weight, nullptr });
            totalWeight += weight;
        };

        std::unique_ptr<Item> roll() {
            if (entries.empty()) { return nullptr; };
            float r = (float)rand() / RAND_MAX * totalWeight;

            float cumulative = 0.0f;
            for (const auto& entry : entries) {
                cumulative += entry.weight;
                if (r <= cumulative) {
                    return entry.factory ? entry.factory() : nullptr;
                }
            }
            // Fallback: floating point edge case
            const auto& last = entries.back();
            return last.factory ? last.factory() : nullptr;
        };
};