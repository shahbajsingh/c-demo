#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* BINARY TREES
 */

// Binary trees are a type of data structure similar to linked lists in that each value
// points to another sequentially, but trees are conceptualized differently

//     g                  s                  9
//    / \                / \                / \
//   b   m              f   u              5   13
//  / \                    / \                /  \
// c   d                  t   y              11  15

// Each node in a binary tree is connected to a left child and a right child
// (those that are missing one or both point to null)

// Binary trees can be implemented in a variety of ways, namely for binary search trees and
// binary heaps, used for efficient searching and sorting algorithms

// A binary tree is technically a special case of a 'K-ary' tree where K is 2

// Operations we may expect to implement with a binary tree include insertion, deletion,
// and traversal within the tree

// The balance of a tree (whether there are more child nodes right or left of center)
// decides how difficult it is to access and manipulate these members

// If a tree is balanced, meaning the difference in the amount of left and right nodes is
// one or less, predicting the depth (or height) of a tree is much easier

struct node{                    // This code is but a longer version of the following:
    int val;                    // typedef struct node{
    struct node *left;          //      
    struct node *right;         //      int val;
};                              //      struct node *left, *right;
                                //
typedef struct node node_t;     //  } node_t;


void insert(node_t *tree, int val);
void print_tree(node_t *current);
void printDFS(node_t *current);

int main()
{
    node_t *test_list = (node_t *)malloc(sizeof(node_t));

    // set values explicitly, alternative would be calloc()
    test_list->val = 0;
    test_list->left = NULL;
    test_list->right = NULL;

    insert(test_list, 10);
    insert(test_list, 5);
    insert(test_list, 8);
    insert(test_list, 7);
    insert(test_list, 2);

    printf("Depth-first search:\n");
    printDFS(test_list);
    printf("\n\n");

    printf("Breadth-first search:\n");
//    printBFS(test_list);
    printf("\n");

    // Output:
    // Depth-first search:
    // 10 5 2 8 7
    //
    // Breadth-first search:
    //

    return 0;
}

void insert(node_t *tree, int val){
    if (tree->val == 0){
        
        // insert node on current empty position
        tree->val = val;

    } else {
        
        if (val < tree->val) {
        
            // insert node left 
            if (tree->left != NULL){
                insert(tree->left, val);
        
            } else {
        
                tree->left = (node_t *)malloc(sizeof(node_t));

                // set values explicitly, alternative would be calloc()
                tree->left->val = val;
                tree->left->left = NULL;
                tree->left->right = NULL;
        
            }
        
        } else {
        
            if (val >= tree->val) {
                // insert node right
                if (tree->right != NULL) {
        
                    insert(tree->right, val);
        
                } else {
        
                    tree->right = (node_t *)malloc(sizeof(node_t));

                    // set values explicitly, alternative would be calloc() 
                    tree->right->val = val;
                    tree->right->left = NULL;
                    tree->right->right = NULL;
        
                }
            }
        }
    }
}

// DEPTH-FIRST SEARCH
// DFS is an algorithm that traverses a tree or graph starting at the root and exploring
// as far as possible down a branch before backtracking (hence depth-first)

void printDFS(node_t *current)
{
    // note the use of recursion
    if (current == NULL)
        return; // security measure
    if (current != NULL)
        printf("%d ", current->val);
    if (current->left != NULL)
        printDFS(current->left);
    if (current->right != NULL)
        printDFS(current->right);
}

// BREADTH-FIRST SEARCH
// (also known as level order traversal)
// BFS is an algorithm that traverses a tree or graph starting at the root and and visiting
// nodes on the same level (of depth n) before descending branches

// To perform a breadth-first search we will be implementing a queue (FIFO) data structure

typedef struct queueitem {
    int val;
    struct node *next;
} queueitem_t;

void enqueue(queueitem_t **head, int val) {
    queueitem_t *new_node = malloc(sizeof(queueitem_t));
    if (!new_node) return;

    new_node->val = val;
    new_node->next = *head;

   *head = new_node;
}

