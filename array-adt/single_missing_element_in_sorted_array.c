#include<stdio.h>

struct Array{
    int A[20];
    int size;
    int length;
};

int find_missing_element1(struct Array arr){
    int sum1, sum2, i, high;
    sum1 = 0;
    high = arr.A[arr.length-1];

    for(i=0; i<arr.length; i++){
        sum1 = sum1 + arr.A[i]; 
    }

    sum2 = high * (high + 1) / 2;

    return sum2 - sum1;
}

int find_missing_element2(struct Array arr){
    int i, diff, low;
    low = arr.A[0];
    diff =  low - 0;

    for(i=0; i<arr.length; i++){
        if(arr.A[i]-i != diff){
            return i + diff;
        } 
    }

    return -1;
}

int main(){
    struct Array my_array1 = {{1,2,3,4,5,6,8,9,10,11,12}, 20, 11};
    struct Array my_array2 = {{6,7,8,9,10,11,13,14,15,16,17}, 20, 11};
    
    printf("Missing element (using method 1): %d\n", find_missing_element1(my_array1));
    printf("Missing element (using method 2): %d\n", find_missing_element2(my_array2));

    return 0;
}