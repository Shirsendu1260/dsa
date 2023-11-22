#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void find_pairs(struct Array arr, int k){
    int i, j;
    i = 0, j = arr.length-1;

    printf("The pairs that constructs a sum of %d in the sorted array are - \n", k);

    while(i<j){
        if(arr.A[i] + arr.A[j] == k){
            printf("%d and %d [where, %d + %d = %d].\n", arr.A[i], arr.A[j], arr.A[i], arr.A[j], k);
            i++;
            j--;
        }
        else if(arr.A[i] + arr.A[j] > k)
            j--;
        else
            i++;
    }
}

int main(){
    struct Array my_array = {{1,3,4,5,6,8,9,10,12,14}, 20, 10};
    int k = 10;

    find_pairs(my_array, k);
    
    return 0;
}