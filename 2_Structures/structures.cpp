#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
    char x; //Allocates 4 bytes and use only 1 byte for the character - Nearest Biggest Size (int)
} r3,r4,r5; //Declare here as well

//Declare here
struct Rectangle r1;

int main(){

    r1.length = 8;
    r1.breadth = 10;
    r1.x = 'a';

    struct Rectangle r2 = {10,5};

    cout<<sizeof(r1)<<endl;

    cout<<"Length: "<< r1.length << endl;
    cout<<"Breadth: "<< r1.breadth << endl;

    return 0;
}