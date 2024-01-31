#include<stdio.h>

int main(){
    char A[] = "Painter", B[] = "Painting";
    int i, j;

    for(i=0, j=0; A[i]!='\0' && B[j]!='\0'; i++, j++){
        if(A[i] != B[j])
            break;
    }

    if(A[i] == B[j])
        printf("\"%s\" and \"%s\" both strings are equal.\n", A, B);
    else if(A[i] < B[j])
        printf("\"%s\" comes earlier than \"%s\" in the dictionary.\n", A, B);
    else
        printf("\"%s\" comes earlier than \"%s\" in the dictionary.\n", B, A);
    
    return 0;
}