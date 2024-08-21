#include "Conversor.h"


string convertToHexa(string bin) {

	bitset<32> set(bin);
	stringstream res;

	res << hex << set.to_ulong();

	string hexa = res.str();

	if (hexa.length() < 8) {
		while (hexa.length() < 8) {
			hexa = "0" + hexa;
		}
	}

	return hexa;
}
 