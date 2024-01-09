#include<iostream>
#include "matrix.h"

using namespace std;

int main() {
    int *array;
    int N = 4;
    array = new int[N*N];
    init2dRandArray(array, N, N);

    // create our D matrix
    linear::matrix<int> D(array, N);
    deAlloc(array);

    D.display();

    D.saveMatrix("matrixD");

    linear::matrix<int> dupD(0,0);

    dupD.loadMatrix("matrixD");
    dupD.display();

    array = new int[10*10];
    init2dRandArray(array, 10, 10);

    linear::matrix<int> A(array, 10);
    deAlloc(array);
    A.display();

    A.saveMatrix("matA");

    linear::matrix<float> C;
    C.loadMatrix("matA");
    C(1,2) = 0.5;
    C.display();


    std::cout<<"\n\nMatrix inverse\n\n";
    N=3;
    float *flarray = new float[N*N];
    init2dArray<float>(flarray, N, N);
    linear::matrix<float> B(flarray, N);
    deAlloc(flarray);

    B.display();
    linear::matrix<float> invB = B.inv();

    invB.display();

    linear::eye<float>(5).display();
    linear::diagonal<float>(3, 5.3).display();
    // int R=5, C=5;

    // linear::matrix<float> A;
    // A.loadMatrix("matrixD");

    // A.display();
    
    // linear::matrix<float> B;
    // B.loadMatrix("matrixD");

    // B.inv().display();

    std::cout<<"\n\nMatrix solve Ax= b\n\n";
    N=3;
    flarray = new float[N*N];
    init2dArray<float>(flarray, N, N);
    linear::matrix<float> MatA(flarray, N, N);
    deAlloc(flarray);

    MatA.display();

    flarray = new float[N*1];
    init2dArray<float>(flarray, N, 1);
    linear::matrix<float> vecB(flarray, N, 1);
    deAlloc(flarray);

    linear::matrix<float> solAb = MatA.solve(vecB);

    std::cout<<"Ax = b, gives x = \n";
    solAb.display();

    cout<<"\n\nIs triangular?";
    N = 4;
    flarray = new float[N*N];
    init2dArray<float>(flarray, N, N);
    linear::matrix<float> trian(flarray, N, N);
    deAlloc(flarray);

    if(linear::is_triangular(trian))
        cout<<"\nIt is triangular.";
    else
        cout<<"\nIt aint triangular.";

    return 0;   
}