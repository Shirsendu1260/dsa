#include<stdio.h>
#include<stdlib.h>

int main(){
    char *p, *q;

    p = (char *)malloc(3 * sizeof(char));

    p[0] = 'b';
    p[1] = 'm';
    p[2] = 'w';

    q = (char *)malloc(5 * sizeof(char));

    for(int i = 0; i < 3; i++){
        q[i] = p[i];
    }

    q[3] = 'm';
    q[4] = '3';

    free(p);
    p = q;
    q = NULL;

    for(int i = 0; i < 5; i++){
        printf("%c ", p[i]);
    }
    printf("\n");

    free(p);
    // free(q);
    
    return 0;
}