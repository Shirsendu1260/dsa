#include<stdio.h>
#include<stdlib.h>

struct TNode{
    struct TNode *lc;
    int data;
    struct TNode *rc;
};

struct TNode *root = NULL;

void insert(struct TNode *p, int key){
    struct TNode *q = NULL, *t;

    while(p != NULL){
        q = p;
        if(key == p->data)
            return;
        else if(key < p->data)
            p = p->lc;
        else
            p = p->rc;
    }

    t = (struct TNode *)malloc(sizeof(struct TNode));
    t->data = key;
    t->lc = t->rc = NULL;
    
    // If it is the very first node (root node), then make this new node as root node.
    if(root == NULL)
        root = t;
    // If it is not the very first node (root node), then do the linkings.
    else{
        if(q->data < t->data)
            q->rc = t;
        else
            q->lc = t;
    }
}

struct TNode * search(struct TNode *p, int key){
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    else if(key < p->data)
        return search(p->lc, key);
    else
        return search(p->rc, key);
}

void inorder(struct TNode *t){
    if(t != NULL){
        inorder(t->lc);
        printf("%d ", t->data);
        inorder(t->rc);
    }
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

struct TNode * in_pre(struct TNode *p){
    while(p!=NULL && p->rc!=NULL)
        p = p->rc;
    return p;
}

struct TNode * in_succ(struct TNode *p){
    while(p!=NULL && p->lc!=NULL)
        p = p->lc;
    return p;
}

struct TNode * delete_node(struct TNode *p, int key){
    struct TNode *q;

    if(p == NULL)
        return NULL;
    if(p->lc==NULL && p->rc==NULL){
        if(p==root)
            root = NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->lc = delete_node(p->lc, key);
    else if(key > p->data)
        p->rc = delete_node(p->rc, key);
    else{
        if(calc_height(p->lc) > calc_height(p->rc)){
            q = in_pre(p->lc);
            p->data = q->data;
            p->lc = delete_node(p->lc, q->data);
        }
        else{
            q = in_succ(p->rc);
            p->data = q->data;
            p->rc = delete_node(p->rc, q->data);
        }
    }

    return p;
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
    int x, y = 0;
    struct TNode *key_node;

    insert(root, 30); // Root node
    insert(root, 20);
    insert(root, 40);
    insert(root, 10);
    insert(root, 25);
    insert(root, 35);
    insert(root, 50);
    insert(root, 50); // Duplicate, will not insert

    printf("Display tree nodes using inorder traversals -- \n");
    inorder(root);

    printf("\n\nEnter the node value you want to search: ");
    scanf("%d", &y);
    key_node = search(root, y);

    if(key_node != NULL)
        printf("\nKey %d found at address %p.\n\n", key_node->data, key_node);
    else
        printf("\nKey not found.\n\n");

    // Deleting root node
    root = delete_node(root, 30);

    printf("Display tree nodes using inorder traversals (after deletion) -- \n");
    inorder(root);

    x = destroy_tree(root);

    if(x != -1)
        printf("\nTree is destroyed successfully.\n");
    else
        printf("\nUnable to destroy the tree.\n");
    
    return 0;
}