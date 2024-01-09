#include<iostream>
#include "./digraph.h"
#define CHANGE_ID_TO_STRING(x) (#x)

using namespace std;

int main () {
    //cout<<"\n Hello\n";
    vector<vector<int>> matrix = {{0,1,0,1},
                                  {1,0,1,0},
                                  {0,1,0,1},
                                  {1,0,1,0}};
    graph::diGraph g(4);
    
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    //g.adjacencyMatrix(matrix);

    g.print();
    cout<<endl;

    std::string var = CHANGE_ID_TO_STRING(matrix);

    cout<<var;
    return 0;
}