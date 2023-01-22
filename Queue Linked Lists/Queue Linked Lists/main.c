//
//  main.c
//  Queue Linked Lists
//
//  Created by test on 28/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

// Display a Queue using a Linked List
void display() {
    struct Node *p = front;
    
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Insert an element in a Queue using Linked List
void enqueue(int x) {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    
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
    struct Node *t;
    
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

int main() {
    
    return 0;
}
