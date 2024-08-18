#include "Conversor.h"

string decimalToBinary(int number, int size)
{
	string binary = "";
	for (int i = number; i > 0; i--)
	{
		if (i % 2 == 0) {
			binary = "0" + binary;
		}
		else
		{
			binary = "1" + binary;
		}
	}
	while (binary.size() < size)
	{
		binary = "0" + binary;
	}
	return binary;
}
