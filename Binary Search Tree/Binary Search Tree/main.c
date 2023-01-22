//
//  main.c
//  Binary Search Tree
//
//  Created by test on 06/01/22.
//  Copyright © 2022 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *leftChild;
    int data;
    struct Node *rightChild;
}*root = NULL;

void insert(int key) {
    struct Node *t = root;
    struct Node *r = NULL, *p;
    
    if (!root) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->leftChild = p->rightChild = NULL;
        root = p;
        return;
    }
    
    while (t) {
        r = t;
        if (key < t->data) {
            t = t->leftChild;
        } else if (key > t->data) {
            t = t->rightChild;
        } else {
            return;
        }
    }
    
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->leftChild = p->rightChild = NULL;
    
    if (key < r->data) {
        r->leftChild = p;
    } else {
        r->rightChild = p;
    }
}

void inorder(struct Node *p) {
    if (p) {
        inorder(p->leftChild);
        printf("%d ", p->data);
        inorder(p->rightChild);
    }
}

struct Node * search(int key) {
    struct Node *t = root;
    
    while (t) {
        if (key == t->data) {
            return t;
        } else if (key < t->data) {
            t = t->leftChild;
        } else {
            t = t->rightChild;
        }
    }
    return NULL;
}

int height(struct Node *p) {
    int x, y;
    
    if (!p) {
        return 0;
    }
    
    x = height(p->leftChild);
    y = height(p->rightChild);
    
    return x > y ? x + 1 : y + 1;
}

struct Node * inPre(struct Node *p) {
    while (p && p->rightChild) {
        p = p->rightChild;
    }
    
    return p;
}


struct Node * inSucc(struct Node *p) {
    while (p && p->leftChild) {
        p = p->leftChild;
    }
    
    return p;
}

struct Node * delete(struct Node *p, int key) {
    
    struct Node *q;
    
    if (!p) {
        return NULL;
    }
    
    if (!p->leftChild && !p->rightChild) {
        if (p == root) {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    
    if (key < p->data) {
        p->leftChild = delete(p->leftChild, key);
    } else if (key > p->data) {
        p->rightChild = delete(p->rightChild, key);
    } else {
        if (height(p->rightChild) > height(p->rightChild)) {
            q = inPre(p->leftChild);
            p->data = q->data;
            p->leftChild = delete(p->leftChild, q->data);
        } else {
            q = inSucc(p->rightChild);
            p->data = q->data;
            p->rightChild = delete(p->rightChild, q->data);
        }
    }
    return p;
}

int main() {
    int A[] = {10,5,20,8,30};
    struct Node *temp;
    
    for (int i = 0; i < 5; i++) {
        insert(A[i]);
    }
    
    inorder(root);
    printf("\n");
    
    temp = search(2);
    if (temp) {
        printf("Element %d is found\n", temp->data);
    } else {
        printf("Element is not found\n");
    }
    
    return 0;
}
