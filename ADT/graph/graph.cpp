#include<iostream>
#include<vector>
//#include "../linked lists/singlylinkedlist.h"
#include "../queue.h"
#define dtype int

using namespace std;

// this undirected graph is represented by adjacency matrix; personal choice
class uGraph {
    /*
        This is an undirected graph implemented by
         
    */
    int nV; //number of vertices
    vector<vector <int>> adjMat; //adjacency matrix
    
    //void bfs(int); //takes the value of start node

    public:
    uGraph() {
        cout<<"\nNull graph.";
    }

    uGraph(int vertices) {
        this->nV = vertices;
        cout<<"\nGraph created.";
    }

    void adjacencyMatrix(vector<vector <int>> matrix, int nv = -1) {
        
        if (matrix.size() != this->nV && nv == -1){
            cout<<"\nError. Adjacency matrix not the same size as number of vertices given.";
            return;
        }

        if(nv != -1) this->nV = nv;
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


    // methods prototype
    vector<int> nodes();
    vector<int> returnChildNodes(int index);
    void bfs(int start);
};


// returns a vector of nodes in the graph
vector<int> uGraph::nodes() {
    vector<int> nodo;

    for(int i=0; i<this->adjMat.size(); i++) 
        nodo.push_back(i);
    
    return nodo;
}

//returns a vector of child nodes of a node
vector<int> uGraph::returnChildNodes(int index) {
    vector<int> nodo;

    for(int i = 0; i < this->nV; ++i)
        if(this->adjMat[index][i] == 1) 
            nodo.push_back(i);
    
    return nodo;
}

void uGraph::bfs(int start) {
    vector<bool> visited;
    visited.resize(this->nV, false);

    queue q; //queue for our BFS

    //pushing start node of graph into visited nodelist
    visited[start] = true;
    q.enqueue(start);

    while(!q.isEmpty()) {

        //dequeue node from queue
        int node = q.dequeue();
        cout<<node<<" ";

        for(auto child : this->returnChildNodes(node))
            if(!visited[child])
             {
                visited[child]=true;
                q.enqueue(child);
             }

    }
}

void printVector(vector<int> arr) {
    cout<<endl;
    for(auto i=arr.begin(); i!=arr.end(); ++i)
        cout<<*i<<" ";
    cout<<endl;
}

int main() {

    vector<vector<int>> aloo = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    cout<<aloo.size();

    uGraph g(aloo.size());
    g.adjacencyMatrix(aloo);
    g.print();

    vector<int> nodes = g.nodes();
    printVector(nodes);

    int idx = 2;
    int node = nodes[idx];
    cout<<endl<<node;
    vector<int> succs = g.returnChildNodes(node);

    printVector(succs);

    g.bfs(1);
    return 0;
}

