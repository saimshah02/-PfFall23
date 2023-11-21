#include <stdio.h>
#include <string.h>

// Define a structure to store book information
struct Book {
    int accessionNumber;
    char author[50];
    char title[100];
    int isIssued; // 0 if not issued, 1 if issued
};

// Function to display book information
void displayBookInfo(struct Book *book) {
    printf("Accession Number: %d\n", book->accessionNumber);
    printf("Author: %s\n", book->author);
    printf("Title: %s\n", book->title);
    printf("Issued: %s\n", (book->isIssued) ? "Yes" : "No");
    printf("\n");
}

// Function to display all books by a particular author
void displayBooksByAuthor(struct Book library[], int totalBooks, const char *author) {
	int i;
    printf("Books by %s:\n", author);
    for ( i = 0; i < totalBooks; i++) {
        if (strcmp(library[i].author, author) == 0) {
            displayBookInfo(&library[i]);
        }
    }
}

// Function to display the number of books of a particular title
void displayNumberOfBooksByTitle(struct Book library[], int totalBooks, const char *title) {
    int i,count = 0;
    for ( i = 0; i < totalBooks; i++) {
        if (strcmp(library[i].title, title) == 0) {
            count++;
        }
    }
    printf("Number of books with title \"%s\": %d\n", title, count);
}

// Function to display the total number of books in the library
void displayTotalNumberOfBooks(int totalBooks) {
    printf("Total number of books in the library: %d\n", totalBooks);
}

// Function to issue a book
void issueBook(struct Book *book) {
    if (book->isIssued == 0) {
        book->isIssued = 1;
        printf("Book with Accession Number %d has been issued.\n", book->accessionNumber);
    } else {
        printf("Book with Accession Number %d is already issued.\n", book->accessionNumber);
    }
}

// Function to add a new book
void addNewBook(struct Book library[], int *totalBooks) {
    struct Book newBook;
    
    printf("Enter details for the new book:\n");
    printf("Accession Number: ");
    scanf("%d", &newBook.accessionNumber);
    printf("Author: ");
    scanf("%s", newBook.author);
    printf("Title: ");
    scanf("%s", newBook.title);
    newBook.isIssued = 0; // New books are not issued by default

    // Add the new book to the library
    library[*totalBooks] = newBook;
    (*totalBooks)++;

    printf("New book added to the library.\n");
}

int main() {
    // Assuming a maximum of 100 books in the library
    struct Book library[100];
    int totalBooks = 0;

    int choice,i;
    char author[50];
    char title[100];

    do {
        // Display menu
        printf("\nLibrary Menu:\n");
        printf("1 - Display book information\n");
        printf("2 - Add a new book\n");
        printf("3 - Display all books by a particular author\n");
        printf("4 - Display the number of books of a particular title\n");
        printf("5 - Display the total number of books in the library\n");
        printf("6 - Issue a book\n");
        printf("0 - Exit\n");

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display book information
                for ( i = 0; i < totalBooks; i++) {
                    displayBookInfo(&library[i]);
                }
                break;

            case 2:
                // Add a new book
                addNewBook(library, &totalBooks);
                break;

            case 3:
                // Display all books by a particular author
                printf("Enter the author's name: ");
                scanf("%s", author);
                displayBooksByAuthor(library, totalBooks, author);
                break;

            case 4:
                // Display the number of books of a particular title
                printf("Enter the title: ");
                scanf("%s", title);
                displayNumberOfBooksByTitle(library, totalBooks, title);
                break;

            case 5:
                // Display the total number of books in the library
                displayTotalNumberOfBooks(totalBooks);
                break;

            case 6:
                // Issue a book
                printf("Enter the Accession Number of the book to be issued: ");
                int accessionNumber;
                scanf("%d", &accessionNumber);
                for ( i = 0; i < totalBooks; i++) {
                    if (library[i].accessionNumber == accessionNumber) {
                        issueBook(&library[i]);
                        break;
                    }
                }
                break;

            case 0:
                // Exit the program
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

