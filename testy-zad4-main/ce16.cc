#include "../treasure_hunt.h"

#include <cstddef>

struct Dummy {
	using strength_t = size_t;
	bool isArmed = true;
	float pay() { return 0; }
	template<bool IsTrapped> void loot(Treasure<float, IsTrapped>) {}
};

int main() {
	Treasure<int, false> t(42);
	Dummy d;
	run(Encounter{t, d});
}
