//
//  Stack.h
//  Tree
//
//  Created by test on 06/01/22.
//  Copyright © 2022 test. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

// Structure of a Stack using an Array
struct Stack {
    int size;
    int top;
    struct Node **S;
};

// Create a Stack using an Array
void createStack(struct Stack *st, int size) {
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

// Push a new element inside a Stack
void push(struct Stack *st, int *x) {
    if (st->top == st->size -1) {
        printf("Stack Overflow\n");
    } else {
        st->top++;
        st->S[st->top] = x;
    }
}

// Pop an element from a Stack
struct Node *pop(struct Stack *st) {
    int *x = -1;
    
    if (st->size == -1) {
        printf("Stack Underflow\n");
    } else {
        x = st->S[st->top--];
    }
    
    return x;
}

// Check if a Stack is empty
int isEmptyStack(struct Stack st) {
    if (st.top == -1) {
        return 1;
    }
    return 0;
}
// Check if a Stack is full
int isFullStack(struct Stack st) {
    if (st.top == st.size - 1) {
        return 1;
    }
    return 0;
}

#endif /* Stack_h */
