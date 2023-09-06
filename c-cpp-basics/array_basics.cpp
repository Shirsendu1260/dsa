#include<iostream>

using namespace  std;

int main(){
    // int A[5];

    // A[0] = 12;
    // A[1] = 15;
    // A[2] = 25;

    // int A[5] = {34, 21, 55, 10, 42};
    // int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    // int A[10] = {1, 3, 5, 7, 9};
    // int A[5] = {0};

    int n;
    cout << "How many elemets you want in the array? ";
    cin >> n;

    int A[n];

    for(int i = 0; i < n; i++){
        cout << "Enter element for index " << i << ": ";
        cin >> A[i];
    }
    
    // cout << sizeof(A) << endl;
    // cout << A[1] << endl;
    // printf("%d\n", A[2]);
    // cout << A[2] << endl;
    // cout << A[3] << endl;

    // for(int i = 0; i < sizeof(A)/sizeof(int); i++){
    //     cout << A[i] << endl;
    // }

    for(int x:A){
        cout << x << endl;
    }

    return 0;
}