# Simulation of MIPS Assembly language in SPIM

- This assignment contains 8 questions, each one in a seperate directory.
- Each directory contains the MIPS-I Assembly code of the given question
  and few screenshots of the simulator at key execution stages.


##### PROGRAM 1

Loads 10^9 in $t0, 5x10^8 in $t1.
Calculates their sum and loads it in $t2.

##### PROGRAM 2

Loads 10^9 into $t0, and stores in memory address pointed to by global pointer.
Loads 5x10^8 into $t1, and stores in the starting of data segment.
Calculates their sum and loades it in $t2, then stores it in 100th word of data segment.

##### PROGRAM 3

Prints "Hello World"

##### PROGRAM 4

The numbers 10 to 19 (both inclusive) are written from the start of the data segment contiguously.
The sum is accumulated and then tranfered into $v0

##### PROGRAM 5

The string "Ashwin Joisa says Hello world!" is reversed in the data segment.
It swaps the ith character with the ith last character for all i less than the length of the string.

##### PROGRAM 6

The list of numbers [1, 3, 2, 7, 10] are loaded into data segment (.data)
A function accepts the base address and length of the array and returns the sum.
The average is then calculated.

##### PROGRAM 7

The following matrix multiplication is carried out with the help of a function
```
|1 2|   |4 3|   |14  7|
|3 4| x |5 2| = |32 17|
|5 6|           |50 27|
```
The function takes 7 parameters:
- Base address of matrix 1 and 2
- Size (NxM) of both matrices
- Base address of resultant matrix (where to store result)

##### PROGRAM 8(a)

The value of 8! (40320) is calculated using loops.

##### PROGRAM 8(b)

The value of 8! (40320) is calculated using recursion.
It makes use of the program stack.
