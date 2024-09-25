#include <stdio.h>
#define MAX 5

int queue[MAX],front=-1,rear=-1;

void dequeue();
void enqueue();
void display();

void main(){
    int op;
    do{
    printf("Menu:\n\t1.enqueue\n\t2.dequeue\n\t3.display\n\t4.Exit\nEnter your choice:\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            enqueue();
            display();
            break;
        case 2:
            dequeue();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Enter a valid option\n");
    }
    }while(op!=4);
}

void enqueue(){
    int el;
    if(rear==MAX-1){
        printf("Queue is full!\n");
    }else{
        printf("Enter the element:\n");
        scanf("%d",&el);

        if(front==-1&&rear==-1){
            front=0;
            rear=0;
            queue[rear]=el;
        }else{
            rear++;
            queue[rear]=el;
        }
    }
}

void dequeue(){
    if(front>rear){
        front=-1;
        rear=-1;
        printf("Queue is empty!\n");
    }else{
        front++;
    }
}

void display(){
    printf("The Queue is:\n");
    for(int i=front;i<=rear;i++){
        printf("%d\t",queue[i]);
    }
    printf("\n");
}