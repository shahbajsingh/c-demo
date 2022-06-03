#include <stdio.h>

/* Variables and Types

// C has several types of variales, but there are a few basic types:

// Signed Integers- defined using char, int, short long, or long long

// Unsigned Integers - defined using unsigned char, unsigned int, unsigned short,
// unsigned long, or unsigned long long

// Floating Point - defined using float and doubles

// Structures - defined using struct

// Note that C does not have a boolean type, it is usually defined using

#define BOOL char
#define FALSE 0
#define TRUE 1

// C strings consist of character arrays

// Variables are defined first by type then name and if necessary value

int main(){
    int a = 2;
    float b = 3.22;
    double c = 12.9;
    float product;

    product = a * b * c;
    printf("The product of a, b, and c is %f.\n", product);

    // We can also use arithmetic operators

    product = (product - a) * 2;
    printf("Twice the product of b and c is %f.\n", product);


    return 0;
}

*/




/* Hello World

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

*/