#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *first = NULL; // It is a global pointer, that will point on to the first node of the first LL, initially it is NULL to denote that the LL has 0 nodes.
struct Node *last = NULL; // It is a global pointer, that will point on to the last node of the first LL.
struct Node *second = NULL; // It is a global pointer, that will point on to the first node of the second LL, initially it is NULL to denote that the LL has 0 nodes.

struct Node * create(int arr[], int n){
    int i;
    struct Node *head, *t, *last;

    // Creating first node
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL; // As it is the last node as well.
    last = head; // Right now it is the only node of this LL, so it is both first and last node.

    for(i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        last->next = t; // The current last node points to this new node.
        t->next = NULL; // As it is the last node.
        last = t; // This new node becomes the last node.
    }

    return head; // Returning the address of the starting node to access the LL further.
}

void display(struct Node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
    printf("The Linked List is traversed successfully.\n\n");
}

void recursive_display(struct Node *p){
    static int i = 1;

    if(p != NULL){
        printf("Node %d: %d\n", i, p->data);
        i++;
        recursive_display(p->next);
    }
}

void recursive_reversed_display(struct Node *p){
    static int i = 5;

    if(p != NULL){
        recursive_reversed_display(p->next);
        printf("Node %d: %d\n", i, p->data);
        i--;
    }
}

int count_nodes(struct Node *p){
    int count = 0;

    while(p != NULL){
        count++;
        p = p->next;
    }

    return count;
}

int count_nodes_rec(struct Node *p){
    if(p == NULL)
        return 0;
    else
        return count_nodes_rec(p->next) + 1;
}

int sum(struct Node *p){
    int sum = 0;

    while(p != NULL){
        sum = sum + p->data;
        p = p->next;
    }

    return sum;
}

int sum_rec(struct Node *p){
    if(p == NULL)
        return 0;
    else
        return sum_rec(p->next) + p->data;
}

int max(struct Node *p){
    int max = INT_MIN;

    printf("%d\n", max);

    while(p != NULL){
        if(p->data > max)
            max = p->data;

        p = p->next;
    }

    return max;
}

int max_rec(struct Node *p){
    static int x = 0;

    if(p == NULL)
        return INT_MIN;
    else{
        x = max_rec(p->next);
        if(x > p->data)
            return x;
        else
            return p->data;
    }
}

struct Node * linear_search(struct Node *p, int key){
    while(p != NULL){
        if(key == p->data)
            return p;
        p = p->next;
    }

    return NULL;
}

struct Node * linear_search_rec(struct Node *p, int key){
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    else
        return linear_search_rec(p->next, key);
}

struct Node * linear_search_move2head(struct Node *p, int key){
    struct Node *q = NULL;

    while(p != NULL){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }

    return NULL;
}

