# Assember Mips
- Mini Assembler written in C++ to complie code in mips architecture
 
 ## Purpose
 - The main goals of our repository is to construct a c++ code that is able to receive a file with .asm extension written entirely based on Mips architure of assembly and return a compiled text, either in binary or hexadecimal, of mips instrunctions for simulations purposes in logisim.
 - This program is built as a project for the Computer Achitecture class in Computer Science course of Universidade Federal Rural do Semi-Arido (UFERSA).

## Required

- Microsoft Visual Studio 2022

 ## How to run

 - First, clone our repository in your computer as follows

 ```bash
 git clone git@github.com:joas-barros/MipsAssembler.git
```
- Then, change your directory to the project's

 ```bash
 cd MipsAssembler
```

- Compiling the next assembly file, called test.asm, as an example 

 ```bash
 L1: add $t0, $s1, $s2 
 L2:    addi $t1, $s3, 7 
        beq $t0, $t1, L1
        j L2
```

- Type the next command to generate the binary code

 ```bash
./Assembler test.asm -b
```

- Result:

 ```bash
 00000010001100100100000000100000 00100010011010010000000000000111 00010001000010011111111111111101 00001000000100000000000000000001
```

- Type the next command to generate the decimal code

 ```bash
./Assembler test.asm -h
```

- Result:

 ```bash
v2.0 raw 
02324020
 22690007
 1109fffd 
 08100001
```

- "v2.0 raw" is a logisim requirement
- After generate the compiled filess, our code also returns the number of clocks per instructions in the command line 

```bash
Quantidades por tipo de instruções:
 add: 1
 addi: 1 
 beq: 1 
 j: 1 

 CPI médio: 1
```

## Limitations

- The MipsAssembler can only work with this instructions:

    - R Type

        - sll
        - slr
        - jr
        - mfhi
        - mflo
        - mult
        - multu
        - div
        - divu
        - add
        - addu
        - sub
        - subu
        - and
        - or
        - slt
        - sltu
        - mul
    
    - J Type

        - j
        - jal

    - I Type

        - beq
        - bne
        - addi
        - addiu
        - slti
        - sltiu
        - andi
        - ori
        - lui
        - lw
        - sw
    
    - If you want to pass a number is a immediate, you have to write it isolated

        - <p style="color:red;">WRONG</p> 
        -  ```bash
            andi $1, $2,100
	        ori $1, $2,100
	        sll $1, $2,10
	        srl $1, $2,10
	        lw $1, 100($2)
	        sw $1, 100($2)
	        lui $1,100
            ```
        
        - <p style="color:green;">RIGHT</p> 
        -  ```bash
            andi $1, $2, 100
	        ori $1, $2, 100
	        sll $1, $2, 10
	        srl $1, $2, 10
	        lw $1, 100 ($2)
	        sw $1, 100 ($2)
	        lui $1, 100
            ```

## How to colaborate

- Feel free to colaborate! Follow the next steps:

1. Fork the repository in your profile
2. Create your branch (git checkout -b my-branch)
3. Commit your changes (git commit -m "my changes")
4. Send your changes to your GitHub repository (git push origin my-branch)
5. Open a Pull Request

## Developers

- Support our development team by following them

- **Joás Gabriel** - [@joas-barros](https://github.com/joas-barros)
- **Lucas Silva** - [@Lucassilv7](https://github.com/Lucassilv7) 