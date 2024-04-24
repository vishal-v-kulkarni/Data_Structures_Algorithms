#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
    
    // 2D Array in Stack
    int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};

    cout<< "2D Array in Stack: " << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    // 2D Array with Pointers in Stack
    int *B[3];

    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    cout<<endl;
    cout<< "2D Array with Pointers in Stack: " << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            B[i][j] = j;
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }

    // 2D Array with All Pointers in Heap

    int **C = (int **) malloc(3 * sizeof(int *));

    C[0] = (int *)malloc(4 * sizeof(int));
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));

    cout<<endl;
    cout<< "2D Array with All Pointers in Heap: " << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}