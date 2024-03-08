#include<stdio.h>
#include<iostream>
using namespace std;

int exponent(int m, int n){
    if(n > 0)
        return exponent(m, n-1) * m;
    else
        return 1;
}

int main(){

    cout<< exponent(3, 4) << endl;

    return 0;
}