#include<stdio.h>

struct Rectangle{
    int length;
    int breadth;
};

int area(struct Rectangle r){
    return r.length * r.breadth;
}

int perimeter(struct Rectangle r){
    return 2 * (r.length + r.breadth);
}

void initialize(struct Rectangle *r, int l, int b){
    r -> length = l;
    r -> breadth = b;
}

int main(){
    struct Rectangle r;
    int l, b;

    printf("Enter length and breadth: ");
    scanf("%d %d", &l, &b);

    initialize(&r, l, b);

    printf("Area: %d\n", area(r));
    printf("Perimeter: %d\n", perimeter(r));

    return 0;
}