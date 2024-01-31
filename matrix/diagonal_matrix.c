#include<stdio.h>

struct Matrix{
    int A[10];
    int n;
};

void set(struct Matrix *ptr, int i, int j, int val){
    if(i == j)
        ptr->A[i-1] = val;
}

int get(struct Matrix m, int i, int j){
    if(i == j)
        return m.A[i-1];
    else
        return 0;
}

void display_matrix(struct Matrix m){
    int i, j;

    for(i=1; i<=m.n; i++){
        for(j=1; j<=m.n; j++){
            if(i == j)
                printf("%d ", m.A[i-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    struct Matrix m;
    m.n = 4;

    set(&m, 1, 1, 5);
    set(&m, 2, 2, 8);
    set(&m, 3, 3, 9);
    set(&m, 4, 4, 12);

    display_matrix(m);

    printf("Value at location [3, 2] in the diagonal matrix: %d\n", get(m, 3, 2));
    printf("Value at location [4, 4] in the diagonal matrix: %d\n", get(m, 4, 4));
    
    return 0;
}