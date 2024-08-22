#include "Functions.h"
#include "Conversor.h"
#include "Getters.h"
#include "instructions.h"

// Posi��o inicial de mem�ria
const int initialAddress = 0x00400000;

// Mapa de fun��es do tipo R com seus respectivos c�digos para pegar o opcode e funct
map<string, Func> functionsMap = {
	{"sll", { 0, 0, 0, 0, 0, 0}},
	{"srl", { 0, 0, 0, 0, 0, 2}},
	{"jr", { 0, 0, 0, 0, 0, 8}},
	{"mfhi", {0, 0, 0, 0, 0, 16}},
	{"mthi", { 0, 0, 0, 0, 0, 17}},
	{"mflo", { 0, 0, 0, 0, 0, 18}},
	{"mult", {0, 0, 0, 0, 0, 24}},
	{"multu", { 0, 0, 0, 0, 0, 25}},
	{"div", { 0, 0, 0, 0, 0, 26}},
	{"divu", {0, 0, 0, 0, 0, 27}},
	{"add", { 0, 0, 0, 0, 0, 32}},
	{"addu", { 0, 0, 0, 0, 0, 33}},
	{"sub", { 0, 0, 0, 0, 0, 34}},
	{"subu", { 0, 0, 0, 0, 0, 35}},
	{"and", {0, 0, 0, 0, 0, 36}},
	{"or", { 0, 0, 0, 0, 0, 37}},
	{"slt", {0, 0, 0, 0, 0, 42}},
	{"sltu", {0, 0, 0, 0, 0, 43}},
	{"mul", {28, 0, 0, 0, 0, 2}}
};

// Vetor com todas as instru��es poss�veis
const vector <string> allInstructions = { "j", "jal",
"beq", "bne", "addi", "addiu", "andi", "ori", "slti", "sltiu", "lui", "lw", "sw",
"sll", "srl", "jr", "mfhi", "mthi", "mflo", "mult", "multu", "div", "divu", "add", "addu", "sub", "subu", "and", "or", "slt", "sltu", "mul" };

// Fun��o que retorna a string bin�ria de uma instru��o do tipo R
string bitRFunction(Func function) {

	// Converte para bin�rio conforme o tamanho de cada campo
	string binaryOp = bitset<6>(function.opCode).to_string();
	string binaryRs = bitset<5>(function.rs).to_string();
	string binaryRt = bitset<5>(function.rt).to_string();
	string binaryRd = bitset<5>(function.rd).to_string();
	string binaryShamt = bitset<5>(function.shamt).to_string();
	string binaryFunct = bitset<6>(function.funct).to_string();

	string binary = binaryOp + binaryRs + binaryRt + binaryRd + binaryShamt + binaryFunct;

	return binary;
}

// Fun��o que trata as instru��es do tipo R
Func treatingRFunction(string line) {

	string funcName = getFunction(line);
	Func function = functionsMap[funcName];
	vector<int> registers = getRegister(line);
	int shamt = getImediate(line);

	// Atribui os valores dos registradores conforme a fun��o
	// dependendo da fun��o a posi��o dos registradores no bin�rio pode ser definido de forma diferente
	if (funcName == "sll" || funcName == "srl")
	{
		function.rd = registers[0];
		function.rt = registers[1];
	}
	else if (funcName == "jr")
	{
		function.rs = registers[0];
	}
	else if (funcName == "mfhi" || funcName == "mflo")
	{
		function.rd = registers[0];
	}
	else if (funcName == "mult" || funcName == "multu" || funcName == "div" || funcName == "divu")
	{
		function.rs = registers[0];
		function.rt = registers[1];
	}
	else
	{
		function.rd = registers[0];
		function.rs = registers[1];
		function.rt = registers[2];
	}

	function.shamt = shamt;

	return function;
}

