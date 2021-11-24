#include "../treasure_hunt.h"

#include <cassert>

template<bool IsTrapped>
void check_ok_treasure(Treasure<int, IsTrapped> &t) {
	assert(t.evaluate() == 42);
	assert(t.isTrapped == IsTrapped);
	assert(t.getLoot() == 42);
	assert(t.evaluate() == 0);
}

int main() {
	Treasure<int, false> t1(42);
	Treasure<int, true> t2(42);
	SafeTreasure<int> t3(42);
	TrappedTreasure<int> t4(42);
	check_ok_treasure<false>(t1);
	check_ok_treasure<true>(t2);
	check_ok_treasure<false>(t3);
	check_ok_treasure<true>(t4);
}
