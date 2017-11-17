# NAME 		: ASHWIN JOISA
# ROLL NO 	: 16CO104
# DATE 		: 24/08/2017

#Question 8b: Factorial Program. Load a random number in $t0. Calculate its factorial using (b) recursion.


.globl main 
.text 		

main:
	
	li $t0, 8 					# Factorial to calculate
	
	sw $t0, 0($sp) 				# Passing $t0 as a parameter, saving in stack segment
	la $t2, after_rec 			# Return address after recursion
	sw $t2, -4($sp) 			# Saving return address in stack segment
	add $sp, $sp, -8 			# Incremend stack pointer
	j fact_rec 					# Calling the fact_rec function

fact_rec:
	
	# Base Case
	lw $t2, 8($sp) 				# Get value of parameter n
	bne $t2, $0, rec_calls 		# if n!=1 continue with recursive calls

	li $v0, 1 					# Else, Set return value to 1
	lw $t2, 4($sp) 				# Fecth return address
	add $sp, $sp, 8 			# Pop from stack segment
	jr $t2 						# Return to caller

	# Get fact(n-1)
	rec_calls: 					

		la $t3, return_point 	# Save return point for the PC to return after recursive calls
		add $t2, $t2, -1 		# n--
		sw $t2, 0($sp) 			# Passing n as a parameter, saving in stack segment
		sw $t3, -4($sp) 		# Saving return address in stack segment
		add $sp, $sp, -8 		# Incremend stack pointer
		j fact_rec 				# Recursive call to fact_rec

	# return n*fact(n-1)
	return_point:

		lw $t2, 8($sp) 			# Get value of parameter n
		mult $t2, $v0
		mflo $v0 				# fact = fact * n

		lw $t2, 4($sp) 			# Fectch return address
		add $sp, $sp, 8 		# Pop from stack segment
		jr $t2 					# Return to caller

after_rec:

	add $t1, $v0, $0 			# Copying answer from $v0, to $t1
	ori $v0, $0, 10 			# 10 is the exit syscall
	syscall 					# exit


# Result : 8! = 40320 (stored in $t1)