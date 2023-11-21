#include <stdio.h>

// Define the Register structure
struct Register {
    int courseId;
    char courseName[50];
};

// Define the Student structure inheriting from Register
struct Student {
    int studentId;
    char firstName[50];
    char lastName[50];
    char cellNo[15];
    char email[50];
    struct Register registration; // Embedding Register structure
};

int main() {
    // Declare an array of struct Student for 5 students
    struct Student students[5];
    int i;

    // Input data for 5 students
    for ( i = 0; i < 5; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Student ID: ");
        scanf("%d", &students[i].studentId);
        printf("First Name: ");
        scanf("%s", students[i].firstName);
        printf("Last Name: ");
        scanf("%s", students[i].lastName);
        printf("Cell No: ");
        scanf("%s", students[i].cellNo);
        printf("Email: ");
        scanf("%s", students[i].email);

        // Input data for the Registration part
        printf("Enter course ID for student %d: ", i + 1);
        scanf("%d", &students[i].registration.courseId);
        printf("Enter course name for student %d: ", i + 1);
        scanf("%s", students[i].registration.courseName);

        printf("\n");
    }

    // Print the details of all students
    printf("Details of all students:\n");
    for ( i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("Student ID: %d\n", students[i].studentId);
        printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
        printf("Cell No: %s\n", students[i].cellNo);
        printf("Email: %s\n", students[i].email);
        printf("Course ID: %d\n", students[i].registration.courseId);
        printf("Course Name: %s\n", students[i].registration.courseName);
        printf("\n");
    }

    return 0;
}

