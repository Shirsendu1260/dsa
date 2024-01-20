#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};

struct Stack * create(struct Stack *st, int n){
    st->size = n;
    st->top = -1;
    st->S = (int *)malloc(st->size*sizeof(int));

    return st;
}

void destroy(struct Stack *st){
    free(st->S);
    // Just freeing the array created in heap.
    // 'size', 'top' and pointer 'S' were created in stack when stack variable was defined, so compiler will destoy them automatically when program finishes.

    printf("Stack is deleted.\n");
}

void display(struct Stack st){
    int i;

    printf("\nStack elements are displayed from top to bottom.\n");

    for(i=st.top; i>=0; i--){
        printf("%d ", st.S[i]);
    }

    printf("\n\n");
}

int isEmpty(struct Stack st){
    if(st.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st){
    if(st.top == st.size-1)
        return 1;
    return 0;
}

void push(struct Stack *st, int val){
    if(isFull(*st)){
        printf("Stack Overflow\n");
    }
    else{
        st->top++;
        st->S[st->top] = val;
        printf("%d is pushed.\n", val);
    }
}

int pop(struct Stack *st){
    int x;

    if(isEmpty(*st)){
        printf("Stack Underflow.\n");
    }
    else{
        x = st->S[st->top];
        st->top--;
    }

    return x;
}

int peek(struct Stack st, int pos){
    int index;

    index = st.top - pos + 1;

    if(index < 0){
        printf("Invalid position.\n");
        return -1;
    }
    else
        return st.S[index];
}

int stackTop(struct Stack st){
    if(isEmpty(st))
        return -1;
    return st.S[st.top];
}

int main(){
    struct Stack stk;
    int size = 6;

    create(&stk, size);

    push(&stk, 11);
    push(&stk, 22);
    push(&stk, 33);
    push(&stk, 44);
    push(&stk, 55);
    push(&stk, 66);
    push(&stk, 77); // Stack overflow, not pushed

    display(stk);

    printf("3rd element: %d\n", peek(stk, 3));
    printf("5th element: %d\n", peek(stk, 5));

    printf("%d is popped.\n", pop(&stk));
    printf("%d is popped.\n", pop(&stk));

    display(stk);

    printf("Top element: %d\n\n", stackTop(stk));

    destroy(&stk);
    
    return 0;
}