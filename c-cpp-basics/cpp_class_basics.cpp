#include<iostream>

using namespace std;

class Rectangle{
    private:
    int length;
    int breadth;

    public:
    Rectangle(){
        length = 0;
        breadth = 0;
    }

    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }

    int area(){
        return length * breadth;
    }

    int perimeter(){
        return 2 * (length + breadth);
    }

    void set_length(int l){
        length = l;
    }

    void set_breadth(int b){
        breadth = b;
    }

    int get_length(){
        return length;
    }

    int get_breadth(){
        return breadth;
    }

    ~Rectangle(){
        cout << "Compiler just called this DESTRUCTER (which deallocates the used memory)." << endl;
    }
};

int main(){
    Rectangle r(100, 10);

    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;

    r.set_length(200);
    r.set_breadth(20);
    cout << "Modified length: " << r.get_length() << endl;
    cout << "Modified breadth: " << r.get_breadth() << endl;

    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;

    return 0;
}