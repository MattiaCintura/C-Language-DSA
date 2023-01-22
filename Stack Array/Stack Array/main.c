//
//  main.c
//  Stack Array

//
//  Created by test on 28/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// Structure of a Stack using an Array
struct Stack {
    int size;
    int top;
    int *S;
};

// Create a Stack using an Array
void create(struct Stack *st) {
    printf("Enter size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

// Display a Stack
void display(struct Stack st) {
    int i;
    
    for (i = st.top; i >= 0; i--) {
        printf("%d ", st.S[i]);
    }
    
    printf("\n");
}

// Push a new element inside a Stack
void push(struct Stack *st, int x) {
    if (st->top == st->size -1) {
        printf("Stack Overflow\n");
    } else {
        st->top++;
        st->S[st->top] = x;
    }
}

// Pop an element from a Stack
int pop(struct Stack *st) {
    int x = -1;
    
    if (st->size == -1) {
        printf("Stack Underflow\n");
    } else {
        x = st->S[st->top--];
    }
    
    return x;
}

// Check if an element at a give index is avelable in a Stack
int peek(struct Stack st, int index) {
    int x = -1;
    
    if (st.top - index + 1 < 0) {
        printf("Invalid Index");
    }
    x = st.S[st.top - index + 1];
    
    return x;
}

// Check if a Stack is empty
int isEmpty(struct Stack st) {
    if (st.top == -1) {
        return 1;
    }
    return 0;
}
// Check if a Stack is full
int isFull(struct Stack st) {
    if (st.top == st.size - 1) {
        return 1;
    }
    return 0;
}

// Return the top element of a Stack
int stackTop(struct Stack st) {
    if (!isEmpty(st)) {
        return st.S[st.top];
    }
    return -1;
}

int main() {
    struct Stack st;
    create(&st);
    
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    
    display(st);
    
    return 0;
}
