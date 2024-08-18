#include <iostream>
#include "Getters.h"
using namespace std;

int main() {
	map<string, int> mapLabels = getLabels("code.asm");

	// printando conteudo do map
	
	for (auto x:mapLabels) {
		cout << x.first << " Linha: " << x.second << endl;
	}
	return 0;
}
