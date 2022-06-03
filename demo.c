#include <stdio.h>
#include <math.h>

/* MULTIDIMENSIONAL ARRAYS

int main(){

    // In the previous code, we looked at a one-dimensional array
    // In C, we can also create multidimensional arrays, for example

    int mtrx[1][2][3];

    // We can also create it and define it as so

    char a[1][5] = {
        {'a', 'e', 'i', 'o', 'u'}
    };


    // TWO-DIMENSIONAL ARRAYS

    // The simplest form of multidimensional array is the two-dimensional array
    // A two-dimensional array is functionally a list of one-dimensional arrays

    // Declaring a two-dimensional array takes the following form:
    // type arrayName [x][y];

    // type can be any C data type (int, char, long, long long, double, etc.)
    // arrayName is an identifier
    // Number of rows is given by [x]
    // Number of columns is given by [y]

    // Thus each element in the matrix is identified by the form:
    // a[i][j]
    // Where 'a' is the name of the array, 'i' specifies the row, and 'j' specifies the column

    // In certain cases, the compiler can infer the value of [x] when provided a definition
    // For example

    char b[][5] = {
        {'A', 'E', 'I', 'O', 'U'},
        {'a', 'e', 'i', 'o', 'u'}
    };

    // However, the [y] value is still necessary, as the compiler cannot infer
    // the number of values per list


    // Let us practice initializing an array with four rows and five columns
    int x[4][5] = {
        {0, 1, 2, 3, 4}, // Initializers for row indexed by 0 
        {5, 6, 7, 8, 9}, // Initializers for row indexed by 1 
        {10, 11, 12, 13, 14}, // Initializers for row indexed by 2 
        {15, 16, 17, 18, 19} // Initializers for row indexed by 3 
    };

    // The inside braces indicate the desired row and are optional
    // The following initialization is functionally the same

    int y[4][5] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    // To access an element, we simply use the row and column indices

    int val = y[3][4];

    printf("The fifth element of the fourth row is %d", val);


    return 0;
}



// The following code finds the average grades for a group of four students for two courses– 
// Calculus and Physics

// To do this we will use a two-dimensional array called grades
// The grades corresponding to Calculus will be stored in the first row (grades[0])
// The grades corresponding to Physics will be stored in the second row (grades[1])

int main(){
    short average;

    int grades[2][4] = {
        {95, 90, 85, 70},
        {85, 75, 90, 95}
    };

    for(int i = 0; i < 2; i++){
        average = 0;

        for(int j = 0; j < 5; j++){
            average += grades[i][j];
        }

        average /= 5.0;
        printf("The average grade obtained in subject %d is: %.2hu\n", i, average);

    }


    return 0;
}

*/




// --------------------------------------------------------------------------------------------------------------




/* ONE-DIMENSIONAL ARRAYS

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

*/




// --------------------------------------------------------------------------------------------------------------




/* VARIABLES & TYPES

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




/* HELLO WORLD

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




// --------------------------------------------------------------------------------------------------------------
