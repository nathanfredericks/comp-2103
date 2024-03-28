// Nathan Fredericks 400300722
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
} Person;

void sortArray(Person* p[], int size) {
    int i;
    int j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (p[j]->age > p[j + 1]->age) {
                // Swap current and next
                Person* temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void mergeArrays(Person* p[], int size, Person* p2[], int size2) {
    int size3 = (size + size2);
    Person* p3[size3];

    // Allocate memory
    for (int h = 0; h < size3; h++) {
        p3[h] = malloc(sizeof(Person));
    }

    int k = 0;
    // Copy to one array (p3)
    for (int i = 0; i < size; i++) {
        strcpy(p3[k]->name, p[i]->name);
        p3[k]->age = p[i]->age;
        free(p[i]);
        k++;
    }

    for (int j = 0; j < size2; j++) {
        strcpy(p3[k]->name, p2[j]->name);
        p3[k]->age = p2[j]->age;
        free(p2[j]);
        k++;
    }

    sortArray(p3, size3);

    for (int l = 0; l < size3; l++) {
        printf("Name: %s, Age: %d\n", p3[l]->name, p3[l]->age);
        free(p3[l]);
    }
}

int main(void) {
    Person* p[3];
    p[0] = malloc(sizeof(Person));
    p[1] = malloc(sizeof(Person));
    p[2] = malloc(sizeof(Person));
    strcpy(p[0]->name, "Ron");
    p[2]->age = 14;
    strcpy(p[1]->name, "Bob");
    p[0]->age = 12;
    strcpy(p[2]->name, "Lisa");
    p[1]->age = 13;


    Person* p2[4];
    p2[0] = malloc(sizeof(Person));
    p2[1] = malloc(sizeof(Person));
    p2[2] = malloc(sizeof(Person));
    p2[3] = malloc(sizeof(Person));
    strcpy(p2[0]->name, "James");
    p2[0]->age = 43;
    strcpy(p2[1]->name, "Danny");
    p2[1]->age = 32;
    strcpy(p2[2]->name, "Jim");
    p2[2]->age = 73;
    strcpy(p2[3]->name, "Mac");
    p2[3]->age = 21;
    mergeArrays(p, 3, p2, 4);
    return EXIT_SUCCESS;
}
