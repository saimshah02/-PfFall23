#include <stdio.h>

// Define the Employee structure
struct Employee {
    int employee_id;
    char name[50];
    float salary;
};

// Define the Organization structure with a nested Employee structure
struct Organization {
    char organisation_name[50];
    int organisation_number;
    struct Employee emp; // Nested structure
};

int main() {
    // Create an instance of the Organization structure
    struct Organization org;

    // Input organization data
    printf("Enter organization details:\n");
    printf("Organization Name: ");
    scanf("%s", org.organisation_name);
    printf("Organization Number: ");
    scanf("%d", &org.organisation_number);

    // Input employee data
    printf("\nEnter employee details:\n");
    printf("Employee ID: ");
    scanf("%d", &org.emp.employee_id);
    printf("Employee Name: ");
    scanf("%s", org.emp.name);
    printf("Employee Salary: ");
    scanf("%f", &org.emp.salary);

    // Display the information using the nested structure variables
    printf("\nOrganization Information:\n");
    printf("Organization Name: %s\n", org.organisation_name);
    printf("Organization Number: %d\n", org.organisation_number);

    printf("\nEmployee Information:\n");
    printf("Employee ID: %d\n", org.emp.employee_id);
    printf("Employee Name: %s\n", org.emp.name);
    printf("Employee Salary: %.2f\n", org.emp.salary);

    return 0;
}

