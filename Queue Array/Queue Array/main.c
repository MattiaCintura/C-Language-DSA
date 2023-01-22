//
//  main.c
//  Queue Array
//
//  Created by test on 28/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

// Create a Queue using an Array
void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    
    q->Q = (int *)malloc(q->size * sizeof(int));
}

// Display a Queue
void display(struct Queue q) {
    for (int i = q.front + 1; i <= q.rear; i++) {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

// Add an element to a Queue
void enqueue(struct Queue *q, int x) {
    if (q->rear == q->size - 1) {
        printf("Queue is full");
    } else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// Delete an element from a Queue
int dequeue(struct Queue *q) {
    int x = -1;
    
    if (q->front == q->rear) {
        printf("Queue is empty");
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int main() {
    struct Queue q;
    create(&q, 5);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    display(q);
    return 0;
}
