#include<stdio.h>
#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    Rectangle r = {10,20};

    cout<<"Direct Access"<<endl;
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;

    //Pointer on Stack
    struct Rectangle *p1; 
    p1 = &r;

    cout<<"Pointer on Stack Access"<<endl;
    cout<<p1->length<<endl;
    cout<<p1->breadth<<endl;

    //Pointer on Heap
    struct Rectangle *p2;
    p2 = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    //p2 = new Rectangle; // In C++

    p2->length = 15;
    p2->breadth = 25;

    cout<<"Pointer on Heap Access"<<endl;
    cout<<p2->length<<endl;
    cout<<p2->breadth<<endl;

}