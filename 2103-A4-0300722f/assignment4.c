/* 
 * File: assignment4.c
 * Author: Nathan Fredericks 0300722f@acadiau.ca
 * Date: 2024/03/04
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* dyn_mem_alloc(int size) {
    int* p;
    if ((p = malloc((size + 1)*sizeof(int))) == NULL)
        exit(EXIT_FAILURE);
    srand(time(NULL));
    p[0] = size;
    int i;
    for (i = 1; i <= size; i++) {
        int r = rand() % 100 + 1;
        p[i] = r;
        printf("%d\n", p[i]);
    }
    return p;
}

void print(const int* p) {
    int i;
    int size = p[0];
    for (i = 1; i <= size; i++) {
        printf("%d\n", p[i]);
    }
}

int max(const int* p) {
    int i;
    int size = p[0];
    int current = 1;
    for (i = 1; i <= size; i++) {
        int el = p[i];
        if (el > current) {
            current = el;
        }
    }
    return current;
}

int min(const int* p) {
    int i;
    int size = p[0];
    int current = 100;
    for (i = 1; i <= size; i++) {
        int el = p[i];
        if (el < current) {
            current = el;
        }
    }
    return current;
}

int sum(const int* p) {
    int i;
    int size = p[0];
    int sum = 0;
    for (i = 1; i <= size; i++) {
        int el = p[i];
        sum += el;
    }
    return sum;
}

float avg(const int* p) {
    int total = sum(p);
    int size = p[0];
    return total / (float)size;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
}

void reverse(int* p) {
    int size = p[0];
    int *arr = p + 1;
    int *a = arr;
    int *b = arr + size - 1;
    while(a < b) {
        swap(a, b);
        a++;
        b--;
    }
}

void dealloc_mem(int* p) {
    free(p);
    p = NULL;
}

int main(void) {
    int size;
    printf("Array size: ");
    scanf("%d", &size);
    getchar();

    printf("Allocating memory...\n");
    int* arr = dyn_mem_alloc(size);
    
    printf("Array:\n");
    print(arr);

    printf("Min value: %d\n", min(arr));
    printf("Max value: %d\n", max(arr));

    printf("Sum: %d\n", sum(arr));
    printf("Average: %.2f\n", avg(arr));

    reverse(arr);
    printf("Reversed Array:\n");
    print(arr);

    printf("Deallocating memory...\n");
    dealloc_mem(arr);

    return EXIT_SUCCESS;
}