void insert(struct Node *p, int ind, int val){
    struct Node *t;
    int i;

    if(ind<0 || ind>count_nodes(first)) // If the index you have given is valid index or not, it should be in b/w 0 and the length of that LL.
        return;
    if(ind == 0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = val;
        t->next = first;
        first = t;
    }
    else{
        for(i=0; i<ind-1 && p!=NULL; i++){
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

void point_to_last_node(struct Node *p){
    while(p->next != NULL){
        p = p->next;
    }

    printf("We are now at the last node.\n");
    last = p; // Currently 'p' stands on the last node. So point it using global ponter 'last'.
}

void insert_last(struct Node *p, int val){
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;

    if(first == NULL)
        first = last = t;
    else{
        last->next = t;
        last = t;
    }
}

void sorted_insert(struct Node *p, int val){
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;

    if(first == NULL) // If LL has 0 nodes, then this new node becomes the only node.
        first = t;
    else{
        while(p!=NULL && p->data<val){
            q = p;
            p = p->next;
        }

        if(p == first){ // The new node we want to insert has value already lesser than the first node of the LL.
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

int delete_node(struct Node *p, int pos){
    struct Node *q = NULL;
    int x = -1, i;

    if(pos<1 || pos>count_nodes(first)) // If the node position no. you have given is valid or not, it should be in b/w 1 and the length of that LL.
        return -1;
    else if(pos == 1){
        x = first->data;
        p = first;
        first = first->next;
        free(p);
    }
    else{
        p = first;
        for(i=0; i<pos-1 && p!=NULL; i++){
            q = p;
            p = p->next;
        }
        if(p != NULL){
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }

    if(x != -1){
        printf("Deletion done successfully.\n");
        return x;
    }
    return -1;
}

int is_sorted(struct Node *p){
    int x = INT_MIN;

    while(p != NULL){
        if(p->data < x)
            return 0; // LL is unsorted.
        else{
            x = p->data;
            p = p->next;
        }
    }

    return 1;  // LL is sorted.
}

void remove_duplicates(struct Node *p){
    struct Node *q;
    int x = -1;
    q = first->next;

    while(q != NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            x = q->data;
            free(q);
            printf("Duplicate value %d is deleted from the LL.\n", x);
            q = p->next;
        }
    }
}

void reverse_using_array(struct Node *p){
    int *A, i;
    i = 0;

    A = (int *)malloc(count_nodes(first) * sizeof(int));

    while(p != NULL){
        A[i] = p->data;
        p = p->next;
        i++;
    }

    p = first;
    i--;

    while(p != NULL){
        p->data = A[i];
        i--;
        p = p->next;
    }

    free(A);
}

void reverse_using_sliding_ptrs(struct Node *p){
    struct Node *q, *r;
    q = r = NULL;

    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;
}

void reverse_using_sliding_ptrs_rec(struct Node *q, struct Node *p){
    if(p != NULL){
        reverse_using_sliding_ptrs_rec(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

struct Node * concatenate(struct Node *head_1, struct Node *head_2){
    struct Node *p = head_1;
    
    while(p->next != NULL)
        p = p->next;

    p->next = head_2;

    return head_1;
}

struct Node * merge(struct Node *head_1, struct Node *head_2){
    struct Node *head_3, *last_3;
    head_3 = last_3 = NULL;

    if(head_1->data < head_2->data){
        head_3 = last_3 = head_1;
        head_1 = head_1->next;
        last_3->next = NULL;
    }
    else{
        head_3 = last_3 = head_2;
        head_2 = head_2->next;
        last_3->next = NULL;
    }

    while(head_1!=NULL && head_2!=NULL){
        if(head_1->data < head_2->data){
            last_3->next = head_1;
            last_3 = head_1;
            head_1 = head_1->next;
            last_3->next = NULL;
        }
        else{
            last_3->next = head_2;
            last_3 = head_2;
            head_2 = head_2->next;
            last_3->next = NULL;
        }
    }

    if(head_1 != NULL)
        last_3->next = head_1;
    else
        last_3->next = head_2;

    return head_3;
}

int is_loop(struct Node *head){
    struct Node *p, *q;
    p = q = first;

    do{
        p = p->next;
        q = q->next;
        q = (q!=NULL) ? q->next : NULL;
    }while(p!=NULL && q!=NULL && p!=q);

    if(p==q)
        return 1;
    return 0;
}

struct Node * get_middle_node(struct Node *p){
    struct Node *q;
    int x;

    q = first;

    while(q != NULL){
        q = q->next;
        if(q != NULL)
            q = q->next;
        if(q != NULL)
            p = p->next;
    }

    if(p != NULL){
        return p;
    }
    return NULL;
}

void destroy(struct Node *p){
    int x = -1;

    while(first != NULL){ // When 'first' becomes NULL, that means we deleted all of the nodes.
        first = first->next; // The next node becomes the new first node.
        x = p->data; // Retrieve the data value from old first node before deleting.
        free(p); // Delete the old first node.
        p = first;
    }

    if(x == -1)
        printf("Failed to destroy the linked List.\n");
    else
        printf("The Linked List is deleted successfully.\n\n");
}

int main(){
    int A[] = {2,8,10,15,19,23,27}, B[] = {4,7,12,14,17};
    int s1 = 7, s2 = 5;
    int C[] = {10,30,50,70,90};
    int s3 = 5;
    int temp = -1;
    struct Node *key, *third, *t, *p, *q, *r;

    first = create(A, s1);
    // second = create(B, s2);

    // printf("No. of nodes: %d\n", count_nodes(first));
    // printf("No. of nodes: %d\n", count_nodes_rec(first));
    // printf("Sum of all elements: %d\n", sum(first));
    // printf("Sum of all elements: %d\n", sum_rec(first));
    // printf("Max element: %d\n", max(first));
    // printf("Max element: %d\n", max_rec(first));
    
    // key = linear_search(first, 30);
    // if(key != NULL)
    //     printf("Key value %d found at the node at address %p of the LL.\n", key->data, key);
    // else
    //     printf("Key not found,\n");

    // key = linear_search_rec(first, 36);
    // if(key != NULL)
    //     printf("Key value %d found at the node at address %p of the LL.\n", key->data, key);
    // else
    //     printf("Key not found,\n");

    // display(first);

    // key = linear_search_move2head(first, 50);
    // if(key != NULL)
    //     printf("Key value %d found at the node at address %p of the LL.\n", key->data, key);
    // else
    //     printf("Key not found,\n");

    // display(first);
    // insert(first, 4, 10); // Insert 10 at index 4

    // point_to_last_node(first);
    // display(first);
    // insert_last(first, 28);

    display(first);
    // sorted_insert(first, 28);
    // sorted_insert(first, 5);

    // display(first);
    // printf("Deleted value: %d\n", delete_node(first, 5));

    // temp = is_sorted(first);
    // if(temp == 1)
    //     printf("LL is sorted.\n");
    // else
    //     printf("LL is unsorted.\n");

    // display(first);
    // remove_duplicates(first);

    // display(first);
    // // reverse_using_array(first);
    // // reverse_using_sliding_ptrs(first);
    // reverse_using_sliding_ptrs_rec(NULL, first);

    // display(first);
    // display(second);
    // // third = concatenate(first, second);
    // // display(third);

    // third = merge(first, second);
    // display(third);

    // // Creating a LL that has a loop in it
    // // 1st node; 8->X
    // t = (struct Node *)malloc(sizeof(struct Node));
    // if(first == NULL){
    //     first = p = q = t;
    //     t->data = 8;
    //     t->next = NULL;
    // }
    // // 2nd node; 8->5->X
    // t = (struct Node *)malloc(sizeof(struct Node));
    // p->next = t;
    // t->data = 5;
    // t->next = NULL;
    // p = q = t;
    // // 3rd node; 8->5->4->X
    // t = (struct Node *)malloc(sizeof(struct Node));
    // p->next = t;
    // t->data = 4;
    // t->next = NULL;
    // p = q = t; // We won't move 'q' as it will point on to the 3rd node.
    // // 4th node; 8->5->4->7->X
    // t = (struct Node *)malloc(sizeof(struct Node));
    // p->next = t;
    // t->data = 7;
    // t->next = NULL;
    // p = t;
    // // 5th node; 8->5->4->7->3->X
    // t = (struct Node *)malloc(sizeof(struct Node));
    // p->next = t;
    // t->data = 3;
    // t->next = NULL;
    // p = t;
    // // 6th node; 8->5->4->7->3->9->X
    // t = (struct Node *)malloc(sizeof(struct Node));
    // p->next = t;
    // t->data = 9;
    // t->next = NULL;
    // p = t;
    // // Forming a loop from 6th node to 3rd node; 8->5->4->7->3->9->4...
    // p->next = q;

    // printf("\n");
    // r = first;
    // // Displaying this LL
    // while(r->next!=q || r!=p){
    //     printf("%d ", r->data);
    //     r = r->next;
    // }
    // printf("%d ", r->data);
    // printf("%d\n", r->next->data);
    // // Displaying crucial nodes
    // printf("first: %d\n", first->data);
    // printf("q: %d\n", q->data);
    // printf("p: %d\n", p->data);

    // if(is_loop(first) == 1)
    //     printf("The LL has a loop.\n\n");
    // else
    //     printf("The LL does not have a loop.\n\n");

    // // Destroying the LL after displaying it
    // temp = -1;
    // r = first;
    // while(first != NULL){
    //     first = first->next;
    //     temp = r->data;
    //     if(first == q){
    //         p->next = NULL;
    //         free(r);
    //         printf("%d is deleted.\n", temp);
    //         q = NULL;
    //     }
    //     else{
    //         free(r);
    //         printf("%d is deleted.\n", temp);
    //     }
    //     r = first;
    // }
    // if(temp == -1)
    //     printf("Failed to destroy the linked List.\n");
    // else
    //     printf("The Linked List is deleted successfully.\n\n");

    // printf("\n");
    // display(first);
    // display(second);
    // printf("\nUsing recursion -- \n");
    // recursive_display(first);
    // printf("\nUsing recursion reversed display -- \n");
    // recursive_reversed_display(first);

    t = get_middle_node(first);
    printf("Middle element: %d\n", t->data);
    
    destroy(first);

    return 0;
}