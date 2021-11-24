#include "../treasure_hunt.h"

int main() {
	Veteran<int, 10>::strength_t s = 0;
	assert((s - 1) == 4294967295);
}
	
