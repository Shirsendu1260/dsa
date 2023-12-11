#include<stdio.h>
#include<stdlib.h>

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create_sparse_matrix(struct Sparse *s){
    int i;
    printf("Enter dimensions: ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter no. of non-zero elements: ");
    scanf("%d", &s->num);
    s->e = (struct Element *)malloc(s->num * sizeof(struct Element));
    
    printf("Enter all non-zero elements: \n");
    for(i=0; i<s->num; i++){
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
    printf("\n");
}

struct Sparse * add(struct Sparse *s1, struct Sparse *s2){
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    if((s1->m != s2->m) || (s1->n != s2->n))
        return 0;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->m = s1->m;
    sum->n = s1->n;
    sum->e = (struct Element *)malloc((s1->num+s2->num) * sizeof(struct Element));

    while(i<s1->num && j<s2->num){
        if(s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++]; // i++; k++;
        else if(s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else{
            if(s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if(s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else{
                sum->e[k] = s1->e[i++];
                sum->e[k++].x += s2->e[j++].x;
            }
        }
    }

    for(; i<s1->num; i++)
        sum->e[k++] = s1->e[i];
    for(; j<s2->num; j++)
        sum->e[k++] = s2->e[j];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k + 1;
    printf("The no. of non-zero elements in the resultant matrix after adding these two sparse matrices: %d\n", k);

    return sum;
}

void display_sparse_matrix(struct Sparse sm){
    int i, j, k = 0;

    printf("The sparse matrix is --- \n");

    for(i=1; i<=sm.m; i++){
        for(j=1; j<=sm.n; j++){
            if(i==sm.e[k].i && j==sm.e[k].j){
                printf("%d ", sm.e[k].x);
                k++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    // struct Sparse sm;
    // create_sparse_matrix(&sm);
    // display_sparse_matrix(sm);

    struct Sparse sm1, sm2, *result;

    printf("Create the 1st sparse matrix --- \n");
    create_sparse_matrix(&sm1);
    printf("Create the 2nd sparse matrix --- \n");
    create_sparse_matrix(&sm2);

    result = add(&sm1, &sm2);

    printf("\nThe 1st sparse matrix is --- \n");
    display_sparse_matrix(sm1);
    printf("\nThe 2nd sparse matrix is --- \n");
    display_sparse_matrix(sm2);
    printf("\nThe resultant sparse matrix is --- \n");
    display_sparse_matrix(*result); // dereferencing the pointer to display the resultant matrix

    return 0;
}