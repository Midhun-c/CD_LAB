#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int symbolCount = 0, expressionLength, i = 0, j = 0;
    void *symbolAddress, *symbolTableAddresses[100];  // Increased size to handle more symbols
    char currentChar, inputChar;
    char expression[100], symbols[100];  // Increased size for larger expressions

    printf("Input the expression ending : ");
    while ((inputChar = getchar()) != '\n') {
        expression[i] = inputChar;
        i++;
    }
    expression[i] = '\0';  // Null-terminate the string
    expressionLength = i - 1;

    printf("Given Expression: ");
    i = 0;
    while (i <= expressionLength) {
        printf("%c", expression[i]);
        i++;
    }
    printf("\nSymbol Table display\n");
    printf("Symbol \t\t addr \t\t type\n");

    while (j <= expressionLength) {
        currentChar = expression[j];
        if (isalpha(currentChar)) {
            symbolAddress = malloc(sizeof(char));  // Allocate memory correctly
            if (symbolAddress == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            symbolTableAddresses[symbolCount] = symbolAddress;
            symbols[symbolCount] = currentChar;
            printf("%c \t\t %p \t identifier\n", currentChar, (void*)symbolAddress);
            symbolCount++;
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '=') {
            symbolAddress = malloc(sizeof(char));  // Allocate memory correctly
            if (symbolAddress == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            symbolTableAddresses[symbolCount] = symbolAddress;
            symbols[symbolCount] = currentChar;
            printf("%c \t\t %p \t operator\n", currentChar, (void*)symbolAddress);
            symbolCount++;
        }
        j++;
    }

    // Free the allocated memory
    for (i = 0; i < symbolCount; i++) {
        free(symbolTableAddresses[i]);
    }

    return 0;
}
