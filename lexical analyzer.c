#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]) {
    char keywords[40][40] = {
        "switch", "typedef", "union", "unsigned", "void", "long", "register", "short", "signed",
        "sizeof", "static", "volatile", "while", "auto", "break", "case", "char", "const", 
        "continue", "default", "do", "double", "enum", "extern", "return", "struct", "float", 
        "for", "goto", "if", "int", "else"
    };
    int i, isKeywordFlag = 0;
    for (i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            isKeywordFlag = 1;
            break;
        }
    }
    return isKeywordFlag;
}

int main() {
    char currentChar, buffer[15], operators[] = "+-*/%=";
    FILE *inputFile;
    int i, bufferIndex = 0;

    inputFile = fopen("t4tutorials.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open the file\n");
        exit(1);
    }

    while ((currentChar = fgetc(inputFile)) != EOF) {
        for (i = 0; i < 6; ++i) {
            if (currentChar == operators[i]) {
                printf("%c : operator\n", currentChar);
            }
        }
        if (isalnum(currentChar)) {
            buffer[bufferIndex++] = currentChar;
        } else if ((currentChar == ' ' || currentChar == '\n') && (bufferIndex != 0)) {
            buffer[bufferIndex] = '\0';
            bufferIndex = 0;
            if (isKeyword(buffer) == 1) {
                printf("%s : keyword\n", buffer);
            } else {
                printf("%s : identifier\n", buffer);
            }
        }
    }

    fclose(inputFile);
    return 0;
}
