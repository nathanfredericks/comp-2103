/* 
 * File:    ifelse.c
 * Author:  Nathan Fredericks	0300722f@acadiau.ca
 * Date:    2024/01/25
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter an integer: ");
    int num;
    scanf("%d", &num);
    if (num > 5) {
        printf("Integer is greater than 5.");
    } else {
        printf("Integer is less than or equal to 5.");
    }
    return EXIT_SUCCESS;
}
