//
//  main.c
//  AVL Tree
//
//  Created by test on 07/01/22.
//  Copyright © 2022 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *leftChild;
    int data;
    int height;
    struct Node *rightChild;
}*root = NULL;

int height(struct Node *p) {
    int leftHeight;
    int rightHeight;
    
    leftHeight = p && p->leftChild ? p->leftChild->height : 0;
    rightHeight = p && p->rightChild ? p->rightChild->height : 0;
    
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int balance(struct Node *p) {
    int leftHeight;
    int rightHeight;
    
    leftHeight = p && p->leftChild ? p->leftChild->height : 0;
    rightHeight = p && p->rightChild ? p->rightChild->height : 0;
    
    return leftHeight - rightHeight;
}

struct Node *LLRotation(struct Node *p) {
    struct Node *pl = p->leftChild;
    struct Node *plr = pl->rightChild;
    
    pl->rightChild = p;
    p->leftChild = plr;
    p->height = height(p);
    pl->height = height(pl);
    
    if (root == p) {
        root = pl;
    }
    
    return pl;
}

struct Node *LRRotation(struct Node *p) {
    struct Node *pl = p->leftChild;
    struct Node *plr = pl->rightChild;
    
    pl->rightChild = plr->leftChild;
    p->leftChild = plr->rightChild;
    plr->leftChild = pl;
    plr->rightChild = p;
    
    pl->height = height(pl);
    p->height = height(p);
    plr->height = height(plr);
    
    if (root == p) {
        root = plr;
    }
    
    return plr;
}

struct Node *RRRotation(struct Node *p) {
    return NULL;
}

struct Node *RLRotation(struct Node *p) {
    return NULL;
}

struct Node *insert(struct Node *p, int key) {
    struct Node *t = NULL;
    
    if (!p) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->leftChild = t->rightChild = NULL;
        return t;
    }
    
    if (key < p->data) {
        p->leftChild = insert(p->leftChild, key);
    } else if (key > p->data) {
        p->rightChild = insert(p->rightChild, key);
    }
    
    p->height = height(p);
    
    if (balance(p) == 2 && balance(p->leftChild) == 1) {
        // LL Rotation
        return LLRotation(p);
    } else if (balance(p) == 2 && balance(p->leftChild) == -1) {
        // LR Rotation
        return LRRotation(p);
    } else if (balance(p) == -2 && balance(p->rightChild) == -1) {
        // RR Rotation
        return RRRotation(p);
    } else if (balance(p) == -2 && balance(p->rightChild) == 1) {
        // RL Rotation
        return RLRotation(p);
    }
    
    return t;
}

int main() {
    return 0;
}
