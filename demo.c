#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* STATIC VARIABLES AND FUNCTIONS



// By default, variables in C are local to the scope in which they are defined
// Variables can be declared as static to increase their scope to the file containing them

// Let's consider the following functions where we want to increase the value of count

int counter(){
    int count = 0;
    count++;
    return count;
}

int main(){
    printf("First call of count: %d\n", counter());
    printf("Second call of count: %d\n", counter());
    return 0;
}

// Output:
// First call of count: 1
// Second call of count: 1

// We can see that count iis not updated because it is removed from memory as soon as
// the function completes



// Now let's try using static

int counter(){
    static int count = 0;
    count++;
    return count;
}

int main(){
    printf("First call of count: %d\n", counter());
    printf("Second call of count: %d\n", counter());
    return 0;
}

// Output:
// First call of count: 1
// Second call of count: 2

// We can see that with the static keyword, the value of variables persists in memory,
// at least within the scope of the file



// STATIC FUNCTIONS

// By default, functions are global in C
// If we precede the function with the keyword static, however, its scope is
// reduced to the file containing it

// For example

static void printExample(){
    printf("This static function cannot be called from another file\n");
}

int main(){
    printExample();
    return 0;
}

*/




// --------------------------------------------------------------------------------------------------------------




/* CONDITIONS AND CONDITIONAL STATEMENTS

int main(){

    // The if statement allows us to execute code based on the true or false value of
    // a condition

    // We can make use of comparison operators (< , > , ==) to evaluate a condition
    // For example

    int a = 1;
    int b = 2;

    if (a < b){
        printf("a is smaller than b (1)\n");
    }

    // We can also use the 'else' keyword to execute code in exception to a condition

    if (a > b){
        printf("a is larger than b");
    } else {
        printf("a is smaller than b (2)\n");
    }

    // We can else nest these conditional statements

    int x = 3;
    int y = 3;

    if (a < b){
        printf("a is smaller than b (3)");
        printf(" and ");
        if (x < y){
            printf("x is smaller than y\n");
        } else if (x > y){
            printf("x is greater than y\n");
        } else if (x == y){
            printf("x is equal to y\n");
        }
    }

    // We can also use logical operators OR (||) and AND (&&) to evaluate multiple statements

    // We use || and && rather than | and & in order to evaluate the veracity of both statements,
    // the latter operators will not bother evaluating the right-hand operand alone

    if(a < b && x == y){
        if(x != 3 || y != 4){
            printf("a is smaller than b (4) and x is equal to y");
        }
    }

    return 0;

}



// The following code prompts the user to guess a random number between 0 and 20

void guessRandom(){
    // To generate random numbers with time include <stdlib.h> and <time.h>
    srand(time(NULL));
    rand();
    int r = rand() % 100 + 1;
    int guess;

    printf("Guess an integer between 1 and 100:\n");
    
    while(guess != r){ // This while-loop iterates through the code until the conditon is met
        scanf("%d", &guess);
        if (guess > r){
            printf("Too high, guess again\n");
        } else if (guess < r){
            printf("Too low, guess again\n");
        }
    }
    printf("You guessed %i, correct!\n", r);
}


int main(){
    guessRandom();
    return 0;
}

*/




// --------------------------------------------------------------------------------------------------------------




/* MULTIDIMENSIONAL ARRAYS

int main(){

    // In the previous code, we looked at a one-dimensional array
    // In C, we can also create multidimensional arrays, for example

    int mtrx[1][2][3];

    // We can also create it and define it as so

    char a[1][5] = {
        {'a', 'e', 'i', 'o', 'u'}
    }


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
    }

    // However, the [y] value is still necessary, as the compiler cannot infer
    // the number of values per list


    // Let us practice initializing an array with four rows and five columns
    int x[4][5] = {
        {0, 1, 2, 3, 4}, // Initializers for row indexed by 0 
        {5, 6, 7, 8, 9}, // Initializers for row indexed by 1 
        {10, 11, 12, 13, 14}, // Initializers for row indexed by 2 
        {15, 16, 17, 18, 19} // Initializers for row indexed by 3 
    }

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
    }

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

// The following code populates the array using a for-loop to iterate through
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
    } // In C, semicolons are not required after the end of such brackets

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
