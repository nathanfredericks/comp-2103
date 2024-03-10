/* 
 * File: assignment3.c
 * Author: Nathan Fredericks 0300722f@acadiau.ca
 * Date: 2024/02/19
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Reads a number from stdin and returns it
int getNumber(void) {
    int num;
    scanf("%d", &num);
    getchar();
    return num;
}

// Reads a character from stdin and returns it
char getOperator(void) {
    char op;
    scanf("%c", &op);
    getchar();
    return (int)op;
}

// Returns the power of x raised to y
int power(int x, int y) {
    return pow(x, y);
}

// Returns the floor of x / y
int bottom(int x, int y) {
    float quotient = x / (float)y;
    return floor(quotient);
}

// Returns the rounded integer from x / y
int rounded(int x, int y) {
    float quotient = x / (float)y;
    return roundf(quotient);
}

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
