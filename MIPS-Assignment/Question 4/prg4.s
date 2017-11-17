# NAME 		: ASHWIN JOISA
# ROLL NO 	: 16CO104
# DATE 		: 22/08/2017

# Question 4: Initialize a contiguous chunk of memory to contain 10 two digit decimal numbers. Your program should
#			  calculate the sum of these numbers and put the result into $v0.


.globl main 
.text 		

main:
	
	# Initializing variables
	lui $t0, 4096				# Starting address of data segemnt (0x10000000)
	ori $t1, $0, 0 				# Initializing Counter variable to 0
	ori $t2, $0, 10 			# Number to be written in data segment


init_loop: 						# Writing the numbers 10 to 19 into data segment, starting from the memory location 0x10000000
	
	sw $t2, 0($t0) 				# Writing the value in memory location
	addi $t0, $t0, 4 			# Increment address for next number to be written.
	addi $t2, $t2, 1 			# Increment number to be written in data segment
	addi $t1, $t1, 1 			# Increment counter variable
	bne $t1, 10, init_loop 		# if counter != 10 : goto loop_init


	# Re-initializing variables
	lui $t0, 4096				# Starting address of data segemnt (0x10000000)
	ori $t1, $0, 0  			# Initializing Counter variable to 0
	ori $t2, $0, 0 				# Current sum.


find_sum:

	ld $t3, 0($t0)
	add $t2, $t2, $t3 			# Adding the current element to the sum
	addi $t0, $t0, 4 			# Increment address for next number to be added.
	addi $t1, $t1, 1 			# Increment counter variable
	bne $t1, 10, find_sum 		# if counter != 10 : goto find_sum

	add $v0, $t2, $0 			# Transfering sum to $v0

	ori $v0, $0, 10 			# 10 is the exit syscall
	syscall 					# exit


# Result
# Writing the numbers from 10 to 19 (both inclusive from the beginning of data segment)
# Sum = 145