#include "Functions.h"
#include "Conversor.h"
#include "Getters.h"
#include "instructions.h"

map<string, Func> functionsMap = {
	{"sll", {R, 0, 0, 0, 0, 0, 0}},
	{"srl", {R, 0, 0, 0, 0, 0, 2}},
	{"jr", {R, 0, 0, 0, 0, 0, 8}},
	{"mfhi", {R,0, 0, 0, 0, 0, 16}},
	{"mthi", {R, 0, 0, 0, 0, 0, 17}},
	{"mflo", {R, 0, 0, 0, 0, 0, 18}},
	{"mult", {R,0, 0, 0, 0, 0, 24}},
	{"multu", {R, 0, 0, 0, 0, 0, 25}},
	{"div", {R, 0, 0, 0, 0, 0, 26}},
	{"divu", {R, 0, 0, 0, 0, 0, 27}},
	{"add", {R, 0, 0, 0, 0, 0, 32}},
	{"addu", {R, 0, 0, 0, 0, 0, 33}},
	{"sub", {R, 0, 0, 0, 0, 0, 34}},
	{"subu", {R, 0, 0, 0, 0, 0, 35}},
	{"and", {R, 0, 0, 0, 0, 0, 36}},
	{"or", {R, 0, 0, 0, 0, 0, 37}},
	{"slt", {R, 0, 0, 0, 0, 0, 42}},
	{"sltu", {R, 0, 0, 0, 0, 0, 43}},
	{"mul", {R, 28, 0, 0, 0, 0, 2}}
};

string bitRFunction(Func function) {
	string op = decimalToBinary(function.opCode, 6);
	string rs = decimalToBinary(function.rs, 5);
	string rt = decimalToBinary(function.rt, 5);
	string rd = decimalToBinary(function.rd, 5);
	string shamt = decimalToBinary(function.shamt, 5);
	string funct = decimalToBinary(function.funct, 6);

	return op + rs + rt + rd + shamt + funct;
}

Func treatingRFunction(string line) {
	string funcName = getFunction(line);
	Func function = functionsMap[funcName];
	vector<int> registers = getRegister(line);
	int shamt = getImediate(line);

	if (funcName == "sll" || funcName == "srl")
	{
		function.rd = registers[0];
		function.rt = registers[1];
	}
	else if (funcName == "jr")
	{
		function.rs = registers[0];
	}
	else if (funcName == "mfhi" || funcName == "mflo")
	{
		function.rd = registers[0];
	}
	else if (funcName == "mult" || funcName == "multu" || funcName == "div" || funcName == "divu")
	{
		function.rs = registers[0];
		function.rt = registers[1];
	}
	else
	{
		function.rd = registers[0];
		function.rs = registers[1];
		function.rt = registers[2];
	}

	function.shamt = shamt;

	return function;
}

string assembling(string line, map<string, int> labels)
{
	string funcName = getFunction(line);

	if (functionsMap.find(funcName) != functionsMap.end())
		return bitRFunction(treatingRFunction(line));
	else if (funcName == "j" || funcName == "jal")
	{
		string label = getLastWord(line);
		int address = labels[label];
		return typeJ(funcName, address);
	}
	else {
		vector<int> registers = getRegister(line);
		if (funcName == "beq" || funcName == "bne")
		{
			int rs = registers[0];
			int rt = registers[1];
			int address = labels[getLastWord(line)];
			return typeI(funcName, rs, rt, address);
		}
		else if (funcName == "addi" || funcName == "addiu" || funcName == "andi" || funcName == "ori" || funcName == "slti" || funcName == "sltiu")
		{
			int rt = registers[0];
			int rs = registers[1];
			int imediate = getImediate(line);
			return typeI(funcName, rs, rt, imediate);
		}
		else if (funcName == "lui")
		{
			int rt = registers[0];
			int imediate = getImediate(line);
			return typeI(funcName, 0, rt, imediate);
		}
		else if (funcName == "lw" || funcName == "sw")
		{
			int rt = registers[0];
			int rs = registers[1];
			int imediate = getImediate(line);
			return typeI(funcName, rs, rt, imediate);
		}
	}
}
