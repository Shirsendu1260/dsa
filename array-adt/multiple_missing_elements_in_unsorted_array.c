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

void find_missing_elements(struct Array arr, int high){
    int i, *H;
    H = (int *)malloc((high+1) * sizeof(int));

    fill_zeroes(H, high+1);

    for(i=0; i<arr.length; i++){
        H[arr.A[i]]++;
    }

    printf("The missing elements in the array are - \n");

    for(i=1; i<=high; i++){
        if(H[i] == 0)
            printf("%d\n", i);
    }

    free(H);
}

int main(){
    struct Array my_array = {{3,7,4,9,12,6,1,11,2,10}, 20, 11};
    int high = 12;
    
    find_missing_elements(my_array, high);

    return 0;
}