#include<iostream>
using namespace std;

int main(){
    
    int A[5];
    //A[0] = 1;
    //A[1] = 2;

    int B[5] = {2,4,6,8};

    int C[] = {2,4,6,8,10,12};

    for(int i=0; i<5;i++){
        //printf("%d\n", B[i]);
        cout<<A[i]<<endl;
    }

    //printf("Size of Array A %lu", sizeof(A));
    cout<< "Size of array A is: "<< sizeof(A)<<endl;
    cout<< "Size of array C is: "<< sizeof(C)<<endl;

    // The elements will be 0 if not initialized while declaring the array, will be garbage if initialized individually.
    cout<<B[4]<<endl;
    cout<<A[2]<<endl;

    //Variable sized array
    int n;
    cout<<"Enter size: "<<endl;
    cin>>n;

    int D[n];

    for(int i=0; i<n; i++){
        cout<<"Enter array value for position "<<i+1<<endl;
        cin>>D[i];
    }

    for(int x:D){
        cout<<x<<endl;
    }

    return 0;

}