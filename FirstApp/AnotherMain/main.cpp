//
//  main.cpp
//  AnotherMain
//
//  Created by samuel.nechiforel on 13.01.2022.
//


#include <iostream>
using namespace std;

struct Rectangle{
    int width;
    int length;
    int arrayUnit[3];
};
void init(struct Rectangle *ptr, int width, int breath){
    ptr->length =breath;
    ptr->width = width;
}
void area(struct Rectangle rect){
    int area = rect.length + rect.width;
    printf("\n%d \n", area);
}

void changeBreath(struct Rectangle *ptr, int newLength){
    ptr->length = newLength;
}



int main(int argc, const char * argv[]) {
    struct Rectangle rect;
    init(&rect, 10,20);
    area(rect);
    changeBreath(&rect, 5);
    area(rect);

    return 0;
}
