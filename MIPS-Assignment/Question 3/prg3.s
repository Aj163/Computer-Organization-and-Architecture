# NAME 		: ASHWIN JOISA
# ROLL NO 	: 16CO104
# DATE 		: 22/08/2017

# Question 3: Hello World Program. Print “Hello World” on the output screen.


.globl main 
.text 		

main:
	
	ori $v0, $0, 4		# 4 is the print_string syscall
	la	$a0, to_print	# Pointer to string (load the address of to_print)
	syscall

	ori $v0, $0, 10 	# 10 is the exit syscall
	syscall 			# exit

.data
	to_print: .asciiz "Hello World"