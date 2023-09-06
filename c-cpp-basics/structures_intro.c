#include<stdio.h>

struct Rectangle{
    int length;
    int breadth;
    char type;
};

// struct Rectangle{
//     int length;
//     int breadth;
// } r1, r2;

// struct Rectangle r1;

int main(){
    struct Rectangle r1 = {10, 10, 'S'};

    r1.length = 55;
    r1.breadth = 12;
    r1.type = 'R';

    // printf("Size of the structure: %lu\n", sizeof(r1));
    printf("%d\n", r1.length);
    printf("%d\n", r1.breadth);
    printf("%c\n", r1.type);

    return 0;
}