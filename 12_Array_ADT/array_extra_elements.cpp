#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){
    int A[3];

    for(int i=0; i < 6; i++){
        A[i] = i;
    }

    for (int i = 0; i < 6; i++)
    {
        cout << A [i] << endl;
    }
  return 0;   
}