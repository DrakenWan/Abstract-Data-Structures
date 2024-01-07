#pragma once
#include<vector>
#include<stdexcept>
#include "../stack.h"
#include "../queue.h"
#include "../pqueue.h"

namespace graph{

class uGraph {

    int nV;
    std::vector<std::vector <int>> adjMat; 

    public:
    uGraph() {
        std::cout<<"\nNull graph.";
    }

    uGraph(int vertices) : nV(vertices){
        this->adjMat.resize(nV, std::vector<int>(nV));
        //std::cout<<"\nGraph created.";
    }

    void adjacencyMatrix(std::vector<std::vector <int>> matrix, int nv = -1) {
        if (matrix.size() != this->nV && nv == -1){
            throw std::invalid_argument("Adjacency matrix not the same size as number of vertices given.");
            return;
        }

        if(nv != -1) this->nV = nv;
        this->adjMat = matrix;
        this->nV = this->adjMat.size();
        std::cout<<"\nAdjacency Matrix updated.";
    }

    // temp functions
    void print() {
        std::cout<<"\n";
        for(int i=0; i<this->nV; i++) {
            for(int j=0; j<this->nV; j++) 
                std::cout<<this->adjMat[i][j]<<" ";
            std::cout<<"\n";
        }
    }


    // methods prototype
    std::vector<int> nodes();
    std::vector<int> const returnAdjacentNodes(int index);
    void bfs(int start);
    void dfs(int start);
    void ucs(int start, int goal);

    void addEdge(int v, int w, int cost=1); //by default cost is 1 if not set

    void dfs_recursive_main(int start);
    void dfs_recursive(int node, std::vector<bool> &visited);

    std::vector<int> operator[](int index);
};

//
std::vector<int> uGraph::operator[](int index) {
    if(index > this->nV) {
        std::cout<<"Error: vertex not present in graph.";
        exit(0);
    }

    std::vector<int> disp;
    for(auto i = 0; i < this->adjMat[index].size(); i++)
        if(this->adjMat[index][i] != 0)
            disp.push_back(i);

    return disp;
}

// returns a std::vector of nodes in the graph
std::vector<int> uGraph::nodes() {
    std::vector<int> nodo;

    for(int i=0; i<this->adjMat.size(); i++) 
        nodo.push_back(i);
    
    return nodo;
}

//returns a std::vector of child nodes of a node
std::vector<int> const uGraph::returnAdjacentNodes(int index) {
    std::vector<int> nodo;

    for(int i = 0; i < this->nV; ++i)
        if(this->adjMat[index][i] != 0) 
            nodo.push_back(i);
    
    return nodo;
}

void uGraph::bfs(int start) {
    std::vector<bool> visited;
    visited.resize(this->nV, false);

    queue<int> q; //queue for our nodes

    //pushing start node of graph into visited nodelist
    visited[start] = true;
    q.enqueue(start);

    while(!q.isEmpty()) {

        //dequeue node from queue
        int node = q.dequeue();
        std::cout<<node<<" ";

        for(auto child : this->returnAdjacentNodes(node))
            if(!visited[child])
             {
                visited[child]=true;
                q.enqueue(child);
             }

    }
}

void uGraph::dfs(int start) {
    std::vector<bool> visited;
    visited.resize(this->nV, false);

    stack<int> s; //stack for our nodes

    //push starting node into stack
    visited[start] = true;
    s.push(start);

    while(s.StackLength() != 0) {
        int node = s.pop();
        std::cout<<node<<" ";

        for(auto child : this->returnAdjacentNodes(node))
            if(!visited[child]) {
                visited[child]=true;
                s.push(child);
            }
    }
}

void uGraph::ucs(int start, int goal) {
    std::vector<bool> visited;
    visited.resize(this->nV, false);

    pqueue pq;
    std::pair<int, int> startNode;
    startNode.first = start;
    startNode.second = 0; //arbitrary number = 0 // can put anything here cuz it's the start node and it will be dequeued first.

    visited[start] = true;
    pq.enqueue(startNode);

    while(!pq.isEmpty()) {
        std::pair<int, int> node = pq.dequeue();
        std::cout<<node.first<<" ";

        for(auto child : this->returnAdjacentNodes(node.first)) {
            if(child == goal) {
                std::cout<<"\nFound goal "<<goal<<" at cost "<<node.second + this->adjMat[node.first][child];
                return;
            }
            if(!visited[child]) {
                visited[child] = true;
                std::pair <int, int> childNode;
                childNode.first = child;
                childNode.second =  node.second + this->adjMat[node.first][child];

                pq.enqueue(childNode);
            }
        }
    }
}

void uGraph::addEdge(int v, int w, int cost){

    if( v < this->nV && w < this->nV)
    {
        this->adjMat[v][w] = cost;
        this->adjMat[w][v] = cost;
    }
    else {
        std::cout<<"Bad vertex. Recheck. Exiting program.";
        exit(0);
    }
    
}

//recursive dfs main function
void uGraph::dfs_recursive_main(int node) {
    std::vector<bool> visited;
    visited.resize(this->nV, false);
    
    this->dfs_recursive(node, visited);
}

void uGraph::dfs_recursive(int node, std::vector<bool> &visited) {
    visited[node] = true;
    std::cout<<node<<" ";
    std::vector<int> neighbs = this->returnAdjacentNodes(node);

    for(auto &i : neighbs)
        if(visited[i] == 0)
            this->dfs_recursive(i, visited);
}

void printVector(std::vector<int> arr) {
    for(auto i=arr.begin(); i!=arr.end(); ++i)
        std::cout<<*i<<" ";
    std::cout<<"\n";
}
}




