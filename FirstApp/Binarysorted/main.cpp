//
//  main.cpp
//  Binarysorted
//
//  Created by samuel.nechiforel on 21.01.2022.
//

#include <iostream>

using namespace std;
void display(struct Array array);

struct Array{
    int *array;
    int length;
    int sizeItem;
};

int binarySort(struct Array array, int key){
    int low = 0, hight = array.sizeItem-1,mid = 0 ;
    while (low<=hight) {
        mid = (low+hight)/2;
        if (key == array.array[mid]) {
            return mid;
        }else if (key < array.array[mid]){
            hight = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

void towerOfHonnai(int n, int a, int b, int c){
    if(n>0){
        towerOfHonnai(n-1, a, c, b);
        cout << "Move from A = " <<a << " to B = "<< b <<" using C = "  << c << endl;
        towerOfHonnai(n-1,b, a, c);
    }
}

int sum(struct Array array){
    int sum = 0;
    for (int i = 0; i<array.sizeItem; i++) {
        sum = sum + array.array[i];
    }
    return sum;
}

int sumRecursiv(struct Array array, int n){
    if(n<0){
        return 0;
    }
    return sumRecursiv(array, n-1) + array.array[n];
}

int averageRec(int number, int size){
    return number/size;
}

int *reverseArray(struct Array array){
    int *anotherArray = (int *)(malloc(sizeof(int)* array.length));
    
    for (int i = 0;i< array.sizeItem;i++) {
        anotherArray[i] = array.array[array.sizeItem-i];
    }
    
    return anotherArray;
}

void insertItem(struct Array *array, int item){
    int i = array->sizeItem-1;
    while (i>=0 && array->array[i]>item) {
        array->array[i+1] = array->array[i];
        i--;
    }
    array->array[i+1] = item;

    array->length++;
    array->sizeItem++;
    display(*array);
}

void swap(int *a,int *b){
    int *temp = a;
    *a = *b;
    *b = *temp;
}

void sorted (struct Array *array){
    int i,j;
    i = 0;
    j = array->sizeItem-1;
    
    while (i<j) {
        while (array->array[i]<0) {
            i++;
        }
        while (array->array[j]>=0) {
            j--;
        }
        if (i<j) {
            swap(&array->array[i],&array->array[j]);
        }
    }
    display(*array);0   
}

void bobleSort(struct Array *array){
    for (int i = array->sizeItem; i > 0; i-- ) {
        for (int j = 0; j < i - 1; j++) {
            if (array->array[j] > array->array[j+1]) {
                swap(array->array[j], array->array[j+1]);
            }
        }
    }
}

void display(struct Array array){
    for (int i = 0; i<array.sizeItem; i++) {
        cout<<array.array[i]<<" ";
    }
    cout<<endl<<"New Line"<< endl;
}

int main(int argc, const char * argv[]) {
    int c = 3;
    int size = 45 ;
    cout<< "c= "<< c << "Size"<<size<<endl;
    struct Array base;
    int *baseSize = &base.sizeItem;
    base.array = (int *)(malloc(sizeof(int) * size ));
    base.length=13;
    base.sizeItem=size;
    struct Array anotherArray;
    anotherArray.length = base.length;
    anotherArray.sizeItem = base.sizeItem;
    for (int i = 1; i<size; i++) {
        base.array[i]=i;
        if (i>35) {
            base.array[i]=i-45;

        }
        if (i>4&&i<15) {
            base.array[i]=i+20;
        }if(i>=15&&i<=34){
            base.array[i]=i+84+i;
        }
        if (i<3) {
            base.array[i]=i+30;
        }
    }
    anotherArray.array = reverseArray(base);
    
    bobleSort(&base);
    display(base);
    int number;
    do{
        cout << "Enter your favorit number between 1 and 100"<<endl<<"\t";
        cin >> number;
    }
    while (number <0 ||number>100);
    if (number >=1 && number <= 100) {
        cout << "Amazing !!! That's my favorite number too!"<<endl;
        cout << "No really!! "<<number<< " is my favorite number!"<<endl;
        
    }
    

    
    
    cout<<endl;
    return 0;

}
