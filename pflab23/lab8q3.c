#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    char searchChar;
    int count = 0;

    printf("Enter a text: ");
    fgets(input, sizeof(input), stdin);

    printf("Enter the character to search for: ");
    scanf(" %c", &searchChar);

    char *ptr = input;
    while ((ptr = strchr(ptr, searchChar)) != NULL) {
        count++;
        ptr++;  
    }

    printf("Total occurrences of '%c' in the text: %d\n", searchChar, count);

    return 0;
}

