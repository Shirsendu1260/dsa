#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Rectangle{
    int length;
    int breadth;
    char type;
};

int main(){
    // int a = 10;
    // int *ptr;
    // ptr = &a;

    // cout << a << endl;
    // printf("%d\n", a);
    // printf("%d\n", *ptr);
    // printf("%d\n", ptr);
    // printf("%d\n", &a);

    // int A[5] = {2, 4, 6, 8, 10};
    // int *ptr1, *ptr2;
    // ptr1 = A;
    // ptr2 = &A[0];

    // printf("%d\n", ptr1);
    // printf("%d\n", ptr2);

    // for(int i = 0; i < 5; i++){
    //     printf("%d\n", A[i]);
    //     cout << ptr1[i] << endl;
    // }

    // int *ptr1;
    // char *ptr2;

    // ptr1 = (int *)malloc(3*sizeof(int));
    // ptr2 = new char[3];

    // ptr1[0] = 11;
    // ptr1[1] = 22;
    // ptr1[2] = 33;

    // ptr2[0] = 'A';
    // ptr2[1] = 'B';
    // ptr2[2] = 'C';    

    // for(int i = 0; i < 3; i++){
    //     printf("%d\n", ptr1[i]);
    //     cout << ptr2[i] << endl;
    // }

    // free(ptr1);
    // delete [] ptr2;

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    cout << sizeof(p5) << endl;

    return 0;
}