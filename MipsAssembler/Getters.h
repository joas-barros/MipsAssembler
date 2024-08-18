#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <map>
using namespace std;


// Definir constante regex para achar texto antes dos :
const regex LABEL("(\\w*):");

map<string, int> getLabels(string);
