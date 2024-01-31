#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *q_arr;
};

struct Queue * create(struct Queue *q, int n){
    q->size = n;
    q->front = q->rear = -1;
    q->q_arr = (int *)malloc(q->size*sizeof(int));

    return q;
}

void destroy(struct Queue *q){
    free(q->q_arr);
    printf("The queue is destroyed successfully.\n");
}

int isEmpty(struct Queue q){
    if(q.front == q.rear)
        return 1;
    else
        return 0;
}

int isFull(struct Queue q){
    if(q.rear == q.size-1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *q, int val){
    if(isFull(*q))
        printf("Queue is full, unable to enqueue.\n");
    else{
        q->rear++;
        q->q_arr[q->rear] = val;
        printf("%d is enqueued.\n", val);
    }
}

int dequeue(struct Queue *q){
    int x = -1;

    if(isEmpty(*q))
        printf("Queue is empty, unable to dequeue.\n");
    else{
        q->front++;
        x = q->q_arr[q->front];
    }

    return x;
}

void display(struct Queue q){
    int i;

    // We will display all of the elements in FIFO.
    // Here 'rear' and 'front' will be on the index of lastly enqueued element and the lastly dequeued element respectively.
    // The element at 'front' is deleted (deleted logically) or unavailable, so we have to start from the very next element and have to go upto 'rear' to display elements.
    printf("\nThe queue elements are: ");
    for(i=q.front+1; i<=q.rear; i++){
        printf("%d ", q.q_arr[i]);
    }
    printf("\n\n");
}

int main(){
    struct Queue qstk;
    int size = 5;

    create(&qstk, size);

    enqueue(&qstk, 100);
    enqueue(&qstk, 150);
    enqueue(&qstk, 200);
    enqueue(&qstk, 250);
    enqueue(&qstk, 300);

    display(qstk);

    printf("%d is dequeued.\n", dequeue(&qstk));
    printf("%d is dequeued.\n", dequeue(&qstk));
    printf("%d is dequeued.\n", dequeue(&qstk));

    display(qstk);

    printf("%d is dequeued.\n", dequeue(&qstk));
    printf("%d is dequeued.\n", dequeue(&qstk));
    printf("%d is dequeued.\n", dequeue(&qstk));

    destroy(&qstk);
    
    return 0;
}