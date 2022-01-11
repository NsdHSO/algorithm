//
//  main.cpp
//  FirstApp
//
//  Created by samuel.nechiforel on 10.01.2022.
//

#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int width;
};

int main(int argc, const char * argv[]) {
    
    int *pointer, *another, **pointer1;
    pointer = (int * )malloc(5* sizeof(int));

    pointer[0] = 21;
    pointer[1]=1;
    pointer[2]=2;

    another = &pointer[0];
    
    pointer1 = &another;
        
    printf("%d \n", **pointer1);
    
    pointer[0] = 10;
    printf("%d \n", **pointer1);
    printf("%d \n", pointer[0]);

    
    return 0;
}
