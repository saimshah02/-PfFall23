#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an employee
struct Employee {
    char name[20];
    char role[20];
    int communication;
    int teamwork;
    int creativity;
};

// Structure to represent a department
struct Department {
    char name[20];
    struct Employee employees[5];
    int totalCommunication;
    int totalTeamwork;
    int totalCreativity;
};

// Function to generate a random name
void generateRandomName(char names[][20], int index) {
    int randomIndex = rand() % 20;
    while (names[randomIndex][0] == '\0') {
        randomIndex = rand() % 20;
    }

    strcpy(names[randomIndex], "");
    sprintf(names[index], "Name%d", index + 1);
}

// Function to initialize attributes of employees in a department
void initializeDepartment(struct Department *department, char names[][20]) {
    char roles[5][20] = {"Director", "Executive", "Manager", "Employee", "Trainee"};

    for (int i = 0; i < 5; i++) {
        generateRandomName(names, i);
        strcpy(department->employees[i].name, names[i]);
        strcpy(department->employees[i].role, roles[i]);
        department->employees[i].communication = rand() % 100 + 1;
        department->employees[i].teamwork = rand() % 100 + 1;
        department->employees[i].creativity = rand() % 100 + 1;

        department->totalCommunication += department->employees[i].communication;
        department->totalTeamwork += department->employees[i].teamwork;
        department->totalCreativity += department->employees[i].creativity;
    }
}

// Function to display the details of a department
void displayDepartment(struct Department *department) {
    printf("\n%s Department\n", department->name);
    printf("%-15s%-15s%-15s%-15s%-15s\n", "Name", "Role", "Communication", "Teamwork", "Creativity");

    for (int i = 0; i < 5; i++) {
        printf("%-15s%-15s%-15d%-15d%-15d\n", department->employees[i].name, department->employees[i].role,
               department->employees[i].communication, department->employees[i].teamwork, department->employees[i].creativity);
    }

    printf("\nTotal Communication: %d\n", department->totalCommunication);
    printf("Total Teamwork: %d\n", department->totalTeamwork);
    printf("Total Creativity: %d\n", department->totalCreativity);
}

int main() {
    // Seed for randomization
    srand((unsigned int)time(NULL));
    int i;
    // Initialize department names and employee names pool
    char departmentNames[4][20] = {"HR", "Finance", "Marketing", "Logistics"};
    char namesPool[20][20];
    for (i = 0; i < 20; i++) {
        sprintf(namesPool[i], "Name%d", i + 1);
    }

    // Initialize departments
    struct Department departments[4];
    for ( i = 0; i < 4; i++) {
        strcpy(departments[i].name, departmentNames[i]);
        departments[i].totalCommunication = 0;
        departments[i].totalTeamwork = 0;
        departments[i].totalCreativity = 0;

        initializeDepartment(&departments[i], namesPool);
    }

    // Display department details
    for (i = 0; i < 4; i++) {
        displayDepartment(&departments[i]);
    }

    // Find the best department
    int bestDepartmentIndex = 0 ,i;
    for (i = 1; i < 4; i++) {
        if (departments[i].totalCommunication + departments[i].totalTeamwork + departments[i].totalCreativity >
            departments[bestDepartmentIndex].totalCommunication + departments[bestDepartmentIndex].totalTeamwork +
                departments[bestDepartmentIndex].totalCreativity) {
            bestDepartmentIndex = i;
        }
    }

    // Display the best department
    printf("\nBest Department: %s\n", departments[bestDepartmentIndex].name);
    printf("\nBest Department Details:\n");
    displayDepartment(&departments[bestDepartmentIndex]);

    return 0;
}

