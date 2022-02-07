//
//  main.cpp
//  FindDuplicateItem
//
//  Created by samuel.nechiforel on 03.02.2022.
//

#include <iostream>


using namespace std;

struct Array{
    int length;
    int *items;
};

struct Array initHashTable(struct Array *array){
    int max = 0;
    for (int i = 0 ; i < array->length; i++) {
        if (array->items[i] > max) {
            max = array->items[i];
        }
    }
    struct Array hashArray;
    hashArray.length = max;
    hashArray.items = (int *)(malloc(sizeof(int) * max));
    
    for (int i = 0 ; i <= max ; i++) {
        hashArray.items[i] = 0;
    }
    return hashArray;
}

void display(struct Array *array){
    for (int i = 0; i < array->length; i++) {
        cout<< array ->items[i]<<" ";
    }
    cout<<" ";
}

void duplicateItem(struct Array duplicateItems, struct Array hashtable){
    for (int i = 0; i < duplicateItems.length ; i++) {
        hashtable.items[duplicateItems.items[i]]++;
    }
//
//    for (int i = 0; i< duplicateItems.length; i++) {
//        cout <<duplicateItems.items[i] << "  Apperance " <<hashtable.items[duplicateItems.items[i]] <<endl;
//    }
        
}

void sumEqual(struct Array array, int sum){
    int f = 0;
    for (int i = 0; i < array.length - 1; i++) {
        for (int j = i+1; j < array.length;j++ ) {
            if (array.items[i] + array.items[j] == sum ) {
                cout << array.items[j] << " + " << array.items[i] << "=" <<array.items[j] + array.items[i] <<endl;
                f++;
            }
        }
        cout<<endl;
    }
    cout<<f;
}


void findSumHash(struct Array array, struct Array hashtable, int sum){
    for (int i = 0; i < array.length; i++) {
        if (sum - array.items[i] >=0) {
            
        
            if (hashtable.items[sum - array.items[i]] != 0) {
                cout << array.items[i] << " + " << sum - array.items[i] << " = " << sum << endl;
            }
        }
        hashtable.items[i]++;
    }
}

void swap(struct Array *array,int first, int second){
    int temp = array->items[first];
    array->items[first] = array->items[second];
    array->items[second] = temp;
}

void bubbleSort(struct Array unsorted){
    for(int i = unsorted.length; i > 0; i--){
        for (int j = 0; j < i + 1 ; j++) {
            if (unsorted.items[j] > unsorted.items[j+1]) {
                swap(&unsorted, j, j+1);
            }
        }
    }
}

void deleteItems(struct Array *duplicateArray, int item){
    for (int i = item; i < duplicateArray->length - 1 ; i++) {
        duplicateArray->items[i] = duplicateArray->items[i+1];
    }duplicateArray->length--;
}

void elementUniq(struct Array *duplicateArray){
    for (int i = 0; i< duplicateArray->length - 1 ; i++) {
        if(duplicateArray->items[i] == duplicateArray->items[i+1]){
            deleteItems(duplicateArray, duplicateArray->items[i]);
        }
    }
}

void addedNewItem(struct Array *oldArray, int item){
    oldArray->items[oldArray->length] = item;
    oldArray->length++;
}

void addedNewItem(struct Array *oldArray, int index,int item){

    for (int i = oldArray->length; i > index; i--) {
        oldArray->items[i] = oldArray->items[i-1];
    }
    oldArray->items[index] = item;
    oldArray->length++;
}

int findSmallest(struct Array *unOrder){
    int index = 0;
    int value = unOrder->items[0];
    for (int i = 1; i < unOrder->length - 1; i++) {
        if (unOrder->items[i] < value) {
            value = unOrder->items[i];
            index = i;
        }
    }
    return index;
}

int popItems(struct Array *array, int index){
    int returns =  array->items[index];

    deleteItems(array, index);
    return returns;
}
int ij = 0;

struct Array selectionSorting(struct Array array){
    struct Array newArray;
    ij = array.length;
    newArray.length = 1;
    newArray.items = (int *)(malloc(sizeof(int) * newArray.length));
    deleteItems(&newArray, 0);
    int smallest;
    for (int i = 0; i < ij -1 ; i++) {
        smallest = findSmallest(&array);
        if(i == 0)
            addedNewItem(&newArray, 0,popItems(&array,smallest));
        addedNewItem(&newArray, popItems(&array,smallest));

    }
    return newArray;
}

int main(int argc, const char * argv[]) {
   
    struct Array items;
    items.length = 200;
    items.items = (int *)(malloc(items.length * sizeof(int)));
    for (int i = 0; i<items.length ; i++) {
        items.items[i] = i;
        if(i>10 && i<15){
            items.items[i] = i-3;
        }
        if (i < 35) {
            items.items[i] = i+2;
        }
        
    }
    struct Array newArray;
    struct Array newArray1;

    newArray.length = 0;
    newArray.items = (int *)(malloc(sizeof(int) * newArray.length));
    struct Array hashItem;
    hashItem = initHashTable(&items);
//    display(&hashItem);
    display(&items);
    cout << endl;
    addedNewItem(&newArray, 1);
    addedNewItem(&newArray, 5);
    addedNewItem(&newArray,1, 3);
    addedNewItem(&newArray, 4);
    addedNewItem(&newArray, 10);
    addedNewItem(&newArray, 8);
    addedNewItem(&newArray, 7);
    addedNewItem(&newArray,5, 76);
    addedNewItem(&newArray,73);


    cout << endl;
    display(&newArray);
    cout<<endl;
    bubbleSort(items);
    cout<<endl;
    newArray1 = selectionSorting(newArray);
    cout << endl;
    display(&newArray1);

    cout << endl;
    display(&items);
    

    cout << endl;
    elementUniq(&items);
    cout << endl;
//    display(&items);
//    findSumHash(items, hashItem, 15);
    delete newArray.items;
    delete newArray1.items;
    
    return 0;
}
