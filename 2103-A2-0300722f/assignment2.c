/* 
 * File:    assignment2.c 
 * Author:  Nathan Fredericks  0300722f@acadiau.ca 
 * Date:    2024/02/08
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(void) {
    if(isatty(fileno(stdin))) {
        return EXIT_FAILURE;
    } else {
#ifdef REVERSED
        FILE *temp;
        if ((temp = tmpfile()) == NULL) {
            return EXIT_FAILURE;
        }
#endif
    	int c;
    	while((c = getc(stdin)) != EOF) {
#ifdef SWITCHED
        	if (isupper(c)) {
            	c = tolower(c);
        	} else {
            	c = toupper(c);
        	}
#endif
#ifdef REVERSED
            fputc(c, temp);
#else
            putc(c, stdout);
#endif
    	}
#ifdef REVERSED
         fseek(temp, 0, SEEK_END);
         int i = 0;
         int pos = ftell(temp);
         while (i < pos) {
             i++;
             fseek(temp, -i, SEEK_END);
             c = fgetc(temp);
             putc(c, stdout);
         }
#endif
		return EXIT_SUCCESS;
	}
}