int dequeue(queueitem_t **head) {
    queueitem_t *current, *prev = NULL;
    int retval = -1;

    if (*head == NULL) return -1;

    current = *head;
    while (current->next != NULL) {
    prev = current;
    current = current->next;
    }

    retval = current->val;
    free(current);

    if (prev)
        prev->next = NULL;
    else
        *head = NULL;

    return retval;
}

void printBFS(node_t *current){



}

// --------------------------------------------------------------------------------------------------------------

/* LINKED LISTS

// Linked lists function as an array that can grow and shrink as needed,
// from any point in the array

// They also have a few advantages over conventional arrays:
//
// 1. Items can be added or removed from any point in the middle of the list
//
// 2. There is no need to define an initial size

// However they also have a few disadvantages:
//
// 1. There is no 'random' access– it is impossible to reach the nth item in
// the array without first iterating through each item preceding it, thus we
// have to start from the beginning of the list and count each iteration until
// we arrive at our item
//
// 2. Dynamic memory allocation and pointers are needed, which complicated our code
// and increases the risk of memory leaks and segment faults
//
// 3. Linked lists have a much greater overhead than arrays– since linked list
// items are dynamically allocated (also less efficient in memory usage) and each
// item in the list must also store an additional pointer, pointing to the next item


// A linked list is functionally a set of dynamically allocated nodes, arranged in a way
// such that each node contains one value and one pointer

// The pointer always points to the next member of the list

// If the pointer is NULL, then it is the last node in the list

// A linked list is held using a local pointer variable which points
// to the first item, or head node, of the list

// If this local pointer variable is also NULL, then the list is considered empty


// The following is a visual diagram of how we may conceptualize linked lists:



//    ------------------------------              ------------------------------
//    |              |             |            \ |              |             |
//    |     DATA     |     NEXT    |--------------|     DATA     |     NEXT    |
//    |              |             |            / |              |             |
//    ------------------------------              ------------------------------



// Let's define a list node, and define our node type 'node_t'

typedef struct node{
    int val;
    struct node * next;
} node_t;

// Notice that C allows us to define the struct in a recursive manner

int main(){

    // Now we can use the nodes

    // Let's create a local variable which points to the first item of the list
    // (the head node)

    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    if (head == NULL){
        return 1;
    }

    head->val = 2;
    head->next = NULL;

    // We've now created the first variable in our list, setting the value
    // of the node and setting the next ittem to be empty

    // Notice that we should always check if malloc returns a NULL value or not


    // To add a variable to the end of the list, we can just continue to advance
    // to the next pointer

    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 3;
    head->next->next = NULL;

    // This can go on ad infinitum, but we should rather advance to the last
    // item of the list, until the 'next' variable is NULL

    printf("The value of head is %d\n", head->val);
    printf("The value of the node after head is %d\n", head->next->val);

    // Output:
    // The value of head is 2
    // The value of the node after head is 3

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// ITERATING OVER A LINKED LIST

// Let's build a function that prints out all the items of a list

typedef struct node{
    int val;
    struct node * next;
} node_t;

void print_list(node_t *head){
    // In order to do this, we need to use a 'current' pointer with which
    // to keep track of the node we are currently pointing to

    node_t *current = head;

    // After printing the value of the node, we will set the current pointer
    // to the next node, print again, and repeat until the end of the list
    // is reached

    printf("LINKED LIST: \n");

        while (current != NULL){
        printf("[ %d ]->", current->val);
        current = current->next;
    }

    printf("[/]\n");
}

// PUSHING A NODE TO THE TAIL END OF A LINKED LIST

// In order to iterate over all members of a linked list, we use the 'current' pointer
// We begin from the head and in each step advance the pointer until the end

void push_to_tail(node_t *head, int val){
    node_t *current = head;

    while (current->next != NULL){
        current = current->next;
    }

    // Now we can add a new node
    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

// PUSHING A NODE TO THE HEAD END OF A LINKED LIST

// To add to the beginning of a list, we have to create a new node and set its value,
// link it to the current head of the list, and set the head to point to the new node

// We want to modify the head variable, so we will have to pass a pointer to the
// pointer variable (a double pointer) so we will be able to modify the pointer itself

void push_to_head(node_t **head, int val){
    node_t *new_node;

    new_node = (node_t *)malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

// REMOVING THE FIRST ITEM OF A LINKED LIST

// To pop a variable, we will have the reverse the above function, effectively
// taking the item to which the current head points, freeing the head item,
// and setting the head to point to the following node

int remove_head(node_t ** head){
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL){
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

// REMOVING THE LAST ITEM OF A LINKED LIST

// Removing the tail item from a linked list is similar to adding it to the
// end, however since we have to change the item preceding the last one to
// point to null, we actually have to look two nodes ahead when iterating in
// order to find the tail

int remove_tail(node_t *head){
    int retval = 0;

    // If there is only one item in the last, remove it
    if (head->next == NULL){
        retval = head->val;
        free(head);
        return retval;
    }

    // Iterate until the second to last node
    node_t *current = head;

    while (current->next->next != NULL){
        current = current->next;
    }

    // Now current points to the second to last node
    retval = current->next->val;

    free(current->next);
    current->next = NULL;

    return retval;
}

// REMOVING SPECIFIC ITEMS IN A LINKED LIST

// Te remove specific items, either by index or value, we will have to iterate
// through the linked list and continuously look ahead to find the node to remove

// We will have to iterate to the node we want to delete, save it in a temporary pointer,
// set the preceding node's 'next' pointer to point to the node after that deleted, and finally
// delete the node at hand

// We also have to take care of a few edge cases


int remove_by_index(node_t **head, int n){
    int i;
    int retval = -1;

    node_t *current = *head;
    node_t *temp_node = NULL;

    if (n == 0){
        return remove_head(head);
    }

    for (i = 0; i < (n - 1); i++){
        if (current->next == NULL){
            return -1;
        }
        current = current->next;
    }

    if (current->next == NULL){
        return -1;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

int remove_by_value(node_t **head, int val){
    node_t *previous, *current;

    if (*head == NULL){
        return -1;
    }

    if ((*head)->val == val){
        return remove_head(head);
    }

    previous = *head;
    current = (*head)->next;
    while (current){
        if (current->val == val){
            previous->next = current->next;
            free(current);
            return val;
        }

        previous = current;
        current = current->next;
    }
    return -1;
}

void delete_list(node_t *head){
    node_t *current = head,
           *next = head;

    while (current){
        next = current->next;
        free(current);
        current = next;
    }
}

int main(void){
    node_t *test_list = (node_t *)malloc(sizeof(node_t));

    test_list->val = 1;
    test_list->next = (node_t *)malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *)malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *)malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
    delete_list(test_list);

    // Output:
    // [ 1 ]->[ 2 ]->[ 4 ]->[/]

    return 0;
}

*/

