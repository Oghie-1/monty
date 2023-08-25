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
if (opcode == NULL || opcode[0] == '#') {
continue; /* Empty line or line that start with #*/
}
argument = strtok(NULL, " \t\n");
if (strcmp(opcode, "pstr") == 0) {
pstr(stack);
}
if (strcmp(opcode, "push") == 0) {
argument = strtok(NULL, "\t\n");
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
} else if (strcmp(opcode, "monty_div") == 0) { /* Implement swap operation */
monty_div(stack, line_number);
} else if (strcmp(opcode, "mul") == 0) { /* Implement mul operation */
mul(stack, line_number);
} else if (strcmp(opcode, "sub") == 0) { /* Implement sub operation */
sub(stack, line_number);
} else if (strcmp(opcode, "swap") == 0) { /* Implement swap operation */
swap(stack, line_number);
} else if (strcmp(opcode, "mod") == 0) { /* Implement swap operation */
mod(stack, line_number);
}else if (strcmp(opcode, "add") == 0) {
add(stack, line_number);
}else if (strcmp(opcode, "pchar") == 0) {
pchar(stack, line_number);
} else if (strcmp(opcode, "nop") == 0) { /* Implement nop operation */
nop(stack);
} else if (strcmp(opcode, "stack") == 0) {
setStackMode(line_number);
continue;
} else if (strcmp(opcode, "queue") == 0) {
setQueueMode(&stack, line_number);
continue;
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
