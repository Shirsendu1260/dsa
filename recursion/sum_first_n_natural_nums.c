#include<stdio.h>

int sum_first_n_natural_nums_rec(int n){
    if(n==0){
        return 0;
    }
    else{
        return sum_first_n_natural_nums_rec(n-1) + n;
    }
}

int sum_first_n_natural_nums_iterative(int n){
    int sum = 0;

    for(int i=1; i<=n; i++){
        sum = sum + i;
    }

    return sum;
}

int sum_first_n_natural_nums_direct(int n){
    return n * (n+1) / 2;
}

int main(){
    int x = 5;

    printf("Sum of first %d natural numbers using formula: %d\n", x, sum_first_n_natural_nums_direct(x));
    printf("Sum of first %d natural numbers using loop: %d\n", x, sum_first_n_natural_nums_iterative(x));
    printf("Sum of first %d natural numbers using recursion: %d\n", x, sum_first_n_natural_nums_rec(x));
    
    return 0;
}