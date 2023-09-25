#include<stdio.h>

int arr[10];

int fib_iteration(int n){
    int t0 = 0, t1 = 1, sum = 0;

    if(n<=1){
        return n;
    }
    else{
        for(int i = 2; i <= n; i++){
            sum = t0 + t1;
            t0 = t1;
            t1 = sum;
        }
    }

    return sum;
}

int fib_rec(int n){
    if(n <= 1){
        return n;
    }
    return fib_rec(n-2) + fib_rec(n-1);
}

int fib_rec_memoization(int n){
    if(n <= 1){
        arr[n] = n;
        return n;
    }
    else{
        if(arr[n-2] == -1){
            arr[n-2] = fib_rec_memoization(n-2);
        }
        if(arr[n-1] == -1){
            arr[n-1] = fib_rec_memoization(n-1);
        }
        return arr[n-2] + arr[n-1];
    }
}

int main(){
    for(int i = 0; i < 10; i++){
        arr[i] = -1;
    }

    printf("%d\n", fib_iteration(7));
    printf("%d\n", fib_rec(7));

    int r = fib_rec_memoization(7);
    printf("%d\n", r);

    arr[7] = r;

    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}