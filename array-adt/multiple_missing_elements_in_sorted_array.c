#include<stdio.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void find_missing_elements(struct Array arr){
    int diff, low, i;
    low = arr.A[0];
    diff = low - 0;

    printf("The missing elements in the array are - \n");

    for(i=0; i<arr.length; i++){
        if(arr.A[i]-i != diff){
            while(diff < arr.A[i]-i){
                printf("%d\n", i + diff);
                diff++;
            }
        }
    }
}

int main(){
    struct Array my_array = {{6,7,8,9,11,12,15,16,17,18,19}, 20, 11};
    
    find_missing_elements(my_array);

    return 0;
}