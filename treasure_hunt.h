#ifndef TREASURE_HUNT_H
#define TREASURE_HUNT_H

#include <concepts>

#include "member.h"
#include "treasure.h"

template<class T>
concept ValidTreasure = requires(T x) {
    { Treasure{x} } -> std::same_as<T>;
};

template <typename T>
concept DefinesPay = requires(T adventurer) {
    { adventurer.pay() } -> std::integral;
};

template <typename T>
concept DefinesGetStrength = requires(T adventurer) {
    adventurer.getStrength();
};

template <typename T, typename U1, typename U2>
concept MatchingLootType = requires (T a, U1 s, U2 t) {
    a.loot(s);
    a.loot(t);
};

template<typename T>
concept ValidAdventurer = DefinesPay<T> && requires(T a) {
    typename T::strength_t;
    { T::isArmed } -> std::convertible_to<bool>;
    {[]() constexpr {return T::isArmed; }()};
    MatchingLootType<T, Treasure<decltype(a.pay()), true>, Treasure<decltype(a.pay()), false>>;
};

template<typename T>
concept ArmedAdventurer = ValidAdventurer<T> && DefinesGetStrength<T>;

template<typename T>
concept EncounterSide = ValidTreasure<T> || ValidAdventurer<T>;

template<EncounterSide SideA, EncounterSide SideB>
using Encounter = std::pair<SideA &, SideB &>;

template<EncounterSide A, EncounterSide B>
requires(ValidAdventurer<A> || ValidAdventurer<B>)
constexpr void run (Encounter<A, B> encounter) {
    if constexpr (ValidAdventurer<A> && ValidAdventurer<B>) {
        if constexpr (!ArmedAdventurer<A> && ArmedAdventurer<B>) {
            auto taken = SafeTreasure<decltype((encounter.second.pay)()) > ((decltype((encounter.second.pay)()))encounter.first.pay());
            encounter.second.loot(std::move(taken));
        } else if constexpr (ArmedAdventurer<A> && !ArmedAdventurer<B>) {
            auto taken = SafeTreasure<decltype((encounter.first.pay)()) > ((decltype((encounter.first.pay)()))encounter.second.pay());
            encounter.first.loot(std::move(taken));
        } else if constexpr (ArmedAdventurer<A> && ArmedAdventurer<B>) {
            if (encounter.first.getStrength() < encounter.second.getStrength()){
                auto taken = SafeTreasure<decltype((encounter.second.pay)()) > ((decltype((encounter.second.pay)()))encounter.first.pay());
                encounter.second.loot(std::move(taken));
            } else if (encounter.first.getStrength() > encounter.second.getStrength()) {
                auto taken = SafeTreasure<decltype((encounter.first.pay)()) > ((decltype((encounter.first.pay)()))encounter.second.pay());
                encounter.first.loot(std::move(taken));
            }
        }
    }

    if constexpr (ValidAdventurer<A> && ValidTreasure<B>){
        encounter.first.loot(std::move(encounter.second));
    }

    if constexpr (ValidAdventurer<B> && ValidTreasure<A>) {
        encounter.second.loot(std::move(encounter.first));
    }
}

template <typename... Expedition>
constexpr void expedition(Expedition... encounters) {
    (run(encounters), ...);
}

#endif // TREASURE_HUNT_H