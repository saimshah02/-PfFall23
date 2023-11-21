#include <stdio.h>

// Define a structure to represent a box
struct Box {
    int length;
    int width;
    int height;
};

// Function to calculate the volume of a box
int calculateVolume(struct Box box) {
    return box.length * box.width * box.height;
}

// Function to check if a box can pass through the tunnel
int canPassThroughTunnel(struct Box box) {
    return box.height < 41;
}

int main() {
    // Assuming 4 boxes
    struct Box boxes[4];
    int i;

    // Input box data (you can modify this part as needed)
    for ( i = 0; i < 4; i++) {
        printf("Enter details for box %d:\n", i + 1);
        printf("Length: ");
        scanf("%d", &boxes[i].length);
        printf("Width: ");
        scanf("%d", &boxes[i].width);
        printf("Height: ");
        scanf("%d", &boxes[i].height);
        printf("\n");
    }

    // Calculate and display the volume of each box that can pass through the tunnel
    for ( i = 0; i < 4; i++) {
        if (canPassThroughTunnel(boxes[i])) {
            int volume = calculateVolume(boxes[i]);
            printf("Volume of box %d: %d\n", i + 1, volume);
        } else {
            printf("Box %d cannot pass through the tunnel.\n", i + 1);
        }
    }

    return 0;
}

