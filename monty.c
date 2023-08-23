#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printStack(Stack *stack) {
Node *current = stack->top;
while (current != NULL) {
printf("%d\n", current->data);
current = current->next;
}
}

int main(int argc, char *argv[]) {

FILE *file;
char line[MAX_LINE_LENGTH];
int line_number = 0;
char *opcode;
int value;
char *argument;
Stack *stack;

if (argc != 2) {
fprintf(stderr, "USAGE: %s file\n", argv[0]);
return EXIT_FAILURE;
}

file = fopen(argv[1], "r");
if (!file) {
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return EXIT_FAILURE;
}

stack = createStack();


while (fgets(line, sizeof(line), file) != NULL) {
line_number++;

opcode = strtok(line, " \t\n");
if (!opcode) {
continue; /* Empty line */
}
argument = strtok(NULL, " \t\n");

if (strcmp(opcode, "push") == 0) {
if (!argument) {
fprintf(stderr, "L%d: missing argument for push\n", line_number);
freeStack(stack);
fclose(file);
return EXIT_FAILURE;
}
sscanf(argument, "%d", &value);
push(stack, value);
} else if (strcmp(opcode, "pop") == 0) {
pop(stack);
} else if (strcmp(opcode, "pall") == 0) { /*Implement Pall Operation*/
printStack(stack);
} else if (strcmp(opcode, "pint") == 0) { /*Implement pint Operation */
printf("Executing pint\n"); /* Debug print */
pint(stack);
} else if (strcmp(opcode, "swap") == 0) { /* Implement swap operation */
swap(stack);
} else {
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
freeStack(stack);
fclose(file);
return EXIT_FAILURE;
}
}

freeStack(stack);
fclose(file);
return EXIT_SUCCESS;
}
