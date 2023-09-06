#include<iostream>

using namespace std;

// void fun(int A[], int n){
//     // cout << sizeof(A)/sizeof(int) << endl;

//     // for(int element:A){
//     //     cout << element << " ";
//     // }
//     // cout << endl;

//     for(int i = 0; i < n; i++){
//         cout << A[i] << " ";
//     }
//     cout << endl;
// }

// void fun(int *A, int n){
//     // cout << sizeof(A)/sizeof(int) << endl;

//     // for(int element:A){
//     //     cout << element << " ";
//     // }
//     // cout << endl;

//     // for(int i = 0; i < n; i++){
//     //     cout << A[i] << " ";
//     // }
//     // cout << endl;

//     A[1] = 44;
//     A[3] = 88;
// }

int * fun(int size){
    int *ptr;
    ptr = (int *)malloc(size * sizeof(int));

    for(int i = 0; i < size; i++){
        ptr[i] = i+100;
    }    

    return ptr;
}

int main(){
    // int A[] = {2, 4, 6, 8, 10};
    // int n = 5;

    // // cout << sizeof(A)/sizeof(int) << endl;

    // fun(A, n);

    // for(int element:A){
    //     cout << element << " ";
    // }
    // cout << endl;

    int *ptr, size = 10;
    
    ptr = fun(size);

    for(int i = 0; i < size; i++){
        cout << ptr[i] << " ";
    }
    cout << endl;

    return 0;
}