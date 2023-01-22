//
//  Queue.h
//  Graphs
//
//  Created by test on 11/01/22.
//  Copyright © 2022 test. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include <stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
}*front = NULL, *rear = NULL;


// Insert an element in a Queue using Linked List
void enqueue(int x) {
    struct Queue *t;
    t = (struct Queue *)malloc(sizeof(struct Queue));
    
    if (t == NULL) {
        printf("Queue is full");
    } else {
        t->data = x;
        t->next = NULL;
        
        if (front == NULL) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}

// Delete an element in a Queue using Linked List
int dequeue() {
    int x = -1;
    struct Queue *t;
    
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

// Check if Queue is empty
int isEmpty() {
    return front == NULL;
}

#endif /* Queue_h */
