#include <stdio.h>
#define n 10

int que[n];
int priorities[n];
int rear = -1;
int front = -1;

void enque(int x, int priority) {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("Queue is full. Please try again later.\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        que[rear] = x;
        priorities[rear] = priority;
    } else {
        int i;
        for (i = rear; i >= front; i--) {
            if (priority > priorities[i]) {
                que[i + 1] = que[i];
                priorities[i + 1] = priorities[i];
            } else {
                break;
            }
        }
        que[i + 1] = x;
        priorities[i + 1] = priority;
        rear = (rear + 1) % n;
    }
}

void deque() {
    if (front == -1 && rear == -1) {
        printf("\n");
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

void displayPriority(int priority) {
    if (priority == 1) {
        printf("HOD/Dean/Director");
    } else if (priority == 2) {
        printf("Staff/Guests");
    } else if (priority == 3) {
        printf("Students");
    }
}

int main() {
    int choice;
    int lift_in_use = 0; // Indicates if the lift is in use

    while (1) {
        printf("\n--------------------------------------------");
        printf("\nWho is in the Lift?\n");
        printf("--------------------------------------------");
        printf("\n1. HOD/Dean/Director\n");
        printf("2. Staff/Guests\n");
        printf("3. Students\n");
        printf("4. Exit\n");
        printf("Enter a Choice(1 or 2 or 3): ");
        scanf("%d", &choice);
        
        if (choice == 4) {
            printf("\n--------------------------------------------\n");
            printf("Exiting the program.\n");
            printf("--------------------------------------------\n");
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please select again.\n");
            continue;
        }

        printf("\n--------------------------------------------");
        printf("\nWho Wants to use the Lift?\n");
        printf("--------------------------------------------");
        printf("\n1. HOD/Dean/Director\n");
        printf("2. Staff/Guests\n");
        printf("3. Students\n");
        printf("4. Exit\n");
        printf("Enter a Choice(1 or 2 or 3): ");
        scanf("%d", &choice);
        printf("\n--------------------------------------------");
        if (choice == 4) {
            printf("Exiting the program.\n");
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please select again.\n");
            continue;
        }

        if (choice == 1) {
            printf("\nThe Lift will be Used By: ");
            displayPriority(choice);
            printf("\n--------------------------------------------\n");
            lift_in_use = 1; // Set lift in use flag
            deque(); // Dequeue after use
        } else if (choice == 2) {
            if (lift_in_use == 1) {
                printf("\nThe Lift will be used by: ");
                displayPriority(choice);
                printf("\n--------------------------------------------\n");
            } else {
                enque(choice, choice);
                printf("\nThe Lift will be used by: ");
                displayPriority(choice-1);
                printf("\n--------------------------------------------\n");
            }
        } else if (choice == 3) {
             if (lift_in_use == 1) {
                printf("\nThe Lift will be used by: ");
                displayPriority(choice-1);
                printf("\n--------------------------------------------\n");
             }
                else{
            printf("\nThe Lift will be Used By: ");
            displayPriority(choice-2);
            printf("\n--------------------------------------------\n");
            deque(); 
            }// Dequeue after use
        }
    }

    return 0;
}
