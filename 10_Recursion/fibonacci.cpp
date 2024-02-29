#include<stdio.h>
#include<iostream>

using namespace std;

int fibonacci(int n){
    if(n == 0)
        return 1;
    return n * fibonacci(n-1);
}

int main(){
    int x=1;

    int result = fibonacci(x);
    cout << result << endl;

    return 0;
}