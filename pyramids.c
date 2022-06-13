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
-- tack comment terminator asterisk when running code snippet below --


// INVERTED HALF PYRAMID OF STARS

int main(){

    int i, j, rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = rows; i >= 1; i--){
        for (j = 1; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }

    // Output:
    // Enter number of rows: 5
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// INVERTED HALF PYRAMID OF NUMBERS

int main(){

    int i, j, rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = rows; i >= 1; i--){
        for (j = 1; j <= i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }

    // Output:
    // Enter number of rows: 5
    // 1 2 3 4 5
    // 1 2 3 4 
    // 1 2 3 
    // 1 2 
    // 1 

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// FULL PYRAMID OF STARS

int main(){

    int i, space, rows, k = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++, k = 0){
        for (space = 1; space <= rows - i; space++){
            printf("  ");
        }
        while (k != 2 * i - 1){
            printf("* ");
            ++k;
        }
        printf("\n");
    }

    // Output:
    //          * 
    //        * * * 
    //      * * * * * 
    //    * * * * * * * 
    //  * * * * * * * * * 

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --

*/
// PASCAL'S TRIANGLE

int main() {

    int rows, coef =1, space, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    for (i = 0; i < rows; i++){
        for (space = 1; space <= rows - i; space++)
            printf("  ");
        for (j = 0; j <= i; j++){
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;
            printf("%4d", coef);
        }
        printf("\n");
    }

    // Output:
    // Enter number of rows: 8
    //               1
    //             1   1
    //           1   2   1
    //         1   3   3   1
    //       1   4   6   4   1
    //     1   5  10  10   5   1
    //   1   6  15  20  15   6   1
    // 1   7  21  35  35  21   7   1

    return 0;
}
