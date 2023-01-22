//
//  Queue.h
//  Tree
//
//  Created by test on 05/01/22.
//  Copyright © 2022 test. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

struct Node {
    struct Node *leftChild;
    int data;
    struct Node *rightChild;
};

struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q;
};

// Create a Queue using an Array
void createQueue(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

// Add an element to a Queue
void enqueue(struct Queue *q, struct Node *x) {
    if (q->rear == q->size - 1) {
        printf("Queue is full");
    } else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// Delete an element from a Queue
struct Node* dequeue(struct Queue *q) {
    struct Node* x = NULL;
    
    if (q->front == q->rear) {
        printf("Queue is empty");
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// Is a Queue empty
int isEmptyQueue(struct Queue q) {
    return q.front == q.rear;
}

#endif /* Queue_h */
