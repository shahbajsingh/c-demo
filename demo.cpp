// C++ DEMO

#include <iostream>
using namespace std;

// --------------------------------------------------------------------------------------------------------------

/* CLASSES AND INHERITANCE
*/

// While C++ is similar in syntax to C, it also implements object-oriented behavior
// The following code is a basic implementation of a class with inheritance

#define NAME_SIZE 50 // Defines a macro for the maximum size of a name

class Person {
    int id; // All members are private by default
    char name[NAME_SIZE];

    public:
        void aboutMe() {
            cout << "I am a person\n";
        }
};

class Student : public Person{
    public:
        void aboutMe() {
            cout << "I am a student\n";
        }
};

int main(){
    Student * p = new Student();
    p->aboutMe(); // Prints the student's description
    delete p; // Delete allocated memory
    return 0;

    // Output:
    // I am a student

}
