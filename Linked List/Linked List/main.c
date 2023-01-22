//
//  main.c
//  Linked List
//
//  Created by test on 23/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

// Create a Linked List
void createLinkedList(int A[], int n) {
    int i;
    struct Node *t, *last;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (i=1; i<n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void createLinkedList2(int A[], int n) {
    int i;
    struct Node *t, *last;
    
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = first;
    
    for (i=1; i<n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Display a Linked List
void display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Count how many Nodes are inside a Linked List
int count(struct Node *p) {
    int c = 0;
    
    while (p != NULL) {
        c++;
        p = p->next;
    }
    
    return c;
}

// Sum all the elements in a Linked List
int sum(struct Node *p) {
    int sum = 0;
    
    while (p) {
        sum = sum + p->data;
        p = p->next;
    }
    
    return sum;
}

// Maximum element in a Linked List
int maxElement(struct Node *p) {
    int max = INT32_MIN;
    
    while (p) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    
    return max;
}

// Minimum element in a Linked List
int minElement(struct Node *p) {
    int min = INT32_MAX;
    
    while (p) {
        if (p->data < min) {
            min = p->data;
        }
        p = p->next;
    }
    
    return min;
}

// Search in a Linked List
struct Node * search(struct Node *p, int key) {
    while (p != NULL) {
        if (key == p->data) {
            return p;
        }
        p = p->next;
    }
    
    return NULL;
}

// Insert an element in a Linked List
void insert(struct Node *p, int index, int x) {
    struct Node *t;
    
    if (index < 0 || index > count(p)) {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    
    if (index == 0) {
        t->next = first;
        first = t;
    } else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    
}

// Insert an element in a sorted Linked List
void insertSort(struct Node *p, int x) {
    struct Node *t, *q = NULL;
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if (first == NULL) {
        first = t;
    } else {
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            t->next = first;
            first = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Delete an element at a given value in a Linked List
int deleteElement(struct Node *p, int index) {
    struct Node *q = NULL;
    int x = -1;
    
    if (index < 1 || index > count(p)) {
        return -1;
    }
    
    if (index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    } else {
        for (int i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

// Check if a Linked List is sorted
int isSorted(struct Node *p) {
    int x = INT32_MIN;
    
    while (p != NULL) {
        if (p->data < x) {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    
    return 1;
}

// Remove duplicates from a sorted Linked List
void removeDup(struct Node *p) {
    struct Node *q = p->next;
    
    while (q != NULL) {
        if (p->data != q->data) {
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

// Reverse a Linked List
void reverse(struct Node *p) {
    int *A;
    int i = 0;
    struct Node *q = p;
    
    A = (int *)malloc(sizeof(int) * count(p));
    
    while (q != NULL) {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    
    q = first;
    i--;
    
    while (q != NULL) {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse2(struct Node *p) {
    struct Node *q = NULL, *r = NULL;
    
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Concatenation of two Linked Lists
void concat(struct Node *p, struct Node *q) {
    third = p;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = q;
}

// Merge two Linked Lists
void merge(struct Node *p, struct Node *q) {
    struct Node *last;
    
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    
    if (p) last->next = p;
    if (q) last->next = q;
}

// Check if a Linked List has a loop
int isLoop(struct Node *f) {
    struct Node *p, *q;
    p = q = f;
    
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while(p && q && p != q);
    
    if (p == q) {
        return 1;
    }
    
    return 0;
}

int main() {
    int A[] = {10,20,30,40,50};
    createLinkedList(A, 5);
    
    display(first);
    
    printf("The minimum is %d \n", minElement(first));
    return 0;
}
