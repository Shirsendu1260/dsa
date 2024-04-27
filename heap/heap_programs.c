#include<stdio.h>

void swap(int *x, int *y){
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void insert(int A[], int ind){
    int i, temp;
    i = ind;
    temp = A[i];

    while(i>1 && temp>A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }

    A[i] = temp;
}

void create_heap(int A[], int size){
    int i;

    for(i=2; i<=size; i++){
        insert(A, i);
    }
}

int delete(int A[], int size){
    int i, j, temp, del_val;
    temp = A[size];
    del_val = A[1];
    A[1] = A[size];
    i = 1, j = 2*i;

    while(j<size-1){
        if(A[j+1]>A[j])
            j = j + 1;
        if(A[i]<A[j]){
            swap(&A[i], &A[j]);
            i = j;
            j = 2*j;
        }
        else{
            break;
        }
    }

    A[size] = del_val;
    return del_val;
}

void heap_sort(int A[], int size){
    int i;

    for(i=size; i>1; i--){
        delete(A, i);
    }
}

void display_heap(int A[], int size){
    int i;

    for(i=1; i<=size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
    // Index 0 element is assigned 0 because we don't need index 0 element, 
    // we need elements from index 1 onwards for our binary heap.
    int BH[] = {0,10,20,30,25,5,40,35}, size = 7;
    // Max heap will be, 40,25,35,10,5,20,30

    create_heap(BH, size);
    display_heap(BH, size);

    printf("Deleted element from the max heap: %d\n", delete(BH, size));
    display_heap(BH, size);
    printf("Deleted element from the max heap: %d\n", delete(BH, size-1));
    display_heap(BH, size);
    printf("Deleted element from the max heap: %d\n", delete(BH, size-2));
    display_heap(BH, size);

    heap_sort(BH, size);
    display_heap(BH, size);

    return 0;
}