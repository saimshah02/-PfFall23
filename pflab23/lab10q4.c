#include <stdio.h>
#include <string.h>

// Function to reverse a word using pointer arithmetic
void reverseWord(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to reverse each word in a sentence
void reverseSentenceWords(char *sentence) {
    char *start = sentence;
    char *end = sentence;

    while (*end) {
        // Find the end of the current word
        while (*end && *end != ' ') {
            end++;
        }

        // Reverse the current word
        reverseWord(start, end - 1);

        // Move to the next word (if any)
        if (*end) {
            start = end + 1;
            end++;
        }
    }
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character from the input
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    // Reverse each word in the sentence
    reverseSentenceWords(sentence);

    // Print the modified sentence
    printf("Modified Sentence: %s\n", sentence);

    return 0;
}

