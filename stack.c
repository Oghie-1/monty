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