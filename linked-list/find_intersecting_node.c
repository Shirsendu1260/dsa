#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Stack{
    struct Node * items[10]; // This array memory will be used for storing and retrieving node addresses in LIFO fashion.
    int top;
};

struct Node *list1 = NULL;
struct Node *list2 = NULL;

void display(struct Node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
    printf("The Linked List is traversed successfully.\n\n");
}

void push_node(struct Stack *stack, struct Node *node){
    if(stack->top < 9){ // Atleast one room left for pushing a node
        // Push that node at top-most index
        stack->top++;
        stack->items[stack->top] = node;
    }
    else{
        printf("Stack overflow.\n");
    }
}

struct Node * pop_node(struct Stack *stack){
    if(stack->top >= 0) // Atleast the stack has 1 node address in it. Here, 'top = 0' means atleast one node address is there in the stack.
        return stack->items[stack->top--];
    else{ // Stack is empty i.e top = -1. Popping a node cannot be possible from an empty stack. 
        printf("Stack underflow.\n");
        return NULL;
    }
}

struct Node *stack_top(const struct Stack* stack){ // This function does not modify the stack itself. That's why 'cpnst' is used.
    if(stack->top >= 0) // Atleast one node address is there in the stack.
        return stack->items[stack->top];
    return NULL;
}

struct Node * get_intersecting_node(struct Node *p, struct Node *q){
    struct Node *result = NULL;
    
    // Create stacks for both LLs.
    struct Stack stk1;
    stk1.top = -1; // First LL's stack has currently 0 node addresses in it.
    struct Stack stk2;
    stk2.top = -1; // Second LL's stack has currently 0 node addresses in it.

    // Push nodes of the first LL onto first stack
    while(p != NULL){
        push_node(&stk1, p);
        p = p->next;
    }

    // Push nodes of the second LL onto second stack
    while(q != NULL){
        push_node(&stk2, q);
        q = q->next;
    }

    while(stk1.top>=0 && stk2.top>=0 && (stack_top(&stk1) == stack_top(&stk2))){
        result = pop_node(&stk1);
        pop_node(&stk2);
    }

    return result;
}

void destroy(struct Node *p){
    int x = -1;
    struct Node *first = p;

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
    struct Node *t, *p, *common_node, *result;
    
    // Create common node; '5'
    common_node = (struct Node *)malloc(sizeof(struct Node));
    common_node->data = 5;

    // Create first linked list
    // First node; '4'
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = 4;
    list1 = p = t;
    // Second node which is the common node; '4->5'
    p->next = common_node;
    p = p->next;
    // Third node; '4->5->1->X'
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = 1;
    p->next = t;
    p = p->next;
    p->next = NULL; // It is the last node

    // Create second linked list
    // First node; '7'
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = 7;
    list2 = p = t;
    // Second node; '7->2->X'
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = 2;
    p->next = t;
    p = p->next; 
    // Third node which is the common node; '7->2->5..'
    p->next = common_node;
    // No need to make the fourth node as it is the common part of both LLs; '7->2->5->1->X'

    display(list1);
    display(list2);

    result = get_intersecting_node(list1, list2);
    printf("The node at address %p having value %d is the intersecting node.\n", result, result->data);

    destroy(list1);
    
    // Manually deleting the rest of the nodes of second linked list as some of its nodes are deleted with first linked list by destroy() function.
    // So the destroy() function won't work properly.
    p = list2;
    list2 = list2->next;
    free(p); // Deleting 1st node i.e 7
    free(list2); // Deleting 2nd node i.e. 2

    return 0;
}