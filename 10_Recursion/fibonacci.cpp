#include<stdio.h>
#include<iostream>

using namespace std;

/* Excessive Recursion */
int fib(int n){
    if(n <= 1)
        return n;
    return fib(n-2) + fib(n-1); 
}

/* Iteration */
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

/* Recursion using Memoization */
int F[10];

int fib_mem(int n){
    if(n <= 1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2] == -1)
            F[n-2] = fib_mem(n-2);
        if(F[n-1] == -1)
            F[n-1] = fib_mem(n-1);

        F[n] = F[n-2] + F[n-1];
        return F[n-2] + F[n-1];
    }
}


int main(){

    cout << fib(6) << endl;
    cout << fib_loop(7) << endl;

    for(int i=0; i < 10; i++)
        F[i] = -1;
    
    cout<< fib_mem(8) << endl;

    return 0;
}