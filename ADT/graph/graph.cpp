#include<iostream>
#include<vector>
//#include "../linked lists/singlylinkedlist.h"
#define dtype int

using namespace std;

// this undirected graph is represented by adjacency matrix; personal choice
class uGraph {
    int nV; //number of vertices
    vector<vector <int>> adjMat; //adjacency matrix
    
    public:
    uGraph() {
        cout<<"\nSingle node Graph created.";
    }

    uGraph(vector<vector <int>> matrix) {
        this->adjMat = matrix;
        this->nV = this->adjMat.size();
        cout<<"\nAdjacency Matrix created.";
    }

    // temp functions
    void print() {
        cout<<"\n";
        for(int i=0; i<this->nV; i++) {
            for(int j=0; j<this->nV; j++) 
                cout<<this->adjMat[i][j]<<" ";
            cout<<endl;
        }
    }
};


int main() {

    vector<vector<int>> aloo = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 1, 0}
    };
    cout<<aloo.size();

    uGraph g(aloo);
    g.print();
    return 0;
}
