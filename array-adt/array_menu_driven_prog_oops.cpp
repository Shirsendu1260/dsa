#include<iostream>

using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
        void swap(int *x, int *y);

    public:
        Array(){
            size = 20;
            length = 0;
            A = new int[size];
        }
        Array(int sz){
            size = sz;
            length = 0;
            A = new int[size];
        }
        ~Array(){
            delete []A;
        }
        void display_elements();
        void append_elements(int val);
        void insert(int index, int val);
        int delete_op(int index);
        int linear_search(int key);
        int lin_search_transposition(int key);
        int lin_search_move2head(int key);
        int bin_search_ite(int key);
        int get(int index);
        void set(int index, int val);
        int min();
        int max();
        int sum();
        float avg();
        void reverse_using_another_array();
        void reverse_using_swap();
        int insert_in_sorted_array(int val);
        void is_sorted();
        void rearrange();
        void merge(Array arr2);
        void union_for_sorted_arrays(Array arr2);
        void intersection_for_sorted_arrays(Array arr2);
        void difference_for_sorted_arrays(Array arr2);
};

void Array::display_elements(){
    int i;

    cout << "The array elements are: ";
    for(i = 0; i < length; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

void Array::swap(int *x, int *y){
        int temp;

        temp = *x;
        *x = *y;
        *y = temp;
    }

void Array::append_elements(int val){
    if(length < size){
        A[length] = val;
        length++;
        cout << val << " appended\n";
    }
}

void Array::insert(int index, int val){
    int i;
    
    if(index >= 0 && index < length && length < size){
        for(i = length; i > index; i--){
            A[i] = A[i-1];
        }
        A[index] = val;
        length++;
    }
}

int Array::delete_op(int index){
    int i, x;

    if(index >= 0 && index < length && length != 0){
        x = A[index];
        
        for(i = index; i < length-1; i++){
            A[i] = A[i+1];
        }

        length--;
        return x;
    }

    return -1;
}

int Array::linear_search(int key){
    int i;

    for(i = 0; i < length; i++){
        if(A[i] == key){
            return i;
        }
    }

    return -1;
}

int Array::lin_search_transposition(int key){
    int i;

    for(i = 0; i < length; i++){
        if(A[i] == key){
            swap(&A[i], &A[i-1]);
            return i-1;
        }
    }

    return -1;
}

int Array::lin_search_move2head(int key){
    int i;

    for(i = 0; i < length; i++){
        if(A[i] == key){
            swap(&A[i], &A[0]);
            return 0;
        }
    }

    return -1;
}

int Array::bin_search_ite(int key){
    int l, m, h;

    l = 0;
    h = length - 1;

    while(l<=h){
        m = (l+h)/2;

        if(A[m] == key){
            return m;
        }
        else if(key < A[m]){
            h = m - 1;
        }
        else{
            l = m + 1;
        }
    }

    return -1;
}

int Array::get(int index){
    if(index >= 0 && index < length){
        return A[index];
    }

    return -1;
}

void Array::set(int index, int val){
    if(index >= 0 && index < length){
        A[index] = val;
    }
}

int Array::min(){
    int min, i;
    
    min = A[0];

    for(i = 1; i < length; i++){
        if(A[i] < min){
            min = A[i];
        }
    }

    return min;
}

int Array::max(){
    int max, i;
    
    max = A[0];

    for(i = 1; i < length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }

    return max;
}

int Array::sum(){
    int sum = 0, i;

    for(i = 0; i < length; i++){
        sum = sum + A[i];
    }

    return sum;
}

float Array::avg(){
    return (float)(sum() / length);
}

void Array::reverse_using_another_array(){
    int i, j;
    int *B;

    B = new int[length];
    
    for(i = length-1, j = 0; i >= 0; i--, j++){
        B[j] = A[i];
    }

    for(i = 0; i < length; i++){
        A[i] = B[i];
    }

    delete []B;
}

void Array::reverse_using_swap(){
    int i, j;

    for(i = 0, j = length-1; i < j; i++, j--){
        swap(&A[i], &A[j]);
    }
}

int Array::insert_in_sorted_array(int val){
    int i;

    if(length < size){
        i = length - 1;
        while(A[i] > val){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = val;
        length++;

        return i+1;
    }
    else{
        return -1;
    }
}

void Array::is_sorted(){
    int i = 0;

    while(i < length-1){
        if(A[i] > A[i+1]){
            cout << "Array is not sorted.\n";
            return;
        }
        i++;
    }

    cout << "Array is sorted.\n";
}

void Array::rearrange(){
    int i, j;

    i = 0;
    j = length - 1;

    while(i<j){
        while(A[i] < 0){
            i++;
        }
        while(A[j] >= 0){
            j--;
        }
        if(i<j){
            swap(&A[i], &A[j]);
        }
    }
}

void Array::merge(Array arr2){
    int i, j, k, s;
    int *arr3;

    s = length + arr2.length;
    arr3 = new int[s];

    i = 0;
    j = 0;
    k = 0;
    while(i<length && j<arr2.length){
        if(A[i] < arr2.A[j]){
            arr3[k] = A[i];
            i++;
            k++;
        }
        else{
            arr3[k] = arr2.A[j];
            j++;
            k++;
        }
    }

    for(; i<length; i++){
        arr3[k] = A[i];
        k++;
    }
    for(; j<arr2.length; j++){
        arr3[k] = arr2.A[j];
        k++;
    }

    cout << "The array elements after merge are: ";
    for(i = 0; i < s; i++){
        cout << arr3[i];
    }
    cout << "\n";
    delete []arr3;
}

void Array::union_for_sorted_arrays(Array arr2){
    int i, j, k, s, count = 0;
    int *arr3;

    s = length + arr2.length;
    arr3 = new int[s];

    i = 0;
    j = 0;
    k = 0;
    while(i<length && j<arr2.length){
        if(A[i] < arr2.A[j]){
            arr3[k] = A[i];
            i++;
            k++;
            count++;
        }
        else if(A[i] > arr2.A[j]){
            arr3[k] = arr2.A[j];
            j++;
            k++;
            count++;
        }
        else{
            arr3[k] = A[i];
            i++;
            j++;
            k++;
            count++;
        }
    }

    for(; i<length; i++){
        arr3[k] = A[i];
        k++;
        count++;
    }
    for(; j<arr2.length; j++){
        arr3[k] = arr2.A[j];
        k++;
        count++;
    }

    cout << "The array elements after union are: ";
    for(i = 0; i < count; i++){
        cout << arr3[i];
    }
    cout << "\n";
    delete []arr3;
}

void Array::intersection_for_sorted_arrays(Array arr2){
    int i, j, k, s, count = 0;
    int *arr3;

    s = length + arr2.length;
    arr3 = new int[s];

    i = 0;
    j = 0;
    k = 0;
    while(i<length && j<arr2.length){
        if(A[i] < arr2.A[j]){
            i++;
        }
        else if(A[i] > arr2.A[j]){
            j++;
        }
        else{
            arr3[k] = A[i];
            i++;
            j++;
            k++;
            count++;
        }
    }

    cout << "The array elements after intersection are: ";
    for(i = 0; i < count; i++){
        cout << arr3[i];
    }
    cout << "\n";
    delete []arr3;
}

void Array::difference_for_sorted_arrays(Array arr2){
    int i, j, k, s, count = 0;
    int *arr3;

    s = length + arr2.length;
    arr3 = new int[s];

    i = 0;
    j = 0;
    k = 0;
    while(i<length && j<arr2.length){
        if(A[i] < arr2.A[j]){
            arr3[k] = A[i];
            i++;
            k++;
            count++;
        }
        else if(A[i] > arr2.A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }

    for(; i<length; i++){
        arr3[k] = A[i];
        k++;
        count++;
    }

    cout << "The array elements after difference are: ";
    for(i = 0; i < count; i++){
        cout << arr3[i];
    }
    cout << "\n";
    delete []arr3;
}

int main(){
    Array *arr1;
    int ch, x, index, size;

    cout << "Enter size of the array: ";
    cin >> size;
    arr1 = new Array[size];

    do{
        printf("Menu\n");
        printf("1. Append\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Sum\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch){
            case 1: cout << "Enter an element you want to append:\n";
                    cin >> x;
                    arr1->append_elements(x);
                    break;
            case 2: cout << "Enter an element and the index where you want to insert:\n";
                    cin >> x;
                    cin >> index;
                    arr1->insert(index, x);
                    break;
            case 3: cout << "Enter the index from where you want to delete:\n";
                    cin >> index;
                    x = arr1->delete_op(index);
                    cout << "Deleted element: " << x << "\n";
                    break;
            case 4: cout << "Enter the element to search: \n";
                    cin >> x;
                    index = arr1->bin_search_ite(x);
                    cout << "Index found: " << index << "\n";
                    break;
            case 5: cout << "Sum of the array elements: " << arr1->sum() << "\n";
                    break;
            case 6: arr1->display_elements();
                    break;
        }
    }
    while(ch < 7);

    return 0;
}