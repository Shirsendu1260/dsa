#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    int priority;
    struct Node *next;
};

struct Node *first, *rear;

void create(){
    first = rear = NULL;
}

void destroy(struct Node *p){
    int x = -1;

    while(first != NULL){
        first = first->next;
        x = p->data;
        free(p);
        p = first;
    }

    // At this moment all nodes are destroyed, so make 'rear' also NULL.
    rear = NULL;

    if(x == -1)
        printf("Failed to destroy the priority queue.\n");
    else
        printf("The priority queue is destroyed successfully.\n\n");
}

int isEmpty(){
    if(rear == NULL)
        return 1;
    else
        return 0;
}

int isFull(){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    int r;

    if(t == NULL)
        r = 1;
    else
        r = 0;

    free(t);
    return r;
}

void enqueue(int val, int pri){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL)
        printf("The priority queue is full.\n");
    else{
        t->data = val;
        t->priority = pri;
        t->next = NULL;
        if(first == NULL){
            first = rear = t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }
}

struct Node * getHighestPriorityElementAddress(){
    int highest_priority = INT_MIN, i;
    struct Node *p, *q, *goal_node;
    q = NULL;
    p = first;

    while(p != NULL){
        if(highest_priority==p->priority && goal_node->data<p->data){
            highest_priority = p->priority;
            goal_node = p;
        }
        else if(highest_priority < p->priority){
            highest_priority = p->priority;
            goal_node = p;
        }
        q = p;
        p = p->next;
    }

    return goal_node;
}

int dequeue(){
    struct Node *r, *p;
    int x = -1;

    if(isEmpty())
        printf("The priority queue is empty.\n");
    else{
        p = first;
        r = getHighestPriorityElementAddress();

        while(p!=r && p->next!=r){
            p = p->next;
        }

        x = r->data;

        if(r->next == NULL){
            rear = p;
            p->next = NULL;
        }
        else if(r == first){
            first = first->next;
        }
        else if(r==first && r==rear){
            rear = first = NULL;
        }
        else{
            p->next = r->next;
        }

        free(r);
    }

    return x;
}

void display(struct Node *p){
    int i;

    // We will display all of the elements in the order they appear.
    // We will not display based on priority, but dequeue() will be done based on priority.
    // Here 'rear' will be on the node of the lastly enqueued element.
    // Here 'rear' is both used for enqueue and dequeue, so both are done at the rear end of the queue (i.e at end of the linked list).
    // So we will start from first node and go upto till the last node.
    printf("\nThe priority queue elements are: ");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}

int main(){
    create();
    
    enqueue(16, 4);
    enqueue(8, 3);
    enqueue(5, 1);
    enqueue(6, 2);
    enqueue(10, 5);

    display(first);
    
    printf("%d is dequeued.\n", dequeue());
    printf("%d is dequeued.\n", dequeue());
    printf("%d is dequeued.\n", dequeue());

    display(first);

    return 0;
}