#include<stdio.h>

int main(){
    char A[] = "NITIN";
    char B[6];
    int i, j, flag = 0;

    for(i=0; A[i]!='\0'; i++){
    }

    i = i - 1;

    for(j=0; i>=0; i--, j++){
        B[j] = A[i];
    }

    B[j] = '\0';

    for(i=0, j=0; A[i]!='\0' && B[j]!='\0'; i++, j++){
        if(A[i] != B[j]){
            printf("\"%s\" is not a palindrome string.\n", A);
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        printf("\"%s\" is a palindrome string.\n", A);
    
    return 0;
}