#include "../treasure_hunt.h"

int main() {
	Adventurer<int, true> uzbroj(42);
	{
		Treasure<int, false> bez_pulapki(42);
		uzbroj.loot(bez_pulapki);
		assert(uzbroj.pay() == 42);
		assert(bez_pulapki.evaluate() == 0);
		assert(uzbroj.getStrength() == 42);
	}

	for(int i = 0; i < 6; ++i) {
		Treasure<int, true> pulapka(42);
		uzbroj.loot(pulapka);
		assert(uzbroj.pay() == 42);
		assert(pulapka.evaluate() == 0);
	}

	{
		Treasure<int, true> pulapka(42);
		uzbroj.loot(pulapka);
		assert(uzbroj.pay() == 0);
		assert(pulapka.evaluate() == 42);
	}

	{
		Treasure<int, false> bez_pulapki(42);
		uzbroj.loot(bez_pulapki);
		assert(uzbroj.pay() == 42);
		assert(bez_pulapki.evaluate() == 0);
		assert(uzbroj.getStrength() == 0);
	}

	Adventurer<int, false> nieuzbroj;
	{
		Treasure<int, false> bez_pulapki(42);
		nieuzbroj.loot(bez_pulapki);
		assert(nieuzbroj.pay() == 42);
		assert(bez_pulapki.evaluate() == 0);
	}

	{
		Treasure<int, true> pulapka(42);
		nieuzbroj.loot(pulapka);
		assert(nieuzbroj.pay() == 0);
		assert(pulapka.evaluate() == 42);
	}
}
