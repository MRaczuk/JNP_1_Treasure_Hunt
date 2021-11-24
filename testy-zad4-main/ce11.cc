#include "../treasure_hunt.h"

int main() {
	Veteran<int, 1> vet;
	Treasure<long, false> tre(42);
	vet.loot(tre);
}
