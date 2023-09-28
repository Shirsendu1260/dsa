#include<stdio.h>
#include<stdlib.h>

void print_array(int arr[]){
    for(int i = 0; i < 4; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int A[4] = {1,3,5,7};

    int *ptr;
    ptr = (int *)malloc(4 * sizeof(int));

    ptr[0] = 2;
    ptr[1] = 4;
    ptr[2] = 6;
    ptr[3] = 8;

    print_array(A);
    print_array(ptr);

    free(ptr);
    
    return 0;
}