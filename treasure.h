ifndef TREASURE_H
#define TREASURE_H

#include "bits/stdc++.h"
using namespace std;

template<integral ValueType, bool IsTrapped>
class Treasure {

private:
    ValueType value;
    bool isTrapped_ = IsTrapped;

public:
    const bool& isTrapped = isTrapped_;
    constexpr Treasure (ValueType value);
    constexpr ValueType evaluate() const;
    constexpr ValueType getLoot();
};

template <integral ValueType, bool IsTrapped>
constexpr Treasure<ValueType, IsTrapped> :: Treasure(ValueType value) : value(value){};

template <integral ValueType, bool IsTrapped>
constexpr ValueType Treasure<ValueType, IsTrapped> :: evaluate() const {
    return value;
}

template <integral ValueType, bool IsTrapped>
constexpr ValueType Treasure<ValueType, IsTrapped> :: getLoot() {
    ValueType out = this->value;
    this->value = 0;
    return out;
}

template<integral ValueType>
using SafeTreasure = Treasure<ValueType, false>;

template<integral ValueType>
using TrappedTreasure = Treasure<ValueType, true>;

#endif // TREASURE_H