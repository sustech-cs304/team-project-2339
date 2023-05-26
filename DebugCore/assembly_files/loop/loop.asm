.data   0x0000
	buf:   .word  0xFFFFFC60, 0xFFFFFC70 #input and output address in main

	# FFFFFC60 input
	# FFFFFC70 output

.text	0x0000
start:
	lw   $v0,buf($zero)
	add  $t0,$zero,$v0
	andi $t2,$t0,1
	sub  $t0,$zero,$v0
	addi $t0,$zero,4
	lw   $v0,buf($t0)
	j start
