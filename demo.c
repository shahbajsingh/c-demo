#include <stdio.h>
#include <math.h>

/* Arrays

// Arrays can hold multiple values under the same variable name organized by index
// Arrays in C are zero-based, meaning they begin at index 0

int main(){
// The following code defines an array of 10 integers
int numbers[10];

// The following code populates the array
for(int i = 0; i < 7; i++){
    numbers[i] = i * 10;
}

// Accessing a value in the array is done with the same syntax
    printf("The 4th number in the array is %d", numbers[3]);
    return 0;
}

// Arrays can only have one type of variable because they are implemented in computer memory
// as a sequence of values

// This allows array access to be very efficient

*/

// The following code calls a method for printing the average of an array

void printAverage(int arr[], int size){
    int sum = 0;
    int average = 0;

    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

    average = sum / size;

    printf("The average of the array is %d", average);

}

int main(){
    int my_arr[10];
    for(int i = 0; i < 10; i++){
        my_arr[i] = pow(i, 2); // To use powers we have to include <math.h>
    }
    
    printAverage(my_arr, 10);
    return 0;
}




// --------------------------------------------------------------------------------------------------------------


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


// --------------------------------------------------------------------------------------------------------------


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