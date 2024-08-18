#include "Getters.h"
#include <fstream>

map<string, int> getLabels(string codeName) {
	map<string, int> labels;
	ifstream codeFile;
	codeFile.open(codeName);
	string line;
	int lineNum = 0;
	while(getline(codeFile, line)){
		// usando regex para pegar o label
		smatch match;
		regex_search(line, match, LABEL);
		if(match.size() > 0){
			labels[match.str(1)] = lineNum;
		}
		lineNum++;
	}
	codeFile.close();
	return labels;
}

string getFunction(string line) {
	smatch match;
	regex_search(line, match, FUNCTION);
	if(match.size() > 0){
		return match.str(1);
	}
	return "";
}

vector<int> getRegister(string line) {
	vector<int> registers;
	smatch matches;
	while (regex_search(line, matches, REGISTER))
	{
		for (const auto& match : matches) {
			int reg = REGISTER_MAP.at(match.str());
			registers.push_back(reg);

		}
	line = matches.suffix().str();
	}
	return registers;
}