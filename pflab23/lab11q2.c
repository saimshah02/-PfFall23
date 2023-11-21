#include <stdio.h>
#include <string.h>

// Define a structure to store information about engine parts
struct EnginePart {
    char serialNumber[4];  // Assuming serial number format like "AA0", "BB1", ..., "FF9"
    int yearOfManufacture;
    char material[20];
    int quantityManufactured;
};

// Function to retrieve information on parts with serial numbers between BB1 and CC6
void retrievePartsInformation(struct EnginePart parts[], int totalParts) {
	int i;
    printf("Parts information for serial numbers between BB1 and CC6:\n");
    for ( i = 0; i < totalParts; i++) {
        // Compare serial numbers
        if (strcmp(parts[i].serialNumber, "BB1") >= 0 && strcmp(parts[i].serialNumber, "CC6") <= 0) {
            printf("Serial Number: %s\n", parts[i].serialNumber);
            printf("Year of Manufacture: %d\n", parts[i].yearOfManufacture);
            printf("Material: %s\n", parts[i].material);
            printf("Quantity Manufactured: %d\n", parts[i].quantityManufactured);
            printf("\n");
        }
    }
}

int main() {
    // Assuming a maximum of 100 engine parts
    struct EnginePart engineParts[100];

    // Populate engine part data (you can modify this part as needed)
    engineParts[0] = {"AA0", 2022, "Steel", 100};
    engineParts[1] = {"BB1", 2021, "Aluminum", 150};
    engineParts[2] = {"CC6", 2022, "Titanium", 75};
    engineParts[3] = {"DD3", 2020, "Carbon Fiber", 200};
    // Add more engine parts...

    int totalParts = 4;  // Update this with the actual number of engine parts

    // Example usage
    retrievePartsInformation(engineParts, totalParts);

    return 0;
}

