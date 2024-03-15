/* 
 * File: assignment5.c
 * Author: Nathan Fredericks 0300722f@acadiau.ca
 * Date: 2024/03/13
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// This function accepts a string, and references to store the number of characters, words, and punctuation.
// The function checks counts characters, words, and punctuation in a string.
// The function does not return anything.
void count_word_char_punct(char* s, int* numChar, int* numWord, int* numPunct) {
    int insideWord = 0;
    for (char *p = s; *p; p++) {
        // Increment character if character is not a newline
        if (p[0] != '\n') {
            (*numChar)++;
        }
        // Increment word
        // Check if character is not a space and not inside a word
        if (!isspace(p[0]) && !insideWord) {
            (*numWord)++;
            // Set variable to inside a word
            insideWord = 1;
        }
        // Check if character is a space or newline
        if (isspace(p[0]) || p[0] == '\n') {
            // Set variable to not inside a word
            insideWord = 0;
        }
        // Increment punctuation
        if (ispunct(p[0])) {
            (*numPunct)++;
        }
    }
}

// This function accepts a string.
// The function checks if the word is a palindrome and returns 0 (false) if the word is not a palindrome, and 1 (true) if the word is a palindrome.
int is_palindrome(char* word) {
    int word_len = strlen(word);
    int i;
    int is_palindrome = 1;
    // For each character in the word
    for (i = 0; i < word_len; i++) {
        // Check that the character is alphanumeric and that the first character is equal to the last character.
        // On each iteration, the loop will move closer to the center of the word.
        if (!isalpha(word[i]) || word[i] != word[word_len - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }
    return is_palindrome;
}

// This function accepts a string.
// The function checks if each word is a palindrome. If it is, word is printed to stdout.
// The function does not return anything.
void palindromic_words(char* s) {
    // Break string into words
    char* word = strtok(s, " ");
    // For each word
    while (word != NULL) {
        // Check if word is palindrome
        if (is_palindrome(word)) {
            printf("\"%s\" is a palindrome.\n", word);
        }
        word = strtok(NULL, " ");
    }
}

// This function accepts a file to read, offset, and a file to write to.
// The function encrypts each character in the file passed in the first parameter, and writes it to the file passed in the third parameter.
// The function does not return anything.
void encrypt(FILE* file, int offset, FILE* encryptedFile) {
    // Normaize offset
    offset = offset % 26;
    char s[10000];
    // For each line in file
    while (fgets(s, sizeof(s), file) != NULL) {
        // For each character in line
        for (char *p = s; *p; p++) {
            // Write encrypted character to encryptedFile 
            if (isupper(p[0])) {
                fputc((p[0] + offset - 'A' + 26) % 26 + 'A', encryptedFile);
            } else if (islower(p[0])) {
                fputc((p[0] + offset - 'a' + 26) % 26 + 'a', encryptedFile);
            } else {
                // Do not encrypt non-alphanumeric characters
                fputc(p[0], encryptedFile);
            }
        }
    }
}

// This function accepts an encrypted file and a offset.
// The function decrypts each character in the file passed in the first parameter, and writes it to stdout.
// The function does not return anything.
void decrypt(FILE* encryptedFile, int offset) {
    offset = offset % 26;
    char s[10000];
    // For each line in file
    while (fgets(s, sizeof(s), encryptedFile) != NULL) {
        // For each character in line
        for (char *p = s; *p; p++) {
            // Write encrypted character to encryptedFile 
            if (isupper(p[0])) {
                fputc((p[0] - offset - 'A' + 26) % 26 + 'A', stdout);
            } else if (islower(p[0])) {
                fputc((p[0] - offset - 'a' + 26) % 26 + 'a', stdout);
            } else {
                // Do not encrypt non-alphanumeric characters
                fputc(p[0], stdout);
            }
        }
    }
}

// This function accepts a string, and a query. 
// The function searches the string for all occurences of query andhighlights them with quotation marks.
// The string is printed to stdout.
// The function runs 0 (false) if the search returned no results and 1 (true) if the search returned a result.
int substr_search(char* s, char* query) {
    char* substr = NULL;
    int substr_found = 0;
    do {
        // If substring is found
        if ((substr = strstr(s, query)) != NULL) {
            // Substring position
            int position = substr - s;
            // Print first part of line, before substring
            printf("%.*s", position, s);
            // Query length
            int query_len = strlen(query);
            // Substring with quotation marks on either side
            printf("\"%.*s\"", query_len, s + position);
            // Set cursor to after substring
            s = s + position + query_len;
            substr_found = 1;
        }
    } while (substr != NULL);
    // If substring is found, print the rest of the string.
    if (substr_found) {
        printf("%s", s);
    }
    return substr_found;
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
    int offset;
    FILE* encryptedFile;

    while (1) {
        printf("Please make a selection:\n");
        printf("1. Word/Character/Punctuation Count\n");
        printf("2. Substring Search\n");
        printf("3. Palindromic Words\n");
        printf("4. Encrypt a File\n");
        printf("5. Decrypt a File\n");
        printf("6. Exit\n");
        char s[10000];
        int selection;
        char encryptedFileName[100];
        strcpy(encryptedFileName, argv[1]);
        strcat(encryptedFileName, ".caesar");

        scanf("%d", &selection);
        switch (selection) {
            case 1:
                rewind(file);
                int numChar = 0;
                int numWord = 0;
                int numPunct = 0;
                while (fgets(s, sizeof(s), file) != NULL) {
                    count_word_char_punct(s, &numChar, &numWord, &numPunct);
                }
                printf("There are %d characters, %d words, and %d punctuation.\n", numChar, numWord, numPunct);
                break;
            case 2:
                printf("Query: ");
                char query[100];
                getchar();
                fgets(query, sizeof(query), stdin);
                // Remove trailing newline
                query[strcspn(query, "\n")] = '\0';
                rewind(file);
                while (fgets(s, sizeof(s), file) != NULL) {
                    substr_search(s, query);
                }
                break;
            case 3:
                rewind(file);
                while (fgets(s, sizeof(s), file) != NULL) {
                    palindromic_words(s);
                }
                break;
            case 4:
                printf("Offset: ");
                scanf("%d", &offset);
                rewind(file);
                if ((encryptedFile = fopen(encryptedFileName, "w")) == NULL) {
                    fprintf(stderr, "Can't open file %s\n", encryptedFileName);
                    exit(EXIT_FAILURE);
                }
                rewind(encryptedFile);
                encrypt(file, offset, encryptedFile);
                printf("Encrypted file.\n");
                fclose(encryptedFile);
                encryptedFile = NULL;
                break;
            case 5:
                printf("Offset: ");
                scanf("%d", &offset);
                rewind(file);
                if ((encryptedFile = fopen(encryptedFileName, "r")) == NULL) {
                    fprintf(stderr, "Can't open file %s\n", encryptedFileName);
                    exit(EXIT_FAILURE);
                }
                rewind(encryptedFile);
                decrypt(encryptedFile, offset);
                fclose(encryptedFile);
                encryptedFile = NULL;
                break;
            case 6:
                fclose(file);
                return EXIT_SUCCESS;
            default:
                getchar();
                printf("Invalid selection.\n");
                break;
        }
    }
    
    fclose(file);
    file = NULL;
}
