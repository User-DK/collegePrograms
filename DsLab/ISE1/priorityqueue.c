#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Element {
    int data;
    int priority;
};

struct PriorityQueue {
    struct Element array[MAX_SIZE];
    int size;
};

void initialize(struct PriorityQueue *pq) {
    pq->size = 0;
}

int isEmpty(struct PriorityQueue *pq) {
    return pq->size == 0;
}

int isFull(struct PriorityQueue *pq) {
    return pq->size == MAX_SIZE;
}

void enqueue(struct PriorityQueue *pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }

    int i = pq->size;
    struct Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    pq->array[i] = newElement;
    pq->size++;

    while (i > 0 && pq->array[i].priority < pq->array[(i - 1) / 2].priority) {
        struct Element temp = pq->array[i];
        pq->array[i] = pq->array[(i - 1) / 2];
        pq->array[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

int dequeue(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = pq->array[0].data;

    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;

    int i = 0;

    while (1) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int smallest = i;

        if (leftChild < pq->size && pq->array[leftChild].priority < pq->array[smallest].priority) {
            smallest = leftChild;
        }
        if (rightChild < pq->size && pq->array[rightChild].priority < pq->array[smallest].priority) {
            smallest = rightChild;
        }

        if (smallest != i) {
            struct Element temp = pq->array[i];
            pq->array[i] = pq->array[smallest];
            pq->array[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }

    return data;
}

void display(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Data: %d, Priority: %d\n", pq->array[i].data, pq->array[i].priority);
    }
}

int main() {
    struct PriorityQueue pq;
    initialize(&pq);

    enqueue(&pq, 5, 2);
    enqueue(&pq, 10, 1);
    enqueue(&pq, 3, 3);
    enqueue(&pq, 7, 2);

    display(&pq);

    printf("\nDequeue: %d\n", dequeue(&pq));

    printf("\nPriority Queue after dequeue:\n");
    display(&pq);

    return 0;
}
