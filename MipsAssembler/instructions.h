#include <map>
#include <string>
#include <sstream>
#include <bitset>
#include <vector>
using namespace std;

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


string typeI(string, /*map<string, unsigned int>*/ int ,/* map<string, unsigned int>*/ int, unsigned short);
string typeJ(string, unsigned int);
int cpiMed(int, string);
