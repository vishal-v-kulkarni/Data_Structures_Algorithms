#include<stdio.h>
#include<iostream>

using namespace std;

int fact(int n){
    if(n == 0)
        return 1;
    
    return fact(n-1) * n;
}

// nCr using Factorial recursion
int nCr_fact(int n, int r){
    int num, den;

    num = fact(n);
    den = fact(r) * fact(n-r);

    return num/den;
}

// nCr with pure recursion
int nCr(int n, int r){
    if(n == r || r == 0)
        return 1;
    return nCr(n-1, r-1) + nCr(n-1, r);
}

int main(){

    cout << nCr_fact(5,2) << endl;

    cout << nCr(4,2) << endl;
    return 0;
}