#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    
    int a = 10;
    int &r = a;

    int b = 25;
    r = b; //This is an assignment and not changing the reference. This will still point to a.

    cout<<r<<endl;

    return 0;
}