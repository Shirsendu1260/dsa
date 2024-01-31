#include<stdio.h>
#include<stdlib.h>

struct CQueue{
    int size;
    int front;
    int rear;
    int *cq_arr;
};

struct CQueue * create(struct CQueue *cq, int n){
    cq->size = n;
    cq->front = cq->rear = -1;
    cq->cq_arr = (int *)malloc(cq->size*sizeof(int));

    return cq;
}

void destroy(struct CQueue *cq){
    free(cq->cq_arr);
    printf("The circular queue is destroyed successfully.\n");
}

int isEmpty(struct CQueue cq){
    if(cq.front == cq.rear)
        return 1;
    else
        return 0;
}

int isFull(struct CQueue cq){
    if((cq.rear+1)%cq.size == cq.front)
        return 1;
    else
        return 0;
}

void enqueue(struct CQueue *cq, int val){
    if(isFull(*cq))
        printf("The circular queue is full, unable to enqueue.\n");
    else{
        cq->rear = (cq->rear+1) % cq->size;
        cq->cq_arr[cq->rear] = val;
        printf("%d is enqueued.\n", val);
    }
}

int dequeue(struct CQueue *cq){
    int x = -1;

    if(isEmpty(*cq))
        printf("The circular queue is empty, unable to dequeue.\n");
    else{
        cq->front = (cq->front+1) % cq->size;
        x = cq->cq_arr[cq->front];
        cq->cq_arr[cq->front] = 0;
    }

    return x;
}

void display(struct CQueue cq){
    int i;

    // We will display all of the elements in FIFO in circular fashion.
    // Here 'rear' and 'front' will be on the index of lastly enqueued element and the lastly dequeued element respectively.
    // The element at 'front' is deleted (deleted logically) or unavailable, so we have to start from the very next element.
    // When we reach 'front' (or 'front+1') again that means it is a circular queue.
    printf("\nThe circular queue elements are: ");
    i = cq.front+1;
    do{
        printf("%d ", cq.cq_arr[i]);
        i = (i+1)%cq.size;
    }while(i!=cq.front+1 && i!=cq.front);
    if(i==cq.front+1 || i==cq.front)
        printf("(Reached 'front' again)");
    printf("\n\n");
}

int main(){
    struct CQueue cqstk;
    int size = 5;

    create(&cqstk, size);

    enqueue(&cqstk, 100);
    enqueue(&cqstk, 150);
    enqueue(&cqstk, 200);
    enqueue(&cqstk, 250);
    enqueue(&cqstk, 300);

    display(cqstk);

    printf("%d is dequeued.\n", dequeue(&cqstk));
    printf("%d is dequeued.\n", dequeue(&cqstk));
    printf("%d is dequeued.\n", dequeue(&cqstk));

    display(cqstk);

    printf("%d is dequeued.\n", dequeue(&cqstk));
    printf("%d is dequeued.\n", dequeue(&cqstk));
    printf("%d is dequeued.\n", dequeue(&cqstk));

    destroy(&cqstk);
    
    return 0;
}