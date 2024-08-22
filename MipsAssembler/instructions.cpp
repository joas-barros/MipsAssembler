#include "instructions.h"
#include "Getters.h"
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin;

// Função para ler as instruções do tipo I
string typeI(string nameOP, int rs, int rt, unsigned short address)
{
    // Inicializa um vetor do tipo opcode, que guarda o nome da instrução e seu valor
    opcode opI[11]; int i = 0;
    // Abre o arquivo que contém os valores de opcode de cada instrução
    fin.open("opcode.txt");
    // Teste para verificar se o arquivo foi lido corretamente
    if (!fin.is_open()) 
    {
        cout << "Abertura do .txt falhou!";
        exit(EXIT_FAILURE);
    }
    // Ler do arquivo e salva na variável opI
    for (int i = 0; i < 11; i++)
    {
        fin >> opI[i].name;
        fin >> opI[i].value;
    }
    fin.close(); 

    // Teste para achar a posição do vetor que está a instrução passada como parâmetro
    for (int j = 0; j < 11; j++)
    {
        if(nameOP == opI[j].name) {
            i = j;
        }
    }

    // Converte para binário cada valor de acordo com sua respectiva quantidade de bits 
    string binaryOP = bitset<6>(opI[i].value).to_string();
    string binaryRS = bitset<5>(rs).to_string();
    string binaryRT = bitset<5>(rt).to_string();
    string binaryAD = bitset<16>(address).to_string();

    string binary;
    // Junta tudo para forma um binário de 32 bits
    binary.append(binaryOP);
    binary.append(binaryRS);
    binary.append(binaryRT);
    binary.append(binaryAD);

    return binary;
}

// Função para ler as instruções do tipo J
string typeJ(string nameOP, unsigned int address)
{ 
    string binary, binaryOP;
    // Condicional para verificar qual intrução é, convertendo para binário de acordo com sua quantidade de bits
    if (nameOP == "jal")
    {
        binaryOP = bitset<6>(3).to_string();
    }
    else 
    {
        binaryOP = bitset<6>(2).to_string();
    }
    // Converte o endereço para binário  
    string binaryAD = bitset<26>(address).to_string();
    
    // Junta tudo para forma um binário de 32 bits
    binary.append(binaryOP);
    binary.append(binaryAD);

    return binary;
}

void cpiMed(string fileName)
{
    // Variável do tipo cpi que guarda o nome, a quantidade de vezes utilizado e o valor do ciclo, respectivamente, de cada instrução 
    cpi informationCPI[] = { {"sll",0,0},{"srl",0,0},{"jr",0,0},{"mfhi",0,0},{"mflo",0,0},{"mult",0,0},{"multu",0,0},{"div",0,0},{"divu",0,0},
        {"add",0,0},{"addu",0,0},{"sub",0,0},{"subu",0,0},{"and",0,0},{"or",0,0},{"slt",0,0},{"sltu",0,0},{"mul",0,0},{"beq",0,0},
        {"bne",0,0},{"addi",0,0},{"addiu",0,0},{"slti",0,0},{"sltiu",0,0},{"andi",0,0},{"ori",0,0},{"lui",0,0},{"lw",0,0},{"sw",0,0},
        {"j",0,0},{"jal",0,0} };

    // Abre o arquivo que contém os valores de ciclo de cada instrução
    fin.open("cpi.csv");
    // Teste para verificar se o arquivo foi lido corretamente
    if (!fin.is_open())
    {
        cout << "Abertura do .csv falhou!";
        exit(EXIT_FAILURE);
    }

    string nameInstru;
    // Ler a linha de cabeçalho e ignora o próximo caractere
    fin >> nameInstru;
    fin.ignore(1);

    // Lê o nome de cada instrução do arquivo 
    while (getline(fin, nameInstru, ',')) {
        for (int i = 0; i < 31; i++)
        {
            // Quando ele achar o nome da instrução, que está salvo na variável do início, referente ao nome lido do arquivo
            // pegar o valor de ciclo contido no arquivo e guarda
            if (nameInstru == informationCPI[i].name)
            {
                fin >> informationCPI[i].value;
                i = 32; // saída do loop
            }
        }
        fin.ignore(1);
    }
    fin.close();

    string line;
    vector<string> nameInst;

    // Abre o arquivo de código .asm
    fin.open(fileName);
    // Teste para verificar se o arquivo foi lido corretamente
    if (!fin.is_open())
    {
        cout << "Abertura do .asm falhou!";
        exit(EXIT_FAILURE);
    }

    // Lê cada linha do código
    while (getline(fin, line)){
        // salva o nome da instrução lida naquela linha
        nameInstru = getFunction(line);
        // guarda o mesmo nome em um vetor para uso futuro
        nameInst.push_back(nameInstru);
        for (int i = 0; i < 31; i++)
        {
            // Quando ele achar o nome da instrução, que está salvo na variável do início, referente ao nome lido do arquivo
            // soma +1 na quantidade. Ao final terá a quantidade de vezes que aquela instrução aparece no código
            if (nameInstru == informationCPI[i].name)
            {
                informationCPI[i].quantity++;
                i = 32;
            }
        }
    }
    fin.close();

    // Pega o tamanho do vetor que foi populado acima (o que foi criado para uso futuro). Pois esse tamanho indica a quantidade de linhas 
    // do códgio
    int totalInstru = nameInst.size();

    int cpi, sum = 0, eq; 
    for (int j = 0; j < totalInstru; j++)
    {
        for (int i = 0; i < 31; i++)
        {
            // Quando ele achar o nome da instrução, que está salvo na variável do início, referente ao nome salvo no vetor 
            // (o que foi criado para uso futuro) calcula a equação do somatório
            if (nameInst[j] == informationCPI[i].name)
            {
                eq = informationCPI[i].quantity * informationCPI[i].value;
                i = 32;
            }
        }
        // Faz o somatório
        sum += eq;
    }
    // Obtém o cpi médio
    cpi = sum / totalInstru;

    // Mostra as informações na tela
    cout << "Quantidades por tipo de instruções: " << endl;
    for (int i = 0; i < totalInstru; i++)
    {
        for (int j = 0; j < 31; j++) {
            if (nameInst[i] == informationCPI[j].name)
            {
                cout << informationCPI[j].name << ": " << informationCPI[j].quantity << endl;
            }
        }
    }
    cout << "\nCPI médio: " << cpi;
}
