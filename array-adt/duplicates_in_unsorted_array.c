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

void find_duplicates1(struct Array arr){
    int i, j, count;

    printf("The duplicate elements (using method 1) in the unsorted array are - \n");

    for(i=0; i<arr.length-1; i++){
        count = 1;
        if(arr.A[i] != -1){
            for(j=i+1; j<arr.length; j++){
                if(arr.A[i] == arr.A[j]){
                    count++;
                    arr.A[j] = -1;
                }
            }
            if(count > 1)
                printf("%d is appearing %d times.\n", arr.A[i], count);
        }
    }
}

void find_duplicates2(struct Array arr, int high){
    int i, *H;
    H = (int *)malloc((high+1) * sizeof(int));

    fill_zeroes(H, high+1);

    for(i=0; i<arr.length; i++){
        H[arr.A[i]]++;
    }

    printf("The duplicate elements (using method 2) in the unsorted array are - \n");

    for(i=1; i<=high; i++){
        if(H[i] > 1)
            printf("The duplicate element is %d. It appeared for %d times.\n", i, H[i]);
    }
}

int main(){
    struct Array my_array = {{8,3,6,4,6,5,6,8,2,7}, 20, 10};
    int high = 8;

    find_duplicates1(my_array);
    find_duplicates2(my_array, high);
    
    return 0;
}