#include <stdlib.h>
#include <stdio.h>

void* mem_alloc(size_t num, size_t size) {
    void* p;
    if ((p = calloc(num, size)) == NULL)
        exit(EXIT_FAILURE);
    return p;
}

void* change_mem_alloc(void** p, size_t num, size_t size) {
    void* p2;
    if ((p2 = (void*)calloc(num, size)) == NULL)
        exit(EXIT_FAILURE);
    free(*p);
    *p = NULL;
    return p2;
}

int main(void) {
    int* p = (int*)mem_alloc(5, sizeof(int));
    printf("%d\n", &p);
    p[0] = 2;
    p[1] = 4;
    p[2] = 6;
    p[3] = 8;
    p[4] = 10;
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d\n", p[i]);
    }
    int *p2 = (int*)change_mem_alloc((void*)&p, 10, sizeof(int));
    printf("%d\n", &p2);
    for (i = 0; i < 10; i++) {
        printf("%d\n", p2[i]);
    }
    free(p2);
    float* p3 = (float*)mem_alloc(5, sizeof(float));
    printf("%d\n", &p3);
    p3[0] = 2.0;
    p3[1] = 4.0;
    p3[2] = 6.0;
    p3[3] = 8.0;
    p3[4] = 10.0;
    for (i = 0; i < 5; i++) {
        printf("%.2f\n", p3[i]);
    }
    float *p4 = (float*)change_mem_alloc((void*)&p3, 10, sizeof(float));
    printf("%d\n", &p4);
    for (i = 0; i < 10; i++) {
        printf("%.2f\n", p4[i]);
    }
    free(p4);
}
