#pragma once
#include <string>
#include <map>
using namespace std;

struct RFunctions
{
	int opCode;
	int rs;
	int rt;
	int rd;
	int shamt;
	int funct;
};

map<string, RFunctions> RFunctionsMap = {
	{"sll", {0, 0, 0, 0, 0, 0}},
	{"srl", {0, 0, 0, 0, 0, 2}},
	{"jr", {0, 0, 0, 0, 0, 8}},
	{"mfhi", {0, 0, 0, 0, 0, 16}},
	{"mthi", {0, 0, 0, 0, 0, 17}},
	{"mflo", {0, 0, 0, 0, 0, 18}},
	{"mult", {0, 0, 0, 0, 0, 24}},
	{"multu", {0, 0, 0, 0, 0, 25}},
	{"div", {0, 0, 0, 0, 0, 26}},
	{"divu", {0, 0, 0, 0, 0, 27}},
	{"add", {0, 0, 0, 0, 0, 32}},
	{"addu", {0, 0, 0, 0, 0, 33}},
	{"sub", {0, 0, 0, 0, 0, 34}},
	{"subu", {0, 0, 0, 0, 0, 35}},
	{"and", {0, 0, 0, 0, 0, 36}},
	{"or", {0, 0, 0, 0, 0, 37}},
	{"slt", {0, 0, 0, 0, 0, 42}},
	{"sltu", {0, 0, 0, 0, 0, 43}},
	{"mul", {28, 0, 0, 0, 0, 2}}
};


// Prototipo das funções de tratamento de instruções
string bitRFunction(RFunctions);

