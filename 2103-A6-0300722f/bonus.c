/* 
 * File: bonus.c
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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* file;
    if ((file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    Student* students[100];
    char s[10000];
    int i = 0;
    while (fgets(s, sizeof(s), file) != NULL) {
        if (i >= 100) {
            fprintf(stderr, "Too many rows in CSV file.\n");
            return EXIT_FAILURE;
        }
        if ((students[i] = (Student*)malloc(sizeof(Student))) == NULL) {
            fprintf(stderr, "Error allocating memory.\n");
            return EXIT_FAILURE;
        }
        char* column = strtok(s, ",");
        int current_col = 0;
        // For each column in row
        while (column != NULL) {
            switch (current_col) {
                // Given name and family name
                case 0:
                    strcpy(students[i]->name, column);
                    break;
                // Student ID
                case 1:
                    sscanf(column, "%d", &(students[i]->id));
                    break;
                // Overall GPA
                case 2:
                    sscanf(column, "%f", &(students[i]->gpa));
                    break;
                default:
                    printf("Invalid CSV file.\n");
                    return EXIT_FAILURE;
            }
            current_col++;
            column = strtok(NULL, ",");
        }
        i++;
    }

    fclose(file);

    while (1) {
        printf("Please make a selection:\n");
        printf("1. Print Students\n");
        printf("2. Find Student With Highest GPA\n");
        printf("3. Sort Students By GPA\n");
        printf("4. Exit\n");
        int selection;
        scanf("%d", &selection);
        switch (selection) {
            case 1:
                print_students(students, i);
                break;
            case 2:
                printf("Highest GPA:\n");
                Student* highest = highest_gpa(students, i);
                printf("Name: ");
                printf("%s\n", highest->name);
                printf("Student ID: ");
                printf("%d\n", highest->id);
                printf("Overall GPA: ");
                printf("%.2f\n", highest->gpa);
                break;
            case 3:
                printf("Sorted by GPA:\n");
                sort_by_gpa(students, i);
                print_students(students, i);
                break;
            case 4:
                // Free memory allocated to store students
                for (int j = 0; j < i; j++) {
                    free(students[j]);
                }
                return EXIT_SUCCESS;
            default:
                getchar();
                printf("Invalid selection.\n");
                break;
        }
    }
}
