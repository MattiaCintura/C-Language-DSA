//
//  quiz.cpp
//  Recursions
//
//  Created by test on 11/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>

// Question 1
int quest1(int n) {
    static int i = 1;
    if (n >= 5) {
        return n;
    }
    n += i;
    i++;
    
    return quest1(n); // quest1(1)  7
}

// Question 2
void quest2(int n, int sum) {
    int k = 0, j = 0;
    if (n == 0) return;
    k = n % 10;
    j = n / 10;
    sum = sum + k;
    quest2(j, sum);
    printf("%d", k); // quest2(2048, 0)  2, 0, 4, 8, 0
}

// Question 3
int quest3(int &x, int c) {
    c = c - 1;
    if (c == 0) return c;
    x = x + 1;
    return quest3(x, c) * c; // quest3(5, 5)  9^4 6561
}

// Question 4
int quest4(int n){
    int x = 1, k;
    if (n == 0) return x;
    for (k = 1; k < n; k++) {
        x = x + quest4(k) * quest4(n - k);
    }
    return x; // quest4(5)  51
}

// Question 5
void quest5(int n) {
    static int d = 1;
    printf("%d", n);
    printf("%d", d);
    d++;
    if (n > 1) quest5(n - 1);
    printf("%d", d); // quest5(3)  3 1 2 2 1 3 4 4 4
}
