#include<iostream>

using namespace std;

// void swap_numbers(int x, int y){
//     int temp = 0;
//     temp = x;
//     x = y;
//     y = temp;
// }

// void swap_numbers(int *x, int *y){
//     int temp = 0;
//     temp = *x;
//     *x = *y;
//     *y = temp;
// }

void swap_numbers(int &x, int &y){
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 10, b = 9;
    cout << "Numbers before swapping: ";
    cout << a << " " << b << endl;
    swap_numbers(a, b);
    // swap_numbers(&a, &b);
    cout << "Numbers after swapping: ";
    cout << a << " " << b << endl;

    return 0;
}