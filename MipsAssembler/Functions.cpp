#include "Functions.h"
#include "Conversor.h"

string bitRFunction(RFunctions function) {
	string op = decimalToBinary(function.opCode, 6);
	string rs = decimalToBinary(function.rs, 5);
	string rt = decimalToBinary(function.rt, 5);
	string rd = decimalToBinary(function.rd, 5);
	string shamt = decimalToBinary(function.shamt, 5);
	string funct = decimalToBinary(function.funct, 6);

	return op + rs + rt + rd + shamt + funct + "\n";
}