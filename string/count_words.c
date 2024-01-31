#include<stdio.h>

int count_words(char S[]){
    int i, wcount = 0;

    for(i=0; S[i]!='\0'; i++){
        if(S[i] == ' '){
            wcount++;
        }
    }

    return wcount+1;
}

int count_words_if_many_spaces(char S[]){
    int i, wcount = 0;

    for(i=0; S[i]!='\0'; i++){
        if(S[i]==' ' && S[i-1]!=' '){
            wcount++;
        }
    }

    return wcount+1;
}

int main(){
    char A[] = "How are you?";
    char B[] = "How are   you?";
    printf("Total words in string \"%s\": %d\n", A, count_words(A));
    printf("Total words in string \"%s\": %d\n", A, count_words_if_many_spaces(A));
    printf("Total words in string \"%s\": %d\n", B, count_words(B));
    printf("Total words in string \"%s\": %d\n", B, count_words_if_many_spaces(B));
    
    return 0;
}