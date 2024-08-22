#include <iostream>
#include "Getters.h"
#include "Functions.h"
#include "instructions.h"
#include "Choice.h"
#include <fstream>
using namespace std;

// Função principal

int main(int argc, char** argv) {
	
	string filename = argv[1];
	if (strcmp(argv[2], "-b") == 0) {
		choiceB(filename);
	}
	else if (strcmp(argv[2], "-h") == 0) {
		choiceH(filename);
	}
	else{
		cout << "Invalid choice" << endl;
		return 0;
	}

	cpiMed(filename); // Mostra o cpi por instrução e médio

	return 0;
}
