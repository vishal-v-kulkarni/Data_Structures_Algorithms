#include<stdio.h>
#include<iostream>

using namespace std;

int factorial(int n){
    if(n == 0)
        return 1;
    return n * factorial(n-1);
}

int main(){
    int x=5;

    int result = factorial(x);
    cout << result << endl;

    return 0;
}