#ifndef MEMBER_H
#define MEMBER_H

#include <concepts>
#include <algorithm>

#include "treasure.h"

#define MAX_EXPEDITIONS 25

template<std::integral ValueType, bool IsArmed>
class Adventurer;

template<std::integral ValueType>
using Explorer = Adventurer<ValueType, false>;

template<std::integral ValueType>
class Adventurer<ValueType, false> {
public:
    using strength_t = uint32_t;

private:
    ValueType looted = 0;

public:
    static constexpr const bool isArmed = false;

    constexpr Adventurer<ValueType, false>() {};

    template<bool isTrapped>
    constexpr void loot(Treasure<ValueType, isTrapped>&& treasure) {
        if constexpr (!isTrapped)
        looted += treasure.getLoot();
    }

    constexpr ValueType pay() {
        ValueType tmp = looted;
        looted = 0;
        return tmp;
    }
};

template<std::integral ValueType>
class Adventurer<ValueType, true> {
public:
    using strength_t = uint32_t;

private:
    strength_t strength;
    ValueType looted = 0;

public:
    static constexpr const bool isArmed = true;

    constexpr Adventurer<ValueType, true>(strength_t strength) : strength(strength) {};

    constexpr strength_t getStrength() const {
        return strength;
    }

    template<bool isTrapped>
    constexpr void loot(Treasure<ValueType, isTrapped>&& treasure) {
        if constexpr (isTrapped) {
            if (strength > 0) {
                strength /= 2;
                looted += treasure.getLoot();
            }
        } else {
            looted += treasure.getLoot();
        }
    }

    constexpr ValueType pay() {
        ValueType tmp = looted;
        looted = 0;
        return tmp;
    }
};

template<std::integral ValueType, size_t CompletedExpeditions>
requires (CompletedExpeditions < MAX_EXPEDITIONS)
class Veteran {
public:
    using strength_t = uint32_t;

private:
    ValueType looted = 0;

    static constexpr strength_t fib(size_t n) {
        int a = 0, b = 1;

        for (size_t i = 0; i < n; i++){
            a += b;
            std::swap(a, b);
        }

        return a;
    }

    strength_t strength = fib(CompletedExpeditions);

public:
    static constexpr const bool isArmed = true;
    constexpr Veteran<ValueType, CompletedExpeditions>() {};

    template<bool isTrapped>
    constexpr void loot(Treasure<ValueType, isTrapped>&& treasure) {
        if constexpr (isTrapped) {
            if (strength > 0) looted += treasure.getLoot();
        } else {
            looted += treasure.getLoot();
        }
    }

    constexpr strength_t getStrength() const {
        return strength;
    }

    constexpr ValueType pay() {
        ValueType tmp = looted;
        looted = 0;
        return tmp;
    }
};

#endif // MEMBER_H