#include<iostream>

using namespace std;

// class Math{
//     private:
//     int a, b;

//     public:
//     Math();
//     Math(int a, int b);
//     int add();
//     int sub();
// };

// Math::Math(int a, int b){
//     this -> a = a;
//     this -> b = b;
// }

// int Math::add(){
//     return a + b;
// }

// int Math::sub(){
//     return a - b;
// }

template<class T>
class Math{
    private:
    T a, b;

    public:
    Math(T a, T b);
    T add();
    T sub();
};

template<class T>
Math<T>::Math(T a, T b){
    this -> a = a;
    this -> b = b;
}

template<class T>
T Math<T>::add(){
    return a + b;
}

template<class T>
T Math<T>::sub(){
    return a - b;
}

int main(){
    // Math m1(40, 30), m2(9, 3);

    // Math m1(40, 30);

    Math<float> m1(40.25, 30.5);

    cout << "Add: " << m1.add() << endl << "Substract: " << m1.sub() << endl;

    return 0;
}