#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <vector>
using namespace std;


map<string, int> getLabels(string);

string getFunction(string);

vector<int> getRegister(string);

int getImediate(string);

string ignoreComents(string);