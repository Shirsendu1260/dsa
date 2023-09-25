#include<stdio.h>

int fact(int n){
    if(n==0){
        return 1;
    }
    else{
        return fact(n-1) * n;
    }
}

int nCr_basic(int n, int r){
    int t1, t2, t3;

    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);

    return t1 / (t2 * t3);
}

int nCr_rec(int n, int r){
    if(r==0 || r==n){
        return 1;
    }
    return nCr_rec(n-1, r-1) + nCr_rec(n-1, r);
}

int main(){
    printf("%d\n", nCr_basic(4, 2));
    printf("%d\n", nCr_rec(4, 2));
    
    return 0;
}