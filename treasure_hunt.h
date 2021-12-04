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
using Encounter = pair<SideA &, SideB &>;

template<EncounterSide A, EncounterSide B>
requires(ValidAdventurer<A> || ValidAdventurer<B>)
constexpr void run (Encounter<A, B> encounter){
  if constexpr (ValidAdventurer<A> && ValidAdventurer<B>) {
    if (!encounter.first.isArmed && encounter.second.isArmed){
      SafeTreasure<auto> taken = SafeTreasure<decltype((encounter.second.pay)())> ((decltype((encounter.second.pay)()))encounter.first.pay());
      encounter.second.loot(std::move(taken));
    }
    else if (encounter.first.isArmed && !encounter.second.isArmed){
      SafeTreasure<auto> taken = SafeTreasure<decltype((encounter.first.pay)())> ((decltype((encounter.first.pay)()))encounter.second.pay());
      encounter.first.loot(std::move(taken));
    }
    else if (encounter.first.isArmed && encounter.second.isArmed){
      if (encounter.first.getStrength() < encounter.second.getStrength()){
        SafeTreasure<auto> taken = SafeTreasure<decltype((encounter.second.pay)())> ((decltype((encounter.second.pay)()))encounter.first.pay());
        encounter.second.loot(std::move(taken));
      }
      else if (encounter.first.getStrength() > encounter.second.getStrength()){
        SafeTreasure<auto> taken = SafeTreasure<decltype((encounter.first.pay)())> ((decltype((encounter.first.pay)()))encounter.second.pay());
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


#endif // TREASURE_HUNT_H