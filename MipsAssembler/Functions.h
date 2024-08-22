#include <string>
#include <map>
#include <fstream>
#include <bitset>
#include "Getters.h"
#include "Conversor.h"
using namespace std;

// Módulo para definir as funções de tratamento de instruções

struct Func
{
	int opCode;
	int rs;
	int rt;
	int rd;
	int shamt;
	int funct;
};

// Prototipo das funções de tratamento de instruções
Func treatingRFunction(string);

string typeI(string, int, int, unsigned short);
string typeJ(string, unsigned int);


string bitRFunction(Func);

// Prototipo das funções de montagem
string assembling(string, map<string, int>, int);

string assemblingHexa(string, map<string, int>, int);

