#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void find_max_min(struct Array arr){
    int i, max, min;
    min = arr.A[0];
    max = arr.A[0];

    for(i=1; i<arr.length; i++){
        if(arr.A[i] < min)
            min = arr.A[i];
        else if(arr.A[i] > max)
            max = arr.A[i];
    }

    printf("Max: %d and Min: %d.\n", max, min);
}

int main(){
    struct Array my_array = {{5,8,3,9,6,2,10,7,-1,4}, 20, 10};

    find_max_min(my_array);
    
    return 0;
}