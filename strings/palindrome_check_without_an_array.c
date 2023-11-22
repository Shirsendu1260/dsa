#include<stdio.h>

int main(){
    char A[] = "RAHUL";
    int i, j, flag = 0;

    for(j=0; A[j]!='\0'; j++){
    }

    j = j - 1;

    for(i=0; i<j; i++, j--){
        if(A[i] != A[j]){
            printf("\"%s\" is not a palindrome string.\n", A);
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        printf("\"%s\" is a palindrome string.\n", A);
    
    return 0;
}