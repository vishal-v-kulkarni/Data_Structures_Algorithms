#include<stdio.h>
#include<iostream>

using namespace std;

//Using Loop
double e_loop(int x, int n){
    double s = 1;
    for(; n > 0; n--){
        s = 1 + x * s/n;
    }

    return s;
}

//Using Horner's Rule
double e(int x, int n){
    static double s = 1;
    if(n == 0)
        return s;
    s = 1 + x * s/n;
    return e(x, n-1);
}


int main(){

    cout << e(2, 10) << endl;
    cout << e_loop(2, 10) << endl;

    return 0;
}