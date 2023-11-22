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

void count_duplicates(struct Array arr){
    int i, j;

    for(i=0; i<arr.length-1; i++){
        if(arr.A[i] == arr.A[i+1]){
            j = i + 1;
            while(arr.A[i] == arr.A[j])
                j++;
            printf("%d is appearing %d times.\n", arr.A[i], j-i);
            i = j - 1;
        }
    }
}

void find_duplicates1(struct Array arr){
    int last_duplicate, i;
    last_duplicate = 0;

    printf("The duplicate elements (using method 1) in the array are - \n");

    for(i=0; i<arr.length; i++){
        if(arr.A[i] == arr.A[i+1] && arr.A[i] != last_duplicate){
            printf("%d\n", arr.A[i]);
            last_duplicate = arr.A[i];
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

    printf("The duplicate elements (using method 2) in the array are - \n");

    for(i=1; i<=high; i++){
        if(H[i] > 1)
            printf("The duplicate element is %d. It appeared for %d times.\n", i, H[i]);
    }
}

int main(){
    struct Array my_array = {{3,6,8,8,10,12,15,15,15,20}, 20, 10};
    int high = my_array.A[my_array.length-1];

    find_duplicates1(my_array);
    count_duplicates(my_array);
    find_duplicates2(my_array, high);
    
    return 0;
}