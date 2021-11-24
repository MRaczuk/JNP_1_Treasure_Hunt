#include "../treasure_hunt.h"

int main() {
	Treasure<int, false> t1(42);
	Treasure<int, false> t2(42);
	run(Encounter{t1, t2});
}
