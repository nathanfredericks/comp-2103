/* 
 * File:    switch.c
 * Author:  Nathan Fredericks	0300722f@acadiau.ca
 * Date:    2024/01/25
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter a character: ");
    char c = getchar();
    while (getchar() != '\n');
    switch (c) {
        case 'a':
        case 'A':   printf("A");
                    break;
        case 'b':
        case 'B':   printf("B");
                    break;
        case 'c':
        case 'C':   printf("C");
        default:    printf("Unknown character.");
    }
    return EXIT_SUCCESS;
}
