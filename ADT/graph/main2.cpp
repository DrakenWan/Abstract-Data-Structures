#include<iostream>
#include "./digraph.h"

using namespace std;

int main () {
    //cout<<"\n Hello\n";
    vector<vector<int>> matrix = {{0,1,0,1},
                                  {1,0,1,0},
                                  {0,1,0,1},
                                  {1,0,1,0}};
    graph::diGraph g(4);
    g.adjacencyMatrix(matrix);

    g.print();
    return 0;
}