#include <stdio.h>

// Define a structure to store employee information
struct Employee {
    char name[50];
    float salary;
    int hoursWorkedPerDay;
};

// Function to increase salary based on hours worked per day
void increaseSalary(struct Employee *employee) {
    if (employee->hoursWorkedPerDay > 8) {
        // Increase salary by 10% for overtime (more than 8 hours)
        employee->salary += employee->salary * 0.1;
    }
}

int main() {
    // Assuming 10 employees
    struct Employee employees[10];
    int i;

    // Input employee data (you can modify this part as needed)
    for ( i = 0; i < 10; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Hours worked per day: ");
        scanf("%d", &employees[i].hoursWorkedPerDay);

        // Increase salary based on hours worked per day
        increaseSalary(&employees[i]);

        printf("\n");
    }

    // Print the names of all employees along with their final salaries
    printf("Employee details after salary increase:\n");
    for ( i = 0; i < 10; i++) {
        printf("Name: %s, Final Salary: %.2f\n", employees[i].name, employees[i].salary);
    }

    return 0;
}

