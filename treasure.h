#ifndef TREASURE_H
#define TREASURE_H

#include "bits/stdc++.h"
using namespace std;

template<typename ValueType, bool IsTrapped>
requires integral<ValueType>
class Treasure {

private:
    ValueType value;

public:
    bool isTrapped = IsTrapped;
    constexpr Treasure (ValueType value);
    constexpr ValueType evaluate();
    constexpr ValueType getLoot();
};

template <typename ValueType, bool IsTrapped>
constexpr Treasure<ValueType, IsTrapped> :: Treasure(ValueType value) : value(value){};

template <typename ValueType, bool IsTrapped>
constexpr ValueType Treasure<ValueType, IsTrapped> :: evaluate(){
    return value;
}

template <typename ValueType, bool IsTrapped>
constexpr ValueType Treasure<ValueType, IsTrapped> :: getLoot(){
    ValueType out = this->value;
    this->value = 0;
    return out;
}

#endif // TREASURE_H