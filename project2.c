#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store Flight details
struct Flight {
    int flightNum;
    char destination[30];
    char time[10];
    int capacity;
};

void addFlight() {
    FILE *fp = fopen("flights.dat", "ab"); // 'ab' means Append Binary
    struct Flight f;

    printf("\nEnter Flight Number: ");
    scanf("%d", &f.flightNum);
    printf("Enter Destination: ");
    scanf("%s", f.destination);
    printf("Enter Time (e.g. 10AM): ");
    scanf("%s", f.time);
    f.capacity = 150; // Default capacity

    fwrite(&f, sizeof(struct Flight), 1, fp);
    fclose(fp);
    printf("Flight Added Successfully!\n");
}

void displayFlights() {
    FILE *fp = fopen("flights.dat", "rb"); // 'rb' means Read Binary
    struct Flight f;

    if (fp == NULL) {
        printf("\nNo records found!");
        return;
    }

    printf("\n--- Available Flights ---\n");
    printf("ID\tDestination\tTime\tSeats\n");
    while (fread(&f, sizeof(struct Flight), 1, fp)) {
        printf("%d\t%s\t\t%s\t%d\n", f.flightNum, f.destination, f.time, f.capacity);
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Airport Management System ---");
        printf("\n1. Add Flight\n2. View All Flights\n3. Exit\nChoose option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addFlight(); break;
            case 2: displayFlights(); break;
            case 3: exit(0);
            default: printf("Invalid choice!");
        }
    }
    return 0;
}