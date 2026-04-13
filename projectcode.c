#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Patient Structure
struct Patient {
    int token;
    char name[50];
    int priority; // 3 = Critical, 2 = Emergency, 1 = Normal
};

// Queue Array
struct Patient queue[MAX];
int size = 0;
int token = 1;

// Stats
int totalServed = 0;

// Function to get priority name
char* getPriorityName(int p) {
    if (p == 3) return "Critical";
    if (p == 2) return "Emergency";
    return "Normal";
}

// Add Patient
void addPatient() {
    struct Patient p;

    printf("\nEnter patient name: ");
    scanf("%s", p.name);

    printf("Enter priority (3=Critical, 2=Emergency, 1=Normal): ");
    scanf("%d", &p.priority);

    if (p.priority < 1 || p.priority > 3) {
        printf("Invalid priority!\n");
        return;
    }

    p.token = token++;

    int i = size - 1;

    // Insert based on priority (Higher first)
    while (i >= 0 && queue[i].priority < p.priority) {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1] = p;
    size++;

    printf(" Patient added! Token No: %d\n", p.token);
}

// Serve Patient
void servePatient() {
    if (size == 0) {
        printf("\n❌ No patients in queue!\n");
        return;
    }

    struct Patient p = queue[0];

    printf("\n Now Serving: %d - %s (%s)\n",
           p.token, p.name, getPriorityName(p.priority));

    // Shift queue
    for (int i = 1; i < size; i++) {
        queue[i - 1] = queue[i];
    }

    size--;
    totalServed++;
}

// Display Queue
void displayQueue() {
    if (size == 0) {
        printf("\n📭 Queue is empty!\n");
        return;
    }

    printf("\nCurrent Queue:\n");
    for (int i = 0; i < size; i++) {
        printf("%d - %s (%s) | Wait: %d mins\n",
               queue[i].token,
               queue[i].name,
               getPriorityName(queue[i].priority),
               (i + 1) * 5);
    }
}

// Show Stats
void showStats() {
    printf("\n System Stats:\n");
    printf("Total Patients in Queue: %d\n", size);
    printf("Total Patients Served: %d\n", totalServed);
}

// Clear Screen (Windows)
void clearScreen() {
    system("cls"); // use "clear" for Linux/Mac
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n=====================================\n");
        printf("   HealthQ: Patient Handling System\n");
        printf("=====================================\n");
        printf("1. Add Patient\n");
        printf("2. Serve Next Patient\n");
        printf("3. Display Queue\n");
        printf("4. Show Stats\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                servePatient();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                showStats();
                break;
            case 5:
                printf("\nExiting HealthQ...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
