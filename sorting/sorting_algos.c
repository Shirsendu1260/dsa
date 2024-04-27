#include<stdio.h>
#include<limits.h>
#include<math.h>

void swap(int *x, int *y){
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void display_elements(int A[], int n){
    int i;

    printf("The array elements are: ");
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubble_sort(int A[], int n){
    int i, j, flag;

    for(i=0; i<n-1; i++){
        flag = 0;
        for(j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

void insertion_sort(int A[], int n){
    int i, j, x;

    for(i=1; i<n; i++){
        j = i-1;
        x = A[i];

        while(j>-1 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void selection_sort(int A[], int n){
    int i, j, k;

    for(i=0; i<n-1; i++){
        for(j=k=i; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

int partition(int A[], int l, int h){
    int pivot, i, j;
    pivot = A[l];
    i = l;
    j = h;

    do{
        do{
            i++;
        }while(A[i]<=pivot);
        do{
            j--;
        }while(A[j]>pivot);
        if(i<j)
            swap(&A[i], &A[j]);
    }while(i<j);
    swap(&A[l], &A[j]);

    return j;
}

void quick_sort(int A[], int l, int h){
    int p;

    if(l<h){
        p = partition(A, l, h);
        quick_sort(A, l, p);
        quick_sort(A, p+1, h);
    }
}

void merge_lists(int A[], int l, int mid, int h){
    int i, j, k;
    int B[h+1];
    i = l, j = mid+1, k = l;
    while(i<=mid && j<=h){
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(; i<=mid; i++){B[k++] = A[i];}
    for(; j<=h; j++){B[k++] = A[j];}
    for(i=l; i<=h; i++){A[i] = B[i];}
}

void merge_sort(int A[], int l, int h){
    int mid;

    if(l<h){
        mid = floor((l+h)/2);
        merge_sort(A, l, mid);
        merge_sort(A, mid+1, h);
        merge_lists(A, l, mid, h);
    }
}

int main(){
    int arr[] = {8, 5, 7, 3, 2}, s1 = 5;
    int arr2[] = {11,13,7,12,16,9,24,5,10,3,INT_MAX}, s2 = 11;
    display_elements(arr2, s2);
    // bubble_sort(arr, s1);
    // insertion_sort(arr, s1);
    // selection_sort(arr, s1);
    // quick_sort(arr2, 0, s2-1);
    merge_sort(arr2, 0, s2-1);
    display_elements(arr2, s2);
    
    return 0;
}