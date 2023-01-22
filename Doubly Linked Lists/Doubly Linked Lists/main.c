//
//  main.c
//  Doubly Linked Lists
//
//  Created by test on 27/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

// Create a Doubly Linked List
void create(int A[], int n) {
    struct Node *t, *last;
    int i;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Display a Doubly Linked List
void display(struct Node *p) {
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Count the number of elements in Doubly Linked List
int count(struct Node *p) {
    int c = 0;
    
    while (p) {
        c++;
        p = p->next;
    }
    
    return c;
}

// Insert an element at a given index in Doubly Linked List
void insertElement(struct Node *p, int index, int x) {
    struct Node *t;
    int i;
    
    if (index < 0 || index > count(p)) {
        return;
    }

    if (index == 0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        
        t->prev = p;
        t->next = p->next;
        
        if (p->next) p->next->prev = t;
        
        p->next = t;
    }
}

// Delete an element from a Doubly Linked List
int deleteElement(struct Node *p, int index) {
    int i = -1, x;
    
    if (index < 1 || index > count(p)) {
        return -1;
    }
    
    if (index == 1) {
        first = first->next;
        if (first) first->prev = NULL;
        x = p->data;
        free(p);
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        
        if (p->next) p->next->prev = p->prev;
        
        x = p->data;
        free(p);
    }
    return x;
}

// Reverse a Doubly Linked List
void reverse(struct Node *p) {
    struct Node *q;
    
    while (p != NULL) {
        q = p->next;
        p->next = p->prev;
        p->prev = q;
        p = p->prev;
        if (p != NULL && p->next == NULL) first = p;
    }
    
}

int main() {
    int A[] = {10,20,30,40,50};
    create(A, 5);
    
    display(first);
    reverse(first);
    display(first);
    
    
    return 0;
}
