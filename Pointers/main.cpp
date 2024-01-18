//
//  main.cpp
//  Pointers
//
//  Created by Vishal Kulkarni on 21/07/23.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main() {
    
    //Pointer to an integer in STACK section
    int a = 10;
    int* p;
    
    p=&a;
    
    cout << "Value of a: "<< a <<endl;
    cout << "Address of a using p: " << p<< endl;
    cout<< "Value of a using dereferencing: " << *p << endl;
    
    //Pointer to an array of integers in stack
    int A[5] = {2,4,6,8,10};
    int *P;
    
    P = A;
    //OR p = &A[10];
    
    cout << P << endl; // Address(stack) to the 1st element of the array
    
    for(int i=0; i<5; i++){
        
        cout << P[i] << endl;
        //cout << A[i] << endl;
    }
    
    //Pointer to an array of integers in HEAP
    int *Q;
    Q  = (int *) malloc(5*sizeof(int));
    //Q = new int[5];
    
    Q[0] = 11; Q[1] = 12; Q[2] = 13; Q[3] = 14; Q[4] = 15;
    
    for(int i=0; i<5; i++){
        cout<< Q[i] <<endl;
    }
    
    delete [] Q; // For array [], else just the variable name
    //free(Q); This is in C
    
    //Size of the pointer is independent of the data type
    
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;
    
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;
    
    return 0;
}
