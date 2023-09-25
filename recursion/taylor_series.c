#include<stdio.h>

float e(int x, int n){
    static float p=1, f=1;
    float r;

    if(n==0){
        return 1;
    }
    else{
        r = e(x, n-1);
        p = p * x;
        f = f * n;
        return r + p/f;
    }
}

int main(){
    float res = e(1, 10);
    printf("%.3f\n", res);

    return 0;
}