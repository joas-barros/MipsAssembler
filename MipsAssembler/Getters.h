#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <vector>
using namespace std;

// M�dulo para definir as fun��es de tratamento de texto

map<string, int> getLabels(string);

string getFunction(string);

vector<int> getRegister(string);

int getImediate(string);

string ignoreComents(string);

string getLastWord(string);

string ignoreEmptySpaces(string);