#include<stdio.h>
#include<iostream>

using namespace std;

int fib(int n){
    if(n <= 1)
        return n;
    return fib(n-2) + fib(n-1); 
}

int fib_loop(int n){
    int t0 = 0, t1 = 1, s;
    if(n <= 1)
        return n;
    
    for(int i = 2; i <= n; i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

int main(){

    cout << fib(7) << endl;
    cout << fib_loop(7) << endl;
    return 0;
}