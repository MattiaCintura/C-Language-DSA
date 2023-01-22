//
//  main.c
//  Sorting Techniques
//
//  Created by test on 08/01/22.
//  Copyright © 2022 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;
    
    do {
        do { i++; } while(A[i] <= pivot);
        do { j--; } while(A[j] > pivot);
        
        if (i < j) {
            swap(&A[i], &A[j]);
        }
    } while(i < j);
    swap(&A[l], &A[j]);
    
    return j;
}

int findMax(int A[], int n) {
    int max = INT32_MIN;
    int i;
    
    for (i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    
    return max;
}

// Bubble Sort
void bubbleSort(int A[], int n) {
    int i, j;
    int flag = 0;
    
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

// Insertion Sort
void insertionSort(int A[], int n) {
    int i, j, x;
    
    for (i = 1; i < n; i++) {
        j = i - 1;
        x = A[i];
        
        while (j > -1 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

// Selection Sort
void selectionSort(int A[], int n) {
    int i, j, k;
    
    for (i = 0; i < n - 1; i++) {
        for (j = k = i; j < n; j++) {
            if (A[j] < A[k]) {
                k = j;
            }
            swap(&A[i], &A[k]);
        }
    }
}

// Quick Sort
void quickSort(int A[], int l, int h) {
    int j;
    
    if (l < h) {
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
}

// Merge Sort
void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int B[100];
    
    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    for (; i <= mid; i++) {
        B[k++] = A[i];
    }
    for (; j <= h; j++) {
        B[k++] = A[j];
    }
    for (int i = l; i <= h; i++) {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int n) {
    int p, l, h, mid, i;
    
    for (p = 2; p <= n; p = p * 2) {
        for (i = 0; i + p - 1 < n; i = i + p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
        if (n - i > p / 2) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, n - 1);
        }
    }
    if (p / 2 < n) {
        merge(A, 0, p / 2 - 1, n - 1);
    }
}

// Count Sort
void countSort(int A[], int n) {
    int i, j, *C;
    int max = findMax(A, n);
    
    C = (int *)malloc(sizeof(int) * (max + 1));
    
    for (i = 0; i < max + 1; i++) {
        C[i] = 0;
    }
    for (i = 0; i < n; i++) {
        C[A[i]]++;
    }
    
    i = 0;
    j = 0;
    
    while (j < max + 1) {
        if (C[j] > 0) {
            A[i++] = j;
            C[j]--;
        } else {
            j++;
        }
    }
}

// Shell Sort
void shellSort(int A[], int n) {
    int gap, i, j, temp;
    
    for (gap = n / 2; gap >= 1; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp) {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    int A[] = {11,13,7,2,6,9,4,5,10,3};
    // 2 3 4 5 6 7 9 10 11 13
    int n = 10;
    
    shellSort(A, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}
