#include <stdio.h>
#define MAX 5

int Dequeue[MAX], front = -1, rear = -1;

void InsertFront();
void DeleteRear();
void InsertRear();
void DeleteFront();
void Display();

void main() {
    int op;
    do {
        printf("Menu:\n\t1.Insert at Front\n\t2.Delete at Front\n\t3.Insert at Rear\n\t4.Delete at Rear\n\t5.Display\n\t6.Exit\nEnter an option:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                InsertFront();
                Display();
                break;
            case 2:
                DeleteFront();
                Display();
                break;
            case 3:
                InsertRear();
                Display();
                break;
            case 4:
                DeleteRear();
                Display();
                break;
            case 5:
                Display();
                break;
            default:
                printf("Enter a valid input!\n");
        }
    } while (op != 6);
}

void InsertFront() {
    int el;
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
        printf("Queue is full!\n");
    } else {
        printf("Enter the element:\n");
        scanf("%d", &el);
        if (front == -1) { // Corrected the comparison operator
            front = 0;
            rear = 0;
            Dequeue[front] = el;
        } else if (front > 0) {
            front--;
            Dequeue[front] = el;
        } else {
            for (int i = rear; i >= front; i--) {
                Dequeue[i + 1] = Dequeue[i];
            }
            Dequeue[front] = el;
            rear++;
        }
    }
}

void InsertRear() {
    int el;
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
        printf("Queue is full!\n");
    } else {
        printf("Enter the element:\n");
        scanf("%d", &el);
        if (rear == -1) { // Corrected the comparison operator
            front = 0;
            rear = 0;
            Dequeue[rear] = el;
        } else if (rear < MAX - 1) {
            rear++;
            Dequeue[rear] = el;
        } else {
            for (int i = front; i <= rear; i++) {
                Dequeue[i - 1] = Dequeue[i];
            }
            Dequeue[rear] = el;
            front--;
        }
    }
}

void DeleteRear() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else if (front == rear) {
        printf("Deleted: %d\n", Dequeue[rear]);
        front = -1;
        rear = -1;
    } else {
        printf("Deleted: %d\n", Dequeue[rear]);
        rear--;
    }
}

void DeleteFront() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else if (front == rear) {
        printf("Deleted: %d\n", Dequeue[rear]);
        front = -1;
        rear = -1;
    } else {
        printf("Deleted: %d\n", Dequeue[front]);
        front++;
    }
}

void Display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("The queue is:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\t", Dequeue[i]);
    }
    printf("\n");
}
