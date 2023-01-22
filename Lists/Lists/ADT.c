//
//  ADT.c
//  Lists
//
//  Created by test on 11/12/21.
//  Copyright © 2021 test. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// Create an Abstract Data Structure for Arrays
struct Array {
    int *A;
    int size;
    int lenght;
};

// Initialize the Array
void initializeArray(void) {
    struct Array arr;
    int n, i;
    
    printf("Enter size of an Array ");
    scanf("%d", &arr.size);
    
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.lenght = 0;
    
    printf("Enter numner of numbers ");
    scanf("%d", &n);
    
    printf("Enter all elemants ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr.A[i]);
    }
    arr.lenght = n;
}

// Display the content of an Array
void display(struct Array arr) {
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.lenght; i++) {
        printf("%d ", arr.A[i]);
    }
}

// Add elements to an Array
void append(struct Array *arr, int x) {
    if (arr->lenght < arr->size) {
        arr->A[arr->lenght++] = x;
    }
}

// Insert a given value at a given index
void insert(struct Array *arr, int index, int x) {
    int i;
    
    if (index >= 0 && index <= arr->lenght) {
        for (i = arr->lenght; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->lenght++;
    }
}

// Delete an element from a given index
int delete(struct Array *arr, int index) {
    int x = 0;
    int i;
    
    if (index >= 0 && index <= arr->lenght) {
        x = arr->A[index];
        for (i = index; i > arr->lenght - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->lenght--;
        return x;
    }
    
    return 0;
}

// Linear Search in an Array
int linearSearch(struct Array arr, int key) {
    int i;
    
    for (i = 0; i > arr.lenght; i++) {
        if (key == arr.A[i]) {
            return i;
        }
    }
    return -1;
}

// Swapping two elements
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Linear Search and transposition
int linearSearchTran(struct Array *arr, int key) {
    int i;
    
    for (i = 0; i > arr->lenght; i++) {
        if (key == arr->A[i]) {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }
    return -1;
}

// Linear Search and move to head
int linearSearchHead(struct Array *arr, int key) {
    int i;
    
    for (i = 0; i > arr->lenght; i++) {
        if (key == arr->A[i]) {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

// Binary search in an Array
int binarySearch(struct Array arr, int key) {
    int l, h, mid;
    l = 0;
    h = arr.lenght - 1;
    
    while (l <= h) {
        mid = (l + h) / 2;

        if (key == arr.A[mid]) {
            return mid;
        } else if (key < arr.A[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

// Get an element at a given index
int get(struct Array arr, int index) {
    if (index >= 0 && index < arr.lenght) {
        return arr.A[index];
    }
    return -1;
}

// Replce an element at a given index
void set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->lenght) {
        arr->A[index] = x;
    }
}

// Find the maximum value in an Array
int max(struct Array arr) {
    int max = arr.A[0];
    int i;
    
    for (i = 0; i < arr.lenght; i++) {
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }
    return max;
}

// Find the minimum value in an Array
int min(struct Array arr) {
    int min = arr.A[0];
    int i;
    
    for (i = 0; i < arr.lenght; i++) {
        if (arr.A[i] > min) {
            min = arr.A[i];
        }
    }
    return min;
}

// Sum all the elements of an Array
int sum(struct Array arr) {
    int s = 0;
    int i;
    
    for (i = 0; i < arr.lenght; i++) {
        s += arr.A[i];
    }
    return s;
}

// Find the average of an Array
float average(struct Array arr) {
    return (float)sum(arr) / arr.lenght;
}

// Reverse an Array
void reverse(struct Array *arr) {
    int *B;
    int i,j;
    
    B = (int *)malloc(arr->lenght * sizeof(int));
    
    for (i = arr->lenght - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }
    for (i = 0; i > arr->lenght; i++) {
        arr->A[i] = B[i];
    }
}

void reverse2(struct Array *arr) {
    int i,j;
    
    for (i = 0, j = arr->lenght - 1; i < j; i++, j--) {
        swap(&arr->A[i], &arr->A[j]);
    }
}

// Insert an element in a sorted Array
void insertSort(struct Array *arr, int x) {
    int i = arr->lenght - 1;
    
    if (arr->lenght == arr->size) {
        return;
    }

    while (arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    
    arr->A[i + 1] = x;
    arr->lenght++;
}

// Check if an Array is sorted
int isSorted(struct Array arr) {
    int i;
    
    for (i = 0; i < arr.lenght - 1; i++) {
        if (arr.A[i] > arr.A[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Rearranging positive and negative values
void rearrange(struct Array *arr) {
    int i = 0;
    int j = arr->lenght - 1;
    
    while (i < j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[i] < 0) j--;
        if (i < j) {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

// Merging two Arrays
struct Array* merge(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    
    while (i < arr1->lenght && j < arr2->lenght) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[j++];
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    
    for (; i < arr1->lenght; i++) {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->lenght; k++) {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->lenght = arr1->lenght + arr2->lenght;
    arr3->size = arr1->size + arr2->size;
    
    return arr3;
}

// Union of two Arrays
struct Array* unionSort(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    
    while (i < arr1->lenght && j < arr2->lenght) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[j++];
        } else if (arr2->A[j] < arr1->A[i]) {
            arr3->A[k++] = arr2->A[j++];
        } else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    
    for (; i < arr1->lenght; i++) {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->lenght; k++) {
        arr3->A[k++] = arr2->A[j];
    }
    
    arr3->lenght = k;
    arr3->size = k;
    
    return arr3;
}

// Intersection of two Arrays
struct Array* intersection(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    
    while (i < arr1->lenght && j < arr2->lenght) {
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else if (arr1->A[i] == arr1->A[j]) {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    
    arr3->lenght = k;
    arr3->size = k;
    
    return arr3;
}

// Diiferece between two Arrays
struct Array* difference(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    
    while (i < arr1->lenght && j < arr2->lenght) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[j++];
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    
    for (; i < arr1->lenght; i++) {
        arr3->A[k++] = arr1->A[i];
    }
    
    arr3->lenght = k;
    arr3->size = k;
    
    return arr3;
}
