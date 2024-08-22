#include <string>
#include <map>
#include <fstream>
#include <bitset>
#include "Getters.h"
#include "Conversor.h"
using namespace std;

// M�dulo para definir as fun��es de tratamento de instru��es

struct Func
{
	int opCode;
	int rs;
	int rt;
	int rd;
	int shamt;
	int funct;
};

// Prototipo das fun��es de tratamento de instru��es
Func treatingRFunction(string);

string typeI(string, int, int, unsigned short);
string typeJ(string, unsigned int);


string bitRFunction(Func);

// Prototipo das fun��es de montagem
string assembling(string, map<string, int>, int);

string assemblingHexa(string, map<string, int>, int);

