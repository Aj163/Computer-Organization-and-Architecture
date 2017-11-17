# NAME 		: ASHWIN JOISA
# ROLL NO 	: 16CO104
# DATE 		: 23/08/2017

# Question 6: Implement a function that calculates the sum of the elements of the array. The function accepts the length of
#			  the array and the address of the first element of the array. The function returns the sum to the caller. The
#			  main procedure calculates the average of the elements of the array. The main procedure uses the mentioned
#			  the function. Use the MIPS compiler subroutine conventions for this code.


.globl main 
.text 		

main:
	
	# Initialization + function call
	add $a0, $0, 5 				# Set first parameter (length of array) to 7
	la $a1, list 				# Set second parameter (Base address of array)
	jal func 					# Call func

	# Calculation of average
	mtc1 $v0, $f1 				# Load sum (return value) to a floating point register
	cvt.s.w $f1, $f1 			# Convert to floating point

	li $t0, 5 					# Load length of array to $t0
	mtc1 $t0, $f2 				# Load $t0 to a floating point register
	cvt.s.w $f2, $f2 			# Convert to floating point

	div.s $f3, $f1, $f2 		# Calculate average


	ori $v0, $0, 10 			# 10 is the exit syscall
	syscall 					# exit
	

func:
	li $t0, 0 					# Initializing sum to 0

	loop:
		ld $t1, 0($a1) 			# Get value pointed to by $a1 - second parameter 
		add $t0, $t0, $t1 		# Update sum
		add $a1, $a1, 4 		# $a0 now points to next element
		add $a0, $a0, -1 		# Length of array is reduced by 1 - first parameter
		bne $a0, $0, loop 		# If more elements remain in the array, loop back

	add $v0, $0, $t0 			# Return value set to sum
	jr $ra


.data
	list: .word 1, 3, 2, 7, 10

# Result
# Sum     : 23
# Average : 4.6