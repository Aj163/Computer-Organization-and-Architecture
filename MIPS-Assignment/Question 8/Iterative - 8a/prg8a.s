# NAME 		: ASHWIN JOISA
# ROLL NO 	: 16CO104
# DATE 		: 24/08/2017

#Question 8a: Factorial Program. Load a random number in $t0. Calculate its factorial using (a) loops.


.globl main 
.text 		

main:
	
	li $t0, 8 					# Factorial to calculate
	li $t1, 1 					# Answer variable

fact_loop:
	
	ble $t0, $0, end_of_loop 	# if(n<=0) done!
	mult $t0, $t1
	mflo $t1 					# fact = fact * n
	add $t0, $t0, -1 			# n--
	j fact_loop 				# Repeat loop

end_of_loop:

	ori $v0, $0, 10 			# 10 is the exit syscall
	syscall 					# exit


# Result : 8! = 40320 (stored in $t1)