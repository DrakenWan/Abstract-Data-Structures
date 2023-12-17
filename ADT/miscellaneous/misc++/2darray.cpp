/********************
 *  An Implementation of 2d Array using double pointer
 * 
 * 
 * 
 * 
 * 
 * ************************/
#include<iostream>

using namespace std;

int main() {
    int **arr2d;
    int r = 3, c = 5;

    arr2d = new int*[r];

    for(int i=0; i<r; i++)
    {
        int *tempPtr = new int[c];
        cout<<"\nEnter "<<c<<" numbers:-\n";
        for(int j=0; j<c; j++)
            cin>>*(tempPtr + j);
        
        *(arr2d + i) = tempPtr;
    }

    cout<<"\nContents of "<<r<<'x'<<c<<" 2d array are:-\n";
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++)
            cout<<*(*(arr2d+i) + j)<<" ";
        cout<<"\n";
    }
    return 0;  
}