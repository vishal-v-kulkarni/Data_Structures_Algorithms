#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    
    int a = 10;
    int &r = a; //Reference cannot be changed once assigned.

    int b = 25;
    r = b; //This is an assignment of value (25) and not changing the reference. This will still point to a.

    cout<<r<<endl;

    return 0;
}