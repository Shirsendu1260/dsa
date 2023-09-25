#include<stdio.h>

int power(int m, int n){
    if(n==0){
        return 1;
    }
    return  power(m, n-1) * m;
}

int efficient_power(int m, int n){
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return efficient_power(m*m, n/2);
    }
    else{
        return m * efficient_power(m*m, (n-1)/2);
    }
}

int main(){
    int x=2, y=9;

    printf("%d^%d = %d\n", x, y, power(x, y));
    printf("%d^%d = %d\n", x, y, efficient_power(x, y));
    printf("%d^%d = %d\n", x, 8, efficient_power(x, 8));
    
    return 0;
}