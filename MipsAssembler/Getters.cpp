#include "Getters.h"
#include <fstream>

// Função para pegar os labels do código
map<string, int> getLabels(string codeName) {
	regex LABEL("(\\w*):"); // Regex que retorna a palavra acompanhada de dois pontos
	map<string, int> labels;
	ifstream codeFile;
	codeFile.open(codeName);
	string codeLine;
	int lineNum = 0;
	while(getline(codeFile, codeLine)){

		string line = ignoreComents(codeLine); // Ignora os comentários
		smatch match;
		regex_search(line, match, LABEL);
		if(match.size() > 0){
			labels[match.str(1)] = lineNum; // Adiciona o label na tabela de símbolos e sua linha
			lineNum++; // Incrementa a linha
		}
		else if (getFunction(line) != "") {
			lineNum++; // Incrementa a linha se não tiver label e tiver função, estrategia para ignorar linhas vazias
		}
	}
	codeFile.close();
	return labels;
}

string getFunction(string line) {
	regex FUNCTION("^(?:\\w+:)?\\s*(\\w+)"); // Regex para retornar a primeira palavra da linha, caso não seja um label
	smatch match;
	regex_search(line, match, FUNCTION);
	if(match.size() > 0){
		return match.str(1);
	}
	return ""; // Retorna vazio caso não encontre nenhuma função
}

vector<int> getRegister(string line) {

	regex REGISTER("[$]\\d+|[$].\\d+"); // Regex para retornar algo que começa com $

	// Possiveis registradores encontrados e seus valores
	map<string, int> REGISTER_MAP = {
	{"$zero", 0},
	{"$at", 1},
	{"$v0", 2},
	{"$v1", 3},
	{"$a0", 4},
	{"$a1", 5},
	{"$a2", 6},
	{"$a3", 7},
	{"$t0", 8},
	{"$t1", 9},
	{"$t2", 10},
	{"$t3", 11},
	{"$t4", 12},
	{"$t5", 13},
	{"$t6", 14},
	{"$t7", 15},
	{"$s0", 16},
	{"$s1", 17},
	{"$s2", 18},
	{"$s3", 19},
	{"$s4", 20},
	{"$s5", 21},
	{"$s6", 22},
	{"$s7", 23},
	{"$t8", 24},
	{"$t9", 25},
	{"$ra", 31},
	{"$0", 0},
	{"$1", 1},
	{"$2", 2},
	{"$3", 3},
	{"$4", 4},
	{"$5", 5},
	{"$6", 6},
	{"$7", 7},
	{"$8", 8},
	{"$9", 9},
	{"$10", 10},
	{"$11", 11},
	{"$12", 12},
	{"$13", 13},
	{"$14", 14},
	{"$15", 15},
	{"$16", 16},
	{"$17", 17},
	{"$18", 18},
	{"$19", 19},
	{"$20", 20},
	{"$21", 21},
	{"$22", 22},
	{"$23", 23},
	{"$24", 24},
	{"$25", 25},
	{"$31", 31}
	};

	vector<int> registers;
	smatch matches;
	while (regex_search(line, matches, REGISTER))
	{
		for (const auto& match : matches) {
			int reg = REGISTER_MAP.at(match.str()); // primeira ocorrencia do match
			registers.push_back(reg); // Adiciona o valor numerico do registrador na lista

		}
	line = matches.suffix().str(); // Pega o resto da string
	}
	return registers;
}

int getImediate(string line) {
	regex IMEDIATE(" \\d*(\\n|$| )"); // regex para retornar sequencias de dígitos que terminam com espaço, nova linha ou fim de linha
	smatch match;
	regex_search(line, match, IMEDIATE);
	if(match.size() > 0){
		return stoi(match[0]);
	}
	return 0;
}

string ignoreComents(string line) {
	regex COMMENT("#.*"); // Regex para retornar tudo que começa com #
	return regex_replace(line, COMMENT, ""); // Ignora tudo que vem depois do #
}

string getLastWord(string line) {
	regex LASTWORD("\\b\\w+\\b(?=\\s*$)"); // Regex para retornar a última palavra da linha
	smatch match;
	regex_search(line, match, LASTWORD);
	if (match.size() > 0) {
		return match.str(0);
	}
	return "";
}

string ignoreEmptySpaces(string line) {
	regex BEFORE_EMPTY("^.*\\S(?=\\s*$)"); // Regex para retornar tudo que vem antes do espaço final
	smatch match;
	regex_search(line, match, BEFORE_EMPTY);
	if (match.size() > 0) {
		return match.str(0);
	}
	return "";
}

