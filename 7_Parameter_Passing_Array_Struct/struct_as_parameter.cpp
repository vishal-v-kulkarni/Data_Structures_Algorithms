#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

struct Example
{
    int A[2];
};

// Call by value
void fun1(struct Rectangle r1)
{

    r1.length = 20;
    cout << "In fun1:" << endl
         << "Length: " << r1.length << endl
         << "Breadth: " << r1.breadth << endl;
}

// Call by reference
void fun2(struct Rectangle &r2)
{

    r2.length = 20;
    cout << "In fun2:" << endl
         << "Length: " << r2.length << endl
         << "Breadth: " << r2.breadth << endl;
}

// Call by address
void fun3(struct Rectangle *r3)
{

    r3->length = 20;
    r3->breadth = 30;

    cout << "In fun3:" << endl
         << "Length: " << r3->length << endl
         << "Breadth: " << r3->breadth << endl;
}

// Array in struct is Call by Value
void fun4(struct Example e1)
{
    e1.A[0] = 3;

    cout << "In fun4: " << endl;
    for (int i = 0; i < (sizeof(e1.A) / sizeof(int)); i++)
    {
        cout << e1.A[i] << endl;
    }
}

// Creating struct in Heap and returning the address
struct Rectangle *fun5()
{
    struct Rectangle *p;
    p = new Rectangle;
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 15;
    p->breadth = 7;

    return p;
}

int main()
{

    struct Rectangle r = {10, 5};

    struct Example e = {{1, 2}};

    // fun1(r); //Call by value

    // fun2(r); //Call by reference

    // fun3(&r); // Call by address

    // For fun1, fun2, fun3
    // cout<<"In main:"<< endl << "Length: "<< r.length << endl << "Breadth: " << r.breadth <<endl;

    // fun4(e);

    // For fun4
    //  cout<< "In main: "<<endl;
    //  for(int i=0;i<(sizeof(e.A)/sizeof(int)); i++){
    //      cout<<e.A[i]<<endl;
    //  }

    struct Rectangle *rect = fun5();

    cout << "Rectangle in HEAP: " << endl
         << rect->length << endl
         << rect->breadth << endl;

    return 0;
}