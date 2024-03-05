#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// BST node structure
struct TNode{
    struct TNode *lc;
    int data;
    struct TNode *rc;
};

struct TNode *root = NULL;

// Stack structure
struct Stack{
    int size;
    int top;
    struct TNode **S;
};

// Stack functions
struct Stack * create_stack(struct Stack *st, int n){
    st->size = n;
    st->top = -1;
    st->S = (struct TNode **)malloc(st->size*sizeof(struct TNode *));

    return st;
}

void destroy(struct Stack *st){
    free(st->S);
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

void push(struct Stack *st, struct TNode *bst_node){
    if(isFull(*st)){
        printf("Stack Overflow\n");
    }
    else{
        st->top++;
        st->S[st->top] = bst_node;
    }
}

struct TNode * pop(struct Stack *st){
    struct TNode *x;

    if(isEmpty(*st)){
        printf("Stack Underflow.\n");
    }
    else{
        x = st->S[st->top];
        st->top--;
    }

    return x;
}

int stackTop(struct Stack st){
    if(isEmpty(st))
        return INT_MAX;
    return st.S[st.top]->data;
}

// BST functions
void createPre(int pre[], int n){
    struct Stack stk;
    struct TNode *p, *t;
    int i = 0;

    create_stack(&stk, 20);

    // Create root node
    root = (struct TNode *)malloc(sizeof(struct TNode));
    root->data = pre[i++];
    root->lc = root->rc = NULL;
    p = root;

    // Iterative code for creating all other nodes
    while(i < n){
        if(pre[i] < p->data){
            t = (struct TNode *)malloc(sizeof(struct TNode));
            t->data = pre[i++];
            t->lc = t->rc = NULL;
            p->lc = t;
            push(&stk, p);
            p = t;
        }
        else{
            if(pre[i]>p->data && pre[i]<stackTop(stk)){
                t = (struct TNode *)malloc(sizeof(struct TNode));
                t->data = pre[i++];
                t->lc = t->rc = NULL;
                p->rc = t;
                p = t;
            }
            else
                p = pop(&stk);
        }
    }
}

void inorder(struct TNode *t){
    if(t != NULL){
        inorder(t->lc);
        printf("%d ", t->data);
        inorder(t->rc);
    }
}

int destroy_tree(struct TNode *t){
    static int x = -1;

    if(t != NULL){
        destroy_tree(t->lc);
        destroy_tree(t->rc);
        x = t->data;
        free(t);
    }

    return x;
}

int main(){
    int pre[] = {30,20,10,15,25,40,50,45};
    int x, n = 8;

    createPre(pre, n);

    printf("Display tree nodes using inorder traversals -- \n");
    inorder(root);

    x = destroy_tree(root);

    if(x != -1)
        printf("\nTree is destroyed successfully.\n");
    else
        printf("\nUnable to destroy the tree.\n");

    return 0;
}