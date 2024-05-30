#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100

struct Patient {
    char name[50];
    int age;
    char gender;
    char address[100];
    char phone[15];
};

struct Patient patients[MAX_PATIENTS];
int patientCount = 0;

void addPatient() {
    if (patientCount < MAX_PATIENTS) {
        struct Patient newPatient;
        printf("Enter patient name: ");
        scanf("%s", newPatient.name);
        printf("Enter age: ");
        scanf("%d", &newPatient.age);
        printf("Enter gender (M/F/O): ");
        scanf(" %c", &newPatient.gender);
        printf("Enter address: ");
        scanf("%s", newPatient.address);
        printf("Enter phone number: ");
        scanf("%s", newPatient.phone);

        patients[patientCount++] = newPatient;
        printf("Patient added successfully!\n");
    } else {
        printf("Maximum patient limit reached!\n");
    }
}

void displayPatients() {
    printf("Patients:\n");
    printf("Name\tAge\tGender\tAddress\t\tPhone\n");
    for (int i = 0; i < patientCount; ++i) {
        printf("%s\t%d\t%c\t%s\t%s\n", patients[i].name, patients[i].age, patients[i].gender,
               patients[i].address, patients[i].phone);
    }
}

int main() {
    int choice;
    do {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
 return 0;
}
