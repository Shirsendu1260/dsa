#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *first = NULL; // It is a global pointer, that will point on to the first node of the doubly LL, initially it is NULL to denote that the LL has 0 nodes.

struct Node * create_dll(int arr[], int n){
    int i;
    struct Node *h, *t, *last;

    // Creating first node
    h = (struct Node *)malloc(sizeof(struct Node));
    h->prev = NULL; // As it is the first node
    h->data = arr[0];
    h->next = NULL; // As it is the last node as well.
    last = h; // Right now it is the only node of this LL, so it is both first and last node.

    for(i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        last->next = t; // The current last node points to this new node.
        t->prev = last; // The new node points to the current last node.
        t->next = NULL; // As it is currently the last node.
        last = t; // This new node becomes the last node.
    }

    return h; // Returning the address of the starting node to access this doubly LL further.
}

void display_dll(struct Node *p){
    printf("\nIn forward direction: ");
    while(p->next != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data); // At this moment 'p' is on the last node, so print its data.

    printf("\nIn backward direction: ");
    // At this moment 'p' is on the last node.
    while(p != NULL){
        printf("%d ", p->data);
        p = p->prev;
    }

    printf("\n\n");
    printf("The Doubly Linked List is traversed successfully.\n\n");
}

int count_nodes(struct Node *p){
    int count = 0;

    while(p != NULL){
        count++;
        p = p->next;
    }

    return count;
}

void insert_dll(struct Node *p, int ind, int val){
    struct Node *t;
    int i;

    if(ind<0 || ind>count_nodes(first)) // If the index you have given is valid index or not, it should be in b/w 0 and the length of that LL.
        return;
    if(ind == 0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = val;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else{
        p = first;
        for(i=0; i<ind-1 && p!=NULL; i++){
            p = p->next;
        }
        if(p != NULL){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = val;
            t->prev = p;
            t->next = p->next;
            if(p->next != NULL)
                p->next->prev = t;
            p->next = t;
        }
    }
}

int delete_dll(struct Node *p, int pos){
    int x = -1, i;

    if(pos<1 || pos>count_nodes(first)) // If the node position no. you have given is valid or not, it should be in b/w 1 and the length of that LL.
        return -1;
    else if(pos == 1){
        p = first;
        first = first->next;
        if(first != NULL)
            first->prev = NULL;
        x = p->data;
        free(p);
    }
    else{
        p = first;
        for(i=0; i<pos-1 && p!=NULL; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next != NULL)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }

    if(x != -1){
        printf("Deletion done successfully.\n");
        return x;
    }
    return -1;
}

void reverse(struct Node *p){
    struct Node *temp;

    while(p != NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        if(p->prev==NULL && p!=NULL)
            first = p;
        
        p = p->prev;
    }
}

void destroy_dll(struct Node *p){
    int x = -1;

    while(first != NULL){ // When 'first' becomes NULL, that means we deleted all of the nodes.
        first = first->next; // The next node becomes the new first node.
        x = p->data; // Retrieve the data value from old first node before deleting.
        free(p); // Delete the old first node.
        p = first;
    }

    if(x == -1)
        printf("Failed to destroy the doubly linked List.\n");
    else
        printf("The Doubly Linked List is deleted successfully.\n\n");
}

int main(){
    int A[] = {3,5,7,9,11};
    int s = 5;

    first = create_dll(A, s);

    display_dll(first);

    // printf("First node: %d\n", first->data);
    // insert_dll(first, 0, 20);
    // insert_dll(first, 4, 100);
    // printf("First node: %d\n", first->data);

    // display_dll(first);

    // printf("Deleted Node: %d\n", delete_dll(first, 5));
    // printf("Deleted Node: %d\n", delete_dll(first, 1));
    // display_dll(first);

    // reverse(first);
    // display_dll(first);

    destroy_dll(first);

    return 0;
}