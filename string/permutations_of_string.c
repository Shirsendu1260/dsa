#include<stdio.h>

void perm1(char S[], int k){
    static int F[10] = {0};
    static char Res[10];
    int i;

    if(S[k] == '\0'){
        Res[k] = '\0';
        printf("\'%s\'\n", Res);
    }
    else{
        for(i=0; S[i]!='\0'; i++){
            if(F[i] == 0){
                Res[k] = S[i];
                F[i] = 1;
                perm1(S, k+1);
                F[i] = 0;
            }
        }
    }
}

void swap(char *x, char *y){
    char temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void perm2(char S[], int l, int h){
    int i;
    if(l == h)
        printf("\'%s\'\n", S);
    else{
        for(i=l; i<=h; i++){
            swap(&S[l], &S[i]);
            perm2(S, l+1, h);
            swap(&S[l], &S[i]);
        }
    }
}

int main(){
    char S[] = "ABC";
    int k = 0, l = 0, h = 2;
    
    printf("The permutations (without using swapping) of the string \'%s\' are - \n", S);
    perm1(S, k);
    printf("The permutations (using swapping) of the string \'%s\' are - \n", S);
    perm2(S, l, h);
    
    return 0;
}