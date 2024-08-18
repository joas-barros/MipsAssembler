#pragma once
#include <string>
#include <vector>
using namespace std;

struct RFunctions
{
	string name;
	int opCode;
	int rs;
	int rt;
	int rd;
	int shamt;
	int funct;
};

struct IFunctions
{
	string name;
	int opCode;
	int rs;
	int rt;
	int imm;
};

struct JFunctions
{
	string name;
	int opCode;
	int address;
};

vector<RFunctions> RFunctionsList = {
	{"sll", 0, 0, 0, 0, 0, 0},
	{"srl", 0, 0, 0, 0, 0, 2},
	{"jr", 0, 0, 0, 0, 0, 8},
	{"mfhi", 0, 0, 0, 0, 0, 16},
	{"mthi", 0, 0, 0, 0, 0, 17},
	{"mflo", 0, 0, 0, 0, 0, 18},
	{"mult", 0, 0, 0, 0, 0, 24},
	{"multu", 0, 0, 0, 0, 0, 25},
	{"div", 0, 0, 0, 0, 0, 26},
	{"divu", 0, 0, 0, 0, 0, 27},
	{"add", 0, 0, 0, 0, 0, 32},
	{"addu", 0, 0, 0, 0, 0, 33},
	{"sub", 0, 0, 0, 0, 0, 34},
	{"subu", 0, 0, 0, 0, 0, 35},
	{"and", 0, 0, 0, 0, 0, 36},
	{"or", 0, 0, 0, 0, 0, 37},
	{"slt", 0, 0, 0, 0, 0, 42},
	{"sltu", 0, 0, 0, 0, 0, 43},
	{"mul", 28, 0, 0, 0, 0, 2}
};

vector<IFunctions> IFunctionsList = {
	{"beq", 4, 0, 0, 0},
	{"bne", 5, 0, 0, 0},
	{"addi", 8, 0, 0, 0},
	{"addiu", 9, 0, 0, 0},
	{"slti", 10, 0, 0, 0},
	{"sltiu", 11, 0, 0, 0},
	{"andi", 12, 0, 0, 0},
	{"ori", 13, 0, 0, 0},
	{"lui", 15, 0, 0, 0},
	{"lw", 35, 0, 0, 0},
	{"sw", 44, 0, 0, 0}
};

vector<JFunctions> JFunctionsList = {
	{"j", 2, 0},
	{"jal", 3, 0}
};

// Prototipo das funções de tratamento de instruções
string RFunction(string instruction);
string IFunction(string instruction);
string JFunction(string instruction);
