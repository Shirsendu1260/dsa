#include<stdio.h>

// float e(int x, int n){
//     static float s = 1;

//     if(n==0){
//         return s;
//     }
//     else{
//         s = 1 + x*s / n;
//     }

//     return e(x, n-1);
// }

float e(int x, int n){
    float s = 1;

    for(; n>0; n--){
        s = 1 + x*s / n;
    }

    return s;
}

int main(){
    float res = e(1, 10);
    printf("%.3f\n", res);
    
    return 0;
}