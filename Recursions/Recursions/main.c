//
//  main.c
//  Recursions
//
//  Created by test on 04/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>

// Head Recursion
void headRec(int n) {
    if (n > 0) {
        headRec(n - 1);
        printf("%d ", n);
        // Return: 1 2 3 ...
    }
}

// Tail Recursion
void tailRec(int n) {
    if (n > 0) {
        printf("%d ", n);
        tailRec(n - 1);
        // Return ... 3 2 1
    }
}

// Static variable in Recursion
int staticRec(int n) {
    static int stat = 0;
    
    if (n > 0) {
        stat++;
        return staticRec(n - 1) + stat;
        // Return 25
    }
    return 0;
}

// Global variable in Recursion
int global = 0;

int globalRec(int n) {
    if (n > 0) {
        global++;
        return globalRec(n - 1) + global;
        // Return 25 multiplied by the times this func is called
    }
    return 0;
}

// Tree Recursion
void treeRec(int n) {
    if (n > 0) {
        printf("%d ", n);
        treeRec(n - 1);
        treeRec(n - 1);
        // Return 3 2 1 1 2 1 1
    }
}

// Indirect Recursion
void indRec2(int n);

void indRec1(int n) {
    if (n > 0) {
        printf("%d ", n);
        indRec2(n - 1);
    }
}

void indRec2(int n) {
    if (n > 1) {
        printf("%d ", n);
        indRec1(n / 2);
    }
}

// Nested Recursion
int nestRec(int n) {
    if (n > 100) {
        return n - 10;
    } else {
        return nestRec(nestRec(n + 11));
    }
}

// Sum of first natural numbers with Recursion
int sumRec(int n) {
    if (n == 0) {
        return 0;
    }
    return sumRec(n - 1) + n;
}

int sumItr(int n) {
    int s = 0;
    int i;
    for (i=1;i<=n;i++) {
        s = s + i;
    }
    return s;
}

// Factirial of a number with Recursion
int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return fact(n - 1) * n;
}

int factItr(int n) {
    int f = 1;
    int i;
    for (i=1;i<=n;i++) {
        f = f * i;
    }
    return f;
}

// Exponent of a number with Recursion
int power(int m, int n) {
    if (n == 0) {
        return  1;
    }
    return power(m ,n - 1) * m;
}

int powerItr(int m, int n) {
    if (n == 0) {
        return  1;
    }
    if (n % 2 == 0) {
        return powerItr(m * m, n / 2);
    }
    return m * powerItr(m * m, (n - 1) / 2);
}

// Taylor series with Recursion
double taylor(int x, int n) {
    static double p = 1, f = 1;
    double r;

    if (n == 0) {
        return 1;
    }
    
    r = taylor(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

// Taylor series Horner's role
double taylorHorner(int x, int n) {
    static double s = 0;
    if (n == 0) {
        return s;
    }
    s = 1 + x * s / n;
    return taylorHorner(x, n - 1);
}

double taylorHornerItr(int x, int n) {
    static double s = 1;
    int i;
    double num = 1;
    double den = 1;
    
    for (i = 1; i <= n; i++) {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

// Fibonacci series
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}

int fibItr(int n) {
    int t0 = 0;
    int t1 = 1;
    int s = 0;
    int i;
    
    if (n <= 1) {
        return n;
    }
    
    for (i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int F[10];

void arreyInit() {
    int i;
    for (i = 0; i < 10; i++) {
        F[i] = -1;
    }
}

int fibMem(int n) {
    if (n <= 1) {
        F[n] = n;
        return n;
    } else {
        if (F[n - 2] == -1) {
            F[n -2] = fibMem(n - 2);
        }
        if (F[n - 1] == -1) {
            F[n - 1] = fibMem(n - 1);
        }
        return F[n - 2] + F[n - 1];
    }
    
    
}

// Combination formula
int nCr(int n, int r) {
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n - r);
    
    return num / den;
}


int combPascalTri(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    return combPascalTri(n - 1, r - 1) + combPascalTri(n - 1, r);
}

// Tower of Hanoi
void TOH(int n, int A, int B, int C) {
    if (n > 0) {
        TOH(n - 1, A, C, B);
        printf("(%d, %d) \n", A, C);
        TOH(n - 1, B, A, C);
    }
}

int main() {
    TOH(5, 1, 2, 3);
    return 0;
}










