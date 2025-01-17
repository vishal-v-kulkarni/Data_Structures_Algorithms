#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){

    //Pointer to a struct in a Stack.
    struct Rectangle r = {10,5};
    struct Rectangle *p = &r;
    
    //p=&r;

    r.length = 15;
    (*p).length = 20; // . takes precedence over * So add brackets
    p->length = 25; //Another way to access the member

    cout<< "Pointer to a struct in the STACK: " <<endl;
    cout<<p<<endl;
    cout<<"Length of Rectangle is "<< p->length<<endl;
    cout<<"Breadth of Rectangle is "<< p->breadth<<endl<<endl;
    
    //Pointer to a struct in HEAP
    Rectangle *p1;
    p1 = (Rectangle *)malloc(sizeof(Rectangle)); // Without struct keyword is C++ syntax.
    //p1 = new Rectangle; //C++ Syntax
    p1->length = 10;
    p1->breadth = 5;

    cout<< "Pointer to a struct in the HEAP: " <<endl;
    cout<<p1<<endl;
    cout<<"Length of Rectangle is "<< p1->length<<endl;
    cout<<"Breadth of Rectangle is "<< p1->breadth<<endl;
    
    delete p1;

    return 0;
}