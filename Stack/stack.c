#include <stdio.h>
#define MAX 3

void push(int);
void pop();
void display();

int stack[MAX],top=-1;
void main(){
    int op,el;
    do{
    printf("Menu:\n\t1.push()\n\t2.pop()\n\t3.display()\n\t4.Exit\nEnter your choice:\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            printf("Enter the element:\n");
            scanf("%d",&el);
            push(el);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Enter a valid input!\n");
    }
    display();
    }while(op!=4);
}
void push(int val){
    if(top==MAX-1){
        printf("Stack is full!\n");
    }else{
        top=top+1;
        stack[top]=val;
    }
}
void pop(){
    if(top==-1){
        printf("Stack is empty!\n");
    }else{
        top=top-1;
    }
}
void display(){
    printf("The stack is:\n");
    for(int i=0;i<=top;i++){
        printf("%d\t",stack[i]);
    }
}