#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top1, *top2;

void create(){
    top1 = top2 = NULL;
    // Currently both stacks are empty.
}

void destroy(struct Node *p, struct Node *q){
    int x1, x2;
    x1 = x2 = -1;
    
    // Destroy nodes from the first stack
    while(top1 != NULL){
        top1 = top1->next;
        x1 = p->data;
        free(p);
        p = top1;
    }

    // Destroy nodes from the second stack
    while(top2 != NULL){
        top2 = top2->next;
        x2 = q->data;
        free(q);
        q = top2;
    }
    
    if(x1!=-1 || x2!=-1){
        printf("The queue is destroyed successfully.\n");
    }
    else if(x1==-1 && x2==-1){
        printf("The queue was already destroyed.\n");
    }
    else{
        printf("Failed to destroy the queue.\n");
    }
}

void push(int val){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    // As this push() function will always be used for pushing into the second stack,
    // we wrote only the code that will push a node into the second stack.
    t->data = val;
    t->next = top2;
    top2 = t;
}

int pop(struct Node *top){
    int x = -1;
    struct Node *p;

    if(top == top1){
        p = top1;
        top1 = top1->next;
        x = p->data;
        free(p);
    }
    else{
        p = top2;
        top2 = top2->next;
        x = p->data;
        free(p);
    }

    return x;
}

int isEmpty(){
    if(top1==NULL && top2==NULL)
        return 1;
    else
        return 0;
}

int isFull(){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    int r;

    if(t == NULL){
        r = 1;
    }
    else{
        r = 0;
    }

    free(t);
    return r;
}

void enqueue(int x){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL){
        printf("Queue is full, unable to enqueue.\n");
    }
    else{
        t->data = x;
        t->next = top1;
        top1 = t;
    }
}

int dequeue(){
    int x = -1, temp;

    if(top2 == NULL){
        if(top1 == NULL){
            printf("Queue is empty, unable to dequeue.\n");
            return x;
        }
        else{
            while(top1 != NULL){
                temp = pop(top1);
                push(temp); // Push to second stack
            }
        }
    }

    return pop(top2);
}

int main(){
    create();

    enqueue(11);
    enqueue(22);
    enqueue(33);
    
    printf("%d is dequeued.\n", dequeue());

    enqueue(44);
    
    printf("%d is dequeued.\n", dequeue());
    printf("%d is dequeued.\n", dequeue());
    printf("%d is dequeued.\n", dequeue());
    
    destroy(top1, top2);
    
    return 0;
}