// --------------------------------------------------------------------------------------------------------------

/* RECURSION

// Recursion allows a function to call itself, within itself, resulting in
// more simplified, elegant code

// It can also result in unexpectedly large memory usage if not handled well

// Common examples of recursion use cases include:
//
// Walking recursive data structures– binary trees, linked lists, etc.
//
// Exploring possible scenarios in games like chess

// Recursion consists of two main parts–
//
// A terminating base case that indicates when recursion will finish
//
// A function call to itself that must make progress towards the base case

// An example of recursion is the following code, which performes multiplication
// using recursive addition

int multiply(int x, int y){

    // if x < y, swap numbers

    if (x < y)
        return multiply(y, x);

    // calculate y times sum of x through recursive iteration

    else if (y != 0)
        return (x + multiply(x, y - 1));

    // if either number is zero, return zero (base case)

    else
        return 0;

}

int main(){

    int x = 10;
    int y = 4;

    printf("%d\n", multiply(x, y));

    // Output:
    // 40

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// The following function factorial() will compute the factorial of an integer
// by recursive multiplication

int factorial(int number);

int main(){
    // test code

    printf("0! = %i\n", factorial(0));
    printf("1! = %i\n", factorial(1));
    printf("3! = %i\n", factorial(3));
    printf("5! = %i\n", factorial(5));

    // Output:
    // 0! = 1
    // 1! = 1
    // 3! = 6
    // 5! = 120


    return 0;
}

int factorial(int num){
    if (num > 1){
        return num * factorial(num - 1);
    } else {
        return 1;
    }
}

*/

