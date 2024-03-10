/* 
 * File: 0300722fMath.c
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
