#include <string>
#include <map>
#include <fstream>
#include <bitset>
#include "Getters.h"
#include "Conversor.h"
using namespace std;

struct Func
{
	int opCode;
	int rs;
	int rt;
	int rd;
	int shamt;
	int funct;
};


Func treatingRFunction(string);

string typeI(string, int, int, unsigned short);
string typeJ(string, unsigned int);

// Prototipo das fun��es de tratamento de instru��es
string bitRFunction(Func);

string assembling(string, map<string, int>, int);

string assemblingHexa(string, map<string, int>, int);

