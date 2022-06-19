#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* UNIONS
*/

// Unions are essentially the same as structures in C, however instead of containing
// multiple variables, each with their own memory, unions allow for the assignment
// of multiple names to the same variable

// These names can treat the memory as different types, with the size of the union
// taking on the size of the largest type

// If we want to be able to read the memory of a variable in different ways (i.e
// reading an integer one byte at a time), we could construct the following

union intParts{
    int intval;
    char bytes[sizeof(int)];
};

// We can now look at each byte individually without casting a pointer and using
// pointer arithmetic

int main(){
    union intParts parts;
    parts.intval = 52093850; // this is an arbitrary number larger than one byte (integer 255)

    printf("The int %i consists of bytes\n[%i, %i, %i, %i]\n",
    parts.intval, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

    // Output:
    // The int 52093850 consists of bytes
    // [-102, -29, 26, 3]


    // Another method to go about this is the following

    int intval = parts.intval;

    printf("The int %i consists of bytes\n[%i, %i, %i, %i]\n",
    intval, *((char*)&intval+0), *((char*)&intval+1), *((char*)&intval+2), *((char*)&intval+3));

    // Output:
    // The int 52093850 consists of bytes
    // [-102, -29, 26, 3]


    // Yet another method to go about this is the following with array syntax

    printf("The int %i consists of bytes\n[%i, %i, %i, %i]\n",
    intval, ((char*)&intval)[0], ((char*)&intval)[1], ((char*)&intval)[2], ((char*)&intval)[3]);

    // Output:
    // The int 52093850 consists of bytes
    // [-102, -29, 26, 3]

    return 0;
}