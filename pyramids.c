#include<stdio.h>

/* PYRAMIDS 

// HALF PYRAMID OF STARS

int main(){

    int i, j, rows;
    
    printf("Enter numbers of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++){
        for (j = 1; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }

    // Output:
    // Enter number of rows: 5
    // *
    // * *
    // * * *
    // * * * *
    // * * * * *

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// HALF PYRAMID OF INTEGERS

int main(){
    
    int i, j, rows;
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++){
        for (j = 1; j <= i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }

    // Output:
    // Enter number of rows: 5
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4 
    // 1 2 3 4 5

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --

*/
// HALF PYRAMID OF LETTERS

int main(){

    int i, j;
    char input, row = 'a';

    printf("Enter a lowercase letter you would like to pyramidize up to: ");
    scanf("%c", &input);

    for (i = 1; i <= (input - 'a' + 1); i++){
        for (j = 1; j <= i; j++){
            printf("%c ", row);
        }
        row++;
        printf("\n");
    }

    // Output:
    // enter a lowercase letter you would like to pyramidize up to: f
    // a
    // b b 
    // c c c
    // d d d d
    // e e e e e
    // f f f f f f

    return 0;
}