#include<iostream>
#include<vector>
#include "./ugraph.h"

using namespace std;

int main() {
    graph::uGraph g(10);
    /*
        S - 0
        A - 1
        B - 2
        C - 3
        D - 4
        E - 5
        F - 6
        G1 - 7
        G2 - 8
        G3 - 9
    
    */

   // modified form of example graph from the video: https://www.youtube.com/watch?v=1wu2sojwsyQ //
   // This is an undirected graph
    g.addEdge(0, 1, 7);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 4, 2);
    g.addEdge(1, 7, 4);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 8, 1);
    g.addEdge(3, 6, 12);
    g.addEdge(4, 3, 4);
    g.addEdge(4, 5, 5);
    g.addEdge(5, 9, 6);
    g.addEdge(6, 4, 3);
    g.addEdge(6, 9, 8);

    


    int node_index = 0;
    // cout<<"recursive DFS Traversal from node "<<node_index<<".\n";
    // g.dfs_recursive_main(node_index);
    // cout<<endl;
    // cout<<"DFS Traversal from node "<<node_index<<".\n";
    // g.dfs(node_index);
    // cout<<endl;
    // cout<<"BFS Traversal from node "<<node_index<<".\n";
    // g.bfs(node_index);
    // cout<<endl;
    cout<<"UCS Traversal from node "<<node_index<<".\n";

    int goal = 9;
    g.ucs(node_index, goal);
    cout<<endl<<"UCS Traversal from node g["<<node_index<<"] to our goal 4.\n";
    g.ucs(node_index, 4);
    cout<<endl;
    return 0;
}
