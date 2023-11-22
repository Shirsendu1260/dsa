#include<stdio.h>

int main(){
    char A[] = "JAVA";
    char B[5];
    int i, j;

    for(i=0; A[i]!='\0'; i++){
    }

    i = i - 1;

    for(j=0; i>=0; i--, j++){
        B[j] = A[i];
    }

    B[j] = '\0';

    printf("The actual string is \"%s\".\n", A);
    printf("The reversed string is \"%s\".\n", B);
    
    return 0;
}