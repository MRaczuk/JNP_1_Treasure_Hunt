#ifndef TREASURE_H
#define TREASURE_H

#include <concepts>

template<std::integral ValueType, bool IsTrapped>
class Treasure;

template<std::integral ValueType>
class Treasure<ValueType, true> {
private:
    ValueType value;

public:
    static const bool isTrapped = true;
    constexpr Treasure (ValueType value) : value(value) {}
    constexpr ValueType evaluate() const {
        return value;
    }
    constexpr ValueType getLoot(){
        ValueType out = this->value;
        this->value = 0;
        return out;
    }
};

template<std::integral ValueType>
class Treasure<ValueType, false> {
private:
    ValueType value;

public:
    static const bool isTrapped = false;
    constexpr Treasure (ValueType value) : value(value) {}
    constexpr ValueType evaluate() const {
        return value;
    }
    constexpr ValueType getLoot(){
        ValueType out = this->value;
        this->value = 0;
        return out;
    }
};


template<std::integral ValueType>
using SafeTreasure = Treasure<ValueType, false>;

template<std::integral ValueType>
using TrappedTreasure = Treasure<ValueType, true>;

#endif // TREASURE_H
