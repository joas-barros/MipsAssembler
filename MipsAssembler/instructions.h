#include <map>
#include <string>
#include <sstream>
#include <bitset>
#include <vector>
using namespace std;

// M�dulo para definir a fun��o que calcula o cpi m�dio

struct opcode
{
	string name;
	unsigned int value;
};

struct cpi 
{
	string name;
	int quantity;
	int value;
};



void cpiMed(string);
