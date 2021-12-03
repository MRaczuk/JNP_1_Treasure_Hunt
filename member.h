#ifndef MEMBER_H
#define MEMBER_H

#include "bits/stdc++.h"
#include "treasure.h"

#define MAX_EXPEDITIONS 25

using namespace std;

template<integral ValueType, bool IsArmed>
class Adventurer;

template<integral ValueType>
using Explorer = Adventurer<ValueType, false>;

template<integral ValueType>
class Adventurer<ValueType, false> {
private:
  ValueType looted = 0;
public:
  static constexpr const bool isArmed = false;

  constexpr Adventurer<ValueType, false>() {};

  template<integral TreasureValueType, bool isTrapped>
  constexpr void loot(Treasure<TreasureValueType, isTrapped>&& treasure) {
    if constexpr (!isTrapped)
      looted += treasure.getLoot();
  }

  constexpr ValueType pay() {
    ValueType tmp = looted;
    looted = 0;
    return tmp;
  }
};

template<integral ValueType>
class Adventurer<ValueType, true> {
private:
  uint32_t strength;
  ValueType looted = 0;
public:
  static constexpr const bool isArmed = true;

  constexpr Adventurer<ValueType, true>(uint32_t strength) : strength(strength) {};

  constexpr ValueType getStrength() const {
    return strength;
  }

  template<integral TreasureValueType, bool isTrapped>
  constexpr void loot(Treasure<TreasureValueType, isTrapped>&& treasure) {
    if constexpr (isTrapped) {
      if (strength > 0) {
        strength /= 2;
        looted += treasure.getLoot();
      }
    }
    else {
      looted += treasure.getLoot();
    }
  }

  constexpr ValueType pay() {
    ValueType tmp = looted;
    looted = 0;
    return tmp;
  }
};

template<integral ValueType, size_t CompletedExpeditions>
requires (completedExpeditions < MAX_EXPEDITIONS)
class Veteran {
private:
  ValueType looted = 0;
public:
  static constexpr const bool isArmed = true;

};

#endif // MEMBER_H