// --------------------------------------------------------------------------------------------------------------

/* ARRAYS AND POINTERS

// We've learned that a pointer to a given data type can store the address
// of any variable of that specific data type

int main(){
    // For example, the following pointer variable 'pc' stores the
    // address of the char variable c, where 'c' is a scalar variable
    // that can only store a single character value

    char c = 'X';
    char *pc = &c;


    // Let us now explore pointers to arrays

    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char *pvowels = vowels;
    int i;

    // print addresses

    for(i = 0; i < 5; i++){
        printf("&vowels[%d]: %p, pvowels + %d: %p, vowels + %d: %p\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
    }

    // print values

    for(i = 0; i < 5; i++){
        printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }

    // Output:
    // &vowels[0]: 0x7ff7be5436bb, pvowels + 0: 0x7ff7be5436bb, vowels + 0: 0x7ff7be5436bb
    // &vowels[1]: 0x7ff7be5436bc, pvowels + 1: 0x7ff7be5436bc, vowels + 1: 0x7ff7be5436bc
    // &vowels[2]: 0x7ff7be5436bd, pvowels + 2: 0x7ff7be5436bd, vowels + 2: 0x7ff7be5436bd
    // &vowels[3]: 0x7ff7be5436be, pvowels + 3: 0x7ff7be5436be, vowels + 3: 0x7ff7be5436be
    // &vowels[4]: 0x7ff7be5436bf, pvowels + 4: 0x7ff7be5436bf, vowels + 4: 0x7ff7be5436bf
    // vowels[0]: A, *(pvowels + 0): A, *(vowels + 0): A
    // vowels[1]: E, *(pvowels + 1): E, *(vowels + 1): E
    // vowels[2]: I, *(pvowels + 2): I, *(vowels + 2): I
    // vowels[3]: O, *(pvowels + 3): O, *(vowels + 3): O
    // vowels[4]: U, *(pvowels + 4): U, *(vowels + 4): U


    // As expected, '&vowels[i]' gives the memory location of the ith element of the 'vowels' array
    // Since this is a char array, each element occupies one byte so that consecutive memory addresses
    // are separated by a single byte

    // We also created a 'pvowels' pointer and assigned the address of the 'vowels' array to it

    // 'pvowels + i' is a valid operation (reference pointer arithmetics)
    // The output shows that '&vowels[i]' and 'pvowels + i' are equivalent

    // We can also see that 'pvowels + i' and 'vowels + i' return the same value–
    // the address of the ith element of the 'vowels' array

    // *(pvowels + i) and *(vowels + i) also both return the ith element of the 'vowels' array

    // This is because the name of an array itself is a constant pointer to the first element of the array
    // Thus 'vowels', '&vowels[0]', and 'vowels + 0' all represent the same location in memory

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// DYNAMIC MEMORY ALLOCATION FOR ARRAYS

// At this point we are able to traverse arrays using pointers
// We can also dynamically allocate continuous bytes of memory using block pointers
// These two concepts in tandem allow us to dynamically allocate memory for an array

int main(){

    // allocate five continuous bytes of memory to store five chars

    int n = 5;
    char *pvowels = (char *) malloc(n * sizeof(char));
    int i;

    pvowels[0] = 'A';
    pvowels[1] = 'E';
    *(pvowels + 2) = 'I';
    *(pvowels + 3) = 'O';
    *(pvowels + 4) = 'U';

    // traverse blocks of memory as if 'pvowels' is an array
    // remember that in reality it is but a pointer

    for(i = 0; i < n; i++){
        printf("%c ", pvowels[i]);
    }

    printf("\n");

    // Output:
    // A E I O U

    free(pvowels);

    for(i = 0; i < n; i++){
        printf("%c ", pvowels[i]);
    }

    // Output:
    // @ � 3 � w

    // Such manipulation of memory for array-like behavior can be useful for situations
    // where exact array size is unknown, so traditional instantiation would not work

    // This has the benefit of allowing us to free up memory when we are done with the array,
    // however with great memory manipulation power comes great responsibility, so we must only call
    // free() when we have absolutely exhausted the functionality of the dynamic array in our program

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// To get a better look at the behavior of n-dimensional arrays, let us dynamically
// allocate memory for a two-dimensional array

// Unlike one-dimensional arrays, where we used a single pointer, we will now require
// a pointer to a pointer as well

int main(){
    int nrows = 2;
    int ncols = 5;
    int i, j;

    // allocate memory for nrows pointers

    char **pvowels = (char **) malloc(nrows * sizeof(char *)); // note (char *) rather than (char)

    // for each row, allocate memory for ncols values

    pvowels[0] = (char *) malloc(ncols * sizeof(char));
    pvowels[1] = (char *) malloc(ncols * sizeof (char));

    pvowels[0][0] = 'A';
    pvowels[0][1] = 'E';
    pvowels[0][2] = 'I';
    pvowels[0][3] = 'O';
    pvowels[0][4] = 'U';

    pvowels[1][0] = 'a';
    pvowels[1][1] = 'e';
    pvowels[1][2] = 'i';
    pvowels[1][3] = 'o';
    pvowels[1][4] = 'u';

    // use pointers to iterate through memory

    for(i = 0; i < nrows; i++){
        for(j = 0; j < ncols; j++){
            printf("%c ", pvowels[i][j]);
        }
        printf("\n");
    }

    // Output:
    // A E I O U
    // a e i o u

    // free individual rows

    free(pvowels[0]);
    free(pvowels[1]);

    // free top-level pointer

    free(pvowels);

    // use pointers to iterate through newly freed memory

    for(i = 0; i < nrows; i++){
        for(j = 0; j < ncols; j++){
            printf("%c ", pvowels[i][j]);
        }
        printf("\n");
    }

    // Output:
    // zsh: segmentation fault

    return 0;
}

*/

