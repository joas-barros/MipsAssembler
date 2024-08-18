#include <iostream>
#include "Getters.h"
#include <fstream>
using namespace std;

int main() {
	// imprimir a função da cada linha do arquivo
	string file = "code.asm";
	ifstream fin;
	fin.open(file);
	string line;
	while (getline(fin, line)) {
		// imprimir registradores
		vector<int> registers = getRegister(line);
		for (int i = 0; i < registers.size(); i++) {
			cout << registers[i] << " ";
		}
	cout << endl;
	}
	fin.close();
	return 0;
}
