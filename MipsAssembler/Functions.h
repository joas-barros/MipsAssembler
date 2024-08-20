#include <string>
#include <map>
#include "Getters.h"
#include "Conversor.h"
using namespace std;

enum Types
{
	R,
	I,
	J
};

struct Func
{
	Types type;
	int opCode;
	int rs;
	int rt;
	int rd;
	int shamt;
	int funct;
};


Func treatingRFunction(string);

// Prototipo das fun��es de tratamento de instru��es
string bitRFunction(Func);

string assembling(string, map<string, int>);

