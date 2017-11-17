# NAME 		: ASHWIN JOISA
# ROLL NO 	: 16CO104
# DATE 		: 22/08/2017

# Question 2: Load a 32b constant in the memory location pointed to by the global pointer. Load another 32b constant in
# 			  the first memory location of the data segment. Add them both and save the sum in the 100 th word of the data
# 			  segment.


.globl main 
.text 		

main:
	
	# Loading first constant
	li $t0, 1000000000			# Loads 10^9 into $t0
	sw $t0, 0($gp)				# Loads value in $t0 into memory location pointed by global pointer. 


	# Loading second constant
	li $t4, 268435456			# Starting address of data segment is 0x10000000 = 268435456
	li $t1, 500000000			# Loads 5 x 10^8 into $t1
	sw $t1, 0($t4)				# Loads value in $t1 into memory location at the start of data segment (0x1dcd6500 = 5 x 10^8). 


	# Adding
	add $t2, $t1, $t0


	# Loading sum into 100th word of data segment
	sw $t2, 396($t4)			# An offset of 396 is required to get to the 100 th word.

	
	ori $v0, $0, 10 			# 10 is the exit syscall
	syscall 					# exit


# Result
# Required Sum = 1.5 x 10^9
# Memory loaction of 100th word = 0x1000018c = 396($t4).