// --------------------------------------------------------------------------------------------------------------

/* DYNAMIC ALLOCATION

// Dynamic allocation of memory allows us to build complex data structures,
// namely linked lists

// Dynamic allocation of memory helps us to store data without initially having
// to know the size of the data when we write our program

// In order to dynamically allocate a chunk of memory, we need to have a pointer
// ready to store the location of this new memory allocation

// We can access any allocated memory using the respective pointers, and we can
// use such a pointer to free the memory up again once we're done with it

// For example, let us dynamically allocate a person structure, defined as so

typedef struct{
    char * name;
    int exotic_fish;
} person;

int main(){
    // To allocate a new person in the my_person argument,
    // we use the following syntax

    person * my_person = (person *) malloc(sizeof(person));

    // The compiler takes this and dynamically allocates just enough memory to
    // hold a person struct and then return a pointer of type person to the
    // newly allocated data

    // malloc() reserves the specified memroy space, in this case the size of
    // 'person' in bytes

    // We write (person *) before calling malloc() because malloc() returns a
    // 'void pointer'– a pointer that has no type

    // Preceding the call to malloc() with (person *) is called typecasting,
    // it changes the type of pointer returned from malloc() to be of type
    // 'person'
    //
    // Note that this isn't strictly necessary because the C compiler implicitly
    // converts the type of pointer returned from malloc() if we don't typecast

    // Also note that sizeof() is not an actual function, but rather a way of
    // telling the compiler to translate the struct into its actual memory size

    // To access the members of the struct, we can use the shorthand notation
    // previously detailed below

    my_person->name = "Rick Sanchez";
    my_person->exotic_fish = 7000;

    printf("%s has %d exotic fish in his aquarium\n", my_person->name, my_person->exotic_fish);

    // Output:
    // Rick Sanchez has 7000 exotic fish in his aquarium

    // After we are done using the dynamically allocated struct, we can release
    // its space in memory by passing our person to free()
    //
    // Note that this does not delete the my_person variable itself, but rather
    // releases the data that it points to

    free(my_person);

    // my_person will still point to somewhere in memory, but in trying to call
    // it again we will no longer be able to access it
    //
    // We should therefore not use this pointer again until we again need to
    // dynamically allocate data

    printf("%s has %d exotic fish in his aquarium\n", my_person->name, my_person->exotic_fish);

    // Output:
    // zsh: segmentation fault {filepath}


    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// The following code is an example of using malloc() to dynamically allocate
// a point structure

typedef struct{
    int x;
    int y;
} point;

int main(){
    point * p;

    p = (point *) malloc(sizeof(point));

    p->x=37; p->y=108;

    printf("Point p is at coordinate (%d, %d)\n", p->x, p->y);

    // Output:
    // Point p is at coordinate (37, 108)

    return 0;
}

*/

