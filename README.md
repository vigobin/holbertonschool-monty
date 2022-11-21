# Project 0x19. C - Stacks, Queues - LIFO, FIFO

## Description
This project involves learning about the following concepts:
 * What do LIFO and FIFO mean.
 * What is a stack, and when to use it.
 * What is a queue, and when to use it.
 * The common implementations of stacks and queues.
 * The most common use cases of stacks and queues.
 * The proper way to use global variables.

## Compilation
Files will be compiled on Ubuntu 20.04 LTS using: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty`.

## Output
* Any output will be printed on stdout.
* Any error message will be printed on stderr.

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
## Header File
`monty.h` will include all the prototypes of the functions.

## Monty Opcodes:

* ### push
 * The opcode push pushes an element to the stack.
 * Usage: `push <int>` where `<int>` is an integer.
 * Error handling: Exit with the status `EXIT_FAILURE`.

* ## pall

 * The opcode pall prints all the values on the stack, starting from the top of the stack.
 * If the stack is empty, don’t print anything.

* ## pint

 * The opcode pint prints the value at the top of the stack, followed by a new line.
 
* ## pop

 * The opcode pop removes the top element of the stack.

* ## swap

 * The opcode swap swaps the top two elements of the stack.
 
* ## add

 * The opcode add adds the top two elements of the stack.
 
* ## nop

 * The opcode nop doesn’t do anything.

## Authors

 * Taylor Poczynek
 * Vishal Gobin
