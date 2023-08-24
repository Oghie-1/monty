#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct Node {
int data;
struct Node *next;
} Node;

typedef struct {
Node *top;
} Stack;

Stack *createStack();
void push(Stack *stack, int value);
int pop(Stack *stack);
void pint(Stack *stack);
void freeStack(Stack *stack);
void printStack(Stack *stack);
int main(int argc, char *argv[]);
void swap(Stack *stack, int line_number);
void add(Stack *stack, int line_number);
void nop();
void sub(Stack *stack, int line_number);
void monty_div(Stack *stack, int line_number);
void mul(Stack *stack, int line_number);
void pchar(Stack *stack, int line_number);
void mod(Stack *stack, int line_number);
void pstr(Stack *stack);

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



#endif /* MONTY_H */
