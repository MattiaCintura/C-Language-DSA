//
//  main.c
//  Tree
//
//  Created by test on 05/01/22.
//  Copyright © 2022 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

// Create a binary tree
void createTree() {
    struct Node *p, *t;
    int x;
    
    struct Queue q;
    createQueue(&q, 100);
    
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->leftChild = root->rightChild = NULL;
    enqueue(&q, root);
    
    while (!isEmptyQueue(q)) {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->leftChild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->rightChild = t;
            enqueue(&q, t);
        }
    }
}

// Display a binary tree
void preorder(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        preorder(p->leftChild);
        preorder(p->rightChild);
    }
}

void inorder(struct Node *p) {
    if (p) {
        inorder(p->leftChild);
        printf("%d ", p->data);
        inorder(p->rightChild);
    }
}

void postorder(struct Node *p) {
    if (p) {
        postorder(p->leftChild);
        postorder(p->rightChild);
        printf("%d ", p->data);
    }
}

void preorderIter(struct Node *p) {
    struct Stack st;
    createStack(&st, 100);
    
    while (p || !isEmptyStack(st)) {
        if (p) {
            printf("%d ", p->data);
            push(&st, p);
            p = p->leftChild;
        } else {
            p = pop(&st);
            p = p->leftChild;
        }
    }
}

int count(struct Node *root) {
    if (root) {
        return count(root->leftChild) + count(root->rightChild) + 1;
    }
    return 0;
}

int height(struct Node *root) {
    int x = 0;
    int y = 0;
    
    if (root == 0) {
        return 0;
    }
    
    x = height(root->leftChild);
    y = height(root->rightChild);
    
    if (x > y) {
        return x + 1;
    } else {
        return y + 1;
    }
}

int main() {
    createTree();
    
    preorderIter(root);
    
    return 0;
}
