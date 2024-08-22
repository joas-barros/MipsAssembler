#include "Conversor.h"

// Fun��o que converte a instru��o bin�rio para hexadecimal
string convertToHexa(string bin) {

	// Cria uma vari�vel com o tamanho de 32 bits e o valor do bin�rio passado como par�metro
	bitset<32> set(bin);
	// Associa res a um stream permitindo que leia a string como se fosse um stream (como cin). 
	stringstream res;

	// Converte o bitset em unsigned long, depois converte para hexadecimal e ler no objeto res.
	res << hex << set.to_ulong();


	// Salva a string que est� no res na vari�vel hexa
	string hexa = res.str();

	// Caso o n�mero de digitos sehja menor que 8, completa com 0
	if (hexa.length() < 8) {
		while (hexa.length() < 8) {
			hexa = "0" + hexa;
		}
	}

	return hexa;
}

 
