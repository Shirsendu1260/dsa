#include<stdio.h>
#include<stdlib.h>

// Node structure for tree
struct TNode{
    struct TNode *lc;
    int data;
    struct TNode *rc;
};

struct TNode *root = NULL;

// Node structure for queue which will be used to store tree node addresses
struct QNode{
    struct TNode *tree_node;
    struct QNode *next;
};

struct QNode *front, *rear;

// Necessary functions for queue

void create_queue(){
    front = rear = NULL;
}

int isEmpty(){
    if(front == NULL)
        return 1;
    else
        return 0;
}

int isFull(){
    struct QNode *t = (struct QNode *)malloc(sizeof(struct QNode));
    int r;

    if(t == NULL)
        r = 1;
    else
        r = 0;

    free(t);
    return r;
}

void enqueue(struct TNode *node){
    struct QNode *t = (struct QNode *)malloc(sizeof(struct QNode));

    if(t == NULL)
        printf("Queue is full, unable to enqueue.\n");
    else{
        t->tree_node = node;
        t->next = NULL;
        if(front == NULL){
            front = rear = t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }
}

struct TNode * dequeue(){
    struct TNode *node = NULL;
    struct QNode *p;

    if(isEmpty()){
        printf("Queue is empty, unable to dequeue.\n");
    }
    else{
        p = front;
        front = front->next;
        node = p->tree_node;
        free(p);
    }

    return node;
}

// Necessary functions for tree

void create_tree(){
    struct TNode *p, *t;
    int x;
    
    // Create a queue
    create_queue();

    // Create root node
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct TNode *)malloc(sizeof(struct TNode));
    root->data = x;
    root->lc = root->rc = NULL;
    enqueue(root);

    // Loop to create all other nodes for the tree
    while(!isEmpty()){
        p = dequeue();

        // Code for creating left child node if it exists
        printf("Enter left child value of NODE %d: ", p->data);
        scanf("%d", &x);
        if(x != -1){
            t = (struct TNode *)malloc(sizeof(struct TNode));
            t->data = x;
            t->lc = t->rc = NULL;
            p->lc = t;
            enqueue(t);
        }

        // Code for creating right child node if it exists
        printf("Enter right child value of NODE %d: ", p->data);
        scanf("%d", &x);
        if(x != -1){
            t = (struct TNode *)malloc(sizeof(struct TNode));
            t->data = x;
            t->lc = t->rc = NULL;
            p->rc = t;
            enqueue(t);
        }
    }

    // At the end of tree creation, queue will become empty anyway. So we don't need to destroy it explicitly.
}

void preorder(struct TNode *t){
    if(t != NULL){
        printf("%d\n", t->data);
        preorder(t->lc);
        preorder(t->rc);
    }
}

void inorder(struct TNode *t){
    if(t != NULL){
        inorder(t->lc);
        printf("%d\n", t->data);
        inorder(t->rc);
    }
}

void levelorder(struct TNode *p){
    // Create a queue
    create_queue();

    // Visit root node
    printf("%d\n", p->data);
    enqueue(p);

    // Loop to visit all other nodes
    while(!isEmpty()){
        p = dequeue();

        if(p->lc){
            printf("%d\n", p->lc->data);
            enqueue(p->lc);
        }
        if(p->rc){
            printf("%d\n", p->rc->data);
            enqueue(p->rc);
        }
    }

    // At the end of tree creation, queue will become empty anyway. So we don't need to destroy it explicitly.
}

int count_all_nodes(struct TNode *p){
    int x, y;

    if(p != NULL){
        x = count_all_nodes(p->lc);
        y = count_all_nodes(p->rc);
        return x+y+1;
    }
    return 0;
}

int count_deg_2_nodes(struct TNode *p){
    int x, y;

    if(p != NULL){
        x = count_deg_2_nodes(p->lc);
        y = count_deg_2_nodes(p->rc);
        if(p->lc!=NULL && p->rc!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int count_deg_1_nodes(struct TNode *p){
    int x, y;

    if(p != NULL){
        x = count_deg_1_nodes(p->lc);
        y = count_deg_1_nodes(p->rc);
        if(p->lc!=NULL ^ p->rc!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int count_int_nodes(struct TNode *p){
    int x, y;

    if(p != NULL){
        x = count_int_nodes(p->lc);
        y = count_int_nodes(p->rc);
        if(p->lc!=NULL || p->rc!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int count_leaf_nodes(struct TNode *p){
    int x, y;

    if(p != NULL){
        x = count_leaf_nodes(p->lc);
        y = count_leaf_nodes(p->rc);
        if(p->lc==NULL && p->rc==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int calc_height(struct TNode *p){
    int x, y;

    if(p != NULL){
        x = calc_height(p->lc);
        y = calc_height(p->rc);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

// We will use postorder traversal to delete all of the nodes
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
    int x;

    create_tree();

    printf("Display tree nodes using preorder traversals -- \n");
    preorder(root);

    printf("Display tree nodes using inorder traversals -- \n");
    inorder(root);

    printf("Display tree nodes using level-order traversals -- \n");
    levelorder(root);

    printf("Height: %d\n", calc_height(root));
    printf("Total nodes: %d\n", count_all_nodes(root));
    printf("Degree 1 node count: %d\n", count_deg_1_nodes(root));
    printf("Degree 2 node count: %d\n", count_deg_2_nodes(root));
    printf("Internal nodes: %d\n", count_int_nodes(root));
    printf("Leaf nodes: %d\n", count_leaf_nodes(root));

    x = destroy_tree(root);

    if(x != -1)
        printf("Tree is destroyed successfully.\n");
    else
        printf("Unable to destroy the tree.\n");
    
    return 0;
}