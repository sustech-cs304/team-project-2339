.data
	one: .double 1.0
	zero: .double 0.0
	increment: .double 1.0

# $f0 max reciprocal
# $f2 reciprocal to be added
# $f4 factorial
# $f6 number to multiply into factorial
# $f12 result
# $f8 increment 1
.text
	ldc1 $f2, zero
	ldc1 $f4, one
	ldc1 $f6, zero
	ldc1 $f12, one
	ldc1 $f8, increment

	li $v0, 7
	syscall

	c.lt.d $f12, $f0
	bc1t exit

loop:
	add.d $f12, $f12, $f2

	add.d $f6, $f6, $f8
	mul.d $f4, $f4, $f6
	div.d $f2, $f8, $f4

	c.lt.d $f2, $f0
	bc1f loop

exit:
	li $v0, 3
	syscall

	li $v0, 10
	syscall
