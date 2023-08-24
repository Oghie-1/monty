#include <stdio.h>

int main() {
int digit1, result, digit2;

/* Read two digits from stdin */
printf("Enter the first digit: ");
scanf("%d", &digit1);

printf("Enter the second digit: ");
scanf("%d", &digit2);

/* Multiply the digits */
result = digit1 * digit2;

/* Print the result followed by a new line */
printf("Result: %d\n", result);

return 0;
}
