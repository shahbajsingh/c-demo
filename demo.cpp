// C++ DEMO

#include <iostream>
using namespace std;

/* VIRTUAL FUNCTIONS
*/

// Let us take the code we have sampled earlier and expound upon it

#define NAME_SIZE 50 

class Person{

// TO-DO: 

// demo.cpp:39:23: note: in implicit default constructor for 'Student' first required here
//     Student * p = new Student();
//                       ^
// demo.cpp:13:7: note: 'Person' declared here
// class Person{


    Person(int a) : id(a){

    }

    int id;
    char name[NAME_SIZE];

    public:
        void aboutMe(){
            cout << "I am a person\n";
        }
};

class Student : public Person{
    public:
        void aboutMe(){
            cout << "I am a student\n";
        }
};

int main(){
    Student * p = new Student();
    p->aboutMe(); // Output: I am a student
    delete p;
    return 0;
}

// --------------------------------------------------------------------------------------------------------------

/* CONSTRUCTORS AND DESTRUCTORS


// In the absence of a defined constructor, the C++ compiler will automatically generate a default
// constructor, however we may also choose to define our own

#define NAME_SIZE 50

class Person{
//    Person(int a){ // We may choose to initialize primitive types this way, 
//        id = a;    // however the following is preferred
//    }
    Person(int a) : id(a){
        // Here, the data member 'id' is assigned before the object is created
        // or the constructor is called upon
    }   // This way is necessary when the fields are constant or class types
    

    int id;
    char name[NAME_SIZE];

    // The following is an example of a 'destructor' which is called upon object
    // deletion

    // Note that it does not take any arguments as it is not explicitly called upon

//    ~Person(){
//        delete obj;
//    }


}; 

*/

// --------------------------------------------------------------------------------------------------------------

/* CLASSES AND INHERITANCE


// While C++ is similar in syntax to C, it also implements object-oriented behavior
// The following code is a basic implementation of a class with inheritance

#define NAME_SIZE 50 // Defines a macro for the maximum size of a name

class Person {
    int id; // All members are private by default
    char name[NAME_SIZE];

    public: // We must explicitly define public members using the keyword
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

    // Output:
    // I am a student

    return 0;
}

*/

// --------------------------------------------------------------------------------------------------------------