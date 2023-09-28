#include<stdio.h>

void print_array(int arr[]){
    for(int i = 0; i < 4; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_address(int arr[]){
    for(int i = 0; i < 4; i++){
        printf("%u ", &arr[i]);
    }
    printf("\n");
}

int main(){
    int A[4];
    int B[4] = {2, 4, 6, 8};
    int C[4] = {11, 22};
    int D[4] = {0};
    int E[] = {100, 200, 300, 400};

    // print_array(A);
    // print_array(B);
    // print_array(C);
    // print_array(D);
    // print_array(E);

    print_address(E);
    
    return 0;
}