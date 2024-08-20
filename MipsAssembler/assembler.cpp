#include <iostream>
#include "Getters.h"
#include "Functions.h"
#include "instructions.h"
#include <fstream>
using namespace std;

int main() {
	// imprimir a função da cada linha do arquivo
	string file = "teste.txt";

	map<string, int> labels = getLabels(file);

	// retirar a extensão do arquivo
	string out = file.substr(0, file.find("."));
	out += ".bin";

	ofstream fout;
	fout.open(out);

	ifstream fin;
	fin.open(file);

	int cpim = cpiMed(5);

	string line;
	string lineWithoutComents;
	while (getline(fin, line)) {
		lineWithoutComents = ignoreComents(line);
		fout << assembling(lineWithoutComents);
	}

	fin.close();
	fout.close();
	cout << "Arquivo gerado com sucesso!" << endl;
	return 0;
}
