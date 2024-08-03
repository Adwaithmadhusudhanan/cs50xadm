// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

char* replace(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case 'a':
                input[i] = '6';
                break;
            case 'e':
                input[i] = '3';
                break;
            case 'i':
                input[i] = '1';
                break;
            case 'o':
                input[i] = '0';
                break;
            // u does not change, so we skip it
        }
    }
    return input;
}




int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Please provide a single word as a command-line argument.\n");
        return 1;
    }

    char *inputWord = argv[1];
    char *convertedWord = replace(inputWord);
    printf("%s\n", convertedWord);

    return 0;
}
