#include <iostream>
#include "Getters.h"
#include "Functions.h"
#include "instructions.h"
#include <fstream>
using namespace std;

int main() {
	// imprimir a fun��o da cada linha do arquivo
	string file = "code.asm";

	map<string, int> labels = getLabels(file);

	// retirar a extens�o do arquivo
	string out = file.substr(0, file.find("."));
	out += ".hex";

	ofstream fout;
	fout.open(out);

	ifstream fin;
	fin.open(file);

	int cpim = cpiMed(5, file);

	string line;
	string lineWithoutComents;
	int currentLine = 0;

	while (getline(fin, line)) {
		currentLine++;
		lineWithoutComents = ignoreComents(line);
		fout << assemblingHexa(lineWithoutComents, labels, currentLine) << endl;
	}

	fin.close();
	fout.close();
	cout << "Arquivo gerado com sucesso!" << endl;
	return 0;
}
