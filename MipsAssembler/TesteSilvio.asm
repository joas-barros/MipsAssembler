L1: add $1, $2, $3 #sim
L2:	sub $1,$2,$3 #sim
	addi $1, $2, 100 #sim
	addu $1, $2, $3 #sim
	# nao
	subu $1, $2, $3 #sim
	addiu $1, $2, 100 #sim
	mul $1, $2, $3 #sim
	mult $2, $3 #sim
	multu $2, $3 #sim
	div $2, $3 #sim
	and $1, $2, $3 #sim
	or $1, $2, $3 #sim
	andi $1,$2,100 #sim
	ori $1, $2, 100 #sim
	sll $1, $2, 10 #sim
	srl $1, $2, 10 #sim
	lw $1, 100 ($2) #sim
	sw $1, 100 ($2) #sim
	lui $1, 100 #sim
	# nao
	mfhi $2 #sim
	mflo $2 #sim
L3:	beq $1, $2, L1 #sim
 	bne $1, $2, L2 #sim
	slt $1, $2, $3 #sim
	slti $s0, $s1, 100 #sim
	j L1 #sim
	jr $1 #sim
	jal L3 #comentario na mesma linha da instrucao