// --------------------------------------------------------------------------------------------------------------

/* FUNCTION ARGUMENTS BY REFERENCE

// We are aware that function arguments are passed by value; they are copied in and out of the functions
// We will now be inspecting the behavior of passing pointers to these values rather than the values themselves

// For example, let us try defining a function that will double a number

void doubleVal(int n){
    // n is a local variable and only exists within the scope of the function
    n *= 2; // this is why doubling it has no effect
}

int main(){
    int n = 2;

    printf("Before calling doubleVal(): %d\n", n);
    doubleVal(n);
    printf("After calling doubleVal(): %d\n", n);

    // Output:
    // Before calling doubleVal(): 2
    // After calling doubleVal(): 2

    return 0;
}

// We can see that this does not work
-- tack comment terminator asterisk when running code snippet below --


// Now let's try using pointers

void doubleVal(int *n){
    // here n is a pointer and points to a memory-address outside the scope of the function
    (*n) *= 2; // this allows the function to successfully double the number
}

int main(){
    int n = 2;

    printf("Before calling doubleVal(): %d\n", n);
    // we must pass a reference to the variable n, not the variable itself
    doubleVal(&n); // this is done so the function knows the address of the variable rather than passing a copy
    printf("After calling doubleVal(): %d\n", n);

    // Output:
    // Before calling doubleVal(): 2
    // After calling doubleVal(): 4

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// POINTERS TO STRUCTURES

// Say we want to create a function that moves a point forward by
// 2 units in the x direction and 1 unit in the y direction

// Instead of sending two distinct pointers, we can use structures to send just one

typedef struct{
    int x;
    int y;
} point;

void up1Right2(point * p){
    (*p).x += 2;
    (*p).y += 1;
}

int main(){
    point p;
    p.x = 1;
    p.y = 1;

    printf("Before moving point p: (%d, %d)\n", p.x, p.y);
    up1Right2(&p);
    printf("After moving point p: (%d, %d)\n", p.x, p.y);

    // Output:
    // Before moving point p: (1, 1)
    // After moving point p: (3, 2)


    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// To dereference a structure and access one of its internal members, we are able
// to use the shorthand syntax

typedef struct{
    int x;
    int y;
} point;

void up1Right2(point * p){
    p->x+=2;
    p->y+=1;
}

int main(){
    point p;
    p.x = 1;
    p.y = 1;

    printf("Before moving point p: (%d, %d)\n", p.x, p.y);
    up1Right2(&p);
    printf("After moving point p: (%d, %d)\n", p.x, p.y);

    // Output:
    // Before moving point p: (1, 1)
    // After moving point p: (3, 2)

    return 0;

}

*/

// --------------------------------------------------------------------------------------------------------------

