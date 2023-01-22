//
//  main.c
//  Chaining
//
//  Created by test on 10/01/22.
//  Copyright © 2022 test. All rights reserved.
//

#include <stdio.h>
#include "Chains.h"

int hash(int key) {
    return key % 10;
}

void insert(struct Node *H[], int key) {
    int index = hash(key);
    sortedInsert(&H[index], key);
}


int main() {
    struct Node *HT[10];
    struct Node *temp;
    int i;
    
    for (i = 0; i < 10; i++) {
        HT[i] = NULL;
    }
    
    insert(HT, 12);
    insert(HT, 22);
    insert(HT, 42);
    
    temp = search(HT[hash(21)], 21);
    
    printf("%d ", temp->data);
    
    return 0;
}
