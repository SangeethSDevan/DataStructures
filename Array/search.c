#include <stdio.h>

void linearSearch(int A[], int n);
void bubbleSort(int A[], int n);
void binarySearch(int A[], int n);
void displayArray(int A[], int n);

void main(){
   int A[20],n,op;
    printf("Enter the number of digits:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    do{
    printf("Menu\n\n1.linearSearch\n2.BubbleSort\n3.BinarySearch\n4.DisplayArray\n5.Exit\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            linearSearch(A,n);
            break;
        case 2:
            bubbleSort(A,n);
            displayArray(A,n);
            break;
        case 3:
            bubbleSort(A,n);
            binarySearch(A,n);
            break;
        case 4:
            displayArray(A,n);
            break;
        case 5:
            break;
        default:
            printf("Option does'nt match");
    }
    }while(op!=5);
}

void linearSearch(int A[],int n){
    int element,count=0;
    printf("Enter the element to be searched:\n");
    scanf("%d",&element);
    for(int i=0;i<n;i++){
        if(A[i]==element){
            count++;
        }
    }
    if(count>0){
        printf("The element is present %d times\n",count);
    }else{
        printf("The element doesn't exist\n");
    }
}
void bubbleSort(int A[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}
void binarySearch(int A[],int n){
    int key;
    printf("Enter the element to be searched:\n");
    scanf("%d",&key);
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(A[mid]==key){
            printf("Element is present in %d position\n",mid);
            break;
        }else if(key<A[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
}
void displayArray(int A[],int n){
    printf("The elements are\n");
    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
}