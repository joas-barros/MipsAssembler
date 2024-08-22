#include "Choice.h"
#include "Getters.h"
#include "Functions.h"
#include <iostream>
#include <fstream>
#include <map>


void choiceB(string file) {

	// Chama a função para pagar os labels do dódigo e sua respectiva linha (tabela de símbolos)
	map<string, int> labels = getLabels(file);

	// retirar a extensão do arquivo
	string out = file.substr(0, file.find("."));
	out += ".bin";

	ofstream fout;
	fout.open(out);

	ifstream fin;
	fin.open(file);



	string line, lineWithoutComents, assembledLine;
	int currentLine = 0;

	// Ler as linhas do arquivo
	while (getline(fin, line)) {

		lineWithoutComents = ignoreEmptySpaces(ignoreComents(line)); // Ignora os espaços vazios e os comentários
		assembledLine = assembling(lineWithoutComents, labels, currentLine); // gera o código compilado
		if (assembledLine != "") { // Caso a linha não tenha instrução, não escreve no arquivo
			currentLine++;
			fout << assembledLine << endl;
		}
	}

	// Fecha os arquivos
	fin.close();
	fout.close();
}

// Versão da função em hexadecimal
void choiceH(string file) {
	map<string, int> labels = getLabels(file);

	// retirar a extensão do arquivo
	string out = file.substr(0, file.find("."));
	out += ".hex";

	ofstream fout;
	fout.open(out);

	ifstream fin;
	fin.open(file);

	string line, lineWithoutComents, assembledLine;
	int currentLine = 0;

	fout << "v2.0 raw" << endl;

	while (getline(fin, line)) {

		lineWithoutComents = ignoreEmptySpaces(ignoreComents(line));
		assembledLine = assemblingHexa(lineWithoutComents, labels, currentLine);
		if (assembledLine != "") {
			currentLine++;
			fout << assembledLine << endl;
		}
	}

	fin.close();
	fout.close();
}