#include<stdio.h>
#include<stdlib.h>

struct Rectangle{
    int length;
    int breadth;
    char type;
};

int main(){
    // struct Rectangle r = {30, 15, 'R'};
    // struct Rectangle *ptr = &r;

    struct Rectangle *ptr = (struct Rectangle*)malloc(sizeof(struct Rectangle));

    ptr -> length = 30;
    ptr -> breadth = 30;
    ptr -> type = 'S';

    // printf("%d, %d, %c\n", r.length, r.breadth, r.type);
    printf("%li\n", sizeof(struct Rectangle));
    printf("%d, %d, %c\n", ptr -> length, ptr -> breadth, ptr -> type);

    return 0;
}