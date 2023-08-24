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
