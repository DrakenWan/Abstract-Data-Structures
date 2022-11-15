#include<iostream>
#include<vector>
#include "../stack.h"
#include "../queue.h"
#define dtype int

using namespace std;

// this undirected graph is represented by adjacency matrix; personal choice
class uGraph {
    int nV; //number of vertices
    vector<vector <int>> adjMat; //adjacency matrix
    
    //void bfs(int); //takes the value of start node

    public:
    uGraph() {
        cout<<"\nNull graph.";
    }

    uGraph(int vertices) {
        this->nV = vertices;
        this->adjMat.resize(nV);
        for(int i=0; i<nV; i++)
            this->adjMat[i].resize(nV,0);
        
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
        cout<<"\nAdjacency Matrix updated.";
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
    void dfs(int start);
    void addEdge(int v, int w, int cost=1);
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

    queue q; //queue for our nodes

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

void uGraph::dfs(int start) {
    vector<bool> visited;
    visited.resize(this->nV, false);

    stack<dtype> s; //stack for our nodes

    //push starting node into stack
    visited[start] = true;
    s.push(start);

    while(s.StackLength() != 0) {
        int node = s.pop();
        cout<<node<<" ";

        for(auto child : this->returnChildNodes(node))
            if(!visited[child]) {
                visited[child]=true;
                s.push(child);
            }
    }
}


void uGraph::addEdge(int v, int w, int cost){

    if( !(v < this->nV && v > -1) && !(w < this->nV && w > -1))
        {
            cout<<"Bad vertex. Recheck.";
            return;
        }
    this->adjMat[v][w] = cost;
    this->adjMat[w][v] = cost;
}


//////// 
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
    //g.adjacencyMatrix(aloo);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.print();

    vector<int> nodes = g.nodes();
    printVector(nodes);

    int idx = 2;
    int node = nodes[idx];
    cout<<endl<<node;
    vector<int> succs = g.returnChildNodes(node);

    printVector(succs);

    g.bfs(0);
    cout<<endl;
    g.dfs(0);
    return 0;
}

