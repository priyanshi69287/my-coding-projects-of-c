#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
};

void display(struct Student* head) {
    printf("\n--- Student Records ---\n");
    while (head != NULL) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n", head->roll, head->name, head->marks);
        head = head->next;
    }
}

int main() {
    struct Student *head = NULL, *temp, *newNode;
    int choice = 1;

    while (choice) {
        newNode = (struct Student*)malloc(sizeof(struct Student));
        printf("Enter Roll No, Name, Marks: ");
        scanf("%d %s %f", &newNode->roll, newNode->name, &newNode->marks);
        newNode->next = NULL;

        if (head == NULL) head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Add another? (1/0): ");
        scanf("%d", &choice);
    }

    display(head);

    // Saving to File
    FILE *fp = fopen("students.txt", "w");
    temp = head;
    while(temp != NULL) {
        fprintf(fp, "%d %s %.2f\n", temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
    fclose(fp);
    printf("\nData saved to students.txt successfully!");

    return 0;
}