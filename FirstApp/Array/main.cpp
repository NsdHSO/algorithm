//
//  main.cpp
//  Array
//
//  Created by samuel.nechiforel on 17.01.2022.
//

#include <iostream>
using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void display(struct Array array);

void append( struct Array *array, int number){
    if (array->size < array->length) {
        array->A[array->size++] = number;
    }
       
}

void insert(struct Array *array,int index, int number){
    if (index >= 0 && index <= array->length ) {
        for (int i = array->length; i>index; i--) {
            array->A[i] = array ->A[i-1];
        }
        array->A[index] = number;
        array->length++;
    }
}

void deleteItem(struct Array *array, int index){
    array->A[index]=0;
    if (index >= 0 && index <= array->length ) {
        for (int i = index; i < array->length-1 ; i++) {
            array->A[i] = array->A[i+1];
        }
        array->length--;
    }
}

int searchItem(struct Array array, int number){
    int value = 0;
    for (int a = 0; a<array.size; a++) {
        if (array.A[a] == number) {
            value = a;
        }
        
    }
    return value;
}

int getItem(struct Array array,int index){
    int value = 0;
    for (int a = 0; a<array.size; a++) {
        a == index  ? value = array.A[a] : NULL;

        
    }
    return value;
}

int getMax(struct Array array){
    int value = 0;
    for (int a = 0; a<array.size; a++) {
        array.A[a] > value ? value = array.A[a] : NULL;

        
    }
    return value;
}

int getMin(struct Array array){
    int value = 0;
    value = array.A[0];
    for (int a = 0; a<array.size; a++) {
        array.A[a] < value ? value = array.A[a] : NULL;
       
        
    }
    return value;
}

void display(struct Array array){
    cout<<endl<<"Value At Array is "<<endl;
    for (int i = 0 ; i<=array.length;i++) {
        cout << array.A[i]<<" ";
    }
}

bool sortItem(struct Array array){
    bool value = NULL;
    for (int i = 0; i<array.size-1; i++) {
        array.A[i]< array.A[i+1] ? value = true : value =false;
    }
    return value;
}

int main(int argc, const char * argv[]) {

    struct Array array;
    cout << "Set value for size"<< endl;
    cin>>array.size;
    cout << "Set value for length"<< endl;
    cin>>array.length;
    array.A = (int *)(malloc(sizeof(int)*array.size));
    
    for (int i = 0; i<array.size; i++) {
        cout << "Set Value for array ";
        cin >> array.A[i];
    }
    
    display(array);

    
    cout << "Before Append";
    
    // Append
    append(&array,4);
    
    display(array);
    cout<< "Before to insert one" << endl;
    
    insert(&array,1, 44);
    display(array);
    cout<< "Before to Delete"<< endl;
    deleteItem(&array, 1);
    display(array);
    const int valueToIndex = 3;
    cout<<endl <<"After perform the search"<<endl<<searchItem(array, valueToIndex)<<endl;
    cout<<"Get Value at index "<<valueToIndex<<" = "<<getItem(array, valueToIndex)<<endl;
    cout<<"Get Value at maxim "<<getMax(array)<<endl;
    cout<<"Get Value at minim "<<getMin(array)<<endl;
    cout<<"Value Sorted "<<sortItem(array)<<endl;


    return 0;
}
