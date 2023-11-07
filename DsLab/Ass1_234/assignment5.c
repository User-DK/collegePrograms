

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("\nEnter the length of the string: ");
    scanf("%d", &n);

    char x[n];
    printf("\nEnter the string: "); // Changed the prompt to make it clear we're entering characters
    for (int i = 0; i < n; i++) {
        scanf(" %c", &x[i]); // Used %c to scan characters, and added a space before %c to skip whitespace
    }

    char *start = &x[0];
    char *end = &x[n - 1];
    char t; // Changed t to char type

    for (int i = 0; i < n / 2; i++) {
        t = *start;
        *start = *end;
        *end = t; // Swap characters between start and end
        start++; // Move the start pointer forward
        end--;   // Move the end pointer backward
    }

    printf("\nThe reversed string is: ");
    for (int i = 0; i < n; i++) {
        printf("%c", x[i]); // Changed %d to %c to print characters
    }

    return 0;
}
