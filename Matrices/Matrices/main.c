//
//  main.c
//  Matrices
//
//  Created by test on 15/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>

struct Matrix{
    int *A;
    int n;
};

// Diagonal Matrix
void setDiagnal(struct Matrix *m, int i, int j, int x) {
    if (i == j) {
        m->A[i - 1] = x;
    }
}

int getDiagnal(struct Matrix m, int i, int j) {
    if (i == j) {
        return m.A[i - 1];
    } else {
        return 0;
    }
}

// Lower Triangolar Matrix
void setLowTriangolar(struct Matrix *m, int i, int j, int x) {
    if (i >= j) {
        m->A[i * (i - 2) / 2 + j - 1] = x;
    }
}

int getLowTriangolar(struct Matrix m, int i, int j) {
    if (i >= j) {
        return m.A[i * (i - 2) / 2 + j - 1];
    } else {
        return 0;
    }
}

// Display a Matrix
void display(struct Matrix m) {
    int i, j;
    
    for (i = 0; i < m.n; i++) {
        for (j = 0; j < m.n; j++) {
            if (i == j) {
                printf("%d ", m.A[i]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}



int main() {
    struct Matrix m;
    m.n = 4;
    
    setLowTriangolar(&m, 1, 2, 5);
    setLowTriangolar(&m, 2, 3, 8);
    setLowTriangolar(&m, 3, 4, 9);
    setLowTriangolar(&m, 4, 5, 12);
    
    display(m);
    return 0;
}

