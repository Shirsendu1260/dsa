#include<iostream>

using namespace std;

int miles_to_kms(int dist_miles){
    int dist_kms = dist_miles * 1.609344;
    return dist_kms;
}

int main(){
    int miles;

    cout << "Enter the distance in miles: ";
    cin >> miles;

    cout << "It is " << miles_to_kms(miles) << "kms.";

    return 0;
}