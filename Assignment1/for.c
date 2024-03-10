/* 
 * File:   	for.c
 * Author:  Nathan Fredericks	0300722f@acadiau.ca
 * Date:    2024/01/25
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter an integer: ");
    int num;
    scanf("%d", &num);
    int i;
    for (i = 0; i < num; i++) {
        printf("Hello, world!\n");
    }
    return EXIT_SUCCESS;
}
