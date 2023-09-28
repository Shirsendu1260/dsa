#include<stdio.h>
#include<stdlib.h>

int main(){
    int A[2][3] = {{3,5,8}, {2,1,9}};

    int *B[2];
    B[0] = (int *)malloc(3 * sizeof(int));
    B[1] = (int *)malloc(3 * sizeof(int));

    int **C;
    C = (int **)malloc(2 * sizeof(int *));
    C[0] = (int *)malloc(3 * sizeof(int));
    C[1] = (int *)malloc(3 * sizeof(int));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    free(B[0]);
    free(B[1]);
    free(C);

    return 0;
}