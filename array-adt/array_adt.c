#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void display_elements(struct Array arr){
    int i;

    printf("The array elements are: ");
    for(i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void append_elements(struct Array *arr, int val){
    if(arr->length < arr->size){
        arr->A[arr->length] = val;
        arr->length++;
    }
}

void insert(struct Array *arr, int index, int val){
    int i;
    
    if(index >= 0 && index < arr->length && arr->length < arr->size){
        for(i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = val;
        arr->length++;
    }
}

int delete(struct Array *arr, int index){
    int i, x;

    if(index >= 0 && index < arr->length && arr->length != 0){
        x = arr->A[index];
        
        for(i = index; i < arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }

        arr->length--;
        return x;
    }

    return -1;
}

int linear_search(struct Array arr, int key){
    int i;

    for(i = 0; i < arr.length; i++){
        if(arr.A[i] == key){
            return i;
        }
    }

    return -1;
}

void swap(int *x, int *y){
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int lin_search_transposition(struct Array *arr, int key){
    int i;

    for(i = 0; i < arr->length; i++){
        if(arr->A[i] == key){
            swap(&arr->A[i], &arr->A[i-1]);
            return i-1;
        }
    }

    return -1;
}

int lin_search_move2head(struct Array *arr, int key){
    int i;

    for(i = 0; i < arr->length; i++){
        if(arr->A[i] == key){
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }

    return -1;
}

int bin_search_ite(struct Array arr, int key){
    int l, m, h;

    l = 0;
    h = arr.length - 1;

    while(l<=h){
        m = (l+h)/2;

        if(arr.A[m] == key){
            return m;
        }
        else if(key < arr.A[m]){
            h = m - 1;
        }
        else{
            l = m + 1;
        }
    }

    return -1;
}

int bin_search_rec(int arr[], int key, int l, int h){
    int m;

    if(l<=h){
        m = (l+h)/2;

        if(key == arr[m]){
            return m;
        }
        else if(key < arr[m]){
            bin_search_rec(arr, key, l, m-1);
        }
        else{
            bin_search_rec(arr, key, m+1, h);
        }
    }
    else{
        return -1;
    }
}

int get(struct Array arr, int index){
    if(index >= 0 && index < arr.length){
        return arr.A[index];
    }

    return -1;
}

void set(struct Array *arr, int index, int val){
    if(index >= 0 && index < arr->length){
        arr->A[index] = val;
    }
}

int min(struct Array arr){
    int min, i;
    
    min = arr.A[0];

    for(i = 1; i < arr.length; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }

    return min;
}

int max(struct Array arr){
    int max, i;
    
    max = arr.A[0];

    for(i = 1; i < arr.length; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }

    return max;
}

int sum(struct Array arr){
    int sum = 0, i;

    for(i = 0; i < arr.length; i++){
        sum = sum + arr.A[i];
    }

    return sum;
}

float avg(struct Array arr){
    return (float)(sum(arr) / arr.length);
}

void reverse_using_another_array(struct Array *arr){
    int i, j;
    int *B;

    B = (int *)malloc(arr->length * sizeof(int));
    
    for(i = arr->length-1, j = 0; i >= 0; i--, j++){
        B[j] = arr->A[i];
    }

    for(i = 0; i < arr->length; i++){
        arr->A[i] = B[i];
    }

    free(B);
}

void reverse_using_swap(struct Array *arr){
    int i, j;

    for(i = 0, j = arr->length-1; i < j; i++, j--){
        swap(&arr->A[i], &arr->A[j]);
    }
}

int insert_in_sorted_array(struct Array *arr, int val){
    int i;

    if(arr->length < arr->size){
        i = arr->length - 1;
        while(arr->A[i] > val){
            arr->A[i+1] = arr->A[i];
            i--;
        }
        arr->A[i+1] = val;
        arr->length++;

        return i+1;
    }
    else{
        return -1;
    }
}

void is_sorted(struct Array arr){
    int i = 0;

    while(i < arr.length-1){
        if(arr.A[i] > arr.A[i+1]){
            printf("Array is not sorted.\n");
            return;
        }
        i++;
    }

    printf("Array is sorted.\n");
}

void rearrange(struct Array *arr){
    int i, j;

    i = 0;
    j = arr->length - 1;

    while(i<j){
        while(arr->A[i] < 0){
            i++;
        }
        while(arr->A[j] >= 0){
            j--;
        }
        if(i<j){
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

void merge(struct Array arr1, struct Array arr2){
    int i, j, k, s;
    int *arr3;

    s = arr1.length + arr2.length;
    arr3 = (int *)malloc(s * sizeof(int));

    i = 0;
    j = 0;
    k = 0;
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3[k] = arr1.A[i];
            i++;
            k++;
        }
        else{
            arr3[k] = arr2.A[j];
            j++;
            k++;
        }
    }

    for(; i<arr1.length; i++){
        arr3[k] = arr1.A[i];
        k++;
    }
    for(; j<arr2.length; j++){
        arr3[k] = arr2.A[j];
        k++;
    }

    printf("The array elements after merge are: ");
    for(i = 0; i < s; i++){
        printf("%d ", arr3[i]);
    }
    printf("\n");
    free(arr3);
}

void union_for_sorted_arrays(struct Array arr1, struct Array arr2){
    int i, j, k, s, count = 0;
    int *arr3;

    s = arr1.length + arr2.length;
    arr3 = (int *)malloc(s * sizeof(int));

    i = 0;
    j = 0;
    k = 0;
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3[k] = arr1.A[i];
            i++;
            k++;
            count++;
        }
        else if(arr1.A[i] > arr2.A[j]){
            arr3[k] = arr2.A[j];
            j++;
            k++;
            count++;
        }
        else{
            arr3[k] = arr1.A[i];
            i++;
            j++;
            k++;
            count++;
        }
    }

    for(; i<arr1.length; i++){
        arr3[k] = arr1.A[i];
        k++;
        count++;
    }
    for(; j<arr2.length; j++){
        arr3[k] = arr2.A[j];
        k++;
        count++;
    }

    printf("The array elements after union are: ");
    for(i = 0; i < count; i++){
        printf("%d ", arr3[i]);
    }
    printf("\n");
    free(arr3);
}

void intersection_for_sorted_arrays(struct Array arr1, struct Array arr2){
    int i, j, k, s, count = 0;
    int *arr3;

    s = arr1.length + arr2.length;
    arr3 = (int *)malloc(s * sizeof(int));

    i = 0;
    j = 0;
    k = 0;
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            i++;
        }
        else if(arr1.A[i] > arr2.A[j]){
            j++;
        }
        else{
            arr3[k] = arr1.A[i];
            i++;
            j++;
            k++;
            count++;
        }
    }

    printf("The array elements after intersection are: ");
    for(i = 0; i < count; i++){
        printf("%d ", arr3[i]);
    }
    printf("\n");
    free(arr3);
}

void difference_for_sorted_arrays(struct Array arr1, struct Array arr2){
    int i, j, k, s, count = 0;
    int *arr3;

    s = arr1.length + arr2.length;
    arr3 = (int *)malloc(s * sizeof(int));

    i = 0;
    j = 0;
    k = 0;
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3[k] = arr1.A[i];
            i++;
            k++;
            count++;
        }
        else if(arr1.A[i] > arr2.A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }

    for(; i<arr1.length; i++){
        arr3[k] = arr1.A[i];
        k++;
        count++;
    }

    printf("The array elements after difference are: ");
    for(i = 0; i < count; i++){
        printf("%d ", arr3[i]);
    }
    printf("\n");
    free(arr3);
}

