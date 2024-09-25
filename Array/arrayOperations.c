#include <stdio.h>
void displayArray(int A[], int *size);
void insertAtFirst(int A[], int *size);
void insert(int A[], int *size);
void deleteAtFirst(int A[], int *size);
void delete(int *size);

void main(){
    int A[20],size,op;
    printf("Enter the number of digits:\n");
    scanf("%d",&size);
    printf("Enter the elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&A[i]);
    }
    do{
        printf("Menu\n\t1.Insrt at Start\n\t2.Insert at End\n\t3.Delete First\n\t4.Delete\n\t5.Display Array\n\t6.Exit\n");
        printf("Enter an option:\n");
        scanf("%d",&op);
        switch (op)
        {
            case 1:
                insertAtFirst(A,&size);
                displayArray(A,&size);
                break;
            case 2:
                insert(A,&size);
                displayArray(A,&size);
                break;
            case 3:
                deleteAtFirst(A,&size);
                displayArray(A,&size);
                break;
            case 4:
                delete(&size);
                displayArray(A,&size);
                break;
            case 5:
                displayArray(A,&size);
                break;
            case 6:
                break;
            default:
            printf("Enter a valid operation\n");
        }
    }while(op!=6);
}
void displayArray(int A[],int *size){
    for(int i=0;i<*size;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
}
void insertAtFirst(int A[],int *size){
    int element;
    printf("Enter the element:\n");
    scanf("%d",&element);
    for(int i=*size;i>0;i--){
        A[i]= A[i-1];
    }
    A[0]=element;
    (*size)++;
}
void insert(int A[],int *size){
    int element;
    printf("Enter the element:\n");
    scanf("%d",&element);
    A[*size]=element;
    (*size)++;
}
void deleteAtFirst(int A[],int *size){
    for(int i=0;i<*size;i++){
        A[i]=A[i+1];
    }
    (*size)--;
}
void delete(int *size){
    (*size)--;
}
