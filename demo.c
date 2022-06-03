/* Hello World

*/

#include <stdio.h>

// Every C program uses libraries, allowing us to execute necessary functions
// For example, a basic function 'printf' prints text to the screen, and is defined 
// in the 'stdio.h' header file

// To be able to call printf, we must add the 'include <stdio.h>' directive

// The functional part of the code will go in the main method which returns an integer
// The number returned indicated whether the program ran successfully; if it is successful, we will return 0
// Returning any number other than zero (greater than zero) will indicate that the program has failed

int main(){
    printf("Hello, World!");
    return 0;
}