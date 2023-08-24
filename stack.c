#include "monty.h"
#include <stdio.h>
#include <stdlib.h>


Stack *createStack() {
Stack *stack = (Stack *)malloc(sizeof(Stack));
if (!stack) {
perror("Error: malloc failed");
exit(EXIT_FAILURE);
}
stack->top = NULL;
return stack;
}

void pchar(Stack *stack, int line_number) {
int ascii_value;
if (stack->top == NULL) {
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
ascii_value = stack->top->data;

if (ascii_value < 0 || ascii_value > 127) {
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}

putchar(ascii_value);
putchar('\n');
}

void mod(Stack *stack, int line_number) {
int divisor;
int dividend;
int result;
if (stack->top == NULL || stack->top->next == NULL) {
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
divisor = pop(stack);
dividend = pop(stack);
if (divisor == 0) {
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
result = dividend % divisor;
push(stack, result);
}

void mul(Stack *stack, int line_number) {
int factor;
int product;

if (stack->top == NULL || stack->top->next == NULL) {
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
factor = stack->top->data;
product = stack->top->next->data * factor;
pop(stack); /* Remove the top element */
stack->top->data = product;
}

void swap(Stack *stack, int line_number) {
int temp;
if (stack->top == NULL || stack->top->next == NULL) {
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp = stack->top->data;
stack->top->data = stack->top->next->data;
stack->top->next->data = temp;
}

void pstr(Stack *stack) {
Node *current = stack->top;

while (current != NULL && current->data > 0 && current->data <= 127) {
putchar(current->data);
current = current->next;
}

putchar('\n');
}

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */
void rotl(Stack **stack, int line_number) {
(void)line_number; /* Avoid unused parameter warning */

if (*stack && (*stack)->top && (*stack)->top->next) {
Node *first = (*stack)->top;
Node *second = first->next;
Node *temp = first;

while (temp->next) {
temp = temp->next;
temp->next = first;
first->next = NULL;
(*stack)->top = second;
}
}
}
void monty_div(Stack *stack, int line_number) {
int divisor;
int quotient;
if (stack->top == NULL || stack->top->next == NULL) {
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
divisor = stack->top->data;
if (divisor == 0) {
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
quotient = stack->top->next->data / divisor;
pop(stack); /* Remove the top element */
stack->top->data = quotient;
}

void sub(Stack *stack, int line_number) {
int subtrahend;
int minuend;
int result;
if (stack->top == NULL || stack->top->next == NULL) {
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
subtrahend = pop(stack);
minuend = pop(stack);
result = minuend - subtrahend;
push(stack, result);
}

void nop() {
	/*do nothing */
}

void add(Stack *stack, int line_number) {
int sum;
if (stack->top == NULL || stack->top->next == NULL) {
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

sum = stack->top->data + stack->top->next->data;
pop(stack); /* Remove the top element */
stack->top->data = sum;
}

void pint(Stack *stack) {
if (stack->top == NULL) {
fprintf(stderr, "L: can't pint, stack empty\n");
exit(EXIT_FAILURE);
}
printf("%d\n", stack->top->data);
}

void push(Stack *stack, int value) {
Node *newNode = (Node *)malloc(sizeof(Node));
if (!newNode) {
perror("Error: malloc failed");
exit(EXIT_FAILURE);
}
newNode->data = value;
newNode->next = stack->top;
stack->top = newNode;
}

int pop(Stack *stack) {
int value;
Node *temp;
if (stack->top == NULL) {
fprintf(stderr, "Error: pop from empty stack\n");
exit(EXIT_FAILURE);
}
value = stack->top->data;
temp = stack->top;
stack->top = stack->top->next;
free(temp);
return value;
}

void freeStack(Stack *stack) {
Node *temp;
while (stack->top != NULL) {
temp = stack->top;
stack->top = stack->top->next;
free(temp);
}
free(stack);
}
