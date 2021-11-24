#ifndef MEMBER_H
#define MEMBER_H

#include "bits/stdc++.h"

#define MAX_EXPEDITIONS 25

using namespace std;

template<typename ValueType, bool IsArmed>
requires integral<ValueType>
Adventurer<ValueType, IsArmed>{

public:
    bool isArmed = IsArmed;
};

template<typename ValueType, size_t CompletedExpeditions>
requires integral<ValueType> && CompletedExpeditions < MAX_EXPEDITIONS
Veteran<ValueType, CompletedExpeditions>{

};

#endif // MEMBER_H