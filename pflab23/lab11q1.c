#include <stdio.h>
#include <string.h>

// Define a structure to store student data
struct Student {
    int rollNumber;
    char name[50];
    char department[50];
    char course[50];
    int yearOfJoining;
};

// Function to print names of students who joined in a particular year
void printStudentsByYear(struct Student students[], int totalStudents, int targetYear) {
	int i;
    printf("Students who joined in %d:\n", targetYear);
    for ( i = 0; i < totalStudents; i++) {
        if (students[i].yearOfJoining == targetYear) {
            printf("%s\n", students[i].name);
        }
    }
}

// Function to print data of a student given the roll number
void printStudentByRollNumber(struct Student students[], int totalStudents, int targetRollNumber) {
	int i;
    for (i = 0; i < totalStudents; i++) {
        if (students[i].rollNumber == targetRollNumber) {
            printf("Student Data for Roll Number %d:\n", targetRollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Department: %s\n", students[i].department);
            printf("Course: %s\n", students[i].course);
            printf("Year of Joining: %d\n", students[i].yearOfJoining);
            return;  // Found the student, exit the function
        }
    }
    // If the loop completes without finding the student
    printf("Student with Roll Number %d not found.\n", targetRollNumber);
}

int main() {
    // Assuming a maximum of 450 students
    struct Student students[450];

    // Populate student data (you can modify this part as needed)
    students[0] = {101, "John Doe", "Computer Science", "B.Tech", 2022};
    students[1] = {102, "Jane Smith", "Electrical Engineering", "M.Tech", 2021};
    // Add more students...

    int totalStudents = 2;  // Update this with the actual number of students

    // Example usage
    printStudentsByYear(students, totalStudents, 2022);
    printStudentByRollNumber(students, totalStudents, 101);

    return 0;
}

