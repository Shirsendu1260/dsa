#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front, *rear;

void create(){
    front = rear = NULL;
    printf("Queue is created. Currently it has 0 elements.\n");
}

void destroy(struct Node *p){
    int x = -1;

    while(front != NULL){
        front = front->next;
        x = p->data;
        free(p);
        p = front;
    }

    // At this moment all nodes are destroyed, so make 'rear' also NULL.
    rear = NULL;

    if(x == -1)
        printf("Failed to destroy the queue.\n");
    else
        printf("The queue is destroyed successfully.\n\n");
}

void display(struct Node *p){
    printf("\nQueue elements are displayed from front to rear.\n");

    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n\n");
}

int isEmpty(){
    if(front == NULL)
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

void enqueue(int x){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL)
        printf("Queue is full, unable to enqueue.\n");
    else{
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(){
    int x = -1;
    struct Node *p;

    if(isEmpty()){
        printf("Queue is empty, unable to dequeue.\n");
    }
    else{
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }

    return x;
}

int main(){
    create();

    enqueue(100);
    enqueue(150);
    enqueue(200);
    enqueue(250);
    enqueue(300);

    display(front);

    printf("%d is dequeued.\n", dequeue());
    printf("%d is dequeued.\n", dequeue());
    printf("%d is dequeued.\n", dequeue());

    display(front);

    printf("Queue full status: %d\n", isFull());
    destroy(front);
    
    return 0;
}