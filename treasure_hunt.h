#ifndef TREASURE_HUNT_H
#define TREASURE_HUNT_H

#include "bits/stdc++.h"
#include "member.h"
#include "treasure.h"


template<class T>
concept ValidTreasure = requires(T x) {
    { Treasure{x} } -> std::same_as<T>;
};

template<typename T>
concept ValidAdventurer = requires(T adventurer)
{
  typename T::strength_t;
  { T::isArmed } -> std::convertible_to<bool>;
};

template<typename T>
concept EncounterSide = ValidTreasure<T> || ValidAdventurer<T>;

#endif // TREASURE_HUNT_H