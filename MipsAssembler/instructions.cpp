#include "instructions.h"
#include "Getters.h"
#include <iostream>
#include <fstream>


ifstream fin;
ofstream fout;

string typeI(string nameOP, /*map<string, unsigned int>*/ int rs, /*map<string, unsigned int>*/ int rt, unsigned short address)
{
    opcode opI[11]; int i = 0;
    fin.open("opcode.txt");
    if (!fin.is_open())
    {
        cout << "Abertura do .txt falhou!";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 11; i++)
    {
        fin >> opI[i].name;
        fin >> opI[i].value;
    }
    fin.close();

    for (int j = 0; j < 11; j++)
    {
        if(nameOP == opI[j].name) {
            i = j;
        }
    }

    string binaryOP = std::bitset<6>(opI[i].value).to_string();
    string binaryRS = std::bitset<5>(rs).to_string();
    string binaryRT = std::bitset<5>(rt).to_string();
    string binaryAD = std::bitset<16>(address).to_string();

    string binary;

    binary.append(binaryOP);
    binary.append(binaryRS);
    binary.append(binaryRT);
    binary.append(binaryAD);

    return binary;
}

string typeJ(string nameOP, unsigned int address)
{ 
    string binary, binaryOP;

    if (nameOP == "jal")
    {
        binaryOP = std::bitset<6>(3).to_string();
    }
    else 
    {
        binaryOP = std::bitset<6>(2).to_string();
    }

    string binaryAD = std::bitset<26>(address).to_string();

    binary.append(binaryOP);
    binary.append(binaryAD);

    return binary;
}

void cpiMed(void)
{
    cpi informationCPI[] = { {"sll",0,0},{"srl",0,0},{"jr",0,0},{"mfhi",0,0},{"mflo",0,0},{"mult",0,0},{"multu",0,0},{"div",0,0},{"divu",0,0},
        {"add",0,0},{"addu",0,0},{"sub",0,0},{"subu",0,0},{"and",0,0},{"or",0,0},{"slt",0,0},{"sltu",0,0},{"mul",0,0},{"beq",0,0},
        {"bne",0,0},{"addi",0,0},{"addiu",0,0},{"slti",0,0},{"sltiu",0,0},{"andi",0,0},{"ori",0,0},{"lui",0,0},{"lw",0,0},{"sw",0,0},
        {"j",0,0},{"jal",0,0} };

    fin.open("cpi.csv");
    if (!fin.is_open())
    {
        cout << "Abertura do .csv falhou!";
        exit(EXIT_FAILURE);
    }

    string nameInstru;
    fin >> nameInstru;
    fin.ignore(1);
    
    while (getline(fin, nameInstru, ',')) {
        for (int i = 0; i < 31; i++)
        {
            if (nameInstru == informationCPI[i].name)
            {
                fin >> informationCPI[i].value;
                i = 32;
            }
        }
        fin.ignore(1);
    }
    fin.close();

    string line;
    vector<string> nameInst;

    fin.open("code2.asm");
    if (!fin.is_open())
    {
        cout << "Abertura do .asm falhou!";
        exit(EXIT_FAILURE);
    }

    while (getline(fin, line)){
        nameInstru = getFunction(line);
        nameInst.push_back(nameInstru);
        for (int i = 0; i < 31; i++)
        {
            if (nameInstru == informationCPI[i].name)
            {
                informationCPI[i].quantity++;
                i = 32;
            }
        }
    }
    fin.close();

    int totalInstru = nameInst.size();

    int cpi, sum = 0, eq; 
    for (int j = 0; j < totalInstru; j++)
    {
        for (int i = 0; i < 31; i++)
        {
            if (nameInst[j] == informationCPI[i].name)
            {
                eq = informationCPI[i].quantity * informationCPI[i].value;
                i = 32;
            }
        }
        sum += eq;
    }
    cpi = sum / totalInstru;

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

string convertToHexa(string bin) {

    std::bitset<32> set(bin);
    std::stringstream res;
    
    res << hex << uppercase << set.to_ulong();

    return res.str();
}