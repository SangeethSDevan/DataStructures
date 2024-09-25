#include <stdio.h>
void printSparse(int S[][3])
{
    printf("The sparse matrix is:\n");
    int m = S[0][2];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", S[i][j]);
        }
        printf("\n");
    }
}
void createSparse(int A[][20], int m, int n, int S[][3])
{
    int count = 0, k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                count++;
            }
        }
    }
    if (count < (m * n) / 2)
    {
        S[0][0] = m;
        S[0][1] = n;
        S[0][2] = count;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] != 0)
                {
                    S[k][0] = i;
                    S[k][1] = j;
                    S[k][2] = A[i][j];
                    k++;
                }
            }
        }
    }
}
void readMatrix(int A[][20], int m, int n)
{
    printf("Enter the elements:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}
void createTranspose(int S[][3], int T[][3]){
    T[0][1]=S[0][0];
    T[0][0]=S[0][1];
    T[0][2]=S[0][2];

    int k=1;
    for(int i=0;i<S[0][1];i++){
        for(int j=0;j<=S[0][2];j++){
            if(S[j][1]==i){
                T[k][1]=S[j][0];
                T[k][0]=S[j][1];
                T[k][2]=S[j][2];
                k++;
            }
        }
    }
}

void addSparse(int S[][3], int T[][3], int R[][3])
{
    R[0][1]=S[0][1];
    R[0][0]=S[0][0];

    int m=1,n=1,k=1;

    for(int i=0;i<S[0][0];i++){
        for(int j=0;j<S[0][1];j++){
            if(S[m][0]==i&&S[m][1]==j&&T[n][0]==i&&T[n][1]==j){
                R[k][0]=S[m][0];
                R[k][1]=S[m][1];
                R[k][2]=S[m][2]+T[n][2];
                m++;n++;k++;
            }
            else if(S[m][0]==i&&S[m][1]==j){
                R[k][0]=S[m][0];
                R[k][1]=S[m][1];
                R[k][2]=S[m][2];
                k++; m++;
            }
            else if(T[n][0]==i&&T[n][1]==j){
                R[k][0]=T[n][0];
                R[k][1]=T[n][1];
                R[k][2]=T[n][2];
                k++; n++;
            }
        }
    }
    R[0][2]=k-1;
}
void main()
{
    int m, n, A[20][20], B[20][20], S[20][3], T[20][3], R[20][3], op;
    printf("Enter the order of matrix:\n");
    scanf("%d%d", &m, &n);
    readMatrix(A, m, n);
    do
    {
        printf("Menu:\n\t1.Display tuplet matrix\n\t2.Transpose\n\t3.Sparse Matrix Addition\n\t4.EXit\n\n");
        printf("Enter an option:\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            createSparse(A, m, n, S);
            printSparse(S);
            break;
        case 2:
            createSparse(A, m, n, S);
            createTranspose(S, T);
            printSparse(T);
            break;
        case 3:
            printf("Enter the other %dx%d matrix:\n", m, n);
            readMatrix(B, m, n);
            createSparse(B, m, n, T);
            printSparse(T);
            addSparse(S, T, R);
            printSparse(R);
            break;
        case 4:
            break;
        }
    } while (op != 4);
}