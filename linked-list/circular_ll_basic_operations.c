#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL; // It is a global pointer, that will point on to the first node of the circular LL, initially it is NULL to denote that the LL has 0 nodes.

struct Node * create_cll(int arr[], int n){
    int i;
    struct Node *h, *t, *last;

    // Creating head node
    h = (struct Node *)malloc(sizeof(struct Node));
    h->data = arr[0];
    h->next = h; // As it is the last node as well.
    last = h; // Right now it is the only node of this LL, so it is both head and last node.

    for(i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        last->next = t; // The current last node points to this new node.
        t->next = h; // As it is the last node, it will point on to the head node.
        last = t; // This new node becomes the last node.
    }

    return h; // Returning the address of the starting node to access this circular LL further.
}

void display_cll(struct Node *p){
    do{
        printf("%d ", p->data);
        p = p->next;
    }while(p != head);
    printf("%d(head)\n", p->data); // At this point, 'p' returns back on 'head' forming a circular pattern.

    printf("\n");
    printf("The Circular Linked List is traversed successfully.\n\n");
}

void display_cll_rec(struct Node *p){
    static int flag = 0;

    if(p!=head || flag==0){
        flag = 1;
        printf("%d\n", p->data);
        display_cll_rec(p->next);
    }

    flag = 0;
}

int count_nodes_cll(struct Node *p){
    int count = 0;

    do{
        count++;
        p = p->next;
    }while(p != head);

    return count;
}

void insert_cll(struct Node *p, int ind, int val){
    struct Node *t;
    int i;

    if(ind<0 || ind>count_nodes_cll(head)) // If the index you have given is valid index or not, it should be in b/w 0 and the length of that LL.
        return;
    if(ind == 0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = val;
        if(head == NULL){
            head = t;
            head->next = head;
        }
        else{
            p = head;
            while(p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else{
        p = head;
        for(i=0; i<ind-1; i++){
            p = p->next;
        }
        if(p != NULL){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = val;
            t->next = p->next;
            p->next = t;
        }
    }
}

int delete_node_cll(struct Node *p, int pos){
    struct Node *q = NULL;
    int x = -1, i;

    if(pos<1 || pos>count_nodes_cll(head)) // If the node position no. you have given is valid or not, it should be in b/w 1 and the length of that LL.
        return -1;
    else if(pos == 1){
        p = head;
        while(p->next != head)
            p = p->next;
        x = head->data;
        if(p == head){
            free(head);
            head = NULL;
        }
        else{
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else{
        p = head;
        for(i=0; i<pos-2; i++){
            p = p->next;
        }
        q = p->next;
        if(q != NULL){
            p->next = q->next;
            x = q->data;
            free(q);
        }
    }

    if(x != -1){
        printf("Deletion done successfully.\n");
        return x;
    }
    return -1;
}

void destroy_cll(struct Node *p){
    struct Node *q = head;
    int x = -1;

    while(q->next != head)
        q = q->next;

    while(head != NULL){ // When 'head' becomes NULL, that means we deleted all of the nodes.
        if(head == q){
            x = p->data;
            free(p);
            head = q = NULL;
        }
        else{
            head = head->next; // The next node becomes the new head node.
            x = p->data; // Retrieve the data value from old head node before deleting.
            free(p); // Delete the old head node.
            p = head;
            q->next = head; // The last node points to the new head node.
        }
    }

    if(x == -1)
        printf("Failed to destroy the circular linked List.\n");
    else
        printf("The Circular Linked List is deleted successfully.\n\n");
}

int main(){
    int A[] = {10,30,50,70,90};
    int s = 5;

    head = create_cll(A, s);
    display_cll(head);
    printf("Head node: %d\n\n", head->data);
    // display_cll_rec(head);

    insert_cll(head, 0, 5);
    printf("Head node: %d\n", head->data);
    insert_cll(head, 4, 15);
    printf("Head node: %d\n", head->data);
    display_cll(head);

    printf("Deleted value: %d\n", delete_node_cll(head, 5));
    printf("Head node: %d\n", head->data);
    printf("Deleted value: %d\n", delete_node_cll(head, 1));
    display_cll(head);

    destroy_cll(head);

    return 0;
}