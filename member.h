#ifndef MEMBER_H
#define MEMBER_H

#include "bits/stdc++.h"

#define MAX_EXPEDITIONS 25

using namespace std;

template<integral ValueType, bool IsArmed>
class Adventurer {

public:
    bool isArmed = IsArmed;
};

template<integral ValueType, size_t CompletedExpeditions>
requires (CompletedExpeditions < MAX_EXPEDITIONS)
class Veteran {

};

#endif // MEMBER_H