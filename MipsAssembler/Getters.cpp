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