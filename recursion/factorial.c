#include<stdio.h>

int fact_recursion(int n){
    if(n==0){
        return 1;
    }
    else{
        return fact_recursion(n-1) * n;
    }
}

int fact_iterative(int n){
    int res = 1;

    for(int i=1; i<=n; i++){
        res = res * i;
    }

    return res;
}

int main(){
    int x = 5;

    printf("Factorial of %d using recursion: %d\n", x, fact_recursion(x));
    printf("Factorial of %d using loop: %d\n", x, fact_iterative(x));
    
    return 0;
}