/* STRUCTURES

// Structures in C are special large variables which contain numerous named variables within
// Structures in C are the basic foundation for objects and class

// They are used for things such as:
//
// Serialization of data
// Passing multiple arguments in and out of functions through a single argument
// Data structures such as linked lists, binary trees, etc.

// The most basic example of structures are points, which are a single entity with variables x and y
struct point
{
    int x;
    int y;
};

// Now let's define a poiint and use it
// Let's also create a draw function which simulates the output of a drawing program

// In fact we will define two functions, one called drawPoint() and the other called drawCoords()
// Since C does not support object-oriented features such as method overloading (found in C++ and Java),
// we cannot have two functions of the same name which have different parameters

void drawCoords(int x, int y){
    printf("Point drawn at (%d, %d)\n", x, y);
}

void drawPoint(struct point p){
    printf("Point drawn at (%d, %d)\n", p.x, p.y);
}

int main(){
    int a = 2;
    int b = 3;
    drawCoords(a, b);

    // Note that we use the dot operator to access the point's variables
    struct point p;
    p.x = 4;
    p.y = 5;

    drawPoint(p);

    // Output:
    // Point drawn at (2, 3)
    // Point drawn at (4, 5)

    return 0;

}
-- tack comment terminator asterisk when running code snippet below --


// TYPEDEFS

// Typedefs allow us to define types with a different name, which is useful when deaaling with
// structs and pointers

// Here, we will be redefining the point structure using the following syntax which will allow us
// to remove the keyword struct whenever we want to define a new point

typedef struct{
    int x;
    int y;
} point;

int main(){

    // This will now allow us to define points as such
    point p;
    p.x = 2;
    p.y = 3;

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// OTHER USES

// Structures can also hold pointers, which allow them to hold strings or pointers to other
// structures

// For example, we can define a vehicle structure with the following configuration

typedef struct{
    char * brand;
    char * model;
    int year;
} vehicle;

// Because brand is a char pointer, the vehicle type can contain a string value, which here
// corresponds to the brand name

void printCarDetails(vehicle v){
    printf("%d %s %s\n", v.year, v.brand, v.model);
}


int main(){
    vehicle mycar;

    mycar.brand = "Honda";
    mycar.model = "Accord";
    mycar.year = 2022;

    printCarDetails(mycar);

    // Output:
    // 2022 Honda Accord

    return 0;
}
-- tack comment terminator asterisk when running code snippet below --


// The following code defines a data structure named 'person' which contains a string
// (pointer to a char array) called 'name' and an integer called 'age'

typedef struct{
    char * name;
    int age;
} person;

int main(){
    person peter;

    peter.name = "Peter Griffin";
    peter.age = 45;

    printf("%s is %d years old\n", peter.name, peter.age);

    // Output:
    // Peter Griffin is 45 years old

    return 0;
}

*/

// --------------------------------------------------------------------------------------------------------------

/* POINTERS

// Pointers also function as variables and play an important role in C
// They are used in several ways such as:
//
// Strings
// Dynamic memory allocation
// Sending function arguments by reference
// Building complicated data structures
// Pointing to functions
// Building special data structures like trees, tries, etc.

// A pointer in essence is a simple integer variable that holds a memory address
// which points to a value, rather than holding the actual value itself

// The sequential configuration of data storage in computer memory memory allows
// pointers to exist, pointing to an arbitrary amount of memory addresses

// This is already evident in the discussion of strings, but now we can analyze them further

// Note that strings in C are called 'C-strings' to differentiate them from strings in C++

int main(){

    // Let's look at an example

    char * name1 = "Peter";

    // This line of code does three things:
    //
    // Allocates a local variable in the stack called 'name1', which is a pointer to a single character
    // Causes "Peter" to appear in program memory after compile and execution time
    // Initializes the 'name1' argument to point where the 'P' character resides (followed sequentially by 'eter')

    // If we try to access the name1 variable as an array, it will works and return the
    // ordinal value of the character P, since the name1 variable actually points to the beginning of the string

    // Because we know that memory is stored sequentially, we can assume that if we move ahead to the next
    // character, we'll receive the next letter in the string, until we reach the end of the string marked by a
    // null terminator (\0)

    printf("%s\n", name1);


    // DEREFERENCING

    // Dereferencing concerns referencing to where the pointer points rather than the memory address itself

    // For example, the brackets operator accesses specific items in the array,
    // i.e., name1[0] would access 'P'

    // Since arrays in C are actually pointers, accessing the first item in the array is the same as
    // dereferencing a pointer

    // Let's take a look at the following code

    int a = 1; // defines a local variable

    int * pointer_to_a = &a; // defines a pointer variable and point it to a using & operator

    printf("The value of a is %d\n", a);
    printf("We can also access the value of a with the pointer– %d\n", *pointer_to_a);

    // We have used the & operator to point at the variable a
    // We then referred to it using the dereferencing operator

    // We can also change the contents of the dereferenced variable

    a += 1; // changes the value of a directly

    *pointer_to_a += 2; // changes the value of a indirectly

    printf("The value of a is now %d\n", a);

    // Output:
    // The value of a is now 4


    return 0;

}
-- tack comment terminator asterisk when running code snippet below --


// The following code creates a pointer to a local variable 'n' called
// pointer_to_n, and uses it toincrease the value of n by one

int main(){
    int n = 10;

    int * pointer_to_n = &n;

    *pointer_to_n += 1;

    // Confirm
    if (pointer_to_n != &n || *pointer_to_n != 11) return 1;

    printf("n is %d\n", n);

    // Output:
    // n is 11

    return 0;

}

*/

