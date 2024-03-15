# Code Diary
## Task 1
- I'm going to start the assignment by reading a file from the disk. The file name will be passed in as a command-line argument. I will ensure that the file exists and can be opened. Once I have opened the text file, I am going to read the file as a string. I will traverse the string (array of `char`) counting each charater. During the travsersal, I'll use a conditional statement to search for space characters and punctuation. If I come across one, I'll increment a variable.
March 13, 2024 2:54:40 PM
- I ran into an issue while counting chars/words/punct. The variables are never incremented. Debugging...
- After debugging, the issue appears to be related to `fgetc`. `fgetc` is not reading the file.
- I found the bug! I was using `==` instead of `!==`
- I am having an issue counting the number of words. Using `fgetc`, I have no way to check if the next character is a letter. I am going to try reading the file to a string using `fgets`.
- For the purpose of this assignment, I'm going to set the string length to 100 characters.
- I realized that checking the previous, current, and next character was not enough to determine how many words are in the text file. I am going to try the following: Check if current character is not a space and that the current character is not inside a word. If true, increment the word count and set inside a word to true. Check if current character is a space, set inside a word to false.
- I tested my code and everything is working as expected.
March 13, 2024 3:50:00 PM
March 13, 2024 8:35:00 PM
- For readability and maintainabily, I am going to move the code from task 1 to a function.

## Task 2
- I'm going to start task 2 by using `fgets` to read each line in the file as a string. Then I'm going to use `strstr` to check if the line contains a substring of the string passed into the function. If a substring is found, I will use pointer math to find where the substing begins and ends. I'll print the line contents up until the substring, print quotations, print the substring, and print quotations. I'm going to reference this answer on Stack Overflow. https://stackoverflow.com/a/7500951
- Calling `fgets` twice in the program seems to be causing an error. I'm going to modify my code to only call `fgets` once at the beginning.
- My code is working again. I'm going to continue working on the task.
- I'm doing some research into pointer math to get the first part of the string before the substring.
- I have a working function but I'm frustrated because I forgot to check if there were multiple occurences in each line.
- Going to bed.
March 13, 2024 10:49:39 PM
March 14, 2024 9:04:51 AM
- After reading the assignment over, I realized that I am only supposed to search for one substring on each line.
- Task complete.

## Task 3
- I'm not sure how to approach this problem. I'm going to do some research on other implementations.
    - https://www.educative.io/answers/splitting-a-string-using-strtok-in-c
    - https://prepinsta.com/c-program/to-check-if-a-given-string-is-palindrome-or-not/
- After doing some research, I decided on a solution to this problem. I'm going to use `strtok` to split the string into tokens. Each token is a single word. For each word in the string, I'm going to iterate over each character checking if the first character is equal to the last character. On each iteration, I will move closer to the middle of the word. In each iteration, I will keep track if the word meets all conditions. If it does, the word is a palindrome.
- Before starting, I'm going to reformat the code moving everything from task 2 into a function.
- My palindrome function works, however, it does not exclude punctuation. I'm going to try checking if the current character is punctuation, and skipping the character if true.
- This approach did not work. Researching...
- I had no luck researching. I am going to come back to this later.
March 14, 2024 10:00 AM
March 14, 2024 12:07:22 PM
## Task 4
- I'm going to approach this problem by iterating over each character in the string. I'm going to check if the character is uppercase or lowercase. Then I'm going to set the character to the following:
```c
((current character + offset - 'A') % 26) + 'A'
```
To come up with this solution, I referenced https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/.
Take the current character, add the offset, and subtract 'A'. This subtraction maps the character to an integer. To wrap around the integer back to 0, use `mod 26` for the 26 letters in the alphabet. Lastly, convert the integer to a character by adding 'A'.
- My code works as expected. I read each line in the file to a string, then iterated over each character in the string. I made a new file `encryptedFile` which I wrote to using `fputc` on each iteration.
- I tested my code with a negative number and it does not work. I end up with some weird characters in my output file.
- I'm going to try adding 26 to the character before modulo. This will prevent the character from being a negative number. There are only 26 letters in the alphabet.
- My code works as expected.
- I noticed an issue with negative numbers. The bug is related to an offset that is less than or greater than 26. I'm going to normalize the offset at the beginning of task 1 and 2 so it is always between 0 and 26.

## Task 5
- My code for task 5 is going to be similar to my code for task 4 since I am doing the opposite. I'm going to subtract the offset from the current character.
- My code works as expected.

Now that I have completed the assignment, I am going to go back and make the code more modular and handle errors better. I am also going to add a user interface. I also have some adjustments to make to tasks 1, 2, and 3. Task 1 counts lone punctuation as a word, task 2 handle's new lines weirdly, and task 3 does not handle punctuation. I also need to add way more comments to my code.
March 14, 2024 12:49:26 PM
March 14, 2024 2:13 PM
March 14, 2024 7:00 PM
- I am going to test my code, add comments, build a UI and divide tasks into functions.
March 14, 2024 9:30 PM
March 15, 2024 11:30 AM
- I have finished testing my code and all functions work as expected.
## Known Bugs
* Inputting a non-numeric character during selection causes an infinite loop of quotation marks.
* I am not checking for invalid input when prompting the user.
* The program limits lines to 10,000 characters and does not handle overflows.
March 15, 2024 12:30 PM
