#include "Choice.h"
#include "Getters.h"
#include "Functions.h"
#include <iostream>
#include <fstream>
#include <map>


void choiceB(string file) {

	// Chama a fun��o para pagar os labels do d�digo e sua respectiva linha (tabela de s�mbolos)
	map<string, int> labels = getLabels(file);

	// retirar a extens�o do arquivo
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

		lineWithoutComents = ignoreEmptySpaces(ignoreComents(line)); // Ignora os espa�os vazios e os coment�rios
		assembledLine = assembling(lineWithoutComents, labels, currentLine); // gera o c�digo compilado
		if (assembledLine != "") { // Caso a linha n�o tenha instru��o, n�o escreve no arquivo
			currentLine++;
			fout << assembledLine << endl;
		}
	}

	// Fecha os arquivos
	fin.close();
	fout.close();
}

// Vers�o da fun��o em hexadecimal
void choiceH(string file) {
	map<string, int> labels = getLabels(file);

	// retirar a extens�o do arquivo
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