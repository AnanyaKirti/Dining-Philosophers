# Dining Philosophers Problem Simulation


## Introduction

The output is the state of the philosopher at each iteration.(assuming that the philosophers are dining according to a clock as in an OS)
All the philosopher who were able to eat are shown "eating", the rest who want to eat, but dont have a fork/chopstick are called "thinking".
Kindly let the code run for multiple iteration, to observe that the Eating Philosopher is random.

## How to run.

Compile the philosopher.c code. No argument required for input.

	```code
	$ ./philosopher



I have used mutex lock to avoid race conditions.
I have assumed that all the philosophers are always hungry. and all of them simultaneously request the needed resources. True parallelization is not possible in C, so I have used a for loop to initialize the threads, as discussed.

Each Philosopher needs two resources to eat, both of which are shared. Hence there is bound to be a dead lock. At max only two philosophers can eat, in an iteration. It is possible to have 0 , 1 or 2 philosophers eating.

I have provided a sample output as well.