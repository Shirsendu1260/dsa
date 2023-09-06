#include<iostream>

using namespace std;

class Rectangle{
    public:
    int length;
    int breadth;

    void initialize(int l, int b){
        length = l;
        breadth = b;
    }

    int area(){
        return length * breadth;
    }

    int perimeter(){
        return 2 * (length + breadth);
    }
};

int main(){
    Rectangle r;
    int l, b;

    cout << "Enter length and breadth: ";
    cin >> l >> b;

    r.initialize(l, b);

    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;

    return 0;
}