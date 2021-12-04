#ifndef TREASURE_HUNT_H
#define TREASURE_HUNT_H

#include "bits/stdc++.h"
#include "member.h"
#include "treasure.h"


template<class T>
concept ValidTreasure = requires(T x) {
    { Treasure{x} } -> std::same_as<T>;
};

template <typename A>
concept DefinesPay =
        requires(A a) {
            { a.pay() } -> integral;
        };

// concept DefinesLoot = ?
template<typename T>
concept ValidAdventurer = DefinesPay<T> && requires(T adventurer)
{
  typename T::strength_t;
  { T::isArmed } -> std::convertible_to<bool>;
};

template<typename T>
concept EncounterSide = ValidTreasure<T> || ValidAdventurer<T>;

template<EncounterSide SideA, EncounterSide SideB>
using Encounter = pair<SideA, SideB>;

template<EncounterSide A, EncounterSide B>
requires(ValidAdventurer<A> || ValidAdventurer<B>)
void run (Encounter<A, B> encounter){
    if constexpr (ValidAdventurer<A>){
        if constexpr (ValidAdventurer<B>){
            ;
        }
        if constexpr (ValidTreasure<B>){
            encounter.first.loot(std::move(encounter.second));
        }
    }
    if constexpr (ValidAdventurer<B>)
      encounter.second.loot(std::move(encounter.first));
}


#endif // TREASURE_HUNT_H