// --------------------------------------------------------------------------------------------------------------

/* STRINGS

// Strings in C are functionally arrays of characters

// We have not yet encountered pointers, but we will use pointers to a character array to
// define simply strings

int main(){
    // For example

    // This method of creating strings can be used only for reading

    char * name1 = "John Smith";

    // We will need to define a local character array if we want to manipulate a string
    // This notation allocates an array variable so we can manipulate it, with the brackets []
    // left empty so the compiler may calculate the size of the array automatically

    char name2[] = "John Smith";

    // This is effectively the same as allocating the size explicity
    // Note that the size must be 11 despite "John Smith" having 10 characters (space-inclusive)
    // because there is a special character at the end– a string terminator (equal to zero)
    // indicating the end of the string

    char name3[11] = "John Smith";


    // STRING FORMATTING USING printf

    // We can use the printf command to format a string alongside other strings

    char * name4 = "Peter Griffin";
    int helicopters = 35;

    printf("%s has %d helicopters\n", name4, helicopters);

    // Output:
    // Peter Griffin has 35 helicopters


    // STRING LENGTH

    // The strlen() function returns the length of a string which it takes as an argument
    // Include from <string.h>

    printf("%lu\n", strlen(name4));

    // Output:
    // 13


    // STRING COMPARISON

    // The strncmp() function compares two strings, returning 0 if they are equal and
    // another number if not

    // It takes the two strings to be compared as arguments, and the maximum comparison length
    // An unsafe version of this function exists, strcmp(), but it is not recommended

    char * name5 = "Peter";

    if (strncmp(name5, "Peter", 5) == 0){
        printf("Strings are equivalent\n");
    } else {
        printf("Strings are not equivalent\n");
    }

    // Output:
    // Strings are equivalent


    // STRING CONCATENATION

    // The strncat() function appends the first n characters of a src string to the
    // destination string where n is min(n, length(src))

    // The arguments passed are the destination string, the source string, and n– the maximum
    // number of characters to be appended

    // For example

    char dest[20] = "Peter ";
    char src1[20] = "Griffin";
    char src2[20] = "ffin";

    strncat(dest, src1, 3);
    printf("%s\n", dest);

    strncat(dest, src2, 20);
    printf("%s\n",dest);

    // Output:
    // Peter Gri
    // Peter Griffin

    return 0;
}

*/

// --------------------------------------------------------------------------------------------------------------

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
-- tack comment terminator asterisk when running code snippet below --


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
-- tack comment terminator asterisk when running code snippet below --


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
-- tack comment terminator asterisk when running code snippet below --


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
-- tack comment terminator asterisk when running code snippet below --


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
-- tack comment terminator asterisk when running code snippet below --


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
