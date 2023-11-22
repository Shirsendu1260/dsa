#include<stdio.h>

int valid(char S[]){
    int i;

    for(i=0; S[i]!='\0'; i++){
        if(!(S[i]>='A' && S[i]<='Z') && 
        !(S[i]>='a' && S[i]<='z') && 
        !(S[i]>='0' && S[i]<='9')){
            return 0;
        }
    }

    return 1;
}

int main(){
    char name1[] = "Anil3?1";
    char name2[] = "Ashwin99";
    int x = valid(name1);
    int y = valid(name2);

    if(x == 0)
        printf("\"%s\" is an invalid string.\n", name1);
    else
        printf("\"%s\" is a valid string.\n", name1);

    if(y == 0)
        printf("\"%s\" is an invalid string.\n", name2);
    else
        printf("\"%s\" is a valid string.\n", name2);

    return 0;
}