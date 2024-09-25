#include <stdio.h>
struct poly{
    int coeff;
    int exp;
}p1[10],p2[10],p3[10];

int readPoly(struct poly p[]){
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);

    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        printf("%dst coeff & expo:\n",i+1);
        scanf("%d%d",&p[i].coeff,&p[i].exp);
    }
    return n;
}

void displayPoly(struct poly p[],int n){
    printf("The polynomial is:\n");
    for(int i=0;i<n-1;i++){
        printf("%dx^%d+",p[i].coeff,p[i].exp);
    }
    printf("%dx^%d",p[n-1].coeff,p[n-1].exp);
}

int addPoly(struct poly p1[],struct poly p2[],int t1,int t2,struct poly p3[]){
    int i=0,j=0,k=0;
    while(i<t1&&j<t2){
        if(p1[i].exp==p2[j].exp){
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].coeff=p1[i].coeff;
            i++; j++; k++;
        }
        else if(p1[i].exp>p2[j].exp){
            p3[k].exp=p1[i].exp;
            p3[k].coeff=p1[i].coeff;
            k++; i++;
        }
        else {
            p3[k].exp=p2[j].exp;
            p3[k].coeff=p2[j].coeff;
            k++; j++;
        }
    }
    while(i<t1){
        p3[k].coeff=p1[i].coeff;
        p3[k].exp=p1[i].exp;
        k++; i++;
    }
    while(j<t2){
        p3[k].coeff=p2[j].coeff;
        p3[k].exp=p2[j].exp;
        k++; j++;
    }
}

void main(){
    int t1,t2,t3;
    t1=readPoly(p1);
    t2=readPoly(p2);

    t3=addPoly(p1,p2,t1,t2,p3);
}