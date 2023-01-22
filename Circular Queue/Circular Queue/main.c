//
//  main.c
//  Circular Queue
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

// Create a Circular Queue using an Array
void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    
    q->Q = (int *)malloc(q->size * sizeof(int));
}

// Display a Circular Queue
void display(struct Queue q) {
    int i = q.front + 1;
    do {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("\n");
}

// Add an element to a Circular Queue
void enqueue(struct Queue *q, int x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

// Delete an element from a Circular Queue
int dequeue(struct Queue *q) {
    int x = -1;
    
    if (q->front == q->rear) {
        printf("Queue is empty");
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int main() {
    return 0;
}
