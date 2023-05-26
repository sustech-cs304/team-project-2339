.text
main:
	move $a1, $v0 # load positive integer as second argument
	jal bin_length # call get length function

	move $a0, $s0 # load length as first argument
	jal bin_reverse # call the reverse function

	jal hex_length

	move $a0, $s0
	jal main

bin_length:
	li $a2, 1 # load bit width of base as third argument
	j length
bin_reverse:
	li $a2, 1 # load bit width of base as third argument
	j reverse

hex_length:
	li $a2, 4
	j length
hex_reverse:
	li $a2, 4
	j reverse

# a1: positive integer
# a2: bit width of base
# t0: remaining number value
# s0: length of number
length:
	move $t0, $a1
	li $s0, 0

length_loop:
	srlv $t0, $t0, $a2
	addu $s0, $s0, 1
	bnez $t0, length_loop

	jr $ra

# a0: length of number
# a1: positive integer
# a2: bit width of base
# t0: remaining number
# t1: mask for digit
# t2: current digit value
# s0: reversed number
reverse:
	move $t0, $a1
	li $t1, 1
	li $s0, 0
	sllv $t1, $t1, $a2 # shift left
	subu $t1, $t1, 1 # subtract by 1 to obtain the mask

reverse_loop:
	and $t2, $t0, $t1
	srlv $t0, $t0, $a2
	sllv $s0, $s0, $a2
	or $s0, $s0, $t2
	bnez $t0, reverse_loop

	jr $ra

	syscall
