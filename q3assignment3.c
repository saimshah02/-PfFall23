#include <stdio.h>
#include <stdlib.h>

// Structure to represent personal details
struct PersonalDetails {
    int id;
    char name[50];
};

// Structure to represent department details
struct DepartmentDetails {
    int id;
    float salary;
};

// Structure to represent combined details
struct CombinedDetails {
    int id;
    char name[50];
    float salary;
};

// Function to merge details and write to Combine.txt
void mergeAndWriteToCombine(int recordId) {
    FILE *personalFile = fopen("Personal.txt", "r");
    FILE *departmentFile = fopen("Department.txt", "r");
    FILE *combineFile = fopen("Combine.txt", "a");

    if (personalFile == NULL || departmentFile == NULL || combineFile == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    struct PersonalDetails personal;
    struct DepartmentDetails department;
    struct CombinedDetails combined;

    int found = 0;

    // Search for the record ID in Personal.txt
    while (fscanf(personalFile, "%d %s", &personal.id, personal.name) == 2) {
        if (personal.id == recordId) {
            found = 1;
            break;
        }
    }

    if (found) {
        // Search for the record ID in Department.txt
        rewind(departmentFile); // Reset file pointer to the beginning
        while (fscanf(departmentFile, "%d %f", &department.id, &department.salary) == 2) {
            if (department.id == recordId) {
                // Combine details
                combined.id = personal.id;
                strcpy(combined.name, personal.name);
                combined.salary = department.salary;

                // Write to Combine.txt
                fprintf(combineFile, "%d %s %.2f\n", combined.id, combined.name, combined.salary);

                printf("Record with ID %d merged and added to Combine.txt.\n", recordId);

                fclose(personalFile);
                fclose(departmentFile);
                fclose(combineFile);
                return;
            }
        }
        printf("Record with ID %d not found in Department.txt.\n", recordId);
    } else {
        printf("Record with ID %d not found in Personal.txt.\n", recordId);
    }

    fclose(personalFile);
    fclose(departmentFile);
    fclose(combineFile);
}

int main() {
    int recordId;

    printf("Enter the record ID to merge: ");
    scanf("%d", &recordId);

    mergeAndWriteToCombine(recordId);

    return 0;
}

