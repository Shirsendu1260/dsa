#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct PElement{
    int data;
    int priority;
};

struct PQueue{
    int size;
    int rear;
    struct PElement *pq_arr;
};

struct PQueue * create(struct PQueue *pq, int n){
    pq->size = n;
    pq->rear = -1;
    pq->pq_arr = (struct PElement *)malloc(pq->size*sizeof(struct PElement));

    return pq;
}

void destroy(struct PQueue *pq){
    free(pq->pq_arr);
    printf("The priority queue is destroyed successfully.\n");
}

int isEmpty(struct PQueue pq){
    if(pq.rear == -1)
        return 1;
    else
        return 0;
}

int isFull(struct PQueue pq){
    if(pq.rear == pq.size-1)
        return 1;
    else
        return 0;
}

void enqueue(struct PQueue *pq, int val, int pri){
    struct PElement *e;
    
    if(isFull(*pq))
        printf("The priority queue is full.\n");
    else{
        e = (struct PElement *)malloc(sizeof(struct PElement));
        e->data = val;
        e->priority = pri;

        pq->rear++;
        pq->pq_arr[pq->rear] = *e;
    }
}

int getHighestPriorityElementIndex(struct PElement *arr, int rear){
    int highest_priority, ind, i;
    highest_priority = INT_MIN;
    ind = -1;

    for(i=0; i<=rear; i++){
        if(highest_priority==arr[i].priority && ind>-1 && arr[ind].data<arr[i].data){
            highest_priority = arr[i].priority;
            ind = i;
        }
        else if(highest_priority < arr[i].priority){
            highest_priority = arr[i].priority;
            ind = i;
        }
    }

    return ind;
}

int dequeue(struct PQueue *pq){
    int ind, i;
    struct PElement result;

    if(isEmpty(*pq))
        printf("The priority queue is empty.\n");
    else{
        ind = getHighestPriorityElementIndex(pq->pq_arr, pq->rear);
        for(i=ind; i<pq->rear; i++){
            pq->pq_arr[i] = pq->pq_arr[i+1];
        }
        pq->rear--;
    }

    if(ind == -1)
        return -1;
    else{
        result = pq->pq_arr[ind];
        return result.data;
    }
}

void display(struct PQueue pq){
    int i;

    // We will display all of the elements in the order they appear.
    // We will not display based on priority, but dequeue() will be done based on priority.
    // Here 'rear' will be on the index of the lastly enqueued element.
    // Here 'rear' is both used for enqueue and dequeue, so both are done on the rear end of the queue.
    // So we will start from index 0 and go upto till the rear end.
    printf("\nThe priority queue elements are: ");
    for(i=0; i<=pq.rear; i++){
        printf("%d ", pq.pq_arr[i].data);
    }
    printf("\n\n");
}

int main(){
    struct PQueue pq;
    int size = 5;

    create(&pq, size);
    
    enqueue(&pq, 16, 4);
    enqueue(&pq, 8, 3);
    enqueue(&pq, 5, 1);
    enqueue(&pq, 6, 2);
    enqueue(&pq, 10, 5);

    display(pq);
    
    printf("%d is dequeued.\n", dequeue(&pq));
    printf("%d is dequeued.\n", dequeue(&pq));
    printf("%d is dequeued.\n", dequeue(&pq));

    display(pq);

    return 0;
}