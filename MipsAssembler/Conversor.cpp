#include "Conversor.h"

string decimalToBinary(int number, int size)
{
	string binary = "";
	while (number > 0) {
		binary = to_string(number % 2) + binary;
		number /= 2;
	}
	while (binary.length() < size) {
		binary = "0" + binary;
	}
	return binary;
}

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
 