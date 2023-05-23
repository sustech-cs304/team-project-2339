.data
num1: .word 10       
num2: .word 20     

.text
.globl main

main:
    lw $s0, num1

    lw $s1, num2

    add $s0, $s0, $s1

    sw $s0, num1

    li $v0, 10
    syscall