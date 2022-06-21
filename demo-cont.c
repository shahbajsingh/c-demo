#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* UNIONS

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
-- tack comment terminator asterisk when running code snippet below --


// Combining this with structs allow us to create 'tagged' unions which can store
// multiple different types

// For example, we may have a 'number' struct, but we would want to avoid the following 
// sort of implementation:
//
// struct operator{
// int intNum;
// float floatNum;
// int intType;
// double doubleNum;   
// }
//
// This is because our program is storing many numbers, thus this would take a lot of memory
// considering all the variables

// We could instead implement it as so

struct operator{
    int type;
    union{
        int intNum;
        float floatNum;
        double doubleNum;
    } types; // if we don't name the union then its members can be accessed directly
};          // from the struct variables (i.e. o.intNum = 222)

// The size of this struct is just the size of the type 'int' plus the size
// of the largest type in the union (in this case, the double)

int main(){
    struct operator o;
    o.type = 0; // used to signify int
    o.types.intNum = 222;

    printf("The integer number is %d\n", o.types.intNum);
    
    // Output:
    // The integer number is 222

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --

*/
// Another useful feature of unions is when we always have multiple variables of the same
// type, and we want to be able to use both names and indices

union Coins{
    struct{
        int quarter;
        int dime;
        int nickel;
        int penny;
    }; // anonymous structs act the same way as an anonymous union
    int coins[4]; // members are on the outer container
};

int main(){
    // since the union makes the variables share contiguous memory,
    // the coins array matches with each int in the struct in order

    union Coins change;

    printf("Enter values for quarters, dimes, nickels, and pennies\n");
    printf("Then, enter any value to escape\n");

    for(int i=0; i<sizeof(change) / sizeof(int); i++){
        scanf("%i\n", change.coins + i);
    }

    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
    change.quarter, change.dime, change.nickel, change.penny);

    float sum = 0;
    sum += (0.25 * change.coins[0]);
    sum += (0.1 * change.coins[1]);
    sum += (0.05 * change.coins[2]);
    sum += (0.01 * change.coins[3]);
    printf("%f", sum);
    printf("This amounts to %.2f dollars\n", sum);
    
}