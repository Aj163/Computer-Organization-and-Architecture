# NAME 		: ASHWIN JOISA
# ROLL NO 	: 16CO104
# DATE 		: 22/08/2017

# Question 5: Write a program to reverse a string (choose your favorite string as a global parameter).


.globl main 
.text 		

main:
	
	# Initializing
	la $t0, to_rev				# Start address of the string
	

strlen: 						# Calculates no of bytes required to store the string.
	
	lb $t2, 0($t0) 				# Get contents of M($t0)
	add $t0, $t0, 1 			# Go to next word
	bne $t2, 0, strlen 			# Check for end of string


	# Re-initializing
	la $t1, to_rev				# Start address of the string
	add $t0, $t0, -2 			# End address of the string

strrev: 						# Reverses the string

	lb $t2, 0($t1)
	lb $t3, 0($t0)
	sb $t2, 0($t0)
	sb $t3, 0($t1) 				# Swap the characters pointed by $t1, and $t0

	add $t1, $t1, 1 			# Address pointed to by $t1 ++
	add $t0, $t0, -1 			# Address pointed to by $t0 --
	ble $t1, $t0, strrev 		# Check if all reversals are done (while $t1 < $t0)


	ori $v0, $0, 10 			# 10 is the exit syscall
	syscall 					# exit

.data
	to_rev: .asciiz "Ashwin Joisa says Hello world!"