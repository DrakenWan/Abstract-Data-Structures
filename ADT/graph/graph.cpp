#include<iostream>
#include<vector>
#include "../linked lists/singlylinkedlist.h"
#define dtype int

using namespace std;

class Graph {
    int choice;
    vector<vector <int>> adjMat;
    vector<dtype> adjList;

    public:
    Graph(int choice=0) {
        this->choice = choice;
        if(this->choice) cout<<"Using Adjacency List.";
        if(!this->choice) cout<<"Using Adjacency Matrix";
        cout<<"\nGraph created.";
    }

    Graph(vector<vector <int>> data) {
        this->adjMat = data;
        this->choice = 0;
        cout<<"\nAdjacency Matrix created.";
    }

    Graph(vector<dtype> al) {
        this->adjList = al;
        this->choice = 1;
        cout<<"\nAdjacency List created.";
    } 


    // temp functions
    void display() {
        if(this->choice) cout<<this->adjList[0];
        if(!this->choice) cout<<this->adjMat[0][0];
    }


};


int main() {

    vector<vector<int>> aloo = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 1, 0}
    };

    vector<dtype> l(5,10);
    Graph g(aloo);
    g.display();
    return 0;
}
