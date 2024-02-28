#include<stdio.h>
#include<iostream>

using namespace std;

/* Tail Recursion */
void fun1(int n){
    if(n > 0){
        cout<<"Fun 1: " << n << endl;
        fun1(n-1);
    }

}

/* Head Recursion */
void fun2(int n){
    if(n > 0){
        fun2(n-1);
        cout << "Fun 2: " << n << endl;
    }
}

int main(){

    int x=3;
    
    fun1(x);

    return 0;
}