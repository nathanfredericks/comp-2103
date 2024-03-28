/* 
 * File: assignment8.c
 * Author: Nathan Fredericks 0300722f@acadiau.ca
 * Date: 2024/03/28
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef union {
    int i;
    float r;
    char s[100];
} IntOrRealOrStringT;

typedef enum {
    integer, real, string
} TagTypeT;

typedef struct {
    TagTypeT tag;
    IntOrRealOrStringT value;
} TaggedValueT;

void print_values(TaggedValueT* tagged_values[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        TaggedValueT* tvt = tagged_values[i];
        switch(tvt->tag) {
            case integer:
                printf("%d: %d\n", i, tvt->value.i);
                break;
            case real:
                printf("%d: %.2f\n", i, tvt->value.r);
                break;
            case string:
                printf("%d: %s\n", i, tvt->value.s);
                break;
        }
    }
}

void manually_input_values(TaggedValueT* tagged_values[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if ((tagged_values[i] = (TaggedValueT*)malloc(sizeof(TaggedValueT))) == NULL) {
            fprintf(stderr, "Error allocating memory.\n");
            exit(EXIT_FAILURE);
        }
        TaggedValueT* tvt = tagged_values[i];
        int type;
        printf("Select a data type:\n");
        printf("1. Integer\n");
        printf("2. Float\n");
        printf("3. String\n");
        scanf("%d", &type);
        IntOrRealOrStringT value;
        switch (type) {
            case 1: // Integer
                tvt->tag = integer;
                printf("Enter an integer: ");
                scanf("%d", &value.i);
                getchar();
                break;
            case 2: // Float
                tvt->tag = real;
                printf("Enter a float: ");
                scanf("%f", &value.r);
                getchar();
                break;
            case 3: // String
                tvt->tag = string;
                getchar();
                printf("Enter a string: ");
                fgets(value.s, sizeof(value.s), stdin);
                value.s[strcspn(value.s, "\n")] = '\0'; // Remove trailing newline
                break;
            default:
                printf("Invalid selection.\n");
                exit(EXIT_FAILURE);
        }
        tvt->value = value;
    }
}

// Size must be 10
void hardcode_values(TaggedValueT* tagged_values[]) {
    int i;
    for (i = 0; i < 10; i++) {
        tagged_values[i] = (TaggedValueT*)malloc(sizeof(TaggedValueT));
        if (tagged_values[i] == NULL) {
            fprintf(stderr, "Error allocating memory.\n");
            exit(EXIT_FAILURE);
        }
    }
    tagged_values[0]->tag = integer;
    tagged_values[0]->value.i = 0;
    tagged_values[1]->tag = integer;
    tagged_values[1]->value.i = 1;
    tagged_values[2]->tag = integer;
    tagged_values[2]->value.i = 2;
    tagged_values[3]->tag = integer;
    tagged_values[3]->value.i = 3;
    tagged_values[4]->tag = real;
    tagged_values[4]->value.r = 4.0;
    tagged_values[5]->tag = real;
    tagged_values[5]->value.r = 5.0;
    tagged_values[6]->tag = real;
    tagged_values[6]->value.r = 6.0;
    tagged_values[7]->tag = string;
    strcpy(tagged_values[7]->value.s, "seven");
    tagged_values[8]->tag = string;
    strcpy(tagged_values[8]->value.s, "eight");
    tagged_values[9]->tag = string;
    strcpy(tagged_values[9]->value.s, "nine");
}

int main(void) {
    int selection;
    printf("Please make a selection:\n");
    printf("1. Input Tag/Value Pairs Manually\n");
    printf("2. Use Default Tag/Value Pairs\n");
    scanf("%d", &selection);
    int size;
    switch (selection) {
        case 1:
            printf("Values: ");
            scanf("%d", &size);
            break;
        case 2:
            size = 10;
            break;
        default:
            printf("Invalid selection.\n");
            return EXIT_FAILURE;
    }

    TaggedValueT* tagged_values[size];

    switch (selection) {
        case 1:
            manually_input_values(tagged_values, size);
            break;
        case 2:
            hardcode_values(tagged_values);
            break;
    }

    print_values(tagged_values, size);

    int i;
    for (i = 0; i < size; i++) {
        free(tagged_values[i]);
    }

    return EXIT_SUCCESS;
}
