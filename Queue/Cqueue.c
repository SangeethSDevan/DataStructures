#include <stdio.h>
#define MAX 5

int Cqueue[MAX], front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

void main() {}

void enqueue()
{
    int el;
    if (front == (rear + 1) % MAX)
    {
        printf("Queue is full!\n");
    }
    else
    {
        printf("Enter the element:\n");
        scanf("%d",&op);

        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            Cqueue[rear] =el;
        }
        else
        {
            printf("Enter the element:\n");
            rear = (rear + 1) % MAX;
            Cqueue[rear] = el;
        }
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!\n");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display(){
    int i=front;
    printf("The queue is:\n");
    while(i!=rear){
        i=(i+1)%MAX;
        printf("%d\t",Cqueue[i]);
    }
}