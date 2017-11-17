# NAME 		: ASHWIN JOISA
# ROLL NO 	: 16CO104
# DATE 		: 22/08/2017

# Question 1: Load two 32b constants on to $t0 and $t1. Add them and store the result in $t2.

.globl main 
.text 		

main:
	
	# Loading 1000000000 (10^9) into $t0
	li $t0, 1000000000

	# Loading 500000000 (5 x 10^8) into $t1
	li $t1, 500000000	

	# Adding
	add $t2, $t1 $t0		# Stored in $t2

	# Exit
	ori $v0, $0, 10 		# 10 is the exit syscall
	syscall 				# exit

# Result = 1500000000