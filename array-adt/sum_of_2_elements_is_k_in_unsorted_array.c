#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void fill_zeroes(int *ptr, int size){
    int i;

    for(i=0; i<size; i++){
        ptr[i] = 0;
    }
}

void find_pairs1(struct Array arr, int k){
    int i, j;

    printf("The pairs that constructs a sum of %d (using method 1) in the unsorted array are - \n", k);

    for(i=0; i<arr.length-1; i++){
        for(j=i+1; j<arr.length; j++){
            if(arr.A[i] + arr.A[j] == k)
                printf("%d and %d [where, %d + %d = %d].\n", arr.A[i], arr.A[j], arr.A[i], arr.A[j], k);
        }
    }
}

void find_pairs2(struct Array arr, int high, int k){
    int i, *H;
    H = (int *)malloc((high+1) * sizeof(int));

    fill_zeroes(H, high+1);

    printf("The pairs that constructs a sum of %d (using method 2) in the unsorted array are - \n", k);

    for(i=0; i<arr.length; i++){
        if(H[k-arr.A[i]] != 0){
            printf("%d and %d [where, %d + %d = %d].\n", arr.A[i], k-arr.A[i], arr.A[i], k-arr.A[i], k);
        }
        H[arr.A[i]]++;
    }
}

int main(){
    struct Array my_array = {{6,3,8,10,16,7,5,2,9,14}, 20, 10};
    int high = 16, k = 10;

    find_pairs1(my_array, k);
    find_pairs2(my_array, high, k);
    
    return 0;
}