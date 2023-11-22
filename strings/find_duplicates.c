#include<stdio.h>

void find_duplicates_method_1(char S[]){
    int i, j, count;

    printf("This method compares each letter of the string with remaining portion of the array.\n");

    for(i=0; S[i]!='\0'; i++){
        count = 1;

        if(S[i] != -1){
            for(j=i+1; S[j]!='\0'; j++){
                if(S[i] == S[j]){
                    count++;
                    S[j] = -1;
                }
            }
            if(count > 1)
                printf("\'%c\' appeared for %d times.\n", S[i], count);
        }
    }
}

void find_duplicates_method_2(char S[]){
    int i;
    int H[26] = {0};

    printf("This method uses a hashtable.\n");

    for(i=0; S[i]!='\0'; i++){
        H[S[i]-97]++;
    }

    for(i=0; i<26; i++){
        if(H[i] > 1)
            printf("\'%c\' appeared for %d times.\n", i+97, H[i]);
    }
}

void find_duplicates_method_3(char S[]){
    int H = 0, x = 0, i;

    printf("This method applies bitwise operations.\n");

    for(i=0; S[i]!='\0'; i++){
        x = 1;
        x = x << (S[i]-97);
        if((H&x) != 0)
            printf("\'%c\' has duplicates(s).\n", S[i]);
        else
            H = H | x;
    }
}

int main(){
    char A[] = "finding";
    char B[] = "finding";
    char C[] = "finding";
    printf("The string is \"%s\".\n", A);
    find_duplicates_method_1(A);
    find_duplicates_method_2(B);
    find_duplicates_method_3(C);
    
    return 0;
}