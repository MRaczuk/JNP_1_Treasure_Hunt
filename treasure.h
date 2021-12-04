#ifndef TREASURE_H
#define TREASURE_H

#include <concepts>

template<std::integral ValueType, bool IsTrapped>
class Treasure {
private:
    ValueType value;

public:
    static constexpr const bool isTrapped = IsTrapped;
    constexpr Treasure (ValueType value);
    constexpr ValueType evaluate() const;
    constexpr ValueType getLoot();
};

template <std::integral ValueType, bool IsTrapped>
constexpr Treasure<ValueType, IsTrapped> :: Treasure(ValueType value) : value(value) {};

template <std::integral ValueType, bool IsTrapped>
constexpr ValueType Treasure<ValueType, IsTrapped> :: evaluate() const {
    return value;
}

template <std::integral ValueType, bool IsTrapped>
constexpr ValueType Treasure<ValueType, IsTrapped> :: getLoot() {
    ValueType out = this->value;
    this->value = 0;
    return out;
}

template<std::integral ValueType>
using SafeTreasure = Treasure<ValueType, false>;

template<std::integral ValueType>
using TrappedTreasure = Treasure<ValueType, true>;

#endif // TREASURE_H
