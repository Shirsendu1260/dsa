#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *first = NULL;

void sorted_insert(struct Node **H, int x){
    struct Node *p, *q, *t;
    q = NULL;
    p = *H;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(*H == NULL){
        *H = t;
        first = t;
    }
    else{
        while(p && p->data<x){
            q = p;
            p = p->next;
        }
        if(p == first){
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node * search(struct Node *p, int key){
    while(p){
        if(key == p->data){return p;}
        p = p->next;
    }
    return NULL;
}

int hash(int key, int size){
    return key % size;
}

void insert(struct Node * H[], int size, int key){
    int ind = hash(key, size);
    sorted_insert(&H[ind], key);
}

int main(){
    struct Node * HT[10], *temp;
    int i, h_size = 10, h_ind, key;

    for(i=0; i<h_size; i++){
        HT[i] = NULL;
    }

    insert(HT, h_size, 12);
    insert(HT, h_size, 122);
    insert(HT, h_size, 25);
    insert(HT, h_size, 75);
    insert(HT, h_size, 36);
    
    key = 122;
    h_ind = hash(key, h_size);
    temp = search(HT[h_ind], key);
    
    if(temp == NULL){
        printf("Unable to found %d in index %d chain in the hashtable.\n", key, h_ind);
    }
    else{
        printf("Inserted value at index %d chain: %d\n", h_ind, temp->data);
    }
    
    return 0;
}