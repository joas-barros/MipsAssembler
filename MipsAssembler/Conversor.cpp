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

	// Cria uma variável com o tamanho de 32 bits e o valor do binário passado como parâmetro
	bitset<32> set(bin);
	// Associa res a um stream permitindo que leia a string como se fosse um stream (como cin). 
	stringstream res;

	// Converte o bitset em unsigned long, depois converte para hexadecimal e ler no objeto res.
	res << hex << set.to_ulong();

	// Salva a string que está no res na variável hexa
	string hexa = res.str();

	if (hexa.length() < 8) {
		while (hexa.length() < 8) {
			hexa = "0" + hexa;
		}
	}

	return hexa;
}
 
