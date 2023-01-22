//
//  main.c
//  Stack Linked Lists
//
//  Created by test on 28/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// Structure of a Stack using a Linked List
struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int x) {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    
    if (t == NULL) {
        printf("Stack is full");
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    struct Node *t;
    int x = -1;
    
    if (top == NULL) {
        printf("Stack is empty");
    } else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display() {
    struct Node *p;
    
    p = top;
    
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main() {
    
    return 0;
}
