# NAME 		: ASHWIN JOISA
# ROLL NO 	: 16CO104
# DATE 		: 23/08/2017

# Question 7: Along the same lines as the previous question (Question 6), implement a matrix multiplication program using functions.


.globl main 
.text 		

main:
	
	# Initialization + function call
	# Parameters : Base address, N, M for each matrix (NxM), and base address of result matrix
	# 7 parameters are stored in stack segment
	# Note : For matrix multiplication, M1 = N2.

	la $t0, mat1 				# Base address of matrix 1
	sw $t0, 0($sp) 				# First parameter
	li $t0, 3 					# N1 = 3
	sw $t0, 4($sp) 				# Second parameter
	li $t0, 2					# M1 = 2
	sw $t0, 8($sp) 				# Third parameter

	la $t0, mat2 				# Base address of matrix 2
	sw $t0, 12($sp) 			# Fourth parameter
	li $t0, 2 					# N2 = 2
	sw $t0, 16($sp) 			# Fifth parameter
	li $t0, 2 					# M2 = 2
	sw $t0, 20($sp) 			# Sixth parameter

	la $t0, mat2
	lui $t0, 4096 	 			# Base address of result matrix (beginning of data segment)
	sw $t0, 24($sp) 			# Seventh parameter

	jal mat_mult				# Call func

	ori $v0, $0, 10 			# 10 is the exit syscall
	syscall 					# exit


mat_mult:

	lw $t7, 8($sp) 							# Get value of M1 = N2
	li $s1, 4 								# Load constant 4
	lw $s2, 24($sp) 						# Load base address of result matrix

	li $t0, 0 								# i = 0
	first_loop:

		li $t1, 0 							# j = 0
		second_loop:

			li $t2, 0 						# k = 0
			li $s0, 0 						# res[i][j] = 0
			third_loop:

				# a[i][k]
				lw $t3, 0($sp) 				# Base address of matrix 1
				mult $t7, $t0 				# i x M1
				mflo $t4
				add $t4, $t4, $t2 			# i x M1 + k
				mult $t4, $s1
				mflo $t4
				add $t3, $t3, $t4 			# Address of a[i][k]
				lw $t6, 0($t3) 				# a[i][k]

				# b[k][j]
				lw $t3, 12($sp) 			# Base address of matrix 2
				mult $t7, $t2 				# k x N2
				mflo $t4
				add $t4, $t4, $t1 			# k x N2 + j
				mult $t4, $s1
				mflo $t4
				add $t3, $t3, $t4 			# Address of b[k][j]
				lw $t5, 0($t3) 				# b[k][j]

				# Updating res[i][j]
				mult $t5, $t6
				mflo $t5 					# a[i][k] x b[k][j]
				add $s0, $s0, $t5 			# Update res[i][j]

				add $t2, $t2, 1 			# k++
				bne $t2, $t7, third_loop 	# if(k<M1) repeat third_loop


			sw $s0, 0($s2) 					# Store res[i][j]
			add $s2, $s2, 4 				# Increment pointer of result matrix to next element

			add $t1, $t1, 1 				# j++
			lw $t3, 20($sp) 				# Get value of M2
			bne $t1, $t3, second_loop 		# if(j<M2) repeat second_loop
			

		add $t0, $t0, 1 					# i++
		lw $t3, 4($sp) 						# Get value of N1
		bne $t0, $t3, first_loop 			# if(i<N1) repeat first_loop

	jr $ra


.data
	mat1: .word 1, 2, 3, 4, 5, 6
	mat2: .word 4, 3, 5, 2

# Result
# |1 2|   |4 3|   |14  7|
# |3 4| x |5 2| = |32 17|
# |5 6|           |50 27|