// Fun��o para ler as instru��es do tipo I
string typeI(string nameOP, int rs, int rt, unsigned short address)
{
	// Abre o arquivo com os opcodes
	ifstream fin;
	// Inicializa um vetor do tipo opcode, que guarda o nome da instru��o e seu valor
	opcode opI[11]; int i = 0;
	fin.open("opcode.txt");
	// Teste para verificar se o arquivo foi lido corretamente
	if (!fin.is_open())
	{
		cout << "Abertura do .txt falhou!";
		exit(EXIT_FAILURE);
	}

	// Ler do arquivo e salva na vari�vel opI
	for (int i = 0; i < 11; i++)
	{
		fin >> opI[i].name;
		fin >> opI[i].value;
	}
	fin.close();

	// Teste para achar a posi��o do vetor que est� a instru��o passada como par�metro
	for (int j = 0; j < 11; j++)
	{
		if (nameOP == opI[j].name) {
			i = j;
		}
	}

	// Converte para bin�rio cada valor de acordo com sua respectiva quantidade de bits 
	string binaryOP = bitset<6>(opI[i].value).to_string();
	string binaryRS = bitset<5>(rs).to_string();
	string binaryRT = bitset<5>(rt).to_string();
	string binaryAD = bitset<16>(address).to_string();

	string binary;

	// Junta tudo para forma um bin�rio de 32 bits
	binary.append(binaryOP);
	binary.append(binaryRS);
	binary.append(binaryRT);
	binary.append(binaryAD);

	return binary;
}

// Fun��o que retorna a string bin�ria de uma instru��o do tipo J
string typeJ(string nameOP, unsigned int address)
{
	string binary, binaryOP;

	// Condicional para verificar qual intru��o �, convertendo para bin�rio de acordo com sua quantidade de bits
	if (nameOP == "jal")
	{
		binaryOP = bitset<6>(3).to_string();
	}
	else
	{
		binaryOP = bitset<6>(2).to_string();
	}

	// Converte o endere�o para bin�rio  
	string binaryAD = bitset<26>(address).to_string();

	// Junta tudo para forma um bin�rio de 32 bits
	binary.append(binaryOP);
	binary.append(binaryAD);

	return binary;
}

// Fun��o que monta o binario conforme o tipo
string assembling(string line, map<string, int> labels, int currentLine)
{
	// Pega o nome da fun��o
	string funcName = getFunction(line);

	// se o que achar n�o for uma fun��o v�lida, retorna vazio para ser posteriormente tratada
	if (find(allInstructions.begin(), allInstructions.end(), funcName) == allInstructions.end())
		return "";

	// se for uma fun��o do tipo R, chama a fun��o que trata as fun��es do tipo R
	if (functionsMap.find(funcName) != functionsMap.end())
		return bitRFunction(treatingRFunction(line));
	// Trata fun��es do tipo j
	else if (funcName == "j" || funcName == "jal")
	{
		string label = getLastWord(line);
		int labelAddress = labels[label]; // pega a linha do label

		int address = labelAddress + initialAddress / 4;  // Calcula o endere�o conforme o endere�o inicial por se tratar de um endere�o incondicional

		return typeJ(funcName, address);
	}
	// Trata fun��es do tipo I (as que sobraram)
	else {
		vector<int> registers = getRegister(line);
		if (funcName == "beq" || funcName == "bne")
		{
			int rs = registers[0];
			int rt = registers[1];

			int labelAddress = labels[getLastWord(line)]; // pega a linha da label
			int address = labelAddress - (currentLine + 1); // usando PC como referencia
			return typeI(funcName, rs, rt, address);
		}
		else if (funcName == "addi" || funcName == "addiu" || funcName == "andi" || funcName == "ori" || funcName == "slti" || funcName == "sltiu")
		{
			int rt = registers[0];
			int rs = registers[1];
			int imediate = getImediate(line);
			return typeI(funcName, rs, rt, imediate);
		}
		else if (funcName == "lui")
		{
			int rt = registers[0];
			int imediate = getImediate(line);
			return typeI(funcName, 0, rt, imediate);
		}
		else if (funcName == "lw" || funcName == "sw")
		{
			int rt = registers[0];
			int rs = registers[1];
			int imediate = getImediate(line);
			return typeI(funcName, rs, rt, imediate);
		}
	}
}

// Fun��o que escreve a instru��o em hexadecimal
string assemblingHexa(string line, map<string, int> labels, int currentLine) {
	string binary = assembling(line, labels, currentLine);
	return convertToHexa(binary);
}
