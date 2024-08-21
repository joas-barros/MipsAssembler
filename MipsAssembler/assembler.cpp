#include <iostream>
#include "Getters.h"
#include "Functions.h"
#include "instructions.h"
#include <fstream>
using namespace std;

int main() {
	// imprimir a função da cada linha do arquivo
	string file = "TesteSilvio.asm";

	map<string, int> labels = getLabels(file);

	// retirar a extensão do arquivo
	string out = file.substr(0, file.find("."));
	out += ".bin";

	ofstream fout;
	fout.open(out);

	ifstream fin;
	fin.open(file);

	int cpim = cpiMed(5, file);

	string line, lineWithoutComents, assembledLine;
	int currentLine = 0;

	while (getline(fin, line)) {
		
		lineWithoutComents = ignoreEmptySpaces(ignoreComents(line));
		assembledLine = assembling(lineWithoutComents, labels, currentLine);
		if (assembledLine != "") {
			currentLine++;
			fout << assembledLine << endl;
		}
	}

	fin.close();
	fout.close();
	cout << "Arquivo gerado com sucesso!" << endl;
	return 0;
}
