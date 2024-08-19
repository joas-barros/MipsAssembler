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
 