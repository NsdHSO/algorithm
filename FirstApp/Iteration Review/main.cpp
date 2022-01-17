//
//  main.cpp
//  Iteration Review
//
//  Created by samuel.nechiforel on 17.01.2022.
//

#include <iostream>
using namespace std;

// Create a new Structure
struct Person {
    int age;
    string name;
};

// Function send value By value
void funByValue(int a){
    cout << "In function "<< a << endl;
    a = 5;
    cout << "In function "<< a << endl;
}

void funByReference(int &a){
    cout<<endl << "In function By Reference "<< a << endl;
    a = 5;
    cout << endl << "In function By Reference "<< a << endl;
}

// Function send value By Address
void funByAddress(int *a){
    cout<<endl << "In function By Address "<< *a << endl;
    *a = 7;
    cout << endl << "In function By Address "<< *a << endl;
}

void funStructure(struct Person person){
    cout<< person.name << endl;
    person.name = "David";
}

void funStructureAddress(struct Person *person){
    cout<< person->name << endl;
    person->name = "David";
}

void funStructureReference(struct Person &person){
    cout<< person.name << endl;
    person.name = "Mihai";
}

int main(int argc, const char * argv[]) {
    // Here I created a new Instance at struct Person
    int variable = 2;
    struct Person sami = {24, "Sami"};
   
    // I use instance of Person
    cout<< sami.age<< endl;
    cout<< sami.name << endl;
    
    // Create A new structure pointer
    
    struct Person *andrei;
    andrei = (struct Person *)(malloc(3*sizeof(andrei)));
    andrei->age = 2;
    andrei->name = "Popa";
    cout<< andrei->age << endl;
    cout<< andrei->name << endl;
    
    // Pointer we using for accessing the resources which are outside the program.
    
    struct Person *&referenceCopy = andrei;
    cout << referenceCopy->name << endl;
    cout <<"Reference For copy   " << referenceCopy << endl << "Reference For Parent " << andrei << endl;
    
    // Function send value by Value
    
    funByValue(variable);
    cout << "In main "<< variable<< endl ;

    // Function send value by Reference

    funByReference(variable);
    cout << "In main "<< variable<< endl ;

    // Function send value by Address

    funByAddress(&variable);
    cout << "In main After function call by Address "<< variable<< endl ;

    // Function send structure value
    
    funStructure(sami);
    cout<< sami.name << endl;

    // Function send structure address
    
    funStructureAddress(&sami);
    cout<< sami.name << endl;
    
    funStructureReference(sami);
    cout<< sami.name << endl;
    
    return 0;
}