int main(){
    // struct Array my_array = {{11,22,33,44,55,66,77}, 10, 7};
    // struct Array my_array = {{11,22,-33,44,-55,66,-77}, 10, 7};
    struct Array arr1 = {{3,4,5,6,10}, 10, 5};
    struct Array arr2 = {{2,4,5,7,12}, 10, 5};
    int x, key, index;

    // append_elements(&my_array, 66);
    // display_elements(my_array);

    // insert(&my_array, 2, 100);
    // display_elements(my_array);

    // x = delete(&my_array, 2);
    // printf("Element deleted: %d\n", x);
    // display_elements(my_array);

    // key = 88;
    // printf("%d found at index %d.\n", key, linear_search(my_array, key));
    // printf("%d found at index %d (Using transposition).\n", key, lin_search_transposition(&my_array, key));
    // printf("%d found at index %d (Using Move to head method).\n", key, lin_search_move2head(&my_array, key));
    // printf("%d found at index %d. (Binary Search using loop)\n", key, bin_search_ite(my_array, key));
    // printf("%d found at index %d. (Binary Search using recursion)\n", key, bin_search_rec(my_array.A, key, 0, my_array.length - 1));

    // index = 5;
    // printf("Value at index %d: %d\n", index, get(my_array, index));

    // set(&my_array, index, 108);
    // display_elements(my_array);
    // printf("Value at index %d: %d\n", index, get(my_array, index));

    // printf("Max: %d\nMin: %d\n", max(my_array), min(my_array));
    // printf("Sum: %d\nAvg.: %.2f\n", sum(my_array), avg(my_array));

    // reverse_using_another_array(&my_array);
    // display_elements(my_array);

    // reverse_using_swap(&my_array);
    // display_elements(my_array);

    // key = 50;
    // printf("%d inserted at index %d.\n", key, insert_in_sorted_array(&my_array, key));
    // display_elements(my_array);
    
    // is_sorted(my_array);

    // rearrange(&my_array);
    // display_elements(my_array);

    // display_elements(arr1);
    // display_elements(arr2);
    // merge(arr1, arr2);

    // display_elements(arr1);
    // display_elements(arr2);
    // union_op(arr1, arr2);

    display_elements(arr1);
    display_elements(arr2);
    union_for_sorted_arrays(arr1, arr2);
    intersection_for_sorted_arrays(arr1, arr2);
    difference_for_sorted_arrays(arr1, arr2);
    
    return 0;
}