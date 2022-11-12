<small> NOTE: I will refactor and cleanup this markdown file asap </small>
 
# GRAPHS 

G(E, V) where E is set of edges connecting 
the set of vertices V


## TYPES

1.  A Null Graph has no edges.

2.  A Trivial Graph has only a single vertex. Smallest possible graph

3.  A graph in which edges do not have any direction is called
    Undirected Graph.

4.  Directed graph has edges with direction. 
    Illustration1-
    !https://media.geeksforgeeks.org/wp-content/uploads/20200630114438/directed.jpg

5.  Connected Graph is one in which from one node we can
    visit any other node in the graph

6.  Disconnected graph: You guessed it! Atleast one node has to
    be not reachable from a node

    Illustration2:-
    !https://media.geeksforgeeks.org/wp-content/uploads/20200630121400/connected1.jpg

7.  Regular Graph is one in which degree of every vertex is equal
    to the other vertices of graph

8.  Complete Graph: from each node there is an edge to each other node    
    Illustration3:-
    !https://media.geeksforgeeks.org/wp-content/uploads/20200630122008/regular.jpg

9.  Cycle Graph: graph is a cycle in itself. Degree of each vertex is 2.
10. Cyclice Graph: A graph containing atleast one cycle

    Illustration4:-
    !https://media.geeksforgeeks.org/wp-content/uploads/20200630122225/cyclic.jpg

11. Directed Acyclic Graph: A directed graph that does not co-
    ntain any cycle

12. Bipartite Graph: A graph in which vertices can be divided into
    two sets st. in each set vertices do not contain any edge
    between them.

13. Weighted Graph:
    A graph in which edges are already specified with suit-
    able weight is known as weighted graph.

    weighted graphs further classified based on edge direction
    existence vis a vis Undirected and directed WGs.


■ TREES vs GRAPHS

All trees are graphs.
Not all graphs are trees.

Linked List, Tree and Heaps are special cases of graphs.

Illustration5:-
!https://media.geeksforgeeks.org/wp-content/uploads/20200630123458/tree_vs_graph.jpg

■ Representation of Graphs

There are two ways to store a graph:-
1. Adjacency Matrix
2. Adjacency List

Ɑ==8 ADJACENCY MATRIX 8==D

    - 2D Matrix
    - rows and columns are vertices
    - each value represents the weight of the
    edge between the vertices

    Illustration6:-
    !https://media.geeksforgeeks.org/wp-content/uploads/20200630124726/adjacency_mat1.jpg

Ɑ==8 ADJACENCY LIST 8==D

    - represented as a collection of linked lists.
    - array of pointer which points to the edges connected
    to that vertex (better understood through illustration
    below)

    Illustration7:-
    !https://media.geeksforgeeks.org/wp-content/uploads/20200630125356/adjacency_list.jpg

AMatrix vs AList

    It is good to not have sparse matrix. If there are lot
    of edges then adjacency matrix is a good use

Action        | Adj Matrix   | Adj List 
----------------------------------
Add Edge      |  O(1)        | O(1)
Removing Edge |  O(1)        | O(N)
Initialize    |  O(N*N)      | O(N)


■ Basic Operations on Graphs

- Insertion of Nodes/Edges
- Deletion of Nodes/Edges
- Searching on Graphs
- Traversal of Graphs

■ Usage of Graphs

- Maps can be respresented using graphs. Use search algo on
    them to find shortest route, etc.
- When various tasks depend on each other. This scenario
    can be represented using a directed acyclic graph. Topological
    sort helps find order in which tasks can be done.
- State Transition Diagram

\*/


