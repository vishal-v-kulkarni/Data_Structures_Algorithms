#include<stdio.h>
#include<iostream>

using namespace std;

int sum(int n){
    if(n == 0)
        return 0;
    return sum(n-1) + n;
}

int sum_loop(int n){
    int result = 0;

    for(int i=1; i<=n; i++){
        result = result + i;
    }

    return result;
}

/* Change values of x, till the stack overflows. Loop does not*/
int main(){
    int x=100;

    int result = sum_loop(x);
    cout << result << endl;

    return 0;
}