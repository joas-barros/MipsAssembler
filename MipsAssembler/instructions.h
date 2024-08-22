#include <map>
#include <string>
#include <sstream>
#include <bitset>
#include <vector>
using namespace std;

// Módulo para definir a função que calcula o cpi médio

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
