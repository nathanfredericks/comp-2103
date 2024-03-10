/* 
 * File: assignment3.c
 * Author: Nathan Fredericks 0300722f@acadiau.ca
 * Date: 2024/02/19
 */
#include <stdio.h>
#include "0300722fMath.h"

int main(void) {
    while (1) {
        printf("x: ");
        int x = getNumber();
        printf("y: ");
        int y = getNumber();
        printf("Operator (^, b, r): ");
        int op = getOperator();
        switch (op) {
            case '^':
                printf("%d^%d = %d.\n", x, y, power(x, y));
                break;
            case 'b':
                printf("floor(%d / %d) = %d.\n", x, y,  bottom(x, y));
                break;
            case 'r':
                printf("round(%d / %d) = %d.\n", x, y,  rounded(x, y));
                break;
            default:
                printf("Invalid operation.");
                break;
        }  
    }
}
