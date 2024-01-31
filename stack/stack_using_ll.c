#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * top;

void create(){
    top = NULL;
    printf("Stack is created. Currently it has 0 elements.\n\n");
}

void destroy(struct Node *p){
    int x = -1;

    while(top != NULL){
        top = top->next;
        x = p->data;
        free(p);
        p = top;
    }

    if(x == -1)
        printf("Failed to destroy the stack.\n");
    else
        printf("The stack is deleted successfully.\n\n");
}

void display(struct Node *p){
    printf("\nStack elements are displayed from top to bottom.\n");

    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n\n");
}

int isEmpty(){
    if(top == NULL)
        return 1;
    return 0;
}

int isFull(){
    struct Node *t;
    int r;

    t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL)
        r = 1;
    else
        r = 0;
    
    free(t);

    return r;
}

void push(int val){
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));

    if(isFull())
        printf("Stack Overflow (Node is not created).\n");
    else{
        t->data = val;
        t->next = top;
        top = t;
        printf("%d is pushed.\n", top->data);
    }
}

int pop(){
    int x = -1;
    struct Node *p;

    if(isEmpty()){
        printf("Stack Underflow.\n");
    }
    else{
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }

    return x;
}

int peek(struct Node *p, int pos){
    int i;

    for(i=0; i<pos-1 && p!=NULL; i++){
        p = p->next;
    }

    if(p != NULL)
        return p->data;
    else
        return -1;
}

int stackTop(){
    if(isEmpty())
        return -1;
    return top->data;
}

int main(){
    create();

    push(11);
    push(22);
    push(33);
    push(44);

    display(top);

    printf("3rd element: %d\n", peek(top, 3));
    printf("4th element: %d\n\n", peek(top, 4));

    printf("%d is popped.\n", pop());
    printf("%d is popped.\n", pop());

    display(top);

    printf("Top element: %d\n\n", stackTop());

    destroy(top);
    
    return 0;
}