#pragma once
#include<vector>
#include<stdexcept>


namespace graph {
class diGraph {
    int nV; // vertices;
    std::vector<std::vector<int>> adjMat; 

    public:
        diGraph() {
            std::cout<<"Null graph created.\n";
        }

        diGraph(int vertices) : nV(vertices) {
            this->adjMat.resize(vertices, std::vector<int>(vertices));
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
};

} //graph namespace