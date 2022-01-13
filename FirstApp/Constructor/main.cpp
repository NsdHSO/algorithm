//
//  main.cpp
//  Constructor
//
//  Created by samuel.nechiforel on 13.01.2022.
//

#include <iostream>
using namespace std;

template <class T>
class Arithmetic{
private :
    T a;
    T b;
    
public:
    Arithmetic(){
        this->a = 0;
        this->b =0;
    }
    Arithmetic(T a, T b){
        this->a = a;
        this->b = b;
    }
    
    T sumBoth(){
        return (*this).a + (*this).b;
    }
    T add();
    
    ~Arithmetic(){
        printf("\n Destroy Arithmetric\n");
    }
    
};

template <class T>
T Arithmetic<T>::add(){
    return this->a + this->b;
};

class Rectangle {
private:
    int length;
    int width;
public:
    Rectangle(){
        length = 0;
        width = 0;
    }
    
    Rectangle(int l, int w){
        length = l;
        width = w;
    }
    
    int area(){
        return length*width;
    }
    
    int perimeter(){
        return 2*(length + width);
    }
    
    ~Rectangle(){
        printf("Destructor");
    }
    
};

int main(int argc, const char * argv[]) {
    
    Rectangle r(10, 20);
    printf("\n%d \n", r.area());
 
    Arithmetic<float> homeAtr(1,10);
    float ar = homeAtr.sumBoth();
    printf("%f", ar);
    
    return 0;
}
