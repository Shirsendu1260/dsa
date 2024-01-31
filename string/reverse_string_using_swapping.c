#include<stdio.h>

int main(){
    char A[] = "JAVA";
    char temp;
    int i, j;

    printf("The actual string is \"%s\".\n", A);

    for(j=0; A[j]!='\0'; j++){
    }

    j = j - 1;

    for(i=0; i<j; i++, j--){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    printf("The reversed string is \"%s\".\n", A);
    
    return 0;
}