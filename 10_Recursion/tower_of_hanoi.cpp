#include<stdio.h>
#include<iostream>

using namespace std;

void tower_hanoi(int n, int A, int B, int C){
    if(n > 0){
        tower_hanoi(n-1, A, C, B);
        cout<< "Move disk from "<< A << " to " << C << endl;
        tower_hanoi(n-1, B, A, C);
    }
}

int main(){

    tower_hanoi(3, 1, 2, 3);

    return 0;
}