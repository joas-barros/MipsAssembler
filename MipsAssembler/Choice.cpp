#include "Choice.h"
#include "Getters.h"
#include "Functions.h"
#include <iostream>
#include <fstream>
#include <map>


void choiceB(string file) {

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
}

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