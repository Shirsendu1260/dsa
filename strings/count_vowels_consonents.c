#include<stdio.h>

int main(){
    char A[] = "How are you?";
    int i, vcount = 0, ccount = 0;

    for(i = 0; A[i] != '\0'; i++){
        if(A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u' || 
        A[i]=='A' || A[i]=='E' || A[i]=='I' || A[i]=='O' || A[i]=='U'){
            vcount++;
        }
        else if((A[i]>='A' && A[i]<='Z') || (A[i]>='a' && A[i]<='z')){
            ccount++;
        }
    }

    printf("\"%s\" has %d vowels and %d consonents.\n", A, vcount, ccount);
    
    return 0;
}