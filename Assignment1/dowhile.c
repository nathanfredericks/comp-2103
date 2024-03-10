/* 
 * File:    dowhile.c
 * Author:  Nathan Fredericks	0300722f@acadiau.ca
 * Date:    2024/01/25
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter an integer: ");
    int num;
    scanf("%d", &num);
    do {
        printf("Hello, world!\n");
        num -= 1;
    } while (num > 0);
    return EXIT_SUCCESS;
}
