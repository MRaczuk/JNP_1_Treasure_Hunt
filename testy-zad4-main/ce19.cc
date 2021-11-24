#include "../treasure_hunt.h"

#include <cstddef>

struct Dummy {
	using strength_t = size_t;
	bool isArmed = true;
	int pay() { return 0; }
	void loot(Treasure<int, false>) {}
};

int main() {
	Treasure<int, false> t(42);
	Dummy d;
	run(Encounter{t, d});
}
