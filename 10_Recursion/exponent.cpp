#include<stdio.h>
#include<iostream>
using namespace std;

int exponent(int m, int n){
    if(n > 0)
        return exponent(m, n-1) * m;
    else
        return 1;
}

//Efficient way to calculate exponents
int power(int m, int n){
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return power(m * m, n/2);
    else
        return m * power(m * m, (n-1)/2);
}

int main(){

    cout << exponent(3, 4) << endl;

    cout << power(2, 9) << endl;

    return 0;
}