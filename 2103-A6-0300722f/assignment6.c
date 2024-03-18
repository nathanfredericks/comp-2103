/* 
 * File: assignmen6.c
 * Author: Nathan Fredericks 0300722f@acadiau.ca
 * Date: 2024/03/18
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int id;
    float gpa;
} Student;

// This function accepts a pointer to an array of Student's and the size of the array.
// The function finds the student in the array (up to size) with the highest GPA.
// The function returns a pointer to the student with the highest GPA.
Student* highest_gpa(Student *students[], int size) {
    Student* highest = students[0];
    int i;
    for (i = 0; i < size; i++) {
        if (students[i]->gpa > highest->gpa) {
            highest = students[i];
        }
    }
    return highest;
}

// Bubble sort code from my assignment in Data Structures and Algorithms
// I used this code as a blueprint to implement my sort by GPA function.
// for i in range(len(numbers)):
//     for j in range(len(numbers) - i - 1):
//         if numbers[j] > numbers[j + 1]:
//             numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]
// return numbers

// This function accepts a pointer to an array of Student's and the size of the array.
// The function sorts all students in the array (up to size) by their GPA. The students GPAs are sorted highest to lowest.
// The function does not return anything.
void sort_by_gpa(Student* students[], int size) {
    int i;
    int j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (students[j]->gpa < students[j + 1]->gpa) {
                // Swap current and next
                Student* temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// This function accepts a pointer to an array of Student's and the size of the array.
// The function prints all students in the array (up to size) to stdout.
// The function does not return anything.
void print_students(Student* students[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        printf("%s\n", students[i]->name);
        printf("Student ID: ");
        printf("%d\n", students[i]->id);
        printf("Overall GPA: ");
        printf("%.2f\n", students[i]->gpa);
    }
}

int main(void) {
    int size = 5;
    Student* students[size];

    int i;
    for (i = 0; i < size; i++) {
        if ((students[i] = (Student*)malloc(sizeof(Student))) == NULL) {
            fprintf(stderr, "Error allocating memory.\n");
            return EXIT_FAILURE;
        }
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        fgets(students[i]->name, sizeof(students[i]->name), stdin);
        // Remove trailing newline
        students[i]->name[strcspn(students[i]->name, "\n")] = '\0'; 
        printf("Student ID: ");
        scanf("%d", &students[i]->id);
        getchar();
        printf("Overall GPA: ");
        scanf("%f", &students[i]->gpa);
        getchar();
    }

    // Print student data
    printf("\n");
    print_students(students, size);

    // Print student with highest GPA
    printf("\n");
    printf("Highest GPA:\n");
    Student* highest = highest_gpa(students, size);
    printf("Name: ");
    printf("%s\n", highest->name);
    printf("Student ID: ");
    printf("%d\n", highest->id);
    printf("Overall GPA: ");
    printf("%.2f\n", highest->gpa);

    // Sort students by GPA (highest to lowest)
    printf("\n");
    printf("Sorted by GPA:\n");
    sort_by_gpa(students, size);
    print_students(students, size);

    // Free memory allocated to store students
    for (i = 0; i < size; ++i) {
        free(students[i]);
    }

    return EXIT_SUCCESS;
}
