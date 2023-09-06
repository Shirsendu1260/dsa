#include<stdio.h>
#include<stdlib.h>

struct Rectangle{
    int length;
    int breadth;
    char type;
};

// void fun(struct Rectangle r){
//     r.breadth = 30;
//     printf("L: %d\nB: %d\nT: %c\n", r.length, r.breadth, r.type);
// }

// void fun(struct Rectangle *ptr_r){
//     ptr_r -> breadth = 30;
//     printf("L: %d\nB: %d\nT: %c\n", ptr_r -> length, ptr_r -> breadth, ptr_r -> type);
// }

struct Rectangle * fun(){
    struct Rectangle *ptr;
    ptr = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    ptr -> length = 100;
    ptr -> breadth = 100;
    ptr -> type = 'S';

    return ptr;
}

int main(){
    // struct Rectangle r = {10, 5, 'R'};

    // // fun(r);

    // fun(&r);

    // printf("Length: %d\n", r.length);
    // printf("Breadth: %d\n", r.breadth);
    // printf("Type: %c\n", r.type);

    struct Rectangle *ptr = fun();

    printf("L: %d\nB: %d\nT: %c\n", ptr -> length, ptr -> breadth, ptr -> type);

    return 0;
}