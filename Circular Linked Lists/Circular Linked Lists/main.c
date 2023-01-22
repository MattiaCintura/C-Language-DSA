//
//  main.c
//  Circular Linked Lists
//
//  Created by test on 27/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*head;

// Create a Circular Linked List
void creare(int A[], int n) {
    int i;
    struct Node *t, *last;
    
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;
    
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// Display a Circular Linked List
void display(struct Node *h) {
    do {
        printf("%d ", h->data);
        h = h->next;
    } while (h != head);
    printf("\n");
}

// Count number of elements in a Circular Linked List
int count(struct Node *p) {
    int c = 0;
    
    do {
        c++;
        p = p->next;
    } while(p != head);
    
    return c;
}

// Insert an element in a Circular Linked List
void insertElement(struct Node *p, int index, int x) {
    struct Node *t;
    int i;
    
    if (index < 0 || index > count(p)) {
        return;
    }
    
    if (index == 0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        
        if (head == NULL) {
            head = t;
            head->next = head;
        } else {
            while (p->next != head) {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

// Delete an element from a Circular Linked List
int deleteElement(struct Node *p, int index) {
    struct Node *q;
    int i, x;
    
    if (index < 0 || index > count(p)) {
        return -1;
    }
    
    if (index == 1) {
        while (p->next != head) {
            p = p->next;
        }
        x = head->data;
        if (head == p) {
            free(head);
            head = NULL;
        } else {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    } else {
        for (i = 0; i < index - 2; i++) {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main() {
    int A[] = {1,2,3,4,5};
    
    creare(A, 5);
    
    display(head);

    return 0;
}
