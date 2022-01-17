//
//  main.cpp
//  Static Number
//
//  Created by samuel.nechiforel on 14.01.2022.
//



#include <iostream>
using namespace std;
void recursionTwo(int b);
int func(int a){
    static int value;
    
    if(a>0){
        value ++;
        return func(a-1) + value;
    }
    return 0;
}

int g = 0;

int func1(int a ){
    if(a>0){
        g++;
        return func1(a-1) + g;
    }
    return 0;
}

void recursionOne(int a ){
    if (a>0) {
        cout<<endl<<a<<endl;
        recursionTwo(a-1);
    }
}

void recursionTwo(int b){
    if(b>0){
        cout<<endl<<b<<endl;
        recursionOne(b/2);
    }
}

class Person{
private:
    string name;
    int age;
public:
    Person(string name, int age){
        this->age = age;
        this->name = name;
    }
    
    Person(){
        printf("Constructor Init \n");
    }
    
    ~Person(){
        cout<< "Destroy Object "<<endl;
    }
    
};


int nestedRecu(int a){
    if(a<17){
        return a;
    }return nestedRecu(nestedRecu(a-2));
}

int naturalNumber(int a){
    if(a==0 ){
        return 0;
    }return naturalNumber(a-1)+a;
};


int exponent(int base,int a){
    if (a==0) {
        return 1;
    }
    if(base<0 && a == -1){
        return base = base * (-1);
    }
    if (a<0) {
        return 1;
    }
    return exponent(base, a-1)*base;
}

int fibonaci(int a){
    if (a==1 || a==0) {
        return a;
    }
    return fibonaci(a-1)+ fibonaci(a-2);
};

float taylor(int e, int n){
    static float p = 1, f = 1;
    float r;
    if (n == 0) {
        return 1;
    }
    r = taylor(e, n-1);
    p = p * e;
    f = f* n;
    return r + p/f;
}

double horner(double x, double n){
    static double solution;
    if (n == 0) {
        return solution;
    }
    solution = 1+x/n * solution;
    return horner(x, n-1);
}
int F[10];

int fibonaciNumbe(int a ){
    
    if (a<=1) {
        F[a] = a;
        return a;
    }
    
    else{
        if (F[a-2] == -1)
            F[a-2] = fibonaciNumbe(a-2);
        
        if (F[a-1] == -1)
            F[a-1] = fibonaciNumbe(a-1);
        
        
        return F[a-2] + F[a-1];

    }
}

int factorial(int a){
    if(a == 0 )
        return 1;
    return factorial(a-1)*a;
}

int conb(int n, int k){
    int num,den;
    num = factorial(n);
    den = factorial(k) * factorial(n-k);
    return num/den;
}

int conbin(int k, int n){
    if (n==k || n == 0) {
        return 1;
    }return conbin(k-1, n-1) + conbin(k-1,n);
}
int fun (int n)

       {

int x=1, k;

if (n==1) return x;

for (k=1; k<n; ++k){
    cout<<"FUN(k)"<< "k="<<k<<endl;
    cout<<"FUN(n-k)"<<endl<<endl;
    cout<<x<<"=x"<<endl;
   x=x + fun(k) * fun(n-k);

    }
return x;

        }

int main(int argc, const char * argv[]) {
    for (int i = 0; i<11; i++) {
        F[i]=-1;
    }
    
    cout<<fun(4)<<endl ;
//    cout<< func(a)<< endl;
//    cout<< endl << func1(a)<<endl;
    
//    cout <<nestedRecu(20) << endl;
//    cout<< naturalNumber(a)<<endl;
//    cout<<fibonaciNumbe(6)<<endl ;
//    recursionOne(10);
    cout<<endl<<conbin(5, 2)<<endl;

    cout<<endl<<conb(5, 2)<<endl;
    
    
//    Person person;
    
    
    